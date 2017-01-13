void input() {
	if (_kbhit()) {
		switch (_getch())
		{
		case'a':
			dir = LEFT;
			break;
		case'd':
			dir = RIGHT;
			break;
		case'w':
			dir = UP;
			break;
		case's':
			dir = DOWN;
			break;
		case'j':
			dir2 = LEFT;
			break;
		case'l':
			dir2 = RIGHT;
			break;
		case'i':
			dir2 = UP;
			break;
		case'k':
			dir2 = DOWN;
			break;
		case'A':
			dir = LEFT;
			break;
		case'D':
			dir = RIGHT;
			break;
		case'W':
			dir = UP;
			break;
		case'S':
			dir = DOWN;
			break;
		case'J':
			dir2 = LEFT;
			break;
		case'L':
			dir2 = RIGHT;
			break;
		case'I':
			dir2 = UP;
			break;
		case'K':
			dir2 = DOWN;
			break;
		case 27:
		{
			HWND console = GetConsoleWindow();
			RECT r;
			GetWindowRect(console, &r);

			MoveWindow(console, r.left, r.top, 410, 400, TRUE);
			engine();
		}
		default:
			break;
		}
	}
}