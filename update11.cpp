#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>

#define MAX_X 30
#define MAX_Y 20

#define MAX_X2 30
#define MAX_Y2 30

using namespace std;

bool gameOver;
int score, score2;
int tailx[1000], taily[1000], tail2x[1000], tail2y[1000];
int ntail, ntail2;
int okleft, okright, okup, okdown, okleft2, okright2, okup2, okdown2;
int nrafisari, nrafisaritailred, nrafisarifruit, nrFakeFruit, nrafisaritailredRepeat, nrAfisareSlw, nrAfisareFst;
int bestScore, bestScore2;
bool nrwall = true, okSlow = false, okFast = false;
int nrSlow, nrFast;

int prevMat[MAX_X + 100][MAX_Y + 100], currMat[MAX_X + 100][MAX_Y + 100];
int prevMat2[MAX_X2 + 100][MAX_Y2 + 100], currMat2[MAX_X2 + 100][MAX_Y2 + 100];

struct fruct {
	int x;
	int y;
};

struct fakeFruit {
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

struct slow {
	int x;
	int y;
};

struct fast {
	int x;
	int y;
};

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;
eDirection dir2;

snake sarpe, sarpe2;
fakeFruit fk;
fruct fruit;
wall v1, v2, v3, v4, v5, v6, v7, v8, v9, v10;
redTail r;
slow slw;
fast fst;

void coordTailReduction();
void coordTailReduction2();
void coordFruit();
void engine();
void coordFake2();

void coordSlw() {
	slw.x = rand() % (MAX_X - 3);
	slw.y = rand() % (MAX_Y - 3);

	if (slw.x < 1)
		slw.x = 6;
	if (slw.y < 1)
		slw.y = 8;
}

void coordSlw2() {
	slw.x = rand() % (MAX_X2 - 3);
	slw.y = rand() % (MAX_Y2 - 3);

	if (slw.x < 1)
		slw.x = 6;
	if (slw.y < 1)
		slw.y = 8;
}

void coordFst() {
	fst.x = rand() % (MAX_X - 3);
	fst.y = rand() % (MAX_Y - 3);

	if (fst.x < 1)
		fst.x = 6;
	if (fst.y < 1)
		fst.y = 8;
}

void coordFst2() {
	fst.x = rand() % (MAX_X2 - 3);
	fst.y = rand() % (MAX_Y2 - 3);

	if (fst.x < 1)
		fst.x = 6;
	if (fst.y < 1)
		fst.y = 8;
}

void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

void setCursorPosition(int x, int y)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}

void clearM() {
	for (int y = 0; y <= MAX_Y + 2; y++)
		for (int x = 0; x <= MAX_X + 2; x++) {
			if (prevMat[x][y] == currMat[x][y])
				continue;
			if (currMat[x][y] == 0) {
				setCursorPosition(x, y);
				cout << " ";
			}
			else if (currMat[x][y] == 1) {
				setCursorPosition(x, y);
				cout << char(254);
			}
			else if (currMat[x][y] == 2) {
				setCursorPosition(x, y);
				cout << "F";
			}
			else if (currMat[x][y] == 3) {
				setCursorPosition(x, y);
				cout << char(178);
			}
			else if (currMat[x][y] == 4) {
				setCursorPosition(x, y);
				cout << "R";
			}
			else if (currMat[x][y] == 5) {
				setCursorPosition(x, y);
				cout << char(254);
			}
			else if (currMat[x][y] == 10) {
				setCursorPosition(x, y);
				cout << char(223);
			}
			else if (currMat[x][y] == 101) {
				setCursorPosition(x, y);
				cout << char(219);
			}
			else if (currMat[x][y] == 102) {
				setCursorPosition(x, y);
				cout << char(220);
			}
			else if (currMat[x][y] == 25) {
				setCursorPosition(x, y);
				cout << "Score:" << score;
			}
			else if (currMat[x][y] == 70) {
				setCursorPosition(x, y);
				cout << "S";
			}
			else if (currMat[x][y] == 71) {
				setCursorPosition(x, y);
				cout << "Y";
			}
		}
	for (int y = 0; y < MAX_Y; y++)
		for (int x = 0; x < MAX_X; x++) {
			prevMat[x][y] = currMat[x][y];
			currMat[x][y] = 0;
		}
}

void clearM2() {
	for (int y = 0; y <= MAX_Y2 + 2; y++)
		for (int x = 0; x <= MAX_X2 + 2; x++) {
			if (prevMat2[x][y] == currMat2[x][y])
				continue;
			if (currMat2[x][y] == 0) {
				setCursorPosition(x, y);
				cout << " ";
			}
			else if (currMat2[x][y] == 99) {
				setCursorPosition(x, y);
				cout << char(254);
			}
			else if (currMat2[x][y] == 99) {
				setCursorPosition(x, y);
				cout << char(254);
			}
			else if (currMat2[x][y] == 2) {
				setCursorPosition(x, y);
				cout << "F";
			}
			else if (currMat2[x][y] == 3) {
				setCursorPosition(x, y);
				cout << char(178);
			}
			else if (currMat2[x][y] == 4) {
				setCursorPosition(x, y);
				cout << "R";
			}
			else if (currMat2[x][y] == 95) {
				setCursorPosition(x, y);
				cout << char(254);
			}
			else if (currMat2[x][y] == 10) {
				setCursorPosition(x, y);
				cout << char(223);
			}
			else if (currMat2[x][y] == 101) {
				setCursorPosition(x, y);
				cout << char(219);
			}
			else if (currMat2[x][y] == 102) {
				setCursorPosition(x, y);
				cout << char(220);
			}
			else if (currMat2[x][y] == 21) {
				setCursorPosition(x, y);
				cout << "Score2:" << score2;
			}
			else if (currMat2[x][y] == 20) {
				setCursorPosition(x, y);
				cout << "Score1:" << score;
			}
			else if (currMat2[x][y] == 70) {
				setCursorPosition(x, y);
				cout << "S";
			}
			else if (currMat2[x][y] == 71) {
				setCursorPosition(x, y);
				cout << "Y";
			}
		}
	for (int y = 0; y < MAX_Y2; y++)
		for (int x = 0; x < MAX_X2; x++) {
			prevMat2[x][y] = currMat2[x][y];
			currMat2[x][y] = 0;
		}
}

void setup() {
	gameOver = false;
	dir = STOP;
	sarpe.x = MAX_X / 2;
	sarpe.y = MAX_Y / 2;
	fruit.x = rand() % (MAX_X-2);
	fruit.y = rand() % (MAX_Y-2);
	if (fruit.x < 1)
		fruit.x = 1;
	if (fruit.y < 1)
		fruit.y = 1;

	if (score > bestScore)
		bestScore = score;

	score = 0;
}

void setup2() {
	gameOver = false;
	dir = STOP;
	dir2 = STOP;
	sarpe.x = MAX_X2 - 25;
	sarpe.y = MAX_Y2 - 19;
	sarpe2.x = MAX_X2 - 5;
	sarpe2.y = MAX_Y2 - 3;
	fruit.x = MAX_X2 / 2;
	fruit.y = MAX_Y2 / 2;
	fk.x = rand() % (MAX_X2 - 3);
	fk.y = rand() % (MAX_Y2 - 3);

	if (fk.x < 1)
		fk.x = 3;
	if (fk.y < 1)
		fk.y = 3;

	if (score > bestScore)
		bestScore = score;
	if (score2 > bestScore2)
		bestScore2 = score2;

	score = 0;
	score2 = 0;
}

