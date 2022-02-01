#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 21
#define COLUMNS 80
#define SEED 32

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
    int column = rand() % (COLUMNS - 2) + 1;

    for(row = 0; row < ROWS; row++){
        srand(time(NULL));
        BLOCK[row][column] = '#';
        row += (rand() % 2) - 1;
    }

    srand(SEED);
    row = rand() % (ROWS - 3) + 1;

    for(column = 0; column < COLUMNS; column++){
        srand(time(NULL));
        BLOCK[row][column] = '#';
        column += (rand() % 2) - 1;
    }
    srand(SEED);
}

void tall_gen(int size, int startR, int startC){
    int row; 
    int column; 

    for(row = startR; row < size; row++){
        for(column = startC; column < size; column++){
            BLOCK[row][column] = ',';
        }
    }
    
}

void clear_gen(int size, int startR, int startC){
    int row; 
    int column; 

    for(row = startR; row < size; row++){
        for(column = startC; column < size; column++){
            BLOCK[row][column] = '.';
        }
    }
    
}

void gen_terrain(){
    edge_gen();
    path_gen();
    // tall_gen(7, 1, 1);
    clear_gen(7, 1, 1);
}


int main(){
    srand(SEED);

    printf("\n");
    gen_terrain();

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