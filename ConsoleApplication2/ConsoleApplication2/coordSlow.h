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