void draw() {
	clearM();

	if (ntail < 0)
		ntail = 0;

	if (fruit.x == v1.x && fruit.y == v1.y || sarpe.x == v1.x && sarpe.y == v1.y) {
		v1.x = rand() % MAX_X;
		v1.y = rand() % MAX_Y;
	}

	if (fruit.x == v2.x && fruit.y == v2.y || sarpe.x == v2.x && sarpe.y == v2.y) {
		v2.x = rand() % MAX_X;
		v2.y = rand() % MAX_Y;
	}

	if (fruit.x == v3.x && fruit.y == v3.y || sarpe.x == v3.x && sarpe.y == v3.y) {
		v3.x = rand() % MAX_X;
		v3.y = rand() % MAX_Y;
	}

	if (fruit.x == v4.x && fruit.y == v4.y || sarpe.x == v4.x && sarpe.y == v4.y) {
		v4.x = rand() % MAX_X;
		v4.y = rand() % MAX_Y;
	}

	if (fruit.x == v5.x && fruit.y == v5.y || sarpe.x == v5.x && sarpe.y == v5.y) {
		v5.x = rand() % MAX_X;
		v5.y = rand() % MAX_Y;
	}

	if (fruit.x == v6.x && fruit.y == v6.y || sarpe.x == v6.x && sarpe.y == v6.y) {
		v6.x = rand() % MAX_X;
		v6.y = rand() % MAX_Y;
	}

	if (fruit.x == v7.x && fruit.y == v7.y || sarpe.x == v7.x && sarpe.y == v7.y) {
		v7.x = rand() % MAX_X;
		v7.y = rand() % MAX_Y;
	}

	if (fruit.x == v8.x && fruit.y == v8.y || sarpe.x == v8.x && sarpe.y == v8.y) {
		v8.x = rand() % MAX_X;
		v8.y = rand() % MAX_Y;
	}

	if (fruit.x == v9.x && fruit.y == v9.y || sarpe.x == v9.x && sarpe.y == v9.y) {
		v9.x = rand() % MAX_X;
		v9.y = rand() % MAX_Y;
	}

	if (fruit.x == v10.x && fruit.y == v10.y || sarpe.x == v10.x && sarpe.y == v10.y) {
		v10.x = rand() % MAX_X;
		v10.y = rand() % MAX_Y;
	}

	currMat[MAX_X + 2][MAX_Y - 2] = 25;

	setCursorPosition(MAX_X + 15, MAX_Y - 2);
	cout << "Best Score: " << bestScore;

	currMat[MAX_X - 1][0] = 10;

	for (int i = 0; i < MAX_Y; i++) {
		for (int j = 0; j < MAX_X; j++) {
			if (i == sarpe.y && j == sarpe.x)
				//cout << 'O';
				currMat[j][i] = 1;
			else if (i == fruit.y && j == fruit.x)
				//cout << "F";
				currMat[j][i] = 2;
			else if (i == slw.y && j == slw.x && slw.y != 0 && slw.x != 0)
				//cout << "S";
				currMat[j][i] = 70;
			else if (i == fst.y && j == fst.x && fst.y != 0 && fst.x != 0)
				//cout << "Y";
				currMat[j][i] = 71;
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

			if (j == MAX_X - 1)
				currMat[j][i] = 101;
		}
	}

	for (int i = 0; i < MAX_X; i++)
		currMat[i][0] = 102;

	for (int i = 0; i < MAX_X; i++)
		currMat[i][MAX_Y - 1] = 10;

	for (int i = 1; i < MAX_Y - 1; i++)
		currMat[0][i] = 101;

	currMat[MAX_X - 1][0] = 102;

	//cout << "Score: " << score << endl;

	if (currMat[0][0] == 5)
		currMat[0][0] = 0;

	nrafisari++;
	nrafisaritailred++;
	nrafisarifruit++;

	nrAfisareFst++;
	nrAfisareSlw++;
}

