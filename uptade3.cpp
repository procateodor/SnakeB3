#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

bool gameOver;
const int width = 40;
const int height = 20;
int score, score2;
int tailx[100], taily[100], tail2x[100], tail2y[100];
int ntail, ntail2;

struct fruct {
    int x;
    int y;
};

struct snake {
    int x;
    int y;
};

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;
eDirection dir2;

snake sarpe, sarpe2;
fruct fruit;

void setup() {
    gameOver = false;
    dir = STOP;
    sarpe.x = width / 2;
    sarpe.y = height / 2;
    fruit.x = rand() % width;
    fruit.y = rand() % height;
    score = 0;
}

void setup2() {
    gameOver = false;
    dir = STOP;
    dir2 = STOP;
    sarpe.x = 5;
    sarpe.y = 3;
    sarpe2.x = 35;
    sarpe2.y = 17;
    fruit.x = rand() % width;
    fruit.y = rand() % height;
    score = 0;
    score2 = 0;
}

void draw() {
    system("cls");
    for (int i = 0; i < width + 2; i++)
        cout << ".";
    cout << endl;
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)
                cout << ".";
            if (i == sarpe.y && j == sarpe.x)
                cout << 'O';
            else if (i == fruit.y && j == fruit.x)
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
                cout << ".";
        }
        cout << endl;
    }
    
    for (int i = 0; i < width + 2; i++)
        cout << ".";
    cout << endl;
    cout << "Score: " << score << endl;
}

void draw2() {
    system("cls");
    for (int i = 0; i < width + 2; i++)
        cout << ".";
    cout << endl;
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)
                cout << ".";
            if (i == sarpe2.y && j == sarpe2.x)
                cout << 'O';
            else if (i == sarpe.y && j == sarpe.x)
                cout << 'O';
            else if (i == fruit.y && j == fruit.x)
                cout << "F";
            else {
                
                bool print = false;
                for (int k = 0; k < ntail; k++) {
                    if (tailx[k] == j && taily[k] == i) {
                        cout << 'o';
                        print = true;
                    }
                    
                }
                
                bool print2 = false;
                for (int l = 0; l < ntail2; l++) {
                    if (tail2x[l] == j && tail2y[l] == i) {
                        cout << 'o';
                        print2 = true;
                    }
                    
                }
                if (!print && !print2)
                    cout << ' ';
                //if (!print2)
                //cout << ' ';
            }
            
            if (j == width - 1)
                cout << ".";
        }
        cout << endl;
    }
    
    for (int i = 0; i < width + 2; i++)
        cout << ".";
    cout << endl;
    cout << "Score1: " << score <<"                        "<<"Score2: "<<score2<< endl;
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
            case'j':
                dir2 = LEFT;
                break;
            case'l':
                dir2 = RIGHT;
                break;
            case'i':
                dir2 = UP;
                break;
            case'k':
                dir2 = DOWN;
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
    if (sarpe.x == fruit.x && sarpe.y == fruit.y) {
        
        score++;
        fruit.x = rand() % width;
        fruit.y = rand() % height;
        ntail++;
    }
}

void logic2() {
    int prevx = tailx[0];
    int prevy = taily[0];
    int prevx2 = tail2x[0];
    int prevy2 = tail2y[0];
    
    int prev2x, prev2y, prev2x2, prev2y2;
    tailx[0] = sarpe.x;
    taily[0] = sarpe.y;
    tail2x[0] = sarpe2.x;
    tail2y[0] = sarpe2.y;
    
    for (int i = 1; i < ntail; i++) {
        prev2x = tailx[i];
        prev2y = taily[i];
        tailx[i] = prevx;
        taily[i] = prevy;
        prevx = prev2x;
        prevy = prev2y;
    }
    
    for (int j = 1; j < ntail2; j++) {
        prev2x2 = tail2x[j];
        prev2y2 = tail2y[j];
        tail2x[j] = prevx2;
        tail2y[j] = prevy2;
        prevx2 = prev2x2;
        prevy2 = prev2y2;
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
    
    switch (dir2)
    {
        case LEFT:
            sarpe2.x--;
            break;
        case RIGHT:
            sarpe2.x++;
            break;
        case UP:
            sarpe2.y--;
            break;
        case DOWN:
            sarpe2.y++;
            break;
        default:
            break;
    }
    
    //if (x > width || x < 0 || y>height || y<0)
    //gameOver = true;
    if (sarpe.x >= width) sarpe.x = 0; else if (sarpe.x < 0)	sarpe.x = width - 1;
    if (sarpe.y >= height) sarpe.y = 0; else if (sarpe.y < 0)	sarpe.y = height - 1;
    
    if (sarpe2.x >= width) sarpe2.x = 0; else if (sarpe2.x < 0)	sarpe2.x = width - 1;
    if (sarpe2.y >= height) sarpe2.y = 0; else if (sarpe2.y < 0)	sarpe2.y = height - 1;
    
    if (sarpe.x == sarpe2.x && sarpe.y == sarpe2.y)
        gameOver = true;
    
    for (int i = 0; i < ntail; i++)
        if (tailx[i] == sarpe.x && taily[i] == sarpe.y)
            gameOver = true;
    
    for (int j = 0; j < ntail2; j++)
        if (tail2x[j] == sarpe2.x && tail2y[j] == sarpe2.y)
            gameOver = true;
    
    for (int i = 0; i < ntail; i++)
        if (tailx[i] == sarpe2.x && taily[i] == sarpe2.y)
            gameOver = true;
    
    for (int j = 0; j < ntail2; j++)
        if (tail2x[j] == sarpe.x && tail2y[j] == sarpe.y)
            gameOver = true;
    
    if (sarpe.x == fruit.x && sarpe.y == fruit.y) {
        
        score++;
        fruit.x = rand() % width;
        fruit.y = rand() % height;
        ntail++;
    }
    
    if (sarpe2.x == fruit.x && sarpe2.y == fruit.y) {
        
        score2++;
        fruit.x = rand() % width;
        fruit.y = rand() % height;
        ntail2++;
    }
}

int main()
{
    setup2();
    while (!gameOver) {
        draw2();
        input();
        logic2();
        Sleep(70);
    }
    return 0;
}

