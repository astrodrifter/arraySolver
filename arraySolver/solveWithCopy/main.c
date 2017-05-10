/* A puzzle grid is an N-by-N grid in which every number in the 
 * grid must be a single digit number. Therefore, only numbers 
 * in the range from 0 to 9 are allowed. Duplicate numbers are 
 * allowed. At the end of each row and column there is a number 
 * representing the sum of that row or column. For example, in 
 * the figure below the first row has a sum of 6 (= 5 + 0 + 1) 
 * and the third column has a sum of 9 (= 1 + 6 + 2).
 * 
 * Write a puzzle solver program that will solve these types of 
 * puzzles. Your program will need to read grid data from a provided 
 * file and solve the puzzle based on the file’s input data.
 * 
 * My solution algorithm is as follows:
 * 
 * while not solved
 *      check rows
 *      if row has one empty space 
 *          solve
 *      check column
 *      if column has one epty space 
 *          solve
 * if above algorithm does not solve the puzzle
 *      send to specialCase()
 *          create array copy
 *          find -1 in copy
 *          guess a value and put in copy
 *          send copy to solveArray()
 *          if copy solves
 *              send copy to checkTotals()
 *              if checkTotals() returns true
 *                  puzzle is solved
 * 
 * 
 * Dhruva O'Shea 10/05/17
 * 
 * 
 */ 
#include <stdio.h>
#include <stdlib.h>

/*PROTOTYPES */
int getSize(); // gets array size from file
void fillArray(int **array, int *rowTotal, int *colTotal, int count); // fills array from file
void createCopy(int **myArray, int **copyArray, int size); // creates array copy for specialCase()
void printUnsolvedArray(int **array, int *rowTotal, int *colTotal, int size); //prints unsolved array
int checkTotals(int **copyArray, int *rowTotal, int *colTotal, int size); // checks totals, returns 1 if true
int solveArray(int **myArray, int *rowTotal, int *colTotal, int size); // solves array simple algorithm
int specialCase(int **myArray, int **copyArray, int *rowTotal, int *colTotal, int size); // solves puzzle extended algorithm
void printSolvedArray(int **array, int size); // prints solved array

/* main starts here */
int main()
{
    int i, size = 0;
    size = getSize(); // get size from file

    /* creating memory for array, row totals and column totals */
    int **myArray = (int **)malloc(size*sizeof(int *));
    for(i=0; i<size; i++)
    {
        myArray[i] = (int *)malloc(size*sizeof(int));
    }
    int *rowTotal = (int *)malloc(size*sizeof(int));
    rowTotal = (int *)malloc(size*sizeof(int));
    int *colTotal = (int *)malloc(size*sizeof(int));
    colTotal = (int *)malloc(size*sizeof(int));
    
    /* creat memory for a copy of array incase the going gets tuff */
    int **copyArray = (int **)malloc(size*sizeof(int *));
    for(i=0; i<size; i++)
    {
        copyArray[i] = (int *)malloc(size*sizeof(int));
    }
    
    /* fill arrays */
    fillArray(myArray, rowTotal, colTotal, size);
    
    /* print arrays */
    printUnsolvedArray(myArray, rowTotal, colTotal, size);
    
    
    /* Array solver algorithm starts here as discribed below
     * while not solved
     *      solved = solveArray
     *      if solved = 1 
     *          array is solved
     *      else if solved = 2 
     *          special case algorithm
     *              create array copy
     *              find -1 in copy
     *              guess a value and put in copy
     *              send copy to solveArray()
     *               if copy solves
     *                   send copy to checkTotals()
     *               if checkTotals() returns true
     *                   puzzle is solved
    */
    int solved = 0;
    while(solved != 1)
    {
        solved = solveArray(myArray, rowTotal, colTotal, size); // simple solution
        if(solved == 2)
        {
            /* special case algorithm here */
            solved = specialCase(myArray, copyArray, rowTotal, colTotal, size); // special case
        }
    }
    
    /* print solution */
    printf("Solved array:\n");
    printSolvedArray(myArray, size);
    
    // deleting memory
    for(i=0; i<size; i++)
    {
        free(myArray[i]);
    }
    free(myArray);
    free(rowTotal);
    free(colTotal);
}

