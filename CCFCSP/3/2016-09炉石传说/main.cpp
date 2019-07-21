#pragma warning(disable:4996) 
#include <iostream>
#include <string>
#include <map> 
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>

using namespace std;

struct Summon {
	int attack;
	int health;
	Summon(int a, int h) : attack(a),health(h){}
	Summon() : attack(0), health(0) {}
};

int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int round;
	bool turn=true; // ture for player1, false for player2
	vector<Summon> summons1;
	vector<Summon> summons2;
	summons1.emplace_back(Summon(0, 30));
	summons2.emplace_back(Summon(0, 30));
	auto it1 = summons1.begin();
	auto it2 = summons2.begin();
	int winner = 0; // 1 for player1, -1 for player2
	cin >> round;
	for (int i = 0; i < round;++i) {
		string instruction;
		cin >> instruction;
		if (instruction=="summon") {
			int pos, attack, health;
			cin >> pos >> attack >> health;
			if (turn) {
				summons1.insert(it1 + pos, Summon(attack, health));
				it1 = summons1.begin(); // remember to maintain the iterator, since the vector has changed
			}
			else {
				summons2.insert(it2 + pos, Summon(attack, health));
				it2 = summons2.begin();
			}
		}
		else if (instruction == "attack") {
			int attacker, defender;
			cin >> attacker >> defender;
			if (turn) {
				summons2[defender].health -= summons1[attacker].attack;
				summons1[attacker].health -= summons1[attacker].attack;
				if (summons1[attacker].health <= 0) {
					summons1.erase(it1+attacker);
					it1 = summons1.begin();
				}
				if (summons2[defender].health <= 0) {
					summons2.erase(it2 + defender);
					it2 = summons2.begin();
				}
			}
			else {
				summons1[defender].health -= summons2[attacker].attack;
				summons2[attacker].health -= summons2[attacker].attack;
				if (summons1[defender].health <= 0) {
					summons1.erase(it1 + defender);
					it1 = summons1.begin();
				}
				if (summons2[attacker].health <= 0) {
					summons2.erase(it2 + attacker);
					it2 = summons2.begin();
				}
			}
		}
		else {
			turn = !turn;
		}
	}
	winner = summons1[0].health <= 0 ? -1: 0;
	winner = summons2[0].health <= 0 ? 1 : winner;
	int summons1Num = 0, summons2Num = 0;
	for (auto it = it1 + 1; it < summons1.end(); ++it) {
		if (it->health > 0) {
			summons1Num++;
		}
		else {
			continue;
		}
	}
	for (auto it = it2 + 1; it < summons2.end(); ++it) {
		if (it->health > 0) {
			summons2Num++;
		}
		else {
			continue;
		}
	}
	cout << winner << endl;
	cout << summons1[0].health << endl;
	cout << summons1Num;
	for (auto it = it1 + 1; it < summons1.end(); ++it) {
		if (it->health > 0) {
			cout << " " << it->health;
		}
		else {
			continue;
		}
	}
	cout << endl;
	cout << summons2[0].health << endl;
	cout << summons2Num;
	for (auto it = it2 + 1; it < summons2.end(); ++it) {
		if (it->health > 0) {
			cout << " " << it->health;
		}
		else {
			continue;
		}
	}
	cout << endl;
	return 0;
}
