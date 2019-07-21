#pragma warning(disable:4996) 
#include <iostream>
#include <string>
#include <map> 
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>

using namespace std;

void splitNameRank(string temp, string &name, int &rank) {
	for (auto x : temp) {
		if (x >= '0' && x <= '9') {
			rank = x - '0';
		}
		else if (x != ':') {
			name.push_back(x);
		}
	}
}

int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);

	/*string line;
	while (getline(cin,line)) {
		
	}*/

	int priviledgeNum,roleNum,userNum,requireNum;
	map<string, int> priviledge; // priviledge with maximum -1 representing a no-rank one
	map<string, map<string,int>> roles;
	map<string, vector<string>> users;

	cin >> priviledgeNum; cin.get();
	for (int i = 0; i < priviledgeNum; ++i) {
		string temp;
		string priviledgeName = "";
		int priviledgeRank = -1;
		getline(cin, temp);
		splitNameRank(temp, priviledgeName, priviledgeRank);
		priviledge.emplace(make_pair(priviledgeName, priviledgeRank));
	}

	cin >> roleNum; cin.get();
	for (int i = 0; i < roleNum; ++i) {
		string roleName;
		int priviledgeNum;
		cin >> roleName >> priviledgeNum;
		roles.emplace(make_pair(roleName, map<string, int>()));
		for (int j = 0; j < priviledgeNum;++j) {
			string temp;
			string priviledgeName = "";
			int priviledgeRank = -1;
			cin >> temp;
			splitNameRank(temp, priviledgeName, priviledgeRank);
			roles.at(roleName).emplace(make_pair(priviledgeName, priviledgeRank));
		}
	}
	
	cin >> userNum; cin.get();
	for (int i = 0; i < userNum; ++i) {
		string userName, roleName;
		int roleNum;
		cin >> userName >> roleNum;
		users.emplace(userName, vector<string>());
		for (int j = 0; j < roleNum; ++j) {
			cin >> roleName;
			users.at(userName).emplace_back(roleName);
		}
	}
	
	cin >> requireNum; cin.get();
	for (int i = 0; i < requireNum; ++i) {
		string temp;
		string userName = "";
		string priviledgeName = "";
		int priviledgeRank = -1;
		cin >> userName >> temp;
		if (users.count(userName)==0) {
			cout << "false" << endl;
			continue;
		}
		splitNameRank(temp, priviledgeName, priviledgeRank);
		auto userRoles = users.at(userName);
		if (priviledgeRank == -1) {
			bool hasPriviledge = false;
			int rank = -1;
			for (auto x : userRoles) {
				if (roles.at(x).count(priviledgeName) && roles.at(x).at(priviledgeName) >= priviledgeRank) {
					hasPriviledge = true;
					rank = roles.at(x).at(priviledgeName);
				}
			}
			if (hasPriviledge) {
				if (rank==-1) {
					cout << "true" << endl;
				}
				else {
					cout << rank << endl;
				}
			}
			else {
				cout << "false" << endl;
			}
		}
		else {
			bool hasPriviledge = false;
			for (auto x : userRoles) {
				if (roles.at(x).count(priviledgeName) && roles.at(x).at(priviledgeName) >= priviledgeRank) {
					hasPriviledge = true;
				}
			}
			if (hasPriviledge) {
				cout << "true" << endl;
			}
			else {
				cout << "false" << endl;
			}
		}
	}
	return 0;
}