/* Get aray size from file */
int getSize()
{
    FILE * pointer;
    int size;
    
    pointer = fopen("../test25.txt", "r"); // file reads here. 
                                           // Change according to your data, name and location
    
    if(pointer == NULL)
    {
        printf("Open operation failed.");
        return 1;
    }

    fscanf(pointer, "%d", &size);
    fclose(pointer);
    return size;
}

/* fill arrays from file */
void fillArray(int **array, int *rowTotal, int *colTotal, int count)
{
    FILE * pointer;
    int i, j, x;

    pointer = fopen("../test25.txt", "r"); // file reads here. 
                                           // Change according to your data, name and location

    // skipping size value
    fscanf(pointer, "%d", &x);
  
    for(i = 0; i < count + 2; i++)
    {
        if( i == count)
        {
            for(j = 0; j < count; j++)
            {
                fscanf(pointer, "%d",&rowTotal[j]);
            }
        } else if (i == count + 1) {
            for(j = 0; j < count; j++)
            {
                fscanf(pointer, "%d",&colTotal[j]);
            }
        } else {
            for(j = 0; j < count; j++)
            {
                fscanf(pointer, "%d",&array[i][j]);
            }
        }
    }
    fclose(pointer);
}

/* create copy array */
void createCopy(int **myArray, int **copyArray, int size)
{
    /* create array copy */
    int i, j;
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            copyArray[i][j] = myArray[i][j];
        }
    }
}

/* print unsloved array data */
void printUnsolvedArray(int **array, int *rowTotal, int *colTotal, int size)
{
    int i, x, y;
    printf("\nArray size is %i x %i\n\n",size,size);
    printf("Unsolved array\n");
    for(x = 0; x < size; x++)
    {
        for(y = 0; y < size; y++)
        {
            printf("%i ",array[x][y]);
        }
        printf("\n");
    }
    printf("\nRow totals\n");
    for(i = 0; i < size; i ++)
    {
        printf("%i ", rowTotal[i]);
    }
    printf("\n\n");
    printf("Column totals\n");
    for(int i = 0; i < size; i ++)
    {
        printf("%i ", colTotal[i]);
    }
    printf("\n\n");
}

/* solve array copy to check if guess is correct */
int checkTotals(int **copyArray, int *rowTotal, int *colTotal, int size)
{
    /* sum each row
     * check equals total
     * sum each colum
     * check equals total
     */
     
     /* check row totals */
     int i, j, sumRow = 0;
     for(i = 0; i < size; i++)
     {
         sumRow = 0;
         for(j = 0; j < size; j++)
         {
             sumRow += copyArray[i][j];
         }
         if(sumRow != rowTotal[i])
         {
             printf("Row %i total of %i doesnt equal rowTotal[%i] of %i\n\n",i,sumRow,i,rowTotal[i]);
             return 0;
         }
            
     }
     /* check column totals */
     int k, l, sumCol = 0;
     for(k = 0; k < size; k++)
     {
         sumCol = 0;
         for(l = 0; l < size; l++)
         {
             sumCol += copyArray[l][k];
         }
         if(sumCol != colTotal[k])
         {
             printf("Column %i total of %i doesnt equal colTotal[%i] of %i\n\n",i,sumCol,i,colTotal[i]);
             return 0;
         }
            
     }
     return 1; // if all row and column totals are correct return 1
}

