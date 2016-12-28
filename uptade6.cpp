#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>

#define MAX_X 30
#define MAX_Y 30

using namespace std;

bool gameOver;
const int width = MAX_X;
const int height = MAX_Y;
int score, score2;
int tailx[100], taily[100], tail2x[100], tail2y[100];
int ntail, ntail2;
int okleft, okright, okup, okdown, okleft2, okright2, okup2, okdown2;
int nrafisari, nrafisaritailred;

int prevMat[50][50], currMat[50][50];

struct fruct {
    int x;
    int y;
};

struct snake {
    int x;
    int y;
};

struct wall {
    int x;
    int y;
};

struct redTail {
    int x;
    int y;
};

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;
eDirection dir2;

snake sarpe, sarpe2;
fruct fruit;
wall v1, v2, v3, v4, v5, v6, v7, v8, v9, v10;
redTail r;

void coordTailReduction();

void setCursorPosition(int x, int y)
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hOut, coord);
}

void clearM() {
    for (int y = 0; y <= MAX_Y+10; y++)
        for (int x = 0; x <= MAX_X+10; x++) {
            if (prevMat[x][y] == currMat[x][y])
                continue;
            if (currMat[x][y] == 0) {
                setCursorPosition(x, y);
                cout << " ";
            }
            else if (currMat[x][y] == 1) {
                setCursorPosition(x, y);
                cout << "O";
            }
            else if (currMat[x][y] == 11) {
                setCursorPosition(x, y);
                cout << "Q";
            }
            else if (currMat[x][y] == 2) {
                setCursorPosition(x, y);
                cout << "F";
            }
            else if (currMat[x][y] == 3) {
                setCursorPosition(x, y);
                cout << "X";
            }
            else if (currMat[x][y] == 4) {
                setCursorPosition(x, y);
                cout << "R";
            }
            else if (currMat[x][y] == 5) {
                setCursorPosition(x, y);
                cout << "o";
            }
            else if (currMat[x][y] == 10) {
                setCursorPosition(x, y);
                cout << ".";
            }
            else if (currMat[x][y] == 20) {
                setCursorPosition(x, y);
                cout << "Score1:"<<score;
            }
            else if (currMat[x][y] == 21) {
                setCursorPosition(x, y);
                cout << "Score2:" << score2;
            }
        }
    for (int y = 0; y < MAX_Y; y++)
        for (int x = 0; x < MAX_X; x++)
            prevMat[x][y] = currMat[x][y];
}

