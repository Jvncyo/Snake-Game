#ifndef BOARD_H
#define BOARD_H

#include "snake.h"

#define WIDTH 40
#define HEIGHT 20

void initBoard();
void drawBoard(Snake *snake, Position food);
Position generateFood(Snake *snake);

#endif