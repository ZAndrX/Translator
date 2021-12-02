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
			if (comand == "ÏÎÂÒÎĞÈÒÜ 1" || comand == "ÏÎÂÒÎĞÈÒÜ 2" || comand == "ÏÎÂÒÎĞÈÒÜ 3" || comand == "ÏÎÂÒÎĞÈÒÜ 4" || comand == "ÏÎÂÒÎĞÈÒÜ 5" || comand == "ÏÎÂÒÎĞÈÒÜ 6" || comand == "ÏÎÂÒÎĞÈÒÜ 7" || comand == "ÏÎÂÒÎĞÈÒÜ 8" || comand == "ÏÎÂÒÎĞÈÒÜ 9") {
					vvodcircle(mas_comand, N, i, comand, KC);
				}	
			else {
				mas_comand[i] = comand;
				N[i] = 0;
			}
		}
		else {
			cout << "Ïîâòîğèòå ââîä" << endl;
			i--;
		};
	};
	for (int i1 = 1; i1 < i && erorr == false; i1++) {
		if (mas_comand[i1] == "ÂËÅÂÎ") left(x, y, erorr, i1, xyeror);
		else
			if (mas_comand[i1] == "ÂÏĞÀÂÎ") right(x, y, erorr, i1, xyeror);
			else
				if (mas_comand[i1] == "ÂÂÅĞÕ") up(x, y, erorr, i1, xyeror);
				else
					if (mas_comand[i1] == "ÂÍÈÇ") down(x, y, erorr, i1, xyeror);
					else
						if (mas_comand[i1] == "ÖÈÊË") circle(x, y, N[i1], erorr, i1, xyeror, mas_comand, N,KC);
	}
	if (erorr == false) cout << " Êîîğäèíàòû  èñïîëíèòåëÿ : (" << x << "," << y << ").";
	else
		cout << xyeror;
}
void vvodcircle(string mas_comand[1000], int N[1000], int& i, string comand,int KC[1000]){
	mas_comand[i] = "ÖÈÊË";
	int i0 = i;
	N[i] = char_to_digit(comand[10]);
	for (cout << i << " ",i++; getline(cin, comand) && (comand != "ÊÖ"); cout << i << " ", i++) {
		if (comand == "") {
			cout << "Ïîâòîğèòå ââîä" << endl;
			i--;
		}else {
			if (inputpr(comand) == true) {
				if (comand == "ÏÎÂÒÎĞÈÒÜ 1" || comand == "ÏÎÂÒÎĞÈÒÜ 2" || comand == "ÏÎÂÒÎĞÈÒÜ 3" || comand == "ÏÎÂÒÎĞÈÒÜ 4" || comand == "ÏÎÂÒÎĞÈÒÜ 5" || comand == "ÏÎÂÒÎĞÈÒÜ 6" || comand == "ÏÎÂÒÎĞÈÒÜ 7" || comand == "ÏÎÂÒÎĞÈÒÜ 8" || comand == "ÏÎÂÒÎĞÈÒÜ 9") {
					vvodcircle(mas_comand, N, i, comand,KC);
				}
				else {
					mas_comand[i] = comand;
					N[i] = 0;
				}
			}
			else {
				cout << "Ïîâòîğèòå ââîä" << endl;
				i--;
			};
		};
	};
	KC[i0] = i;
	mas_comand[i] = "ÊÖ";
}
void circle(int& x, int& y, int n, bool& erorr, int i0, string& xyeror, string mas_comand[1000], int N[1000],int KC[1000]) {
	for (int n0 = 1; n0 < n && erorr == false; n0++) {
		for (int i = i0 + 1; i<KC[i0]; i++) {
			if (mas_comand[i] == "ÂËÅÂÎ") left(x, y, erorr, i, xyeror);
			else
				if (mas_comand[i] == "ÂÏĞÀÂÎ") right(x, y, erorr, i, xyeror);
				else
					if (mas_comand[i] == "ÂÂÅĞÕ") up(x, y, erorr, i, xyeror);
					else
						if (mas_comand[i] == "ÂÍÈÇ") down(x, y, erorr, i, xyeror);
						else
							if (mas_comand[i] == "ÖÈÊË") circle(x, y, N[i], erorr, i, xyeror, mas_comand, N, KC);
		}
	}
}
void eror(int x, int y, bool& erorr, string& xyeror, int i) {
	if (x < 1) {
		xyeror.append("Êîìàíäà ");
		xyeror += digit_to_char(i - 1);
		xyeror.append(" : X < 0");
		erorr = true;
	};
	if (y < 1) {
		xyeror.append("Êîìàíäà ");
		xyeror += digit_to_char(i - 1);
		xyeror.append(" : Y < 0");
		erorr = true;
	};
	if (x > 10) {
		xyeror.append("Êîìàíäà ");
		xyeror += digit_to_char(i - 1);
		xyeror.append(" : X > 10");
		erorr = true;
	};
	if (y > 10) {
		xyeror.append("Êîìàíäà ");
		xyeror += digit_to_char(i - 1);
		xyeror.append(" : Y > 10");
		erorr = true;
	};
}
bool inputpr(string comand) {
	if (comand == "ÂËÅÂÎ" || comand == "ÂÏĞÀÂÎ" || comand == "ÂÍÈÇ" || comand == "ÂÂÅĞÕ" || comand == "ÏÎÂÒÎĞÈÒÜ 1" || comand == "ÏÎÂÒÎĞÈÒÜ 2" || comand == "ÏÎÂÒÎĞÈÒÜ 3" || comand == "ÏÎÂÒÎĞÈÒÜ 4" || comand == "ÏÎÂÒÎĞÈÒÜ 5" || comand == "ÏÎÂÒÎĞÈÒÜ 6" || comand == "ÏÎÂÒÎĞÈÒÜ 7" || comand == "ÏÎÂÒÎĞÈÒÜ 8" || comand == "ÏÎÂÒÎĞÈÒÜ 9") return true;
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
