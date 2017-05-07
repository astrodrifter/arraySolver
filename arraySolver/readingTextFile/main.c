#include <stdio.h>

//Declare the global variables
FILE *gridFile = NULL; 		//The file that will be opened

void readFile(int data[100][100]) {
    /* get data and fill an array */
    //int gridSize, debug = 1;
    int i = 0;
	//Open the file and test it worked.	
	data = fopen("../test1.txt", "r");	
    
    while(!feof(data))
    {
        if (data == NULL)
            printf("Cannot open file.\n");
        else
            fgets(data[i], 10);
        i++;
    }
}

int main(int argc, char **argv)
{
	int gridFile[10][10];
    readFile(gridFile);
    
    for (int i = 0; i < 200; i++)
    {
        printf("Size = %i\n",gridFile[i]);
    }
    
    
	return 0;
}
