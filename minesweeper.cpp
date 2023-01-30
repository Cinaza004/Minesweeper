#include <iostream>
#include <cstdlib>
#include <time.h>
#include <sstream>
using namespace std;
int n[8][8];
int point1 = 0, point2 = 0;
string name1, name2;
void firstr();
void giving_value();
void check_the_points();
void otherr(int p, int i);
void answer(int p, int t);
void giving_up(string name, int z);
void player1();
void player2();
void playGame();



void firstr() {

	int a = 0;                                      //making the bord of the game for the firsttime
	for (int i = 0; i < 8; i++) {

		for (int p = 0; i < 1 && p < 8; p++) { cout << "    " << p << "    "; }
		cout << endl;
		if (a < 9) { cout << a; a++; }
		for (int z = 0; z < 8; z++) { cout << "   ##    "; }
		cout << endl;
	}
}
void giving_value() {							//giving value to the matris and declare the bombs
	for (int i = 0; i < 8; i++) {
		for (int p = 0; p < 8; p++) {
			n[i][p] = -5;
		}
	}
	int i = 0;
	while (i < 12) {
		int const m = rand() % 8;
		int const x = rand() % 8;
		if (n[m][x] == -5) {
			n[m][x] = 10;
		}
		else {
			continue;
		}
		i++;
	}

}
void check_the_points()			//check if the game should be still continued
{                        
	if (point1 == 7)
	{
		cout << name1 << " won the game :)";
		exit(0);
	}else if (point2 == 7)
	{
		cout << name2 << " won the game :)";
		exit(0);
	}else if (point1 + point2 == 12)
	{
		cout << "Draw :|";
		exit(0);
	}
}

void playGame()
{
	while (true)
	{
		player1();
		player2();
	}
}


void otherr(int p, int i) {
	system("cls");
	int a = 0;                                      //making the bord of the game
	for (int i = 0; i < 8; i++) {
		for (int p = 0; i < 1 && p < 8; p++) {
			cout << "    " << p << "    ";
		}
		cout << endl;
		if (a < 9) {
			cout << a; a++;
		}
		for (int z = 0; z < 8; z++) {
			if (n[i][z] == 0) {
				cout << "         ";
			}
			else if ((n[i][z] != -5) && (n[i][z] != 10) && (n[i][z] != 15)) {
				cout << "    " << n[i][z] << "    ";
			}
			else if (n[i][z] == 15) {
				cout << "  bomb!  ";
			}
			else {
				cout << "   ##    ";
			}
		}
		cout << endl;
	}
	cout << name1 << "  point : " << point1 << endl;
	cout << name2 << " point : " << point2 << endl;


}

void answer(int p, int t) {                       //checking the number of bombs around 				
	int noba = 0;        //stands for number of the bombs around
	for (int i = p - 1; i < p + 2; i++) {
		for (int z = t - 1; z < t + 2; z++) {

			if (((i > -1) && (i < 8)) && ((z > -1) && (z < 8))) {
				if (n[i][z] == 10) {
					noba++;
				}
				else if (n[i][z] == 15) {
					noba++;
				}
			}
		}
	}
	if (noba == 0) {
		for (int i = p - 1; i < p + 2; i++) {
			for (int z = t - 1; z < t + 2; z++) {
				if (((i > -1) && (i < 8)) && ((z > -1) && (z < 8)) && (n[i][z] == -5)) {
					n[i][z] = 0;
					otherr(p, t);
				}
			}
		}
	}
	else if (noba > 0) {
		n[p][t] = noba; otherr(p, t);
	}
}
void giving_up(string name, int z) {
	cout << name << " has giiven up " << endl;
	if (z == 1) {
		point2 = 7;
		point1 = 0;
		check_the_points();
	}
	else if (z == 2) {
		point1 = 7;
		point2 = 0;
		check_the_points();
	}

}

void player1() {
	cout << name1 << " : " << endl;
	int  t, p;
	string ps, ts;
	cout << "choose an horizontal line : ";
	cin >> ps;
	if (ps == "x") { giving_up(name1, 1); }
	cout << "choose an vertical line : ";
	cin >> ts;
	if (ts == "x") { giving_up(name1, 1); }
	p = stoi(ps);
	t = stoi(ts);

	if (n[p][t] == 10) {
		cout << "you found a bomb" << endl;
		n[p][t] = 15;
		point1++;
		otherr(p, t);
		check_the_points();
		player1();
	}
	else if (n[p][t] == -5) {
		answer(p, t);
	}
	else {
		cout << "it doesnt exist" << endl;
	}

}


void player2() {
	cout << name2 << " : " << endl;
	int p, t;
	string ps, ts;
	cout << "choose an vertical line : ";
	cin >> ps;
	if (ps == "x") { giving_up(name2, 2); }
	cout << "choose an horizontal line : ";
	cin >> ts;
	if (ts == "x") { giving_up(name2, 2); }
	p = stoi(ps);
	t = stoi(ts);

	if (n[p][t] == 10) {
		cout << "you found a bomb" << endl;
		n[p][t] = 15;
		point2++;
		otherr(p, t);
		check_the_points();
		player2();
	}
	else if (n[p][t] == -5) {
		answer(p, t);
	}
	else {
		cout << "it dosent exist" << endl;
	}
}


int main() {
	firstr();
	cout << "press x twice to end the game!" << endl;
	cout << "name for player 1 : ";
	cin >> name1;
	cout << "name for player 2 : ";
	cin >> name2;
	srand(time(0));
	giving_value();
	for (int i = 0; i < 8; i++) {
		for (int z = 0; z < 8; z++) {
			cout << n[i][z]<<"    ";
		}
	}
	playGame();
}