void draw22() {
    clearM();
    
    if (ntail < 0)
        ntail = 0;
    
    if (fruit.x == v1.x && fruit.y == v1.y || sarpe.x == v1.x && sarpe.y == v1.y) {
        v1.x = rand() % width;
        v1.y = rand() % height;
    }
    
    if (fruit.x == v2.x && fruit.y == v2.y || sarpe.x == v2.x && sarpe.y == v2.y) {
        v2.x = rand() % width;
        v2.y = rand() % height;
    }
    
    if (fruit.x == v3.x && fruit.y == v3.y || sarpe.x == v3.x && sarpe.y == v3.y) {
        v3.x = rand() % width;
        v3.y = rand() % height;
    }
    
    if (fruit.x == v4.x && fruit.y == v4.y || sarpe.x == v4.x && sarpe.y == v4.y) {
        v4.x = rand() % width;
        v4.y = rand() % height;
    }
    
    if (fruit.x == v5.x && fruit.y == v5.y || sarpe.x == v5.x && sarpe.y == v5.y) {
        v5.x = rand() % width;
        v5.y = rand() % height;
    }
    
    if (fruit.x == v6.x && fruit.y == v6.y || sarpe.x == v6.x && sarpe.y == v6.y) {
        v6.x = rand() % width;
        v6.y = rand() % height;
    }
    
    if (fruit.x == v7.x && fruit.y == v7.y || sarpe.x == v7.x && sarpe.y == v7.y) {
        v7.x = rand() % width;
        v7.y = rand() % height;
    }
    
    if (fruit.x == v8.x && fruit.y == v8.y || sarpe.x == v8.x && sarpe.y == v8.y) {
        v8.x = rand() % width;
        v8.y = rand() % height;
    }
    
    if (fruit.x == v9.x && fruit.y == v9.y || sarpe.x == v9.x && sarpe.y == v9.y) {
        v9.x = rand() % width;
        v9.y = rand() % height;
    }
    
    if (fruit.x == v10.x && fruit.y == v10.y || sarpe.x == v10.x && sarpe.y == v10.y) {
        v10.x = rand() % width;
        v10.y = rand() % height;
    }
    
    
    
    for (int i = 0; i <= height; i++)
        for (int j = 0; j <= width; j++)
            currMat[j][i] = 0;
    
    currMat[MAX_X+2][MAX_Y] = 20;
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == sarpe.y && j == sarpe.x)
                //cout << 'O';
                currMat[j][i] = 1;
            else if (i == fruit.y && j == fruit.x)
                //cout << "F";
                currMat[j][i] = 2;
            else if (i == v1.y && j == v1.x && v1.y != 0 && v1.x != 0)
                //cout << "X";
                currMat[j][i] = 3;
            else if (i == v2.y && j == v2.x && v2.y != 0 && v2.x != 0)
                //cout << "X";
                currMat[j][i] = 3;
            else if (i == v3.y && j == v3.x && v3.y != 0 && v3.x != 0)
                //cout << "X";
                currMat[j][i] = 3;
            else if (i == v4.y && j == v4.x && v4.y != 0 && v4.x != 0)
                //cout << "X";
                currMat[j][i] = 3;
            else if (i == v5.y && j == v5.x && v5.y != 0 && v5.x != 0)
                //cout << "X";
                currMat[j][i] = 3;
            else if (i == v6.y && j == v6.x && v6.y != 0 && v6.x != 0)
                //cout << "X";
                currMat[j][i] = 3;
            else if (i == v7.y && j == v7.x && v7.y != 0 && v7.x != 0)
                //cout << "X";
                currMat[j][i] = 3;
            else if (i == v8.y && j == v8.x && v8.y != 0 && v8.x != 0)
                //cout << "X";
                currMat[j][i] = 3;
            else if (i == v9.y && j == v9.x && v9.y != 0 && v9.x != 0)
                //cout << "X";
                currMat[j][i] = 3;
            else if (i == v10.y && j == v10.x && v10.y != 0 && v10.x != 0)
                //cout << "X";
                currMat[j][i] = 3;
            else if (i == r.y && j == r.x && r.x != 0 && r.y != 0)
                //cout << "R";
                currMat[j][i] = 4;
            else {
                for (int k = 0; k < ntail; k++) {
                    if (tailx[k] == j && taily[k] == i) {
                        currMat[j][i] = 5;
                    }
                    
                }
            }
            
            if (j == width-1)
                currMat[j][i] = 10;
        }
    }
    
    for (int i = 0; i < width ; i++)
        currMat[i][height] = 10;
    //cout << "Score: " << score << endl;
    
    nrafisari++;
    nrafisaritailred++;
}

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
    sarpe.x = width-20;
    sarpe.y = height-22;
    sarpe2.x = width-5;
    sarpe2.y = height-3;
    fruit.x = width / 2;
    fruit.y = height / 2;
    score = 0;
    score2 = 0;
}

