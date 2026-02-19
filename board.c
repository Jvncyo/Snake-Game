#include "board.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initBoard() {
    //random seed
    srand(time(NULL));
}

void drawBoard(Snake *snake, Position food) {
    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {

            if(x == 0 || y == HEIGHT-1 || x == WIDTH-1 || y == 0) {
                
                printf("#");
            
            } else if(x == food.x && y == food.y) {
            
                printf("*");
            
            } else {
            
                int isSnake = 0;
            
                for(int i = 0; i < snake->length; i++) {
                    if(snake->body[i].x == x && snake->body[i].y == y) {
                        
                        if(i == 0) {
                            printf("@");
                            isSnake = 1;
                            break;
                        } else {
                            printf("O");
                            isSnake = 1;
                            break;
                        }
                    }
                }
                if(!isSnake) {
                    printf(" ");
                }

            }

        }
        printf("\n");
    }
}

Position generateFood(Snake *snake) {
    Position food;
    int vaild = 0;

    while(!vaild) {
        food.x = (rand() % (WIDTH - 2)) + 1;
        food.y = (rand() % (HEIGHT - 2)) + 1;

        vaild = 1;
        for(int i = 0; i < snake->length; i++) {
            if(snake->body[i].x == food.x && snake->body[i].y == food.y) {
                vaild = 0;
                break;
            }
        }
    }

    return food;
}
