#include <stdio.h>

/* PROTOTYPES */
int getSize();
void fillArray(int a[100][100], int size);
void printArray(int a[100][100], int b[], int c[], int size);
void sumRows(int a[100][100], int size);
void sumCols(int a[100][100], int size);
void getRowTotals(int rowTotals[], int size);
void getColTotals(int colTotals[], int size);
int solveArray(int myArray[100][100], int rowsTotals[], int colsTotals[], int size);

int main(int argc, char **argv)
{
	/* get size */
	int size;
	size = getSize();
	/* get array */
	int myArray[size][size]; 
	fillArray(myArray, size);
	/* get row totals */
	int rowsTotals[size];
	getRowTotals(rowsTotals,size);
	/* get column totals */
	int colsTotals[size];
	getColTotals(colsTotals,size);
	/* print data */
	printArray(myArray,rowsTotals,colsTotals,size);
	/* sum rows and columns */
	sumRows(myArray, size);
	sumCols(myArray, size);
    
    /* algorithm starts here */
    //int solved;
    solveArray(myArray, rowsTotals, colsTotals, size);
    //if (solved == 0)
    
    
    
    /* int solved = 0;
    while(solved != 1)
    {
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
            solved = 1;
        }
        //check if row has one empty and solve - working
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
            
    } */
    
	//print solved array
    printf("\nSolved array:\n");
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            printf("%i ",myArray[i][j]);
        }
        printf("\n");
    }
    printf("\n");
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
void printArray(int a[100][100], int rowTotals[], int colTotals[], int size)
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
void getRowTotals(a[], int size)
{
    printf("Enter %i row totals\n",size);
	int i;
	for(i=0; i<size; i++)
	{
		scanf("%i",&a[i]);
	}
}
/* get column totals */
void getColTotals(a[], int size)
{
    printf("Enter %i column totals\n", size);
	int i;
	for(i=0; i<size; i++)
	{
		scanf("%i",&a[i]);
	}
}

/* sum rows */
void sumRows(int a[100][100], int size)
{
	printf("\nRow and Column sums:\n");
	int i, j, sum;
	for(i=0; i<size; i++)
	{
		sum = 0;
		for(j=0; j<size; j++)
		{
			sum+=a[i][j];
		}
		printf("row %i sum = %i\n",i,sum);
	}
}

/* sum columns */
void sumCols(int a[100][100], int size)
{
	int i, j, sum;
	for(i=0; i<size; i++)
	{
		sum = 0;
		for(j=0; j<size; j++)
		{
			sum+=a[j][i];
		}
		printf("column %i sum = %i\n",i,sum);
	}
	printf("\n");
}

int solveArray(int myArray[100][100], int rowsTotals[], int colsTotals[], int size)
{
    int countEmpty = 0, solved = 0;
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
        solved = 1;
    }
    //check if row has one empty and solve - working
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
    return solved;
}
