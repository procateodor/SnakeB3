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