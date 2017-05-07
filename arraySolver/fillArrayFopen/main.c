#include <stdio.h>
 
#define ARRAY_SIZE 10
extern int array;

int fillArray()
{
    array[ARRAY_SIZE][ARRAY_SIZE];
    FILE * pointer;
    int i, j, x, y, count;
     
    pointer = fopen("../testTest.txt", "r");
     
    if(pointer == NULL)
    {
        printf("Open operation failed.");
        return 1;
    }
     
    fscanf(pointer, "%i", &count);
     
    for(i = 0; i < count; i++)
    {
        for(j = 0; j < count; j++)
        {
            fscanf(pointer, "%i",&array[i][j]);
        }
        
    }
    for(x = 0; x < count; x++)
    {
        for(y = 0; y < count; y++)
        {
            printf("%i",array[x][y]);
        }
        
    }
     
    fclose(pointer);
    return count;
}

int main()
{
    /*int x, y, count;
    count = fillArray();*/
    fillArray();
    /*for(x = 0; x < count; x++)
    {
        for(y = 0; y < count; y++)
        {
            printf("%i",array[x][y]);
        }
        
    }*/
}

/*
#include <stdio.h>
 
#define ARRAY_SIZE 20
 
 
int main()
{
    FILE * pointer;
    int test1[ARRAY_SIZE], test2[ARRAY_SIZE];
    int c, count;
     
    pointer = fopen("input.txt", "r");
     
    if(pointer == NULL)
    {
        printf("Open operation failed.");
        return 1;
    }
     
    fscanf(pointer, "%d", &count);
     
    for(c = 0; c < count; c++)
    {
        fscanf(pointer, "%d%d", &test1[c], &test2[c]);
    }
     
    fclose(pointer); 
}*/