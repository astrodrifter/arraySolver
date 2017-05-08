#include <stdio.h>
#include <stdlib.h>

int getSize()
{
    FILE * pointer;
    int count;

    pointer = fopen("../testTest.txt", "r");

    if(pointer == NULL)
    {
        printf("Open operation failed.");
        return 1;
    }

    fscanf(pointer, "%d", &count);
    fclose(pointer);
    return count;
}

void fillArray(int **array, int *rowTotal, int *colTotal, int count)
{
    FILE * pointer;
    int i, j, x;

    pointer = fopen("../testTest.txt", "r");

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

int main()
{
    int x, y, size = 0, i;

    size = getSize();

    // creating memory for array
    int **myArray = (int **)malloc(size*sizeof(int *));

    for(i=0; i<size; i++)
    {
        myArray[i] = (int *)malloc(size*sizeof(int));
    }
    
    // creating memory for row totals
    int *rowTotal = (int *)malloc(size*sizeof(int));

    rowTotal = (int *)malloc(size*sizeof(int));
    
    // creating memory for column totals
    int *colTotal = (int *)malloc(size*sizeof(int));

    colTotal = (int *)malloc(size*sizeof(int));
    

    fillArray(myArray, rowTotal, colTotal, size);
  
    /* print array */
    printf("\n Array size is %i x %i\n\n",size,size);
    printf("Unsolved array\n");
    for(x = 0; x < size; x++)
    {
        for(y = 0; y < size; y++)
        {
            printf("%i ",myArray[x][y]);
        }
        printf("\n");
    }

    /* print row totals and column totals */
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
    
    // deleting memory

    for(i=0; i<size; i++)
    {
        free(myArray[i]);
    }

    free(myArray);
    free(rowTotal);
    free(colTotal);
}


