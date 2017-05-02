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
 * file and solve the puzzle based on the file’s input data.
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
Test data 1: (solves)
   5
   -1 7 -1 5 -1
   7 -1 5 -1 2
   2 2 4 -1 6
   -1 -1 7 5 4
   5 4 4 4 -1
   20 20 20 19 18 
   17 15 25 25 15

Test data 2. (solves)
   3
   2 4 -1
   1 -1 1
   -1 8 -1
   8 9 16
   8 9 16
    
Test data 3. (solves)
    4
    0 0 -1 4
    2 9 4 -1
    -1 8 3 -1
    0 -1 0 0
    11 24 19 9
    2 26 14 21
    
Test data 4.  (cannot solve yet with my one epmty space algorithm)
    4
    -1 -1 -1 1
    9 0 -1 -1
    1 3 -1 -1
    0 8 6 -1
    7 10 14 19
    10 12 18 10
 
Test data 5. (solves)
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

int main()
{
    //start message
    printf("Enter your array data.\n");
    //get size of array
    int size;
    scanf("%i",&size);
    
    //initalise array
    int nums[size][size];
    
    //enter values into array
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            scanf("%i",&nums[i][j]);
        }
    }
    
    //get totals
    int rowsTotals[size];
    for(int i = 0; i < size; i++)
    {
        scanf("%i",&rowsTotals[i]);
    }
    
    int colsTotals[size];
    for(int i = 0; i < size; i++)
    {
        scanf("%i",&colsTotals[i]);
    }
    
    //print unsolved array
    printf("\nunSolved array:\n");
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            printf("%i ",nums[i][j]);
        }
        printf("\n");
    }
    
    printf("\nRows sums:\n");
    for(int i = 0; i < size; i++)
    {
        printf("%i ",rowsTotals[i]);
    }
    
    printf("\n\nColumn sums:\n");
    for(int i = 0; i < size; i++)
    {
        printf("%i ",colsTotals[i]);
    }
    printf("\n\n");
    
    int solved = 0;
    
    //Alogrithm starts here
    while(solved != 1)
    {
        int countEmpty = 0;
        for(int i = 0; i< size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                if(nums[i][j] == -1)
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
                sumRow += nums[i][j];
                if(nums[i][j] == -1)
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
                    if(nums[i][j] == -1)
                    {
                        nums[i][j] = difRow;
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
                sumCol += nums[j][i];
                if(nums[j][i] == -1)
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
                    if(nums[j][i] == -1)
                    {
                        nums[j][i] = difCol;
                    }
                }
            }
        
        }
            
    }
    //print solved array
    printf("Solved array:\n");
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            printf("%i ",nums[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}