void draw2() {
	clearM2();

	if (ntail < 0)
		ntail = 0;

	if (ntail2 < 0)
		ntail2 = 0;

	if (fruit.x == v1.x && fruit.y == v1.y || sarpe.x == v1.x && sarpe.y == v1.y || sarpe2.x == v1.x && sarpe2.y == v1.y) {
		v1.x = rand() % MAX_X2;
		v1.y = rand() % MAX_Y2;
	}

	if (fruit.x == v2.x && fruit.y == v2.y || sarpe.x == v2.x && sarpe.y == v2.y || sarpe2.x == v2.x && sarpe2.y == v2.y) {
		v2.x = rand() % MAX_X2;
		v2.y = rand() % MAX_Y2;
	}

	if (fruit.x == v3.x && fruit.y == v3.y || sarpe.x == v3.x && sarpe.y == v3.y || sarpe2.x == v3.x && sarpe2.y == v3.y) {
		v3.x = rand() % MAX_X2;
		v3.y = rand() % MAX_Y2;
	}

	if (fruit.x == v4.x && fruit.y == v4.y || sarpe.x == v4.x && sarpe.y == v4.y || sarpe2.x == v4.x && sarpe2.y == v4.y) {
		v4.x = rand() % MAX_X2;
		v4.y = rand() % MAX_Y2;
	}

	if (fruit.x == v5.x && fruit.y == v5.y || sarpe.x == v5.x && sarpe.y == v5.y || sarpe2.x == v5.x && sarpe2.y == v5.y) {
		v5.x = rand() % MAX_X2;
		v5.y = rand() % MAX_Y2;
	}

	if (fruit.x == v6.x && fruit.y == v6.y || sarpe.x == v6.x && sarpe.y == v6.y || sarpe2.x == v6.x && sarpe2.y == v6.y) {
		v6.x = rand() % MAX_X2;
		v6.y = rand() % MAX_Y2;
	}

	if (fruit.x == v7.x && fruit.y == v7.y || sarpe.x == v7.x && sarpe.y == v7.y || sarpe2.x == v7.x && sarpe2.y == v7.y) {
		v7.x = rand() % MAX_X2;
		v7.y = rand() % MAX_Y2;
	}

	if (fruit.x == v8.x && fruit.y == v8.y || sarpe.x == v8.x && sarpe.y == v8.y || sarpe2.x == v8.x && sarpe2.y == v8.y) {
		v8.x = rand() % MAX_X2;
		v8.y = rand() % MAX_Y2;
	}

	if (fruit.x == v9.x && fruit.y == v9.y || sarpe.x == v9.x && sarpe.y == v9.y || sarpe2.x == v9.x && sarpe2.y == v9.y) {
		v9.x = rand() % MAX_X2;
		v9.y = rand() % MAX_Y2;
	}

	if (fruit.x == v10.x && fruit.y == v10.y || sarpe.x == v10.x && sarpe.y == v10.y || sarpe2.x == v10.x && sarpe2.y == v10.y) {
		v10.x = rand() % MAX_X2;
		v10.y = rand() % MAX_Y2;
	}

	currMat2[MAX_X2 + 2][MAX_Y2 - 5] = 20;

	setCursorPosition(MAX_X2 + 15, MAX_Y2 - 5);
	cout << "Best Score1: " << bestScore;

	currMat2[MAX_X2 + 2][MAX_Y2 - 2] = 21;

	setCursorPosition(MAX_X2 + 15, MAX_Y2 - 2);
	cout << "Best Score2: " << bestScore2;

	currMat[MAX_X2 - 1][0] = 10;

	for (int i = 0; i < MAX_Y2; i++) {
		for (int j = 0; j < MAX_X2; j++) {
			if (i == sarpe2.y && j == sarpe2.x)
				//cout << 'Q';
				currMat2[j][i] = 99;
			if (i == sarpe.y && j == sarpe.x)
				//cout << 'O';
				currMat2[j][i] = 99;
			else if (i == fruit.y && j == fruit.x)
				//cout << "F";
				currMat2[j][i] = 2;
			else if (i == fk.y && j == fk.x)
				//cout << "F";
				currMat2[j][i] = 2;
			else if (i == slw.y && j == slw.x && slw.y != 0 && slw.x != 0)
				//cout << "S";
				currMat2[j][i] = 70;
			else if (i == fst.y && j == fst.x && fst.y != 0 && fst.x != 0)
				//cout << "Y";
				currMat2[j][i] = 71;
			else if (i == v1.y && j == v1.x)
				//cout << "X";
				currMat2[j][i] = 3;
			else if (i == v2.y && j == v2.x)
				//cout << "X";
				currMat2[j][i] = 3;
			else if (i == v3.y && j == v3.x)
				//cout << "X";
				currMat2[j][i] = 3;
			else if (i == v4.y && j == v4.x)
				//cout << "X";
				currMat2[j][i] = 3;
			else if (i == v5.y && j == v5.x)
				//cout << "X";
				currMat2[j][i] = 3;
			else if (i == v6.y && j == v6.x)
				//cout << "X";
				currMat2[j][i] = 3;
			else if (i == v7.y && j == v7.x)
				//cout << "X";
				currMat2[j][i] = 3;
			else if (i == v8.y && j == v8.x)
				//cout << "X";
				currMat2[j][i] = 3;
			else if (i == v9.y && j == v9.x)
				//cout << "X";
				currMat2[j][i] = 3;
			else if (i == v10.y && j == v10.x)
				//cout << "X";
				currMat2[j][i] = 3;
			else if (i == r.y && j == r.x && r.x != 0 && r.y != 0)
				//cout << "R";
				currMat2[j][i] = 4;
			else {
				for (int k = 0; k < ntail; k++) {
					if (tailx[k] == j && taily[k] == i) {
						currMat2[j][i] = 95;
					}

				}

				for (int l = 0; l < ntail2; l++) {
					if (tail2x[l] == j && tail2y[l] == i) {
						currMat2[j][i] = 95;
					}
				}
			}

			if (j == MAX_X2 - 1)
				currMat2[j][i] = 101;
		}
	}

	for (int i = 0; i < MAX_X2; i++)
		currMat2[i][MAX_Y2 - 1] = 10;

	for (int i = 0; i < MAX_X2; i++)
		currMat2[i][0] = 102;

	for (int i = 1; i < MAX_Y2 - 1; i++)
		currMat2[0][i] = 101;

	for (int i = 0; i < MAX_X2; i++)
		currMat2[i][MAX_Y2 - 1] = 10;

	//cout << "Score1: " << score << "                        " << "Score2: " << score2 << endl;
	if (currMat2[0][0] == 5)
		currMat2[0][0] = 117;


	nrafisari++;
	nrafisaritailred++;
	nrafisarifruit++;
	nrFakeFruit++;

	nrAfisareFst++;
	nrAfisareSlw++;
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
		case 27:
		{
			HWND console = GetConsoleWindow();
			RECT r;
			GetWindowRect(console, &r);

			MoveWindow(console, r.left, r.top, 410, 400, TRUE);
			engine();
		}
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
	if (sarpe.x > MAX_X - 1 || sarpe.x < 1 || sarpe.y >= MAX_Y - 1 || sarpe.y<1)
		gameOver = true;
	//if (sarpe.x >= MAX_X - 1) sarpe.x = 0; else if (sarpe.x < 0)	sarpe.x = MAX_X - 2;
	//if (sarpe.y >= MAX_Y - 1) sarpe.y = 0; else if (sarpe.y < 0)	sarpe.y = MAX_Y - 2;

	if (nrwall) {
		v1.x = MAX_X;
		v1.y = MAX_Y;
		v2.x = MAX_X;
		v2.y = MAX_Y;
		v3.x = MAX_X;
		v3.y = MAX_Y;
		v4.x = MAX_X;
		v4.y = MAX_Y;
		v5.x = MAX_X;
		v5.y = MAX_Y;
		v6.x = MAX_X;
		v6.y = MAX_Y;
		v7.x = MAX_X;
		v7.y = MAX_Y;
		v8.x = MAX_X;
		v8.y = MAX_Y;
		v9.x = MAX_X;
		v9.y = MAX_Y;
		v10.x = MAX_X;
		v10.y = MAX_Y;
		nrwall = false;
	}

	if (sarpe.x == v1.x && sarpe.y == v1.y)		gameOver = true;
	if (sarpe.x == v2.x && sarpe.y == v2.y)		gameOver = true;
	if (sarpe.x == v3.x && sarpe.y == v3.y)		gameOver = true;
	if (sarpe.x == v4.x && sarpe.y == v4.y)		gameOver = true;
	if (sarpe.x == v5.x && sarpe.y == v5.y)		gameOver = true;
	if (sarpe.x == v6.x && sarpe.y == v6.y)		gameOver = true;
	if (sarpe.x == v7.x && sarpe.y == v7.y)		gameOver = true;
	if (sarpe.x == v7.x && sarpe.y == v7.y)		gameOver = true;
	if (sarpe.x == v8.x && sarpe.y == v8.y)		gameOver = true;
	if (sarpe.x == v9.x && sarpe.y == v9.y)		gameOver = true;
	if (sarpe.x == v10.x && sarpe.y == v10.y)   gameOver = true;

	if (nrAfisareFst == 600) {
		coordFst();
		nrAfisareFst = 0;
	}

	if (nrAfisareSlw == 800) {
		coordSlw();
		nrAfisareSlw = 0;
	}


	if (nrAfisareSlw > 800)
		for (int i = 0; i < ntail + 1; i++)
			if (tailx[i] == slw.x && taily[i] == slw.y)
				coordSlw();

	if (nrAfisareFst > 600)
		for (int i = 0; i < ntail + 1; i++)
			if (tailx[i] == fst.x && taily[i] == fst.y)
				coordFst();


	if (sarpe.x == slw.x && sarpe.y == slw.y) {
		slw.x = 0;
		slw.y = 0;
		okSlow = true;
		okFast = false;
		score += 2;
		nrAfisareSlw = 0;
		nrSlow = 1;
	}

	if (sarpe.x == fst.x && sarpe.y == fst.y) {
		fst.x = 0;
		fst.y = 0;
		okSlow = false;
		okFast = true;
		score += 2;
		nrAfisareFst = 0;
		nrFast = 1;
	}

	for (int i = 0; i < ntail; i++)
		if (tailx[i] == sarpe.x && taily[i] == sarpe.y)
			gameOver = true;

	for (int i = 0; i < ntail + 1; i++)
		if (tailx[i] == fruit.x && taily[i] == fruit.y) {
			while (tailx[i] == fruit.x && taily[i] == fruit.y) {
				fruit.x = rand() % (MAX_X2 - 3);
				fruit.y = rand() % (MAX_Y2 - 3);
			}
			if (fruit.x < 1)
				fruit.x = 1;
			if (fruit.y < 1)
				fruit.y = 1;
		}

	for (int i = 0; i < ntail; i++)
		while (tailx[i] == r.x && taily[i] == r.y) {
			r.x = rand() % (MAX_X2 - 3);
			r.y = rand() % (MAX_Y2 - 3);
			if (r.x < 1)
				r.x = 2;
			if (r.y < 2)
				r.y = 2;
		}

	if (slw.x == fruit.x && slw.y == fruit.y) {
		fruit.x = rand() % (MAX_X2 - 3);
		fruit.y = rand() % (MAX_Y2 - 3);
		if (fruit.x < 1)
			fruit.x = 1;
		if (fruit.y < 1)
			fruit.y = 1;
	}

	if (fst.x == fruit.x && fst.y == fruit.y) {
		fruit.x = rand() % (MAX_X2 - 3);
		fruit.y = rand() % (MAX_Y2 - 3);
		if (fruit.x < 1)
			fruit.x = 1;
		if (fruit.y < 1)
			fruit.y = 1;
	}

	if (slw.x == r.x && slw.y == r.y && r.x != 0 && r.y!=0) {
		r.x = rand() % (MAX_X2 - 3);
		r.y = rand() % (MAX_Y2 - 3);
		if (r.x < 1)
			r.x = 2;
		if (r.y < 2)
			r.y = 2;
	}

	if (fst.x == r.x && fst.y == r.y && r.x != 0 && r.y!=0) {
		r.x = rand() % (MAX_X2 - 3);
		r.y = rand() % (MAX_Y2 - 3);
		if (r.x < 1)
			r.x = 2;
		if (r.y < 2)
			r.y = 2;
	}

	for (int i = 0; i < ntail; i++) {
		if (tailx[i] == v1.x && taily[i] == v1.y) {
			v1.x = rand() % MAX_X;
			v1.y = rand() % MAX_Y;
		}

		if (tailx[i] == v2.x && taily[i] == v2.y) {
			v2.x = rand() % MAX_X;
			v2.y = rand() % MAX_Y;
		}

		if (tailx[i] == v3.x && taily[i] == v3.y) {
			v3.x = rand() % MAX_X;
			v3.y = rand() % MAX_Y;
		}

		if (tailx[i] == v4.x && taily[i] == v4.y) {
			v4.x = rand() % MAX_X;
			v4.y = rand() % MAX_Y;
		}

		if (tailx[i] == v5.x && taily[i] == v5.y) {
			v5.x = rand() % MAX_X;
			v5.y = rand() % MAX_Y;
		}

		if (tailx[i] == v6.x && taily[i] == v6.y) {
			v6.x = rand() % MAX_X;
			v6.y = rand() % MAX_Y;
		}

		if (tailx[i] == v7.x && taily[i] == v7.y) {
			v7.x = rand() % MAX_X;
			v7.y = rand() % MAX_Y;
		}

		if (tailx[i] == v8.x && taily[i] == v8.y) {
			v8.x = rand() % MAX_X;
			v8.y = rand() % MAX_Y;
		}

		if (tailx[i] == v9.x && taily[i] == v9.y) {
			v9.x = rand() % MAX_X;
			v9.y = rand() % MAX_Y;
		}

		if (tailx[i] == v10.x && taily[i] == v10.y) {
			v10.x = rand() % MAX_X;
			v10.y = rand() % MAX_Y;
		}
	}

	while (fruit.x == v1.x &&fruit.y == v1.y || fruit.x == v2.x &&fruit.y == v2.y || fruit.x == v3.x &&fruit.y == v3.y || fruit.x == v4.x &&fruit.y == v4.y
		|| fruit.x == v5.x &&fruit.y == v5.y || fruit.x == v6.x &&fruit.y == v6.y || fruit.x == v7.x &&fruit.y == v7.y || fruit.x == v8.x &&fruit.y == v8.y || fruit.x == v9.x &&fruit.y == v9.y
		|| fruit.x == v10.x &&fruit.y == v10.y) {

		fruit.x = rand() % (MAX_X2 - 3);
		fruit.y = rand() % (MAX_Y2 - 3);
		if (fruit.x < 1)
			fruit.x = 1;
		if (fruit.y < 1)
			fruit.y = 1;
	}

	if (r.x == fruit.x && r.y == fruit.y) {
		fruit.x = rand() % (MAX_X2 - 3);
		fruit.y = rand() % (MAX_Y2 - 3);
		if (fruit.x < 1)
			fruit.x = 1;
		if (fruit.y < 1)
			fruit.y = 1;
	}

	if (nrafisaritailred == 500) {
		coordTailReduction2();
		nrafisaritailredRepeat = 0;
	}

	if (nrafisaritailredRepeat == 10 && nrafisaritailred >= 500) {
		coordTailReduction2();
		nrafisaritailredRepeat = 0;
	}

	if (sarpe.x == r.x && sarpe.y == r.y && ntail==0) {
		score -= 10;
		nrafisaritailred = 0;
		r.x = 0;
		r.y = 0;
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
		fruit.x = rand() % (MAX_X - 2);
		fruit.y = rand() % (MAX_Y - 2);
		if (fruit.x < 1)
			fruit.x = 1;
		if (fruit.y < 1)
			fruit.y = 1;
		nrafisarifruit = 0;
		ntail++;
	}

	if (nrSlow > 0 && nrSlow < 30 && okSlow) {
		Sleep(130);
		nrSlow++;
	}
	else if (nrFast > 0 && nrFast < 60 && okFast) {
		Sleep(55);
		nrFast++;
	}
	else
	{
		Sleep(85);
		nrSlow = 0;
		nrFast = 0;
	}

	nrafisaritailredRepeat++;
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
	if (sarpe.x >= MAX_X2 - 1) sarpe.x = 1; else if (sarpe.x < 1)	sarpe.x = MAX_X2 - 2;
	if (sarpe.y >= MAX_Y2 - 1) sarpe.y = 1; else if (sarpe.y < 1)	sarpe.y = MAX_Y2 - 2;

	if (sarpe2.x >= MAX_X2 - 1) sarpe2.x = 1; else if (sarpe2.x < 1)	sarpe2.x = MAX_X2 - 2;
	if (sarpe2.y >= MAX_Y2 - 1) sarpe2.y = 1; else if (sarpe2.y < 1)	sarpe2.y = MAX_Y2 - 2;

	if (sarpe.x == sarpe2.x && sarpe.y == sarpe2.y)
		gameOver = true;

	if (nrwall) {
		v1.x = MAX_X2;
		v1.y = MAX_Y2;
		v2.x = MAX_X2;
		v2.y = MAX_Y2;
		v3.x = MAX_X2;
		v3.y = MAX_Y2;
		v4.x = MAX_X2;
		v4.y = MAX_Y2;
		v5.x = MAX_X2;
		v5.y = MAX_Y2;
		v6.x = MAX_X2;
		v6.y = MAX_Y2;
		v7.x = MAX_X2;
		v7.y = MAX_Y2;
		v8.x = MAX_X2;
		v8.y = MAX_Y2;
		v9.x = MAX_X2;
		v9.y = MAX_Y2;
		v10.x = MAX_X2;
		v10.y = MAX_Y2;
		nrwall = false;
	}

	if (nrAfisareFst == 600) {
		coordFst2();
		nrAfisareFst = 0;
	}

	if (nrAfisareSlw == 800) {
		coordSlw2();
		nrAfisareSlw = 0;
	}

	if (nrAfisareSlw > 800) {
		for (int i = 0; i < ntail + 1; i++)
		while (tailx[i] == slw.x && taily[i] == slw.y)
				coordSlw2();

		for (int i = 0; i < ntail2 + 1; i++)
			while (tail2x[i] == slw.x && tail2y[i] == slw.y)
				coordSlw2();
	}

	if (nrAfisareFst > 600) {
		for (int i = 0; i < ntail + 1; i++)
			while (tailx[i] == fst.x && taily[i] == fst.y)
				coordFst2();

		for (int i = 0; i < ntail2 + 1; i++)
			while (tail2x[i] == fst.x && tail2y[i] == fst.y)
				coordFst2();
	}

	if (fst.x == fruit.x && fst.y == fruit.y) {
		fruit.x = rand() % (MAX_X2 - 3);
		fruit.y = rand() % (MAX_Y2 - 3);
		if (fruit.x < 1)
			fruit.x = 1;
		if (fruit.y < 1)
			fruit.y = 1;
	}

	if (slw.x == fruit.x && slw.y == fruit.y) {
		fruit.x = rand() % (MAX_X2 - 3);
		fruit.y = rand() % (MAX_Y2 - 3);
		if (fruit.x < 1)
			fruit.x = 1;
		if (fruit.y < 1)
			fruit.y = 1;
	}

	if (fst.x == r.x && fst.y == r.y && r.x!=0 && r.y!=0) {
		r.x = rand() % (MAX_X2 - 3);
		r.y = rand() % (MAX_Y2 - 3);
		if (r.x < 1)
			r.x = 2;
		if (r.y < 1)
			r.y = 2;
	}

	if (slw.x == r.x && slw.y == r.y && r.x != 0 && r.y != 0) {
		r.x = rand() % (MAX_X2 - 3);
		r.y = rand() % (MAX_Y2 - 3);
		if (r.x < 1)
			r.x = 2;
		if (r.y < 1)
			r.y = 2;
	}

	if (fst.x == fk.x && fst.y == fk.y) {
		fk.x = rand() % (MAX_X2 - 3);
		fk.y = rand() % (MAX_Y2 - 3);
		if (fk.x < 1)
			fk.x = 3;
		if (fk.y < 1)
			fk.y = 3;
	}

	if (slw.x == fk.x && slw.y == fk.y) {
		fk.x = rand() % (MAX_X2 - 3);
		fk.y = rand() % (MAX_Y2 - 3);
		if (fk.x < 1)
			fk.x = 3;
		if (fk.y < 1)
			fk.y = 3;
	}

	if (sarpe.x == slw.x && sarpe.y == slw.y) {
		slw.x = 0;
		slw.y = 0;
		okSlow = true;
		okFast = false;
		score += 2;
		nrAfisareSlw = 0;
		nrSlow = 1;
	}

	if (sarpe.x == fst.x && sarpe.y == fst.y) {
		fst.x = 0;
		fst.y = 0;
		okSlow = false;
		okFast = true;
		score += 2;
		nrAfisareFst = 0;
		nrFast = 1;
	}

	if (sarpe2.x == slw.x && sarpe2.y == slw.y) {
		slw.x = 0;
		slw.y = 0;
		okSlow = true;
		okFast = false;
		score2 += 2;
		nrAfisareSlw = 0;
		nrSlow = 1;
	}

	if (sarpe2.x == fst.x && sarpe2.y == fst.y) {
		fst.x = 0;
		fst.y = 0;
		okSlow = false;
		okFast = true;
		score2 += 2;
		nrAfisareFst = 0;
		nrFast = 1;
	}

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
			while (tailx[i] == fruit.x && taily[i] == fruit.y) {
				fruit.x = rand() % (MAX_X2 - 3);
				fruit.y = rand() % (MAX_Y2 - 3);
			}
			if (fruit.x < 1)
				fruit.x = 1;
			if (fruit.y < 1)
				fruit.y = 1;
		}

	for (int j = 0; j < ntail2; j++)
		if (tail2x[j] == fruit.x && tail2y[j] == fruit.y) {
			while (tail2x[j] == fruit.x && tail2y[j] == fruit.y) {
				fruit.x = rand() % (MAX_X2 - 3);
				fruit.y = rand() % (MAX_Y2 - 3);
			}
			if (fruit.x < 1)
				fruit.x = 1;
			if (fruit.y < 1)
				fruit.y = 1;
		}

	for (int i = 0; i < ntail; i++)
		if (tailx[i] == fk.x && taily[i] == fk.y) {
			while (tailx[i] == fk.x && taily[i] == fk.y) {
				fk.x = rand() % (MAX_X2 - 3);
				fk.y = rand() % (MAX_Y2 - 3);
			}
			if (fk.x < 1)
				fk.x = 3;
			if (fk.y < 1)
				fk.y = 3;
		}

	for (int j = 0; j < ntail2; j++)
		if (tail2x[j] == fk.x && tail2y[j] == fk.y) {
			while (tail2x[j] == fk.x && tail2y[j] == fk.y) {
				fk.x = rand() % (MAX_X2 - 3);
				fk.y = rand() % (MAX_Y2 - 3);
			}
			if (fk.x < 1)
				fk.x = 3;
			if (fk.y < 1)
				fk.y = 3;
		}

	for (int i = 0; i < ntail; i++)
		while (tailx[i] == r.x && taily[i] == r.y) {
			r.x = rand() % (MAX_X2 - 3);
			r.y = rand() % (MAX_Y2 - 3);
			if (r.x < 1)
				r.x = 2;
			if (r.y < 2)
				r.y = 2;
		}

	for (int i = 0; i < ntail2; i++)
		while (tail2x[i] == r.x && tail2y[i] == r.y) {
			r.x = rand() % (MAX_X2 - 3);
			r.y = rand() % (MAX_Y2 - 3);
			if (r.x < 1)
				r.x = 2;
			if (r.y < 2)
				r.y = 2;
		}

	while (fk.x == fruit.x && fk.y == fruit.y || fk.x == r.x && fk.y == r.y || fk.x == v1.x &&fk.y == v1.y || fk.x == v2.x &&fk.y == v2.y || fk.x == v3.x &&fk.y == v3.y || fk.x == v4.x &&fk.y == v4.y
		|| fk.x == v5.x &&fk.y == v5.y || fk.x == v6.x &&fk.y == v6.y || fk.x == v7.x &&fk.y == v7.y || fk.x == v8.x &&fk.y == v8.y || fk.x == v9.x &&fk.y == v9.y || fk.x == v10.x &&fk.y == v10.y) {

		fk.x = rand() % (MAX_X2 - 3);
		fk.y = rand() % (MAX_Y2 - 3);
		if (fk.x < 1)
			fk.x = 3;
		if (fk.y < 1)
			fk.y = 3;
	}

	while (fruit.x == v1.x &&fruit.y == v1.y || fruit.x == v2.x &&fruit.y == v2.y || fruit.x == v3.x &&fruit.y == v3.y || fruit.x == v4.x &&fruit.y == v4.y
		|| fruit.x == v5.x &&fruit.y == v5.y || fruit.x == v6.x &&fruit.y == v6.y || fruit.x == v7.x &&fruit.y == v7.y || fruit.x == v8.x &&fruit.y == v8.y || fruit.x == v9.x &&fruit.y == v9.y
		|| fruit.x == v10.x &&fruit.y == v10.y) {

		fruit.x = rand() % (MAX_X2 - 3);
		fruit.y = rand() % (MAX_Y2 - 3);
		if (fruit.x < 1)
			fruit.x = 1;
		if (fruit.y < 1)
			fruit.y = 1;
	}

	if (nrafisaritailred == 300) {
		coordTailReduction2();
		nrafisaritailredRepeat = 0;
	}

	if (nrafisaritailredRepeat == 15 && nrafisaritailred >= 300) {
		coordTailReduction2();
		nrafisaritailredRepeat = 0;
	}

	if (r.x == fruit.x && r.y == fruit.y){
		fruit.x = rand() % (MAX_X2 - 3);
		fruit.y = rand() % (MAX_Y2 - 3);
		if (fruit.x < 1)
			fruit.x = 1;
		if (fruit.y < 2)
			fruit.y = 1;
	}

	if (r.x == fk.x && r.y == fk.y) {
		fk.x = rand() % (MAX_X2 - 3);
		fk.y = rand() % (MAX_Y2 - 3);
		if (fk.x < 1)
			fk.x = 3;
		if (fk.y < 1)
			fk.y = 3;
	}

	for (int i = 0; i < ntail; i++) {
		if (tailx[i] == v1.x && taily[i] == v1.y) {
			v1.x = rand() % MAX_X2;
			v1.y = rand() % MAX_Y2;
		}

		if (tailx[i] == v2.x && taily[i] == v2.y) {
			v2.x = rand() % MAX_X2;
			v2.y = rand() % MAX_Y2;
		}

		if (tailx[i] == v3.x && taily[i] == v3.y) {
			v3.x = rand() % MAX_X2;
			v3.y = rand() % MAX_Y2;
		}

		if (tailx[i] == v4.x && taily[i] == v4.y) {
			v4.x = rand() % MAX_X2;
			v4.y = rand() % MAX_Y2;
		}

		if (tailx[i] == v5.x && taily[i] == v5.y) {
			v5.x = rand() % MAX_X2;
			v5.y = rand() % MAX_Y2;
		}

		if (tailx[i] == v6.x && taily[i] == v6.y) {
			v6.x = rand() % MAX_X2;
			v6.y = rand() % MAX_Y2;
		}

		if (tailx[i] == v7.x && taily[i] == v7.y) {
			v7.x = rand() % MAX_X2;
			v7.y = rand() % MAX_Y2;
		}

		if (tailx[i] == v8.x && taily[i] == v8.y) {
			v8.x = rand() % MAX_X2;
			v8.y = rand() % MAX_Y2;
		}

		if (tailx[i] == v9.x && taily[i] == v9.y) {
			v9.x = rand() % MAX_X2;
			v9.y = rand() % MAX_Y2;
		}

		if (tailx[i] == v10.x && taily[i] == v10.y) {
			v10.x = rand() % MAX_X2;
			v10.y = rand() % MAX_Y2;
		}
	}

	for (int i = 0; i < ntail2; i++) {
		if (tail2x[i] == v1.x && tail2y[i] == v1.y) {
			v1.x = rand() % MAX_X2;
			v1.y = rand() % MAX_Y2;
		}

		if (tail2x[i] == v2.x && tail2y[i] == v2.y) {
			v2.x = rand() % MAX_X2;
			v2.y = rand() % MAX_Y2;
		}

		if (tail2x[i] == v3.x && tail2y[i] == v3.y) {
			v3.x = rand() % MAX_X2;
			v3.y = rand() % MAX_Y2;
		}

		if (tail2x[i] == v4.x && tail2y[i] == v4.y) {
			v4.x = rand() % MAX_X2;
			v4.y = rand() % MAX_Y2;
		}

		if (tail2x[i] == v5.x && tail2y[i] == v5.y) {
			v5.x = rand() % MAX_X2;
			v5.y = rand() % MAX_Y2;
		}

		if (tail2x[i] == v6.x && tail2y[i] == v6.y) {
			v6.x = rand() % MAX_X2;
			v6.y = rand() % MAX_Y2;
		}

		if (tail2x[i] == v7.x && tail2y[i] == v7.y) {
			v7.x = rand() % MAX_X2;
			v7.y = rand() % MAX_Y2;
		}

		if (tail2x[i] == v8.x && tail2y[i] == v8.y) {
			v8.x = rand() % MAX_X2;
			v8.y = rand() % MAX_Y2;
		}

		if (tail2x[i] == v9.x && tail2y[i] == v9.y) {
			v9.x = rand() % MAX_X2;
			v9.y = rand() % MAX_Y2;
		}

		if (tail2x[i] == v10.x && tail2y[i] == v10.y) {
			v10.x = rand() % MAX_X2;
			v10.y = rand() % MAX_Y2;
		}
	}

	if (sarpe.x == r.x && sarpe.y == r.y && ntail==0) {
		score -= 10;
		nrafisaritailred = 0;
		r.x = 0;
		r.y = 0;
	}

	if (sarpe.x == r.x && sarpe.y == r.y) {
		score += 2;
		nrafisaritailred = 0;
		r.x = 0;
		r.y = 0;

		ntail -= 4;
	}

	if (sarpe.x == fk.x && sarpe.y == fk.y) {
		score += 3;
		nrFakeFruit = 0;
		nrafisarifruit = 0;
		fk.x = rand() % (MAX_X2 - 3);
		fk.y = rand() % (MAX_Y2 - 3);

		fruit.x = rand() % (MAX_X2 - 3);
		fruit.y = rand() % (MAX_Y2 - 3);

		if (fruit.x < 1)
			fruit.x = 1;
		if (fruit.y < 1)
			fruit.y = 1;
		if (fk.x < 1)
			fk.x = 3;
		if (fk.y < 1)
			fk.y = 3;

		ntail++;
		if (ntail2 > 0)
			ntail2 += 2;
	}

	if (sarpe2.x == fk.x && sarpe2.y == fk.y) {
		score2 += 3;
		nrFakeFruit = 0;
		nrafisarifruit = 0;
		fk.x = rand() % (MAX_X2 - 3);
		fk.y = rand() % (MAX_Y2 - 3);

		fruit.x = rand() % (MAX_X2 - 3);
		fruit.y = rand() % (MAX_Y2 - 3);

		if (fruit.x < 1)
			fruit.x = 1;
		if (fruit.y < 1)
			fruit.y = 1;
		if (fk.x < 1)
			fk.x = 3;
		if (fk.y < 1)
			fk.y = 3;

		ntail2++;
		if (ntail > 0)
			ntail += 2;
	}

	if (sarpe2.x == r.x && sarpe2.y == r.y && ntail2==0) {
		score2 -= 10;
		nrafisaritailred = 299;
		r.x = 0;
		r.y = 0;
	}

	if (sarpe2.x == r.x && sarpe2.y == r.y) {
		score2 += 2;
		nrafisaritailred = 299;
		r.x = 0;
		r.y = 0;

		ntail2 -= 4;
	}

	if (sarpe.x == fruit.x && sarpe.y == fruit.y) {
		score++;
		nrFakeFruit = 0;
		nrafisarifruit = 0;
		fk.x = rand() % (MAX_X2 - 3);
		fk.y = rand() % (MAX_Y2 - 3);

		fruit.x = rand() % (MAX_X2 - 3);
		fruit.y = rand() % (MAX_Y2 - 3);

		if (fruit.x < 1)
			fruit.x = 1;
		if (fruit.y < 1)
			fruit.y = 1;
		if (fk.x < 1)
			fk.x = 3;
		if (fk.y < 1)
			fk.y = 3;

		ntail++;
	}

	if (sarpe2.x == fruit.x && sarpe2.y == fruit.y) {
		score2++;
		nrFakeFruit = 0;
		nrafisarifruit = 0;
		fk.x = rand() % (MAX_X2 - 3);
		fk.y = rand() % (MAX_Y2 - 3);

		fruit.x = rand() % (MAX_X2 - 3);
		fruit.y = rand() % (MAX_Y2 - 3);

		if (fruit.x < 1)
			fruit.x = 1;
		if (fruit.y < 1)
			fruit.y = 1;
		if (fk.x < 1)
			fk.x = 3;
		if (fk.y < 1)
			fk.y = 3;

		ntail2++;
	}

	if (nrSlow > 0 && nrSlow < 30 && okSlow) {
		Sleep(130);
		nrSlow++;
	}
	else if (nrFast > 0 && nrFast < 60 && okFast) {
		Sleep(55);
		nrFast++;
	}
	else
	{
		Sleep(95);
		nrSlow = 0;
		nrFast = 0;
	}

	nrafisaritailredRepeat++;
}