/* solve array returns 1 is solved or 2 if not solvable with this algorithm 
     * array solver algorithm
     * 
     *      while not solved
     *         check rows
     *         if row has one empty space 
     *            solve
     *         check column
     *         if column has one empty space 
     *            solve
     * 
     * Note: if more than one empty space left in more than one array or column 
     * array will not be solved by this algorithm.
*/
int solveArray(int **myArray, int *rowTotal, int *colTotal, int size)
{
    int solved = 0, count = 0;
    while(solved != 1)
    {
        /* check if not solved */
        int countEmpty = 0;
        for(int i = 0; i< size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                if(myArray[i][j] == -1)
                {
                    countEmpty++;
                }
            }
        }
        if(countEmpty == 0)
        {
            solved = 1; // there's no -1, puzzle is solved
        }
        
        /* check if row has one empty and solve - working */
        int sumRow, countRow;
        for(int i = 0; i < size; i++) // for each row
        {
            sumRow = 0, countRow = 0;
            for(int j = 0; j < size; j++) // for each column
            {
                sumRow += myArray[i][j];
                if(myArray[i][j] == -1)
                {
                    countRow++;
                }
            }
            
        /* if one empty space in row solve row */
            sumRow++; // to account for the -1
            if(countRow == 1)
            {
                int difRow = rowTotal[i] - sumRow;
                for(int j = 0; j < size; j++)
                {
                    if(myArray[i][j] == -1)
                    {
                        myArray[i][j] = difRow;
                    }
                }
            }
        }
    
        //check if row has one empty and solve - working
        int sumCol, countCol;
        for(int i = 0; i < size; i++) // for each row
        {
            sumCol = 0, countCol = 0;
            for(int j = 0; j < size; j++) // for each column
            {
                sumCol += myArray[j][i];
                if(myArray[j][i] == -1)
                {
                    countCol++;
                }
            }
            
        /* if only one empty space in column solve column */
            sumCol++; // to account for the -1
            if(countCol == 1)
            {
                int difCol = colTotal[i] - sumCol;
                for(int j = 0; j < size; j++)
                {
                    if(myArray[j][i] == -1)
                    {
                        myArray[j][i] = difCol;
                    }
                }
            }
        }
        if(solved == 1)
        {
            return solved;
        }
        count++;
        if(count == 20)
        {
            printf("It has been %i loops and still not solved\n\n",count);
            printf("puzzle not solved in amature function\n\n");
            printf("Array progress\n");
            printSolvedArray(myArray, size);
            solved = 2;
            return solved;
        }
        
    }
    //printf("it took %i loops to solve\n\n", count);
    return solved;
}

/* special case algorithm */
int specialCase(int **myArray, int **copyArray, int *rowTotal, int *colTotal, int size)
{
    printf("\nYou have reached my special Case function.\n\n");
    printf("Prepare to experiance my awesome extended algorithm.\n\n");
    /* Algorithm
     * create a copy of array
     * find -1 record position
     * guess and put in copy
     * check if copy solves and totals are correct
     * if yes 
     *     put guess in myArray and solve 
     * else 
     *     make copy of orginal again and make new guess
     * keep going until its solves.
     */
     
    int i, j, x, solved = 0, check1 = 0, check2 = 0;
    /* rows */
    while(solved != 1 && check1 != 1 && check2 != 1)
    {
        for(i = 0; i < size; i ++)
        {
            for(j = 0; j < size; j++)
            {
                if(myArray[i][j] == -1)
                {
                    for(x = 0; x < 10; x++)
                    {
                        createCopy(myArray, copyArray, size); // create a copy array to check solution
                        copyArray[i][j] = x;   // put a guess in copyArray
                        check1 = solveArray(copyArray, rowTotal, colTotal, size); //check1 if copyArray is solved
                        check2 = checkTotals(copyArray, rowTotal, colTotal, size); // check2 totals
                        if(check1  == 1 && check2 == 1) // if arrays solves and totals are correct
                        {
                            myArray[i][j] = x;  // put guess into myArray and solve
                            solved = solveArray(myArray, rowTotal, colTotal, size);
                            return solved;
                        }
                    }
                }
            }
        }
    }
    if(solved == 1)
    {
        printf("Array solved in special case function.\n\n");
        return solved;
    } 
    return solved;
}

/* print solved array */
void printSolvedArray(int **array, int size)
{
    int x, y;
    //printf("Solved array\n");
    for(x = 0; x < size; x++)
    {
        for(y = 0; y < size; y++)
        {
            printf("%i ",array[x][y]);
        }
        printf("\n");
    }
    printf("\n");
}
