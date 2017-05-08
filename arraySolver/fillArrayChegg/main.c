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

void fillArray(int **array, int count)
{
    FILE * pointer;
    int i, j, x;

    pointer = fopen("../testTest.txt", "r");

    // skipping size value
    fscanf(pointer, "%d", &x);
  
    for(i = 0; i < count; i++)
    {
        for(j = 0; j < count; j++)
        {
            fscanf(pointer, "%d",&array[i][j]);
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

    fillArray(myArray, size);
  
    printf("size = %i\n",size);
    for(x = 0; x < size; x++)
    {
        for(y = 0; y < size; y++)
        {
            printf("%i ",myArray[x][y]);
        }
        printf("\n");
    }

    // deleting memory

    for(i=0; i<size; i++)
    {
        free(myArray[i]);
    }

    free(myArray);
}


