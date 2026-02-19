#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include "snake.h"
#include "board.h"

enum Direction { UP=0, RIGHT=1, DOWN=2, LEFT=3 };

void gotoxy(int x, int y) { 
    COORD coord; 
    coord.X = x; 
    coord.Y = y; 
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); 
}

int main() {
    Snake snake;
    Position food;
    int score = 0;
    int gameOver = 0;

    initBoard();
    initSnake(&snake);
    food = generateFood(&snake);

    while(!gameOver) {
        //input
        if(kbhit()) {
            int c = getch();
            if(c == 0 || c == 224) {
                int newDir = snake.direction;
                switch(getch()) {
                case 72: newDir = UP; break;
                case 80: newDir = DOWN; break;
                case 75: newDir = LEFT; break;
                case 77: newDir = RIGHT; break;
                default: break;
                }

                if(!((snake.direction == UP && newDir == DOWN) ||
                     (snake.direction == DOWN && newDir == UP) ||
                     (snake.direction == RIGHT && newDir == LEFT) ||
                     (snake.direction == LEFT && newDir == RIGHT))) {
                   snake.direction = newDir;
                }
            }
        }
        
        moveSnake(&snake);
        
        if(checkCollision(&snake)) {
            gameOver = 1;
        }

        //check food
        if(snake.body[0].x == food.x && snake.body[0].y == food.y) {
            score++;
            snake.length++;
            food = generateFood(&snake);
        }
        //+score, gen new food

        gotoxy(0,0);
        drawBoard(&snake, food);

        Sleep(100);
    }

    printf("Game over!\nScore : %d\n", score);
    system("pause");
    
    return 0;
}