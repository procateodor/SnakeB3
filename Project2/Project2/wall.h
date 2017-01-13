void coord() {
	v1.x = rand() % MAX_X2;
	v1.y = rand() % MAX_Y2;
	v2.x = rand() % MAX_X2;
	v2.y = rand() % MAX_Y2;
	v3.x = rand() % MAX_X2;
	v3.y = rand() % MAX_Y2;
	v4.x = rand() % MAX_X2;
	v4.y = rand() % MAX_Y2;
	v5.x = rand() % MAX_X2;
	v5.y = rand() % MAX_Y2;
	v6.x = rand() % MAX_X2;
	v6.y = rand() % MAX_Y2;
	v7.x = rand() % MAX_X2;
	v7.y = rand() % MAX_Y2;
	v8.x = rand() % MAX_X2;
	v8.y = rand() % MAX_Y2;
	v9.x = rand() % MAX_X2;
	v9.y = rand() % MAX_Y2;
	v10.x = rand() % MAX_X2;
	v10.y = rand() % MAX_Y2;
}

void walls() {
	if (nrafisari == 45)
		coord();
	if (nrafisari == 60) {
		v1.x = 0;
		v1.y = 0;
		v2.x = 0;
		v2.y = 0;
		v3.x = 0;
		v3.y = 0;
		v4.x = 0;
		v4.y = 0;
		v5.x = 0;
		v5.y = 0;
		v6.x = 0;
		v6.y = 0;
		v7.x = 0;
		v7.y = 0;
		v8.x = 0;
		v8.y = 0;
		v9.x = 0;
		v9.y = 0;
		v10.x = 0;
		v10.y = 0;
		nrafisari = 0;
		okWall = false;
		okwall2 = false;
	}
}

void coordSG() {
	v1.x = rand() % MAX_X;
	v1.y = rand() % MAX_Y;
	v2.x = rand() % MAX_X;
	v2.y = rand() % MAX_Y;
	v3.x = rand() % MAX_X;
	v3.y = rand() % MAX_Y;
	v4.x = rand() % MAX_X;
	v4.y = rand() % MAX_Y;
	v5.x = rand() % MAX_X;
	v5.y = rand() % MAX_Y;
	v6.x = rand() % MAX_X;
	v6.y = rand() % MAX_Y;
	v7.x = rand() % MAX_X;
	v7.y = rand() % MAX_Y;
	v8.x = rand() % MAX_X;
	v8.y = rand() % MAX_Y;
	v9.x = rand() % MAX_X;
	v9.y = rand() % MAX_Y;
	v10.x = rand() % MAX_X;
	v10.y = rand() % MAX_Y;
}

void wallsSG() {
	if (nrafisari == 45)
		coordSG();
	if (nrafisari == 60) {
		v1.x = 0;
		v1.y = 0;
		v2.x = 0;
		v2.y = 0;
		v3.x = 0;
		v3.y = 0;
		v4.x = 0;
		v4.y = 0;
		v5.x = 0;
		v5.y = 0;
		v6.x = 0;
		v6.y = 0;
		v7.x = 0;
		v7.y = 0;
		v8.x = 0;
		v8.y = 0;
		v9.x = 0;
		v9.y = 0;
		v10.x = 0;
		v10.y = 0;
		nrafisari = 0;
		okWall = false;
	}
}