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