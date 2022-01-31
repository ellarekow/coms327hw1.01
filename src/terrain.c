#include <stdio.h>
#include <stdlib.h>

#define ROWS 21
#define COLUMNS 80

char BLOCK[ROWS][COLUMNS];

void edge_gen(){
    int row, column;

    // creates the border of impassible rocks
    for(row = 0; row < ROWS; row++){
        for(column = 0; column < COLUMNS; column++){
            if(column == 0 || row == 0 || column == COLUMNS - 1 || row == ROWS - 1)
                BLOCK[row][column] = '%';
            else
                BLOCK[row][column] = ' ';
        }
    }
}

void path_gen(){
    // N to S path
    int row;
    int column = rand() % COLUMNS;

    for(row = 0; row < ROWS; row++){
        BLOCK[row][column] = '#';
    }

    row = rand() % (ROWS - 2) + 1;

    for(column = 0; column < COLUMNS; column++){
        BLOCK[row][column] = '#';
    }
}

int main(){
    srand(32);

    printf("\n");
    edge_gen();
    path_gen();

    int row, column;

    //prints the map
    
    for(row = 0; row < ROWS; row++){
        for(column = 0; column < COLUMNS; column++){
            printf("%c", BLOCK[row][column]);
        }
        printf("\n");
    }

    return 0;
}