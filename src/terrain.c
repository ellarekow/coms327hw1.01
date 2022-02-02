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
        if(column == 0)
            column++;
        else if(column == ROWS - 1)
            column--;

        BLOCK[row][column] = '#';
        if(random % 3 == 0 && column < COLUMNS - 1)
            column += (rand() % 3) - 1;

        random = rand() % 12;
    }
    
    row = rand() % (ROWS - 3) + 1;

    for(column = 0; column < COLUMNS; column++){
        if(row == 0)
            row++;
        else if(row == ROWS - 1)
            row--;

        BLOCK[row][column] = '#';
        if(random % 3 == 0 && row < ROWS - 1)
            row += (rand() % 3) - 1;
        
        random = rand() % 12;
    }
}

void patch_gen(int size, int startR, int startC, char c){
    int row; 
    int column; 

    int sizeR, sizeC;
    

    if(startR == 0)
        startR += 1;

    if(startC == 0)
        startC += 1;

    sizeR = size;
    for(row = startR; size >= 0 && row < ROWS - 1; row++){
        sizeC = sizeR;
        for(column = startC; size >= 0 && column < COLUMNS - 1; column++){
            if(BLOCK[row][column] == ' ')
                BLOCK[row][column] = c;
            sizeC--;
        }
        sizeR--;

    }
    
}

void mart_gen(){
    
}

void gen_terrain(){
    edge_gen();
    
    int size = (rand() % 3);
    int row = (rand() % 5) + 2;
    int column = (rand() % 10) + 2; 
    int number = (rand() % 10) + 2;


    //loop to generate ~2 clearing and ~2 long grass
    int i;
    for(i = 0; i < 4; i++){
        if(i == 1 || i == 3)
            patch_gen(size, row, column, '.');
        else   
            patch_gen(size, row, column, ',');

        size = (rand() % 3);
        row = (rand() % 3) + 1;
        column = (rand() % 5) + 1; 
    }
 
    int what = rand() % 3;

    //generates other objects
    for(i = 0; i < number; i++){
        
        if(what == 0){
            if(row > 0 && column > 0)
                BLOCK[row][column] = '%';
        }
        else if(what == 1)
        {
            if(row > 0 && column > 0)
                BLOCK[row][column] = '"';
        }

        size = (rand() % 3);
        row = (rand() % ROWS - 2) + 1;
        column = (rand() % COLUMNS - 2) + 1;
        what = (rand() % 3);
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
            // if(BLOCK[row][column] == ' ')
            //     BLOCK[row][column] = '.';

            pos = BLOCK[row][column];

            // curses library for color

            if(pos == 'C') // red
                printf("\033[1;31m");
            else if(pos == '.') // green
                printf("\033[0;32m");
            else if(pos == 'M') // blue
                printf("\033[0;34m");
            else if(pos == '#') // white
                printf("\033[0;37m");
            else if(pos == '"') // yellow 
                printf("\033[0;33m");
            else if(pos == '%') // black
                printf("\e[0;34m");
            else if(pos == ',') // bright green
                printf("\033[92;102m");
            else
                printf("\e[0m");

            printf("%c", pos);
        }
        printf("\n");
    }

    return 0;
}