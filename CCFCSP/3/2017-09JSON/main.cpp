#pragma warning(disable:4996) 
#include <iostream>
#include <string>
#include <map> 
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>

using namespace std;

struct Node {
	string key;
	string content;
	map<string,Node*> children;
	Node* parent;
	Node() :key(""),content(""), parent(nullptr) {}
	Node(string k, string c) :key(k), content(c), parent(nullptr) {}
	Node(string k, Node *p) :key(k), parent(p) {}
};

int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int m, n;
	Node *root = new Node(), *now = root;
	string input, key, content;
	bool inKey = false, inContent = false, isTransformed = false, inMid = false;
	cin >> m >> n;
	for (int i = 0; i < m; ++i) {
		getline(cin,input);
		for (auto x : input) {
			if (isTransformed) {
				if (inKey) {
					key.push_back(x);
					isTransformed = false;
				}
				else {
					content.push_back(x);
					isTransformed = false;
				}
			}
			else if(inKey) {
				if (x=='\\') {
					isTransformed = true;
				}
				else if (x=='\"') {
					inKey = false;
					inMid = true;
				}
				else {
					key.push_back(x);
				}
			}
			else if (inContent) {
				if (x == '\\') {
					isTransformed = true;
				}
				else if (x == '\"') {
					inContent = false; 
					Node* child = new Node(key, content);
					now->children.emplace(make_pair(key, child));
					key = "";
					content = "";
					inMid = false;
				}
				else {
					content.push_back(x);
				}
			}
			else if (x=='\"') {
				if (inMid) {
					inContent = true;
				}
				else {
					inKey = true;
				}
			}
			else if (x=='{') {
				if (key.length() != 0) {
					Node* child = new Node(key,now);
					now->children.emplace(make_pair(key,child));
					now = now->children.at(key);
					key = "";
					content = "";
					inMid = false;
				}
			}
			else if (x=='}') {
				if (now->parent != nullptr) {
					now = now->parent;
				}
			}
		}
	}
	
	cin.get();
	for (int i = 0; i < n;++i) {
		string input, key = "";
		now = root;
		cin >> input;
		for (auto x:input) {
			if (x == '.') {
				if (!now->children.count(key)) {
					cout << "NOTEXIST" << endl;
				}
				else {
					now = now->children.at(key);
					key = "";
				}
			}
			else {
				key.push_back(x);
			}
		}

		if (!now->children.count(key)) {
			cout << "NOTEXIST" << endl;
		}
		else {
			now = now->children.at(key);
			if (now->children.empty()) {
				cout << "STRING " << now->content << endl;
			}
			else {
				cout << "OBJECT" << endl;
			}
		}

	}

	return 0;
}
