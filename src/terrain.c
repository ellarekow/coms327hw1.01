#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    int column = rand() % (COLUMNS - 2) + 1;

    int random = rand() % 12;

    for(row = 0; row < ROWS; row++){
        BLOCK[row][column] = '#';
        if(random % 3 == 0 && column < COLUMNS - 1)
            column += (rand() % 3) - 1;

        random = rand() % 12;
    }
    
    row = rand() % (ROWS - 3) + 1;

    for(column = 0; column < COLUMNS; column++){
        BLOCK[row][column] = '#';
        if(random % 3 == 0 && row < ROWS - 1)
            row += (rand() % 3) - 1;
        
        random = rand() % 12;
    }
}

void tall_gen(int size, int startR, int startC){
    int row; 
    int column; 

    if(startR == 0)
        startR += 1;

    if(startC == 0)
        startC += 1;

    for(row = startR; row < (size + row) && (row < ROWS - 1); row++){
        for(column = startC; column < (size + column) && (column < COLUMNS - 1); column++){
            if(BLOCK[row][column] == ' ')
                BLOCK[row][column] = ',';
        }
    }
    
}

void clearing_gen(int size, int startR, int startC){
    int row; 
    int column; 

    if(startR == 0)
        startR += 1;

    if(startC == 0)
        startC += 1;

    for(row = startR; row < (size + row) && (row < ROWS - 1); row++){
        for(column = startC; column < (size + column) && (column < COLUMNS - 1); column++){
            if(BLOCK[row][column] == ' ')
                BLOCK[row][column] = '.';
        }
    }
    
}

void gen_terrain(){
    edge_gen();

    int size = (rand() % 20) + 2;
    int row = (rand() % 20) + 2;
    int column = (rand() % 20) + 2; 

    int number = (rand() % 10) + 2;

    int what = (rand() % 100) + 1;

    int i; 
    for(i = 0; i < number; i++){
        
        if(what % 7 == 2){
            if(row > 0 && column > 0)
                BLOCK[row][column] = '%';
        }
        else if(what % 10 == 3)
        {
            if(row > 0 && column > 0)
                BLOCK[row][column] = '"';
        }

        else if(what % 3 == 1)
            clearing_gen(size, row, column);

        else if(what % 2 == 0)
            tall_gen(size, row, column);


        size = (rand() % 10) + 2;
        row = (rand() % ROWS - 2) + 1;
        column = (rand() % COLUMNS - 2) + 1;
        what = rand() % 5;
    }
    path_gen();

}


int main(){
    int seed = time(NULL);
    srand(seed);

    printf("Seed: %d\n", seed);
    gen_terrain();

    int row, column;

    //prints the map
    char pos; 
    for(row = 0; row < ROWS; row++){
        for(column = 0; column < COLUMNS; column++){
            pos = BLOCK[row][column];

            if(pos == 'C')
                // red
                printf("\033[1;31m");
            else if(pos == '.')
                // green
                printf("\033[0;32m");
            else if(pos == 'M')
                // blue
                printf("\033[0;34m");
            else if(pos == '#')
                // white
                printf("\033[0;37m");
            else if(pos == '"')
                //yellow 
                printf("\033[0;33m");
            else if(pos == '%')
                //black
                printf("\033[0;30m");
            else if(pos == ',')
                //bright green
                printf("\033[92;102m");

            printf("%c", pos);
        }
        printf("\n");
    }

    return 0;
}