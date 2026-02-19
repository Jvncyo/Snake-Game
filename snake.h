#ifndef SNAKE_H
#define SNAKE_H

typedef struct {
    int x, y;
} Position;

typedef struct {
    Position body[100];
    int length;
    int direction;
} Snake;

void initSnake(Snake *snake);
void moveSnake(Snake *snake);
int checkCollision(Snake *snake);

#endif