/*void draw() {
	system("cls");
 
	if (ntail < 0)
 ntail = 0;
 
	if (fruit.x == v1.x && fruit.y == v1.y || sarpe.x == v1.x && sarpe.y == v1.y) {
 v1.x = rand() % width;
 v1.y = rand() % height;
	}
 
	if (fruit.x == v2.x && fruit.y == v2.y || sarpe.x == v2.x && sarpe.y == v2.y) {
 v2.x = rand() % width;
 v2.y = rand() % height;
	}
 
	if (fruit.x == v3.x && fruit.y == v3.y || sarpe.x == v3.x && sarpe.y == v3.y) {
 v3.x = rand() % width;
 v3.y = rand() % height;
	}
 
	if (fruit.x == v4.x && fruit.y == v4.y || sarpe.x == v4.x && sarpe.y == v4.y) {
 v4.x = rand() % width;
 v4.y = rand() % height;
	}
 
	if (fruit.x == v5.x && fruit.y == v5.y || sarpe.x == v5.x && sarpe.y == v5.y) {
 v5.x = rand() % width;
 v5.y = rand() % height;
	}
 
	if (fruit.x == v6.x && fruit.y == v6.y || sarpe.x == v6.x && sarpe.y == v6.y) {
 v6.x = rand() % width;
 v6.y = rand() % height;
	}
 
	if (fruit.x == v7.x && fruit.y == v7.y || sarpe.x == v7.x && sarpe.y == v7.y) {
 v7.x = rand() % width;
 v7.y = rand() % height;
	}
 
	if (fruit.x == v8.x && fruit.y == v8.y || sarpe.x == v8.x && sarpe.y == v8.y) {
 v8.x = rand() % width;
 v8.y = rand() % height;
	}
 
	if (fruit.x == v9.x && fruit.y == v9.y || sarpe.x == v9.x && sarpe.y == v9.y) {
 v9.x = rand() % width;
 v9.y = rand() % height;
	}
 
	if (fruit.x == v10.x && fruit.y == v10.y || sarpe.x == v10.x && sarpe.y == v10.y) {
 v10.x = rand() % width;
 v10.y = rand() % height;
	}
 
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
 else if (i == v1.y && j == v1.x && v1.y != 0 && v1.x != 0)
 cout << "X";
 else if (i == v2.y && j == v2.x && v2.y != 0 && v2.x != 0)
 cout << "X";
 else if (i == v3.y && j == v3.x && v3.y != 0 && v3.x != 0)
 cout << "X";
 else if (i == v4.y && j == v4.x && v4.y != 0 && v4.x != 0)
 cout << "X";
 else if (i == v5.y && j == v5.x && v5.y != 0 && v5.x != 0)
 cout << "X";
 else if (i == v6.y && j == v6.x && v6.y != 0 && v6.x != 0)
 cout << "X";
 else if (i == v7.y && j == v7.x && v7.y != 0 && v7.x != 0)
 cout << "X";
 else if (i == v8.y && j == v8.x && v8.y != 0 && v8.x != 0)
 cout << "X";
 else if (i == v9.y && j == v9.x && v9.y != 0 && v9.x != 0)
 cout << "X";
 else if (i == v10.y && j == v10.x && v10.y != 0 && v10.x != 0)
 cout << "X";
 else if (i == r.y && j == r.x && r.x != 0 && r.y != 0)
 cout << "R";
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
 
	nrafisari++;
	nrafisaritailred++;
 }*/

