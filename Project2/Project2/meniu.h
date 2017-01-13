int meniu() {
	int a = 0, x1, y1, x2, y2, x3, y3;
	int n, m;

	n = 17;	m = 11;

	setCursorPosition(16, 2);
	cout << "Press SPACE to select";

	setCursorPosition(20, 4);
	cout << "W-UP";

	setCursorPosition(27, 4);
	cout << "S-DOWN";

	while (a != 32) {
		x1 = 20;
		y1 = 11;
		setCursorPosition(x1, y1);
		cout << "SINGLE PLAYER";
		setCursorPosition(n, m);
		cout << "->";

		x2 = 20;
		y2 = 13;
		setCursorPosition(x2, y2);
		cout << "MULTI PLAYERS";

		x3 = 22;
		y3 = 15;
		setCursorPosition(x3, y3);
		cout << "EXIT GAME";

		setCursorPosition(n, m);
		cout << "->";
		a = _getch();

		if (a == 87 || a == 119)
			m -= 2;
		else if (a == 83 || a == 115)
			m += 2;

		if (m < 11)
			m = 11;
		if (m > 15)
			m = 15;

		if (m == 11) {
			setCursorPosition(n, m + 2);
			cout << " ";
			setCursorPosition(n, m + 4);
			cout << " ";
			setCursorPosition(n + 1, m + 2);
			cout << " ";
			setCursorPosition(n + 1, m + 4);
			cout << " ";
		}

		if (m == 13) {
			setCursorPosition(n, m - 2);
			cout << " ";
			setCursorPosition(n, m + 2);
			cout << " ";
			setCursorPosition(n + 1, m - 2);
			cout << " ";
			setCursorPosition(n + 1, m + 2);
			cout << " ";
		}

		if (m == 15) {
			setCursorPosition(n, m - 2);
			cout << " ";
			setCursorPosition(n, m - 4);
			cout << " ";
			setCursorPosition(n + 1, m - 2);
			cout << " ";
			setCursorPosition(n + 1, m - 4);
			cout << " ";
		}

		setCursorPosition(n, m);
		cout << "->";

		if (a == 32 && m == 11) {
			system("cls");
			return 1;
		}
		else if (a == 32 && m == 13) {
			system("cls");
			return 2;
		}
		else if (a == 32 && m == 15)
			return 0;
	}
	return 0;
}

void engine() {
	HWND consoleWindow = GetConsoleWindow();

	SetWindowPos(consoleWindow, 0, 610, 300, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);

	MoveWindow(console, r.left, r.top, 410, 400, TRUE);

	ShowConsoleCursor(false);
	while (1) {
		HWND console = GetConsoleWindow();
		RECT r;
		GetWindowRect(console, &r);
		MoveWindow(console, r.left, r.top, 410, 400, TRUE);

		system("cls");

		int st = meniu();

		if (st == 0)
			exit(EXIT_SUCCESS);

		if (st == 1) {
			HWND console = GetConsoleWindow();
			RECT r;
			GetWindowRect(console, &r);

			reset();
			setCursorPosition(MAX_X / 2, MAX_Y / 2);
			cout << "Press SPACE to start";
			while (_getch() != 32)
				_getch();
			system("cls");
			setup();

			MoveWindow(console, r.left, r.top, 500, 360, TRUE);


			setCursorPosition(MAX_X + 13, MAX_Y - 17);
			cout << "Move Key:";

			setCursorPosition(MAX_X + 17, MAX_Y - 15);
			cout << "W";

			setCursorPosition(MAX_X + 15, MAX_Y - 14);
			cout << "A S D";

			setCursorPosition(MAX_X + 13, MAX_Y - 11);
			cout << "GOOD LUCK!";

			while (!gameOver) {
				//wallsSG();
				//tailReduction();
				coordFruit();
				draw();
				input();
				logic();
				//Sleep(70);

				if (gameOver == true) {
					system("cls");
					setCursorPosition(MAX_X / 2 - 2, MAX_Y / 2 - 3);
					cout << "Ai pierdut. Mult noroc data viitoare!:)";

					setCursorPosition(MAX_X / 2 + 5, MAX_Y2 / 2 - 6);
					cout << "Press Any Key To Continue";
					_getch();
				}
			}
		}

		if (st == 2) {
			HWND console = GetConsoleWindow();
			RECT r;
			GetWindowRect(console, &r);

			reset2();
			setCursorPosition(MAX_X / 2, MAX_Y / 2);
			cout << "Press SPACE to start";
			while (_getch() != 32)
				_getch();
			system("cls");
			setup2();

			MoveWindow(console, r.left, r.top, 500, 530, TRUE);

			setCursorPosition(MAX_X + 9, MAX_Y - 17);
			cout << "Move Key Player 1:";

			setCursorPosition(MAX_X + 17, MAX_Y - 15);
			cout << "W";

			setCursorPosition(MAX_X + 15, MAX_Y - 14);
			cout << "A S D";

			setCursorPosition(MAX_X + 9, MAX_Y - 11);
			cout << "Move Key Player 2:";

			setCursorPosition(MAX_X + 17, MAX_Y - 9);
			cout << "I";

			setCursorPosition(MAX_X + 15, MAX_Y - 8);
			cout << "J K L";

			setCursorPosition(MAX_X + 13, MAX_Y - 5);
			cout << "GOOD LUCK!";

			while (!gameOver && !gameOver2 && !gameOver3) {
				walls();
				//tailReduction2();
				coordFruit2();
				coordFake2();
				draw2();
				input();
				logic2();
				//Sleep(100);

				if (gameOver == true) {
					system("cls");
					setCursorPosition(MAX_X2 / 2 + 11, MAX_Y2 / 2 - 3);
					cout << "Player 1 Win!";

					setCursorPosition(MAX_X2 / 2 + 5, MAX_Y2 / 2);
					cout << "Press Any Key To Continue";
					_getch();
				}
				else if (gameOver2 == true) {
					system("cls");
					setCursorPosition(MAX_X2 / 2 + 11, MAX_Y2 / 2 - 3);
					cout << "Player 2 Win!";

					setCursorPosition(MAX_X2 / 2 + 5, MAX_Y2 / 2);
					cout << "Press Any Key To Continue";
					_getch();
				}
				else if (gameOver3 == true) {
					system("cls");
					setCursorPosition(MAX_X2 / 2 + 14, MAX_Y2 / 2 - 3);
					cout << "Remiza";

					setCursorPosition(MAX_X2 / 2 + 5, MAX_Y2 / 2);
					cout << "Press Any Key To Continue";
					_getch();
				}
			}
		}


	}
}