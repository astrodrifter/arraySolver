#include <stdio.h>
#include <stdlib.h>

/*PROTOTYPES */
int getSize();
void fillArray(int **array, int *rowTotal, int *colTotal, int count);
void createCopy(int **myArray, int **copyArray, int size);
//void fillCopy(int **copyArray, int size);
void printUnsolvedArray(int **array, int *rowTotal, int *colTotal, int size);
int checkTotals(int **copyArray, int *rowTotal, int *colTotal, int size); // checks totals retunrs 1 if true
int solveArray(int **myArray, int *rowTotal, int *colTotal, int size);
int specialCase(int **myArray, **copyArray, int *rowTotal, int *colTotal, int size);
void printSolvedArray(int **array, int size);

/* main starts here */
int main()
{
    int i, size = 0;

    size = getSize();

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
    //fillCopy(copyArray, size);
    
    /* print arrays */
    printUnsolvedArray(myArray, rowTotal, colTotal, size);
    
    /* solve array */
    /* first algorithm starts here */
    /* while not solved
     *      solved = solveArray
     *      if solved = 1 array is solved
     *      else if solved = 2 special case algorithm
    */
    int solved = 0;
    while(solved != 1)
    {
        solved = solveArray(myArray, rowTotal, colTotal, size);
        if(solved == 2)
        {
            /* special case algorithm here */
            solved = specialCase(myArray, copyArray, rowTotal, colTotal, size);
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
    int count;

    pointer = fopen("../test16.txt", "r");

    if(pointer == NULL)
    {
        printf("Open operation failed.");
        return 1;
    }

    fscanf(pointer, "%d", &count);
    fclose(pointer);
    return count;
}

/* fill arrays from file */
void fillArray(int **array, int *rowTotal, int *colTotal, int count)
{
    FILE * pointer;
    int i, j, x;

    pointer = fopen("../test16.txt", "r");

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

/* creat copy array */
void createCopy(int **myArray, int **copyArray, int size)
{
    /* create array copy */
    printf("you have netered the create copy function\n\n");
    int i, j;
    for(i = 0; i < size; i++)
    {
        printf("You have entered first for loop\n\n");
        for(j = 0; j < size; j++)
        {
            printf("You have entered second for loop\n\n");
            copyArray[i][j] = myArray[i][j];
        }
    }
}

/* fill copy 
void fillCopy(int **copyArray, int size)
{
    int i, j;
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            copyArray[i][j] = 0;
        }
    }
}*/

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
     
}

/* solve array returns 1 is solved or 2 if not solvable with this algorithm 
     * array solver algorithm
     * 
     *      while not solved
     *         check rows
     *         if row has one empty space 
     *            solve
     *         check column
     *         if column has one epty space 
     *            solve
     * 
     * Note: if more than one empty space left array will not be solved by this algorithm.
     * 
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
    printf("\nYou have reached specialCase() function.\n\n");
    printf("Prepare to experiance my awesome algorithm.\n\n");
    /* create a copy of array
     * find -1 record position
     * guess and put in copy
     * check if copy solves and totals are correct
     * if yes put guess in myArray and solve 
     * else make copy of orginal again and make new guess
     * keep going until its solves.
     */
     
    int i, j, x, solved = 0, check1 = 0, check2 = 0;
    /* rows */
    while(solved != 1 && check1 != 1 && check2 != 1)
    {
        printf("You made it into while loop\n\n");
        for(i = 0; i < size; i ++)
        {
            printf("You made it into first for loop\n\n");
            for(j = 0; j < size; j++)
            {
                printf("You made it into second for loop\n\n");
                if(myArray[i][j] == -1)
                {
                    printf("You found the first -1\n\n");
                    for(x = 0; x < 10; x++)
                    {
                        printf("You have entered the for x loop\n\n");
                        createCopy(myArray, copyArray, size); // create a copy array to check slution
                        printf("Copy array check:\n");
                        printSolvedArray(copyArray,size); // check copy arrived
                        copyArray[i][j] = x;   // put a guess in copyArray
                        check1 = solveArray(copyArray, rowTotal, colTotal, size); //check if copyArray is solved
                        check2 = checkTotals(copyArray, rowTotal, colTotal, size); // check totals
                        //check1 = solveArray(copyArray, rowTotal, colTotal, size); //check if copyArray is solved
                        // now check if totals are true
                        if(check1  == 1 && check2 == 1)
                        {
                            myArray[i][j] = x;
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
