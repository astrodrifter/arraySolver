#include <stdio.h>

int getSize()
{
    FILE * pointer;
    int  count;
     
    pointer = fopen("../testTest.txt", "r");
     
    if(pointer == NULL)
    {
        printf("Open operation failed.");
        return 1;
    }
     
    fscanf(pointer, "%i", &count);
    return count;
}

void fillArray(int array[100][100])
{
    FILE * pointer;
    int i, j, x, y, count;
     
    pointer = fopen("../testTest.txt", "r");
     
    fscanf(pointer, "%i", &count);
     
    for(i = 0; i < count; i++)
    {
        for(j = 0; j < count; j++)
        {
            fscanf(pointer, "%i",&array[i][j]);
        }
        
        
    }
     
    fclose(pointer);
}

int main()
{
    int x, y, size = 0;
    size = getSize();
    int myArray[size][size];
    fillArray(myArray);
    
    printf("size = %i\n",size);
    for(x = 0; x < size; x++)
    {
        for(y = 0; y < size; y++)
        {
            printf("%i ",myArray[x][y]);
        }
        printf("\n");
        
    }
}

