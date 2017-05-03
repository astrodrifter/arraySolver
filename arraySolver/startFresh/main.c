/* 
 * 1 Get data 
 * 2 build algorithm
 * 
 * */ 
#include <stdio.h>

int getSize();
void fillArray(int a[100][100], int size);
void printArray(int a[100][100], int size);

int main(int argc, char **argv)
{
    int size;
    
    /* get size */
    printf("Enter size\n");
	scanf("%i",size);
    
    /* fill array */
    int array[size][size];
    printf("Enter data\n");
    fillArray(array, size);
    
	return 0;
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
void printArray(int a[100][100], int size)
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
}