void coord() {
	v1.x = rand() % MAX_X2;
	v1.y = rand() % MAX_Y2;
	v2.x = rand() % MAX_X2;
	v2.y = rand() % MAX_Y2;
	v3.x = rand() % MAX_X2;
	v3.y = rand() % MAX_Y2;
	v4.x = rand() % MAX_X2;
	v4.y = rand() % MAX_Y2;
	v5.x = rand() % MAX_X2;
	v5.y = rand() % MAX_Y2;
	v6.x = rand() % MAX_X2;
	v6.y = rand() % MAX_Y2;
	v7.x = rand() % MAX_X2;
	v7.y = rand() % MAX_Y2;
	v8.x = rand() % MAX_X2;
	v8.y = rand() % MAX_Y2;
	v9.x = rand() % MAX_X2;
	v9.y = rand() % MAX_Y2;
	v10.x = rand() % MAX_X2;
	v10.y = rand() % MAX_Y2;
}

void walls() {
	if (nrafisari == 45)
		coord();
	if (nrafisari == 60) {
		v1.x = MAX_X2;
		v1.y = MAX_Y2;
		v2.x = MAX_X2;
		v2.y = MAX_Y2;
		v3.x = MAX_X2;
		v3.y = MAX_Y2;
		v4.x = MAX_X2;
		v4.y = MAX_Y2;
		v5.x = MAX_X2;
		v5.y = MAX_Y2;
		v6.x = MAX_X2;
		v6.y = MAX_Y2;
		v7.x = MAX_X2;
		v7.y = MAX_Y2;
		v8.x = MAX_X2;
		v8.y = MAX_Y2;
		v9.x = MAX_X2;
		v9.y = MAX_Y2;
		v10.x = MAX_X2;
		v10.y = MAX_Y2;
		nrafisari = 0;
	}
}

