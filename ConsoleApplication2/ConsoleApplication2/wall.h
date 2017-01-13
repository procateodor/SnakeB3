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
		nrafisari = 0;
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
		nrafisari = 0;
	}
}