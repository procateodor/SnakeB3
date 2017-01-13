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