void coordSG() {
	v1.x = rand() % MAX_X;
	v1.y = rand() % MAX_Y;
	v2.x = rand() % MAX_X;
	v2.y = rand() % MAX_Y;
	v3.x = rand() % MAX_X;
	v3.y = rand() % MAX_Y;
	v4.x = rand() % MAX_X;
	v4.y = rand() % MAX_Y;
	v5.x = rand() % MAX_X;
	v5.y = rand() % MAX_Y;
	v6.x = rand() % MAX_X;
	v6.y = rand() % MAX_Y;
	v7.x = rand() % MAX_X;
	v7.y = rand() % MAX_Y;
	v8.x = rand() % MAX_X;
	v8.y = rand() % MAX_Y;
	v9.x = rand() % MAX_X;
	v9.y = rand() % MAX_Y;
	v10.x = rand() % MAX_X;
	v10.y = rand() % MAX_Y;
}

void wallsSG() {
	if (nrafisari == 45)
		coordSG();
	if (nrafisari == 60) {
		v1.x = MAX_X;
		v1.y = MAX_Y;
		v2.x = MAX_X;
		v2.y = MAX_Y;
		v3.x = MAX_X;
		v3.y = MAX_Y;
		v4.x = MAX_X;
		v4.y = MAX_Y;
		v5.x = MAX_X;
		v5.y = MAX_Y;
		v6.x = MAX_X;
		v6.y = MAX_Y;
		v7.x = MAX_X;
		v7.y = MAX_Y;
		v8.x = MAX_X;
		v8.y = MAX_Y;
		v9.x = MAX_X;
		v9.y = MAX_Y;
		v10.x = MAX_X;
		v10.y = MAX_Y;
		nrafisari = 0;
	}
}

