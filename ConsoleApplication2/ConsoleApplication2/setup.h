void setup() {
	gameOver = false;
	dir = STOP;
	sarpe.x = MAX_X / 2;
	sarpe.y = MAX_Y / 2;
	fruit.x = rand() % (MAX_X - 2);
	fruit.y = rand() % (MAX_Y - 2);
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
	gameOver2 = false;
	gameOver3 = false;
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