#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int fruitx, fruity, score;
int tailx[100], taily[100];
int ntail;

struct snake {
    int x;
    int y;
};

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

snake sarpe;


void setup() {
    gameOver = false;
    dir = STOP;
    sarpe.x = width / 2;
    sarpe.y = height / 2;
    fruitx = rand() % width;
    fruity = rand() % height;
    score = 0;
}

void draw() {
    system("cls");
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)
                cout << "#";
            if (i == sarpe.y && j == sarpe.x)
                cout << 'O';
            else if (i == fruity && j == fruitx)
                cout << "F";
            else {
                bool print = false;
                for (int k = 0; k < ntail; k++) {
                    if (tailx[k] == j && taily[k] == i) {
                        cout << 'o';
                        print = true;
                    }
                    
                }
                if (!print)
                    cout << ' ';
            }
            
            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }
    
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;
    cout << "Score: " << score << endl;
}

void input() {
    if (_kbhit()) {
        switch (_getch())
        {
            case'a':
                dir = LEFT;
                break;
            case'd':
                dir = RIGHT;
                break;
            case'w':
                dir = UP;
                break;
            case's':
                dir = DOWN;
                break;
            case'x':
                gameOver = true;
                break;
            default:
                break;
        }
    }
}

void logic() {
    int prevx = tailx[0];
    int prevy = taily[0];
    int prev2x, prev2y;
    tailx[0] = sarpe.x;
    taily[0] = sarpe.y;
    for (int i = 1; i < ntail; i++) {
        prev2x = tailx[i];
        prev2y = taily[i];
        tailx[i] = prevx;
        taily[i] = prevy;
        prevx = prev2x;
        prevy = prev2y;
    }
    switch (dir)
    {
        case LEFT:
            sarpe.x--;
            break;
        case RIGHT:
            sarpe.x++;
            break;
        case UP:
            sarpe.y--;
            break;
        case DOWN:
            sarpe.y++;
            break;
        default:
            break;
    }
    //if (x > width || x < 0 || y>height || y<0)
    //gameOver = true;
    if (sarpe.x >= width) sarpe.x = 0; else if (sarpe.x < 0)	sarpe.x = width - 1;
    if (sarpe.y >= height) sarpe.y = 0; else if (sarpe.y < 0)	sarpe.y = height - 1;
    for (int i = 0; i < ntail; i++)
        if (tailx[i] == sarpe.x && taily[i] == sarpe.y)
            gameOver = true;
    if (sarpe.x == fruitx && sarpe.y == fruity) {
        
        score++;
        fruitx = rand() % width;
        fruity = rand() % height;
        ntail++;
    }
}

int main()
{
    setup();
    while (!gameOver) {
        draw();
        input();
        logic();
        Sleep(70);
    }
    return 0;
}

