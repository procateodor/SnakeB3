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