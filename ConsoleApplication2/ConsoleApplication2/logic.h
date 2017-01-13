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

	if (slw.x == r.x && slw.y == r.y && r.x != 0 && r.y != 0) {
		r.x = rand() % (MAX_X2 - 3);
		r.y = rand() % (MAX_Y2 - 3);
		if (r.x < 1)
			r.x = 2;
		if (r.y < 2)
			r.y = 2;
	}

	if (fst.x == r.x && fst.y == r.y && r.x != 0 && r.y != 0) {
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

	if (sarpe.x == r.x && sarpe.y == r.y && ntail == 0) {
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
		gameOver3 = true;

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

	if (fst.x == r.x && fst.y == r.y && r.x != 0 && r.y != 0) {
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
		gameOver2 = true;

	if (sarpe2.x == v1.x && sarpe2.y == v1.y || sarpe2.x == v2.x && sarpe2.y == v2.y || sarpe2.x == v3.x && sarpe2.y == v3.y || sarpe2.x == v4.x && sarpe2.y == v4.y || sarpe2.x == v5.x && sarpe2.y == v5.y
		|| sarpe2.x == v6.x && sarpe2.y == v6.y || sarpe2.x == v7.x && sarpe2.y == v7.y || sarpe2.x == v8.x && sarpe2.y == v8.y || sarpe2.x == v9.x && sarpe2.y == v9.y || sarpe2.x == v10.x && sarpe2.y == v10.y)
		gameOver = true;

	for (int i = 0; i < ntail; i++)
		if (tailx[i] == sarpe.x && taily[i] == sarpe.y)
			gameOver2 = true;

	for (int j = 0; j < ntail2; j++)
		if (tail2x[j] == sarpe2.x && tail2y[j] == sarpe2.y)
			gameOver = true;

	for (int i = 0; i < ntail; i++)
		if (tailx[i] == sarpe2.x && taily[i] == sarpe2.y)
			gameOver = true;

	for (int j = 0; j < ntail2; j++)
		if (tail2x[j] == sarpe.x && tail2y[j] == sarpe.y)
			gameOver2 = true;

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

	if (r.x == fruit.x && r.y == fruit.y) {
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

	if (sarpe.x == r.x && sarpe.y == r.y && ntail == 0) {
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

	if (sarpe2.x == r.x && sarpe2.y == r.y && ntail2 == 0) {
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