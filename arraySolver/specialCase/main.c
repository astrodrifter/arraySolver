#include <stdio.h>
#include <stdlib.h>

/*PROTOTYPES */
int getSize();
void fillArray(int **array, int *rowTotal, int *colTotal, int count);
int solveArray(int **myArray, int *rowTotal, int *colTotal, int size);
int specialCase(int **myArray, int *rowTotal, int *colTotal, int size);

int main()
{
    int x, y, size = 0, i;

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
    
    /* fill arrays */
    fillArray(myArray, rowTotal, colTotal, size);
  
    /* print arrays */
    printf("\nArray size is %i x %i\n\n",size,size);
    printf("Unsolved array\n");
    for(x = 0; x < size; x++)
    {
        for(y = 0; y < size; y++)
        {
            printf("%i ",myArray[x][y]);
        }
        printf("\n");
    }
    printf("\nRow totals\n");
    for(int i = 0; i < size; i ++)
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
    
    /* solve array 
     * while not solved
     *      solved = solveArray
     *      if solved = 1 array is solved
     *      else if solved = 2 special case algorithm
     * 
     * */
    int solved = 0;
    while(solved != 1)
    {
        solved = solveArray(myArray, rowTotal, colTotal, size);
        if(solved == 2)
        {
            solved = specialCase(myArray, rowTotal, colTotal, size);
        }
    }
    
    /* print solution */
    printf("Solved array\n");
    for(int x = 0; x < size; x++)
    {
        for(y = 0; y < size; y++)
        {
            printf("%i ",myArray[x][y]);
        }
        printf("\n");
    }
    printf("\n");
    
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
            //printf("It has been %i loops and still not solved\n",count);
            printf("puzzle not solved in amature function\n");
            solved = 2;
            return solved;
        }
        
    }
    //printf("it took %i loops to solve\n\n", count);
    return solved;
}

/* special case algorithm */
int specialCase(int **myArray, int *rowTotal, int *colTotal, int size)
{
    printf("\nYou have reached specialCase() function.\n\n");
    printf("Prepare to experiance my awesome algorithm.\n\n");
    /* find -1's
     * guess
     */
    int i, j, x, solved = 0;
    /* rows */
    while(solved != 1)
    {
        for(i = 0; i < size; i ++)
        {
            for(j = 0; j < size; j++)
            {
                if(myArray[i][j] == -1)
                    for(x = 0; x < 10; x++)
                    {
                        myArray[i][j] = x;
                        solved = solveArray(myArray, rowTotal, colTotal, size);
                    }
            }
        }
    }
    if(solved == 1)
    {
        printf("Array solved in special case function.\n\n");
        return solved;
    } 
    return 1;
}