void coordTailReduction() {
	r.x = rand() % (MAX_X - 2);
	r.y = rand() % (MAX_Y - 2);

	if (r.x < 1)
		r.x = 2;
	if (r.y < 1)
		r.y = 2;
}

void coordTailReduction2() {
	r.x = rand() % (MAX_X2 - 2);
	r.y = rand() % (MAX_Y2 - 2);

	if (r.x < 1)
		r.x = 2;
	if (r.y < 1)
		r.y = 2;
}

void tailReduction() {
	if (nrafisaritailred == 180)
		coordTailReduction();
}

void tailReduction2() {
	if (nrafisaritailred == 100)
		coordTailReduction2();
}

void coordFruit() {
	if (nrafisarifruit == 80) {
		fruit.x = rand() % (MAX_X - 3);
		fruit.y = rand() % (MAX_Y - 3);

		if (fruit.x < 1)
			fruit.x = 1;
		if (fruit.y < 1)
			fruit.y = 1;

		nrafisarifruit = 0;
	}
}

void coordFruit2() {
	if (nrafisarifruit == 80) {
		fruit.x = rand() % (MAX_X2 - 3);
		fruit.y = rand() % (MAX_Y2 - 3);

		if (fruit.x < 1)
			fruit.x = 1;
		if (fruit.y < 1)
			fruit.y = 1;

		nrafisarifruit = 0;
	}
}

