#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>
#include <fstream>
using namespace std;
int char_to_digit(char ch) {
	return ch - '0';
}
char digit_to_char(int x) {
	return x + '0';
};
bool inputpr(string comand);
void left(int& x, int& y, bool& erorr, int i, string& xyeror);
void right(int& x, int& y, bool& erorr, int i, string& xyeror);
void up(int& x, int& y, bool& erorr, int i, string& xyeror);
void down(int& x, int& y, bool& erorr, int i, string& xyeror);
void vvodcircle(string mas_comand[1000], int N[1000], int& i, string comand, int KC[1000]);
void circle(int& x, int& y, int n, bool& erorr, int i0, string& xyeror, string mas_comand[1000], int N[1000], int KC[1000]);
void eror(int x, int y, bool& erorr, string& xyeror, int i);
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int y = 1, x = 1, i = 1, N[1000],KC[1000];
	bool erorr = false;
	string comand, xyeror,mas_comand[1000];
	for (cout << i << " ", i++; getline(cin, comand) && (comand != ""); cout << i << " ", i++) {
		if (inputpr(comand) == true) {
			if (comand == "��������� 1" || comand == "��������� 2" || comand == "��������� 3" || comand == "��������� 4" || comand == "��������� 5" || comand == "��������� 6" || comand == "��������� 7" || comand == "��������� 8" || comand == "��������� 9") {
					vvodcircle(mas_comand, N, i, comand, KC);
				}	
			else {
				mas_comand[i] = comand;
				N[i] = 0;
			}
		}
		else {
			cout << "��������� ����" << endl;
			i--;
		};
	};
	for (int i1 = 1; i1 < i && erorr == false; i1++) {
		if (mas_comand[i1] == "�����") left(x, y, erorr, i1, xyeror);
		else
			if (mas_comand[i1] == "������") right(x, y, erorr, i1, xyeror);
			else
				if (mas_comand[i1] == "�����") up(x, y, erorr, i1, xyeror);
				else
					if (mas_comand[i1] == "����") down(x, y, erorr, i1, xyeror);
					else
						if (mas_comand[i1] == "����") circle(x, y, N[i1], erorr, i1, xyeror, mas_comand, N,KC);
	}
	if (erorr == false) cout << " ����������  ����������� : (" << x << "," << y << ").";
	else
		cout << xyeror;
}
void vvodcircle(string mas_comand[1000], int N[1000], int& i, string comand,int KC[1000]){
	mas_comand[i] = "����";
	int i0 = i;
	N[i] = char_to_digit(comand[10]);
	for (cout << i << " ",i++; getline(cin, comand) && (comand != "��"); cout << i << " ", i++) {
		if (comand == "") {
			cout << "��������� ����" << endl;
			i--;
		}else {
			if (inputpr(comand) == true) {
				if (comand == "��������� 1" || comand == "��������� 2" || comand == "��������� 3" || comand == "��������� 4" || comand == "��������� 5" || comand == "��������� 6" || comand == "��������� 7" || comand == "��������� 8" || comand == "��������� 9") {
					vvodcircle(mas_comand, N, i, comand,KC);
				}
				else {
					mas_comand[i] = comand;
					N[i] = 0;
				}
			}
			else {
				cout << "��������� ����" << endl;
				i--;
			};
		};
	};
	KC[i0] = i;
	mas_comand[i] = "��";
}
void circle(int& x, int& y, int n, bool& erorr, int i0, string& xyeror, string mas_comand[1000], int N[1000],int KC[1000]) {
	for (int n0 = 1; n0 < n && erorr == false; n0++) {
		for (int i = i0 + 1; i<KC[i0]; i++) {
			if (mas_comand[i] == "�����") left(x, y, erorr, i, xyeror);
			else
				if (mas_comand[i] == "������") right(x, y, erorr, i, xyeror);
				else
					if (mas_comand[i] == "�����") up(x, y, erorr, i, xyeror);
					else
						if (mas_comand[i] == "����") down(x, y, erorr, i, xyeror);
						else
							if (mas_comand[i] == "����") circle(x, y, N[i], erorr, i, xyeror, mas_comand, N, KC);
		}
	}
}
void eror(int x, int y, bool& erorr, string& xyeror, int i) {
	if (x < 1) {
		xyeror.append("������� ");
		xyeror += digit_to_char(i - 1);
		xyeror.append(" : X < 0");
		erorr = true;
	};
	if (y < 1) {
		xyeror.append("������� ");
		xyeror += digit_to_char(i - 1);
		xyeror.append(" : Y < 0");
		erorr = true;
	};
	if (x > 10) {
		xyeror.append("������� ");
		xyeror += digit_to_char(i - 1);
		xyeror.append(" : X > 10");
		erorr = true;
	};
	if (y > 10) {
		xyeror.append("������� ");
		xyeror += digit_to_char(i - 1);
		xyeror.append(" : Y > 10");
		erorr = true;
	};
}
bool inputpr(string comand) {
	if (comand == "�����" || comand == "������" || comand == "����" || comand == "�����" || comand == "��������� 1" || comand == "��������� 2" || comand == "��������� 3" || comand == "��������� 4" || comand == "��������� 5" || comand == "��������� 6" || comand == "��������� 7" || comand == "��������� 8" || comand == "��������� 9") return true;
	else return false;
}

void left(int& x, int& y, bool& erorr, int i, string& xyeror) {
	x--;
	eror(x, y, erorr, xyeror, i);
}
void right(int& x, int& y, bool& erorr, int i, string& xyeror) {
	x++;
	eror(x, y, erorr, xyeror, i);
}
void up(int& x, int& y, bool& erorr, int i, string& xyeror) {
	y++;
	eror(x, y, erorr, xyeror, i);
}
void down(int& x, int& y, bool& erorr, int i, string& xyeror) {
	y--;
	eror(x, y, erorr, xyeror, i);
}