void draw2() {
    clearM();
    
    if (ntail < 0)
        ntail = 0;
    
    if (ntail2 < 0)
        ntail2 = 0;
    
    if (fruit.x == v1.x && fruit.y == v1.y || sarpe.x == v1.x && sarpe.y == v1.y || sarpe2.x == v1.x && sarpe2.y == v1.y) {
        v1.x = rand() % width;
        v1.y = rand() % height;
    }
    
    if (fruit.x == v2.x && fruit.y == v2.y || sarpe.x == v2.x && sarpe.y == v2.y || sarpe2.x == v2.x && sarpe2.y == v2.y) {
        v2.x = rand() % width;
        v2.y = rand() % height;
    }
    
    if (fruit.x == v3.x && fruit.y == v3.y || sarpe.x == v3.x && sarpe.y == v3.y || sarpe2.x == v3.x && sarpe2.y == v3.y) {
        v3.x = rand() % width;
        v3.y = rand() % height;
    }
    
    if (fruit.x == v4.x && fruit.y == v4.y || sarpe.x == v4.x && sarpe.y == v4.y || sarpe2.x == v4.x && sarpe2.y == v4.y) {
        v4.x = rand() % width;
        v4.y = rand() % height;
    }
    
    if (fruit.x == v5.x && fruit.y == v5.y || sarpe.x == v5.x && sarpe.y == v5.y || sarpe2.x == v5.x && sarpe2.y == v5.y) {
        v5.x = rand() % width;
        v5.y = rand() % height;
    }
    
    if (fruit.x == v6.x && fruit.y == v6.y || sarpe.x == v6.x && sarpe.y == v6.y || sarpe2.x == v6.x && sarpe2.y == v6.y) {
        v6.x = rand() % width;
        v6.y = rand() % height;
    }
    
    if (fruit.x == v7.x && fruit.y == v7.y || sarpe.x == v7.x && sarpe.y == v7.y || sarpe2.x == v7.x && sarpe2.y == v7.y) {
        v7.x = rand() % width;
        v7.y = rand() % height;
    }
    
    if (fruit.x == v8.x && fruit.y == v8.y || sarpe.x == v8.x && sarpe.y == v8.y || sarpe2.x == v8.x && sarpe2.y == v8.y) {
        v8.x = rand() % width;
        v8.y = rand() % height;
    }
    
    if (fruit.x == v9.x && fruit.y == v9.y || sarpe.x == v9.x && sarpe.y == v9.y || sarpe2.x == v9.x && sarpe2.y == v9.y) {
        v9.x = rand() % width;
        v9.y = rand() % height;
    }
    
    if (fruit.x == v10.x && fruit.y == v10.y || sarpe.x == v10.x && sarpe.y == v10.y || sarpe2.x == v10.x && sarpe2.y == v10.y) {
        v10.x = rand() % width;
        v10.y = rand() % height;
    }
    
    for (int i = 0; i <= height; i++)
        for (int j = 0; j <= width; j++)
            currMat[j][i] = 0;
    
    currMat[MAX_X + 2][MAX_Y-3] = 20;
    currMat[MAX_X + 2][MAX_Y] = 21;
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == sarpe2.y && j == sarpe2.x)
                //cout << 'Q';
                currMat[j][i] = 11;
            if (i == sarpe.y && j == sarpe.x)
                //cout << 'O';
                currMat[j][i] = 1;
            else if (i == fruit.y && j == fruit.x)
                //cout << "F";
                currMat[j][i] = 2;
            else if (i == v1.y && j == v1.x && v1.y != 0 && v1.x != 0)
                //cout << "X";
                currMat[j][i] = 3;
            else if (i == v2.y && j == v2.x && v2.y != 0 && v2.x != 0)
                //cout << "X";
                currMat[j][i] = 3;
            else if (i == v3.y && j == v3.x && v3.y != 0 && v3.x != 0)
                //cout << "X";
                currMat[j][i] = 3;
            else if (i == v4.y && j == v4.x && v4.y != 0 && v4.x != 0)
                //cout << "X";
                currMat[j][i] = 3;
            else if (i == v5.y && j == v5.x && v5.y != 0 && v5.x != 0)
                //cout << "X";
                currMat[j][i] = 3;
            else if (i == v6.y && j == v6.x && v6.y != 0 && v6.x != 0)
                //cout << "X";
                currMat[j][i] = 3;
            else if (i == v7.y && j == v7.x && v7.y != 0 && v7.x != 0)
                //cout << "X";
                currMat[j][i] = 3;
            else if (i == v8.y && j == v8.x && v8.y != 0 && v8.x != 0)
                //cout << "X";
                currMat[j][i] = 3;
            else if (i == v9.y && j == v9.x && v9.y != 0 && v9.x != 0)
                //cout << "X";
                currMat[j][i] = 3;
            else if (i == v10.y && j == v10.x && v10.y != 0 && v10.x != 0)
                //cout << "X";
                currMat[j][i] = 3;
            else if (i == r.y && j == r.x && r.x != 0 && r.y != 0)
                //cout << "R";
                currMat[j][i] = 4;
            else {
                for (int k = 0; k < ntail; k++) {
                    if (tailx[k] == j && taily[k] == i) {
                        currMat[j][i] = 5;
                    }
                    
                }
                
                for (int l = 0; l < ntail2; l++) {
                    if (tail2x[l] == j && tail2y[l] == i) {
                        currMat[j][i] = 5;
                    }
                }
            }
            
            if (j == width - 1)
                currMat[j][i] = 10;
        }
    }
    
    for (int i = 0; i < width; i++)
        currMat[i][height-1] = 10;
    
    //cout << "Score1: " << score << "                        " << "Score2: " << score2 << endl;
    
    nrafisari++;
    nrafisaritailred++;
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
            case'A':
                dir = LEFT;
                break;
            case'D':
                dir = RIGHT;
                break;
            case'W':
                dir = UP;
                break;
            case'S':
                dir = DOWN;
                break;
            case'J':
                dir2 = LEFT;
                break;
            case'L':
                dir2 = RIGHT;
                break;
            case'I':
                dir2 = UP;
                break;
            case'K':
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
            if (okright == 0) {
                sarpe.x--;
                okleft = 1;
                okright = 0;
                okdown = 0;
                okup = 0;
            }
            else sarpe.x++;
            break;
        case RIGHT:
            if (okleft == 0) {
                sarpe.x++;
                okright = 1;
                okleft = 0;
                okdown = 0;
                okup = 0;
            }
            else sarpe.x--;
            break;
        case UP:
            if (okdown == 0) {
                sarpe.y--;
                okup = 1;
                okleft = 0;
                okdown = 0;
                okright = 0;
            }
            else sarpe.y++;
            break;
        case DOWN:
            if (okup == 0) {
                sarpe.y++;
                okdown = 1;
                okleft = 0;
                okright = 0;
                okup = 0;
            }
            else sarpe.y--;
            break;
        default:
            break;
    }
    //if (x > width || x < 0 || y>height || y<0)
    //gameOver = true;
    if (sarpe.x >= width-1) sarpe.x = 0; else if (sarpe.x < 0)	sarpe.x = width - 1;
    if (sarpe.y >= height) sarpe.y = 0; else if (sarpe.y < 0)	sarpe.y = height - 1;
    
    if (sarpe.x == v1.x && sarpe.y == v1.y || sarpe.x == v2.x && sarpe.y == v2.y || sarpe.x == v3.x && sarpe.y == v3.y || sarpe.x == v4.x && sarpe.y == v4.y || sarpe.x == v5.x && sarpe.y == v5.y
        || sarpe.x == v6.x && sarpe.y == v6.y || sarpe.x == v7.x && sarpe.y == v7.y || sarpe.x == v8.x && sarpe.y == v8.y || sarpe.x == v9.x && sarpe.y == v9.y || sarpe.x == v10.x && sarpe.y == v10.y)
        gameOver = true;
    
    for (int i = 0; i < ntail; i++)
        if (tailx[i] == sarpe.x && taily[i] == sarpe.y)
            gameOver = true;
    
    for (int i = 0; i < ntail; i++)
        if (tailx[i] == fruit.x && taily[i] == fruit.y) {
            fruit.x = rand() % width;
            fruit.y = rand() % height;
        }
    
    if (sarpe.x == r.x && sarpe.y == r.y) {
        score += 2;
        nrafisaritailred = 0;
        r.x = 0;
        r.y = 0;
        ntail -= 2;
    }
    
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
            if (okright == 0) {
                sarpe.x--;
                okleft = 1;
                okright = 0;
                okdown = 0;
                okup = 0;
            }
            else sarpe.x++;
            break;
        case RIGHT:
            if (okleft == 0) {
                sarpe.x++;
                okright = 1;
                okleft = 0;
                okdown = 0;
                okup = 0;
            }
            else sarpe.x--;
            break;
        case UP:
            if (okdown == 0) {
                sarpe.y--;
                okup = 1;
                okleft = 0;
                okdown = 0;
                okright = 0;
            }
            else sarpe.y++;
            break;
        case DOWN:
            if (okup == 0) {
                sarpe.y++;
                okdown = 1;
                okleft = 0;
                okright = 0;
                okup = 0;
            }
            else sarpe.y--;
            break;
        default:
            break;
    }
    
    switch (dir2)
    {
        case LEFT:
            if (okright2 == 0) {
                sarpe2.x--;
                okleft2 = 1;
                okright2 = 0;
                okdown2 = 0;
                okup2 = 0;
            }
            else sarpe2.x++;
            break;
        case RIGHT:
            if (okleft2 == 0) {
                sarpe2.x++;
                okright2 = 1;
                okleft2 = 0;
                okdown2 = 0;
                okup2 = 0;
            }
            else sarpe2.x--;
            break;
        case UP:
            if (okdown2 == 0) {
                sarpe2.y--;
                okup2 = 1;
                okleft2 = 0;
                okdown2 = 0;
                okright2 = 0;
            }
            else sarpe2.y++;
            break;
        case DOWN:
            if (okup2 == 0) {
                sarpe2.y++;
                okdown2 = 1;
                okleft2 = 0;
                okright2 = 0;
                okup2 = 0;
            }
            else sarpe2.y--;
            break;
        default:
            break;
    }
    
    //if (x > width || x < 0 || y>height || y<0)
    //gameOver = true;
    if (sarpe.x >= width-1) sarpe.x = 0; else if (sarpe.x < 0)	sarpe.x = width - 1;
    if (sarpe.y >= height) sarpe.y = 0; else if (sarpe.y < 0)	sarpe.y = height - 1;
    
    if (sarpe2.x >= width-1) sarpe2.x = 0; else if (sarpe2.x < 0)	sarpe2.x = width - 1;
    if (sarpe2.y >= height) sarpe2.y = 0; else if (sarpe2.y < 0)	sarpe2.y = height - 1;
    
    if (sarpe.x == sarpe2.x && sarpe.y == sarpe2.y)
        gameOver = true;
    
    if (sarpe.x == v1.x && sarpe.y == v1.y || sarpe.x == v2.x && sarpe.y == v2.y || sarpe.x == v3.x && sarpe.y == v3.y || sarpe.x == v4.x && sarpe.y == v4.y || sarpe.x == v5.x && sarpe.y == v5.y
        || sarpe.x == v6.x && sarpe.y == v6.y || sarpe.x == v7.x && sarpe.y == v7.y || sarpe.x == v8.x && sarpe.y == v8.y || sarpe.x == v9.x && sarpe.y == v9.y || sarpe.x == v10.x && sarpe.y == v10.y)
        gameOver = true;
    
    if (sarpe2.x == v1.x && sarpe2.y == v1.y || sarpe2.x == v2.x && sarpe2.y == v2.y || sarpe2.x == v3.x && sarpe2.y == v3.y || sarpe2.x == v4.x && sarpe2.y == v4.y || sarpe2.x == v5.x && sarpe2.y == v5.y
        || sarpe2.x == v6.x && sarpe2.y == v6.y || sarpe2.x == v7.x && sarpe2.y == v7.y || sarpe2.x == v8.x && sarpe2.y == v8.y || sarpe2.x == v9.x && sarpe2.y == v9.y || sarpe2.x == v10.x && sarpe2.y == v10.y)
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
    
    for (int i = 0; i < ntail; i++)
        if (tailx[i] == fruit.x && taily[i] == fruit.y) {
            fruit.x = rand() % width;
            fruit.y = rand() % height;
        }
    
    for (int j = 0; j < ntail2; j++)
        if (tail2x[j] == fruit.x && tail2y[j] == fruit.y) {
            fruit.x = rand() % width;
            fruit.y = rand() % height;
        }
    
    if (sarpe.x == r.x && sarpe.y == r.y) {
        score += 2;
        nrafisaritailred = 0;
        r.x = 0;
        r.y = 0;
        ntail -= 2;
    }
    
    if (sarpe2.x == r.x && sarpe2.y == r.y) {
        score2 += 2;
        nrafisaritailred = 0;
        r.x = 0;
        r.y = 0;
        ntail2 -= 2;
    }
    
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

