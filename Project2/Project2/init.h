#define MAX_X 30
#define MAX_Y 20

#define MAX_X2 30
#define MAX_Y2 30

using namespace std;

bool gameOver, gameOver2, gameOver3;
int score, score2;
int tailx[1000], taily[1000], tail2x[1000], tail2y[1000];
int ntail, ntail2;
int okleft, okright, okup, okdown, okleft2, okright2, okup2, okdown2;
int nrafisari, nrafisaritailred, nrafisarifruit, nrFakeFruit, nrafisaritailredRepeat, nrAfisareSlw, nrAfisareFst;
int bestScore, bestScore2;
bool nrwall = true, okSlow = false, okFast = false, okWall = false, okwall2 = false;
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
