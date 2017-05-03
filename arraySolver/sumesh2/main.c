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
 * file and solve the puzzle based on the fileâ€™s input data.
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
 * 
 * Dhruva O'Shea 22/04/17
 * 
 * 
 * 
Test data 1:
   5
   -1 7 -1 5 -1
   7 -1 5 -1 2
   2 2 4 -1 6
   -1 -1 7 5 4
   5 4 4 4 -1
   20 20 20 19 18 
   17 15 25 25 15

Test data 2.
   3
   2 4 -1
   1 -1 1
   -1 8 -1
   8 9 16
   8 9 16
    
Test data 3.
    4
    0 0 -1 4
    2 9 4 -1
    -1 8 3 -1
    0 -1 0 0
    11 24 19 9
    2 26 14 21
    
Test data 4.  (cannot solve yet with my one empty space algorithm)
    4
    -1 -1 -1 1
    9 0 -1 -1
    1 3 -1 -1
    0 8 6 -1
    7 10 14 19
    10 12 18 10
 
Test data 5.
    5
    -1 -1 0 -1 7
    0 4 5 -1 4
    7 1 -1 9 8
    0 5 0 -1 -1
    3 -1 -1 1 8
    15 15 29 22 23
    15 14 17 22 36
*/

#include <stdio.h>

/* PROTOTYPES */
int getSize();
void fillArray(int a[100][100], int size);
void printData(int a[100][100], int b[], int c[], int size);
void getRowTotals(int rowTotals[], int size);
void getColTotals(int colTotals[], int size);
void solveArray(int myArray[100][100], int rowsTotals[], int colsTotals[], int size);
void printArray(int myArray[100][100], int size);

int main(int argc, char **argv)
{
	/* get size */
	int size;
	size = getSize();
	/* get array */
	int myArray[100][100]; 
	fillArray(myArray, size);
	/* get row totals */
	int rowsTotals[size];
	getRowTotals(rowsTotals,size);
	/* get column totals */
	int colsTotals[size];
	getColTotals(colsTotals,size);
	/* print data */
	printData(myArray,rowsTotals,colsTotals,size);
    
    /* algorithm starts here */
    solveArray(myArray, rowsTotals, colsTotals, size);
    
	/* print solved array */
    printArray(myArray,size);
    
    /* finished program */
    return 0;
}

/* get size input */
int getSize()
{
	int input;
	printf("Enter integer N for your N X N array:\n");
	scanf("%i",&input);
	printf("Size = %i\n", input);
	return input;
}

/* Fills array */
void fillArray(int a[100][100], int size)
{
	printf("Enter %i integers\n",size*size);
	int i, j;
	for (i=0; i<size; i++)
	{
		for (int j=0; j<size; j++)
		{
			scanf("%i",&a[i][j]);
		}
	}
}

/* prints array */
void printData(int a[100][100], int rowTotals[], int colTotals[], int size)
{
	/* print puzzle array */
	printf("\nYou array is:\n");
	int i, j;
	for (i=0; i<size; i++)
	{
		for (int j=0; j<size; j++)
		{
			printf("%i ",a[i][j]);
		}
		printf("\n");
	}
	/* print row totals */
	printf("\nRow Totals are:\n");
	int k;
	for(k=0; k<size; k++)
	{
		printf("%i ",rowTotals[k]);
	}
	printf("\n");
	/* print column totals */
	printf("\nColumn Totals are:\n");
	int l;
	for(l=0; l<size; l++)
	{
		printf("%i ",colTotals[l]);
	}
	printf("\n\n");
}

/* get row totals */
void getRowTotals(int a[], int size)
{
    printf("Enter %i row totals\n",size);
	int i;
	for(i=0; i<size; i++)
	{
		scanf("%i",&a[i]);
	}
}
/* get column totals */
void getColTotals(int a[], int size)
{
    printf("Enter %i column totals\n", size);
	int i;
	for(i=0; i<size; i++)
	{
		scanf("%i",&a[i]);
	}
}
/* solve array */
void solveArray(int myArray[100][100], int rowsTotals[], int colsTotals[], int size)
{
    /* loop */
    int solved = 0;
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
                int difRow = rowsTotals[i] - sumRow;
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
                int difCol = colsTotals[i] - sumCol;
                for(int j = 0; j < size; j++)
                {
                    if(myArray[j][i] == -1)
                    {
                        myArray[j][i] = difCol;
                    }
                }
            }
        }
    }
}

/* print solved array */
void printArray(int a[100][100], int size)
{
    printf("\nSolved array:\n");
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            printf("%i ",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