void coord() {
    v1.x = rand() % width;
    v1.y = rand() % height;
    v2.x = rand() % width;
    v2.y = rand() % height;
    v3.x = rand() % width;
    v3.y = rand() % height;
    v4.x = rand() % width;
    v4.y = rand() % height;
    v5.x = rand() % width;
    v5.y = rand() % height;
    v6.x = rand() % width;
    v6.y = rand() % height;
    v7.x = rand() % width;
    v7.y = rand() % height;
    v8.x = rand() % width;
    v8.y = rand() % height;
    v9.x = rand() % width;
    v9.y = rand() % height;
    v10.x = rand() % width;
    v10.y = rand() % height;
}

void walls() {
    if (nrafisari == 30)
        coord();
    if (nrafisari == 50) {
        v1.x = 0;
        v1.y = 0;
        v2.x = 0;
        v2.y = 0;
        v3.x = 0;
        v3.y = 0;
        v4.x = 0;
        v4.y = 0;
        v5.x = 0;
        v5.y = 0;
        v6.x = 0;
        v6.y = 0;
        v7.x = 0;
        v7.y = 0;
        v8.x = 0;
        v8.y = 0;
        v9.x = 0;
        v9.y = 0;
        v10.x = 0;
        v10.y = 0;
        nrafisari = 0;
    }
}

void coordTailReduction() {
    r.x = rand() % width;
    r.y = rand() % height;
}

void tailReduction() {
    if (nrafisaritailred == 60)
        coordTailReduction();
}

int main()
{
    setup2();
    while (!gameOver) {
        walls();
        //tailReduction();
        draw2();
        input();
        logic2();
        Sleep(110);
    }
    
    
    return 0;
}
