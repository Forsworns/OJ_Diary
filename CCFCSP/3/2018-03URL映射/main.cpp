#pragma warning(disable:4996) 
#include <iostream>
#include <string>
#include <map> 
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>

using namespace std;

void split(const char &delimiter, const string &input, vector<string> &output) {
	string slice="";
	for (auto x : input) {
		if (x==delimiter) {
			output.push_back(slice);
			slice = "";
		}
		else {
			slice.push_back(x);
		}
	}
	output.push_back(slice);
}

bool isValid(const vector<string> &inputVec, const vector<string> &ruleVec, vector<string> &parameters) {
	bool valid = false;
	for (int i = 0; i < inputVec.size(); ++i) {
		if (inputVec[i] != ruleVec[i]) {
			if (ruleVec[i][0] != '<') { // 二者字面不相同，且规则中的不是通配符
				break;
			}
			else if (ruleVec[i][1] == 'i') { // 匹配整数，注意去0
				string integer = "";
				bool start = true, notNum = false;
				for (int j = 0; j < inputVec[i].size();++j) {
					if (inputVec[i][j] < '0' || inputVec[i][j] > '9') {
						notNum = true;
						break;
					}
					else if (start && inputVec[i][j]=='0') {
						continue;
					}
					else {
						start = false;
						integer.push_back(inputVec[i][j]);
					}
				}
				if (notNum) {
					break;
				}
				parameters.push_back(integer);
			}
			else if (ruleVec[i][1] == 's') { // 匹配字符串或路径
				string str = inputVec[i];
				parameters.push_back(str);
				continue;
			}
			else if (ruleVec[i][1] == 'p') {
				string path = inputVec[i];
				parameters.push_back(path);
				valid = true;
				break;
			}
		}
		else if (i == inputVec.size() - 1) {
			valid = true;
		}
	}
	return valid;
}

int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int n, m;
	cin >> n >> m;
	vector<pair<string, string>> rules;
	for (int i = 0; i < n; ++i) {
		string p, r;
		cin >> p >> r;
		rules.emplace_back(make_pair(r, p));
	}

	for (int i = 0; i < m; ++i) {
		string input;
		bool valid = false;
		string ruleName;
		vector<string> parameters;
		cin >> input;

		for (auto rule:rules) {
			parameters.clear();
			vector<string> ruleVec;
			vector<string> inputVec;
			ruleName = rule.first;
			split('/', rule.second, ruleVec);
			split('/', input, inputVec);
			if (inputVec.size()==ruleVec.size()) {
				valid = isValid(inputVec, ruleVec, parameters);
				if (valid) {
					break;
				}
			}
			else if (inputVec.size() > ruleVec.size()) {
				//只可能出现路径匹配
				if (ruleVec.at(ruleVec.size() - 1)!="" && ruleVec.at(ruleVec.size()-1).at(1)=='p') { // 最后一个是路径
					vector<string> ruleTemp;
					vector<string> inputTemp;
					string path = "";
					for (int j = 0; j < ruleVec.size() - 1;++j) {
						ruleTemp.push_back(ruleVec[j]);
					}
					for (int j = 0; j < ruleVec.size() - 1; ++j) {
						inputTemp.push_back(inputVec[j]);
					}
					path.append(inputVec[ruleVec.size()-1]);
					for (int j = ruleVec.size(); j < inputVec.size();++j) {
						path.push_back('/');
						path.append(inputVec[j]);
					}
					// 此时转化为等长的判断
					valid = isValid(inputTemp,ruleTemp, parameters);
					if (valid) {
						parameters.push_back(path);
						break;
					}
				}
			}
		}
		
		if (valid) {
			cout << "" << ruleName;
			for (auto x:parameters) {
				cout << " " << x;
			}
			cout << endl;
		}
		else {
			cout << "404" << endl;
		}
	}
	return 0;
}
