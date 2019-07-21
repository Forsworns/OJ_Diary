#pragma warning(disable:4996) 
#include <iostream>
#include <string>
#include <map> 
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>

using namespace std;


int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int templateLength = 0, variableNum = 0;
	cin >> templateLength >> variableNum;
	string *templates = new string[templateLength];
	map<string, string> variables;
	cin.get();
	for (int i = 0; i < templateLength;++i) {
		getline(cin, templates[i]);
	}
	for (int i = 0; i < variableNum;++i) {
		string temp1,temp2;
		cin >> temp1>>temp2;
		temp2 = temp2.substr(1, temp2.length() - 1);
		variables.emplace(make_pair(temp1,temp2));
	}
	for (int i = 0; i < templateLength;++i) {
		string replaced="";
		string now = templates[i];
		bool hasFind = false;
		string key = "";
		for (int j = 0; j < now.length();++j) { // 最后六个字符不可能是模板变量
			if (!hasFind) {
				if (j< now.length()-2 && now[j]=='{' && now[j + 1] == '{' && now[j + 2] == ' ') {
					hasFind = true;
					j += 2;
				}
				else {
					replaced += now[j];
				}
			}
			else {
				if (now[j] == ' ' && now[j + 1] == '}' && now[j + 2] == '}') {
					if (variables.count(key)) {
						replaced += variables[key];
					}
					hasFind = false;
					j += 2;
				}
				else {
					key += now[j];
				}
			}
		}
		cout << replaced << endl;
	}

	return 0;
}