void coordFake2() {
	if (nrFakeFruit == 80) {
		fk.x = rand() % (MAX_X2 - 3);
		fk.y = rand() % (MAX_Y2 - 3);

		if (fk.x < 1)
			fruit.x = 3;
		if (fruit.y < 1)
			fruit.y = 3;

		nrFakeFruit = 0;
	}
}

void resetCoord() {
	v1.x = MAX_X;
	v1.y = MAX_Y;
	v2.x = MAX_X;
	v2.y = MAX_Y;
	v3.x = MAX_X;
	v3.y = MAX_Y;
	v4.x = MAX_X;
	v4.y = MAX_Y;
	v5.x = MAX_X;
	v5.y = MAX_Y;
	v6.x = MAX_X;
	v6.y = MAX_Y;
	v7.x = MAX_X;
	v7.y = MAX_Y;
	v8.x = MAX_X;
	v8.y = MAX_Y;
	v9.x = MAX_X;
	v9.y = MAX_Y;
	v10.x = MAX_X;
	v10.y = MAX_Y;

	r.x = 0;
	r.y = 0;

	slw.x = 0;
	slw.y = 0;

	fst.x = 0;
	fst.y = 0;
}

void resetCoord2() {
	v1.x = MAX_X2;
	v1.y = MAX_Y2;
	v2.x = MAX_X2;
	v2.y = MAX_Y2;
	v3.x = MAX_X2;
	v3.y = MAX_Y2;
	v4.x = MAX_X2;
	v4.y = MAX_Y2;
	v5.x = MAX_X2;
	v5.y = MAX_Y2;
	v6.x = MAX_X2;
	v6.y = MAX_Y2;
	v7.x = MAX_X2;
	v7.y = MAX_Y2;
	v8.x = MAX_X2;
	v8.y = MAX_Y2;
	v9.x = MAX_X2;
	v9.y = MAX_Y2;
	v10.x = MAX_X2;
	v10.y = MAX_Y2;

	r.x = 0;
	r.y = 0;

	slw.x = 0;
	slw.y = 0;

	fst.x = 0;
	fst.y = 0;
}

