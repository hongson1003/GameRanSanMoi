#include"Header.h"
#include<iostream>

using namespace std;

int speed = 100;
int length = 4;

void Ve_Tuong_Tren();
void Ve_Tuong_Duoi();
void Ve_Tuong_Trai();
void Ve_Tuong_Phai();
void Ve_Tuong();
void Khoi_Tao_Ran(int [], int []);
void Ve_Ran(int [], int []);
void Them_Mang(int [], int);
void Xoa_Mang(int [], int);
void Xu_Ly_Ran(int [], int [], int , int,int &, int &);
void Xoa_Du_Lieu_Cu(int [], int []);
bool Ran_Cham_Tuong(int , int);
bool Ran_Can_Duoi(int [], int []);
void Tao_Qua(int [], int [], int &, int &);
bool Ran_De_Len_Qua(int [], int [], int , int);
bool Ran_An_Qua(int, int, int, int);

int main() {
	int quax, quay;
	srand(time(NULL));
	int toadoX[100], toadoY[100];
	Ve_Tuong();
	Khoi_Tao_Ran(toadoX, toadoY);
	int x = 50, y = 13;
	Ve_Ran(toadoX, toadoY);
	int check = 2;
	bool Gameover = false;
	Tao_Qua(toadoX, toadoY, quax, quay);
	while (!Gameover) {
		Xoa_Du_Lieu_Cu(toadoX, toadoY);
		// check = 0 di xuong 1 di len 2 di phai 3 di trai
		if (_kbhit()) {
			char kitu = _getch();
			if (kitu == -32) {
				kitu = _getch();
				if (kitu == 72 && check!=0)
					check = 1;
				else if (kitu == 80 && check!=1)
					check = 0;
				else if (kitu == 77 && check!=3)
					check = 2;
				else if (kitu == 75 && check!=2)
					check = 3;
			}

		}
		if (check == 0)
			// di xuong
			y++;
		else if (check == 1)
			// di len
			y--;
		else if (check == 2)
			// di phai
			x++;
		else if (check == 3)
			// di trai
			x--;

		Xu_Ly_Ran(toadoX, toadoY, x, y, quax, quay);
		Gameover = Ran_Can_Duoi(toadoX, toadoY) + Ran_Cham_Tuong(toadoX[0], toadoY[0]);
		Sleep(speed);
	}
	_getch();
	return 0;
}
bool Ran_An_Qua(int x0, int y0, int quax, int quay) {
	if (x0 == quax && y0 == quay)
		return true;
	return false;

}

bool Ran_De_Len_Qua(int toadoX[], int toadoY[], int a, int b) {
	for (int i = 0; i < length; i++)
		if (a == toadoX[i] && b == toadoY[i])
			return true;
	return false;

}
void Tao_Qua(int toadoX[], int toadoY[], int & quax, int& quay) {
	do {
		quax = rand() % (99 - 11 + 1) + 11;
		quay = rand() % (25 - 2 + 1) + 2;
	} while (Ran_De_Len_Qua(toadoX, toadoY, quax, quay));
	gotoXY(quax, quay);
	int i = rand() % (15 - 1 + 1) + 1;
	SetColor(i);
	cout << "$";
	SetColor(7); // tao lai con rang mau trang
}

bool Ran_Can_Duoi(int toadoX[], int toadoY[]) {
	for (int i = 1; i < length; i++)
		if (toadoX[0] == toadoX[i] && toadoY[0] == toadoY[i])
			return true;
	return false;
}
bool Ran_Cham_Tuong(int x, int y) {
	if (y == 1 && (x >= 10 && x <= 100))
		return true;
	else if (y == 26 && (x >= 10 && x <= 100))
		return true;
	else if (x == 10 && (y >= 1 && y <= 26))
		return true;
	else if (x == 100 && (y >= 1 && y <= 26))
		return true;
	return false;
}

void Xoa_Du_Lieu_Cu(int toadoX[], int toadoY[]) {
	for (int i = 0; i < length; i++) {
		gotoXY(toadoX[i], toadoY[i]);
		cout << " ";
	}
}
void Xu_Ly_Ran(int toadoX[], int toadoY[], int x, int y, int &quax, int &quay) {
	Them_Mang(toadoX, x); // them toa do moi vao dau mang
	Them_Mang(toadoY, y);
	if ((Ran_An_Qua(toadoX[0], toadoY[0], quax, quay)==false)){
		length -= 2;
	}
	else {
		Tao_Qua(toadoX, toadoY, quax, quay);
		speed--;
	}
	//Xoa_Mang(toadoY, length); // xoa toa do cuoi mang
	//Xoa_Mang(toadoX, length);
	// ve ran
	Ve_Ran(toadoX, toadoY);
}


void Them_Mang(int a[], int x) {
	for (int i = length; i > 0; i --) {
		a[i] = a[i - 1];
	}
	a[0] = x;
	length++;
}

void Xoa_Mang(int a[], int vt) {
	for (int i = vt; i < length; i++) {
		a[i] = a[i + 1];
	}
	length--;
}
void Khoi_Tao_Ran(int toadoX[], int toadoY[]) {
	int x = 50, y = 13;
	for (int i = 0; i < length; i++) {
		gotoXY(toadoX[i], toadoY[i]);
		toadoX[i] = x;
		toadoY[i] = y;
		x--;
	}
}
void Ve_Ran(int toadoX[], int toadoY[]) {
	for (int i = 0; i < length; i++) {
		gotoXY(toadoX[i], toadoY[i]);
		if (i == 0)
			cout << "0";
		else
			cout << "o";
	}
}
		

void Ve_Tuong_Tren() {
	int x = 10, y = 1;
	while (x <= 100) {
		gotoXY(x, y);
		cout << "+";
		x++;
	}
}
void Ve_Tuong_Duoi() {
	int x = 10, y = 26;
	while (x <= 100) {
		gotoXY(x, y);
		cout << "+";
		x++;
	}
}
void Ve_Tuong_Trai() {
	int x = 10, y = 1;
	while (y <= 26) {
		gotoXY(x, y);
		cout << "+";
		y++;
	}
}
void Ve_Tuong_Phai() {
	int x = 100, y = 1;
	while (y <= 26) {
		gotoXY(x, y);
		cout << "+";
		y++;
	}
}
void Ve_Tuong() {
	SetColor(11);
	Ve_Tuong_Tren();
	Ve_Tuong_Duoi();
	Ve_Tuong_Trai();
	Ve_Tuong_Phai();
	SetColor(7);

}
// nang cap ran di xuyen tuong :))
// tao ra vat the nhu chuyen ngai vat
