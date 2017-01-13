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