void reset() {
	ntail = 0;
	okleft = 0; okright = 0; okup = 0; okdown = 0;
	nrafisari = 0; nrafisaritailred = 0; nrafisarifruit = 0, nrafisaritailredRepeat = 0, nrFakeFruit = 0;
	nrSlow = 0, nrFast = 0;

	for (int i = 0; i < MAX_X; i++)
		tailx[i] = 0;

	for (int i = 0; i < MAX_Y; i++)
		taily[i] = 0;

	for (int i = 0; i<MAX_X + 100; i++)
		for (int j = 0; j < MAX_Y + 100; j++) {
			currMat[i][j] = 0;
			prevMat[i][j] = 0;
		}

	resetCoord();
}

void reset2() {
	ntail = 0; ntail2 = 0;
	okleft = 0; okright = 0; okup = 0; okdown = 0; okleft2 = 0; okright2 = 0; okup2 = 0; okdown2 = 0;
	nrafisari = 0; nrafisaritailred = 0; nrafisarifruit = 0, nrafisaritailredRepeat = 0, nrFakeFruit = 0;
	nrSlow = 0;
	nrFast = 0;

	for (int i = 0; i < MAX_X2; i++) {
		tailx[i] = 0;
		tail2x[i] = 0;
	}

	for (int i = 0; i < MAX_Y; i++) {
		taily[i] = 0;
		tail2y[i] = 0;
	}

	for (int i = 0; i<MAX_X2 + 100; i++)
		for (int j = 0; j < MAX_Y2 + 100; j++) {
			currMat2[i][j] = 0;
			prevMat2[i][j] = 0;
		}

	resetCoord2();
}

int meniu() {
	int a = 0, x1, y1, x2, y2, x3, y3;
	int n, m;

	n = 17;	m = 11;

	setCursorPosition(16, 2);
	cout << "Press SPACE to select";

	setCursorPosition(20, 4);
	cout << "W-UP";

	setCursorPosition(27, 4);
	cout << "S-DOWN";

	while (a != 32) {
		x1 = 20;
		y1 = 11;
		setCursorPosition(x1, y1);
		cout << "SINGLE PLAYER";
		setCursorPosition(n, m);
		cout << "->";

		x2 = 20;
		y2 = 13;
		setCursorPosition(x2, y2);
		cout << "MULTI PLAYERS";

		x3 = 22;
		y3 = 15;
		setCursorPosition(x3, y3);
		cout << "EXIT GAME";

		setCursorPosition(n, m);
		cout << "->";
		a = _getch();

		if (a == 87 || a == 119)
			m -= 2;
		else if (a == 83 || a == 115)
			m += 2;

		if (m < 11)
			m = 11;
		if (m > 15)
			m = 15;

		if (m == 11) {
			setCursorPosition(n, m + 2);
			cout << " ";
			setCursorPosition(n, m + 4);
			cout << " ";
			setCursorPosition(n + 1, m + 2);
			cout << " ";
			setCursorPosition(n + 1, m + 4);
			cout << " ";
		}

		if (m == 13) {
			setCursorPosition(n, m - 2);
			cout << " ";
			setCursorPosition(n, m + 2);
			cout << " ";
			setCursorPosition(n + 1, m - 2);
			cout << " ";
			setCursorPosition(n + 1, m + 2);
			cout << " ";
		}

		if (m == 15) {
			setCursorPosition(n, m - 2);
			cout << " ";
			setCursorPosition(n, m - 4);
			cout << " ";
			setCursorPosition(n + 1, m - 2);
			cout << " ";
			setCursorPosition(n + 1, m - 4);
			cout << " ";
		}

		setCursorPosition(n, m);
		cout << "->";

		if (a == 32 && m == 11) {
			system("cls");
			return 1;
		}
		else if (a == 32 && m == 13) {
			system("cls");
			return 2;
		}
		else if (a == 32 && m == 15)
			return 0;
	}
	return 0;
}

void engine() {
	HWND consoleWindow = GetConsoleWindow();

	SetWindowPos(consoleWindow, 0, 610, 300, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);

	MoveWindow(console, r.left, r.top, 410, 400, TRUE);

	ShowConsoleCursor(false);
	while (1) {
		HWND console = GetConsoleWindow();
		RECT r;
		GetWindowRect(console, &r);
		MoveWindow(console, r.left, r.top, 410, 400, TRUE);

		system("cls");

		int st = meniu();

		if (st == 0)
			exit(EXIT_SUCCESS);

		if (st == 1) {
			HWND console = GetConsoleWindow();
			RECT r;
			GetWindowRect(console, &r);

			reset();
			setCursorPosition(MAX_X / 2, MAX_Y / 2);
			cout << "Press SPACE to start";
			while (_getch() != 32)
				_getch();
			system("cls");
			setup();

			MoveWindow(console, r.left, r.top, 500, 360, TRUE);


			setCursorPosition(MAX_X + 13, MAX_Y - 17);
			cout << "Move Key:";

			setCursorPosition(MAX_X + 17, MAX_Y - 15);
			cout << "W";

			setCursorPosition(MAX_X + 15, MAX_Y - 14);
			cout << "A S D";

			setCursorPosition(MAX_X + 13, MAX_Y - 11);
			cout << "GOOD LUCK!";

			while (!gameOver) {
				//wallsSG();
				//tailReduction();
				coordFruit();
				draw();
				input();
				logic();
				//Sleep(70);
			}
		}

		if (st == 2) {
			HWND console = GetConsoleWindow();
			RECT r;
			GetWindowRect(console, &r);

			reset2();
			setCursorPosition(MAX_X / 2, MAX_Y / 2);
			cout << "Press SPACE to start";
			while (_getch() != 32)
				_getch();
			system("cls");
			setup2();

			MoveWindow(console, r.left, r.top, 500, 530, TRUE);

			setCursorPosition(MAX_X + 9, MAX_Y - 17);
			cout << "Move Key Player 1:";

			setCursorPosition(MAX_X + 17, MAX_Y - 15);
			cout << "W";

			setCursorPosition(MAX_X + 15, MAX_Y - 14);
			cout << "A S D";

			setCursorPosition(MAX_X + 9, MAX_Y - 11);
			cout << "Move Key Player 2:";

			setCursorPosition(MAX_X + 17, MAX_Y - 9);
			cout << "I";

			setCursorPosition(MAX_X + 15, MAX_Y - 8);
			cout << "J K L";

			setCursorPosition(MAX_X + 13, MAX_Y - 5);
			cout << "GOOD LUCK!";

			while (!gameOver) {
				walls();
				//tailReduction2();
				coordFruit2();
				coordFake2();
				draw2();
				input();
				logic2();
				//Sleep(100);
			}
		}
	}
}

int main()
{
	engine();
	return 0;
}
