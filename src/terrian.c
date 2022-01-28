#include <stdio.h>
#include <stdlib.h>

#define ROWS 80
#define COLUMNS 21

char* BLOCK[ROWS][COLUMNS];

void edge_gen(){
    int row, column;

    // creates the border of impassible rocks
    for(column = 0; column < COLUMNS; column++){
        for(row = 0; row < ROWS; row++){
            if(column == 0 || row == 0 || column == COLUMNS - 1 || row == ROWS - 1)
                BLOCK[row][column] = "%";
            else
                BLOCK[row][column] = " ";
        }
    }
}

int main(){
    printf("\n");
    edge_gen();

    int row, column;

    //prints the map
    for(column = 0; column < COLUMNS; column++){
        for(row = 0; row < ROWS; row++){
            printf("%s", BLOCK[row][column]);
        }
        printf("\n");
    }

    return 0;
}