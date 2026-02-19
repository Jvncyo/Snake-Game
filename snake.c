#include "snake.h"
#include "board.h"
#include <stdio.h>

void initSnake(Snake *snake) {
    snake->length = 1;
    snake->direction = 0; //up
    snake->body[0].x = WIDTH / 2;
    snake->body[0].y = HEIGHT / 2;
}

void moveSnake(Snake *snake) {
    for(int i = snake->length - 1; i > 0; i--) {
        snake->body[i] = snake->body[i - 1];
    }

    switch(snake->direction) {
    case 0: snake->body[0].y--; break;
    case 1: snake->body[0].x++; break;
    case 2: snake->body[0].y++; break;
    case 3: snake->body[0].x--; break;
    default: break;
    }
}

int checkCollision(Snake *snake) {
    if(snake->body[0].x == 0 || snake->body[0].y == 0 || snake->body[0].x == WIDTH-1 || snake->body[0].y == HEIGHT-1) {
        return 1;
    } else {

        for(int i = 1; i < snake->length; i++) {

            if(snake->body[0].x == snake->body[i].x && snake->body[0].y == snake->body[i].y) {
                return 1;
            }

        }
    }

    return 0;
}