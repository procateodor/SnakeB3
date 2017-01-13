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