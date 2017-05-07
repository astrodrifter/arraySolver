#include <stdio.h>
//Declare the global variables
FILE *gridFile = NULL; 		//The file that will be opened

void readFile() {
	//Open the file and test it worked.	
	gridFile = fopen("C:\\Assignment\\grid_11.txt", "r");	
	if (gridFile == NULL)
	{
		printf("Cannot open file.\n");
	} else {
		printf("Opening file\n");
		//Read the first line as that will set the size of the grid.
		fscanf(gridFile,"%i",&gridMAX);
	}
	if (debug) {printf("%i\n",gridMAX);}  		//Only for debuging to ensure that gridMAX contactins a value
}

int main(int argc, char **argv)
{
	readFile();
	return 0;
}
