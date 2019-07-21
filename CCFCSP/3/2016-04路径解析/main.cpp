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
	string name;
	map<string,Node*> children;
	Node *parent;

	Node() {
		name = "";
		children = map<string,Node*>();
		parent = nullptr;
	}
	Node(string n,Node* p) {
		name = n;
		parent = p;
	}
};


int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	// 建立目录
	Node *root, *d1, *d2, *d3, *d4, *f1, *f2, *f3, *f4, *f5;
	root = new Node();
	d1 = new Node("d1",root);
	d2 = new Node("d2",root);
	d3 = new Node("d3",d2);
	d4 = new Node("d4",d2);
	f1 = new Node("f1",d1);
	f2 = new Node("f2",d1);
	f3 = new Node("f3",d3);
	f4 = new Node("f4",d2);
	f5 = new Node("f1",d4);
	root->children.emplace("d1",d1);
	root->children.emplace("d2",d2);
	d1->children.emplace("f1",f1);
	d1->children.emplace("f2",f2);
	d2->children.emplace("d3", d3);
	d2->children.emplace("d4", d4);
	d2->children.emplace("f4", f4);
	d3->children.emplace("f3", d3);
	d4->children.emplace("f1", f5);


	int nums = 0;
	cin >> nums;
	string pwd;
	cin >> pwd;
	// 确定当前目录
	Node *pwdNode = root;
	for (int i = 0; i < pwd.length(); i++) {
		string child = "";
		if (i < pwd.length() - 2) {
			child = pwd.substr(i + 1, 2);
			i += 2;
			pwdNode = pwdNode->children.at(child);
		}
	}

	string *paths = new string[nums];
	for (int i = 0; i < nums;++i) {
		cin >> paths[i];
	}

	for (int i = 0; i < nums;++i) {
		string output;
		Node *nodeNow;
		if (paths[i][0]=='/') { //绝对路径
			nodeNow = root;
			output = "/";
		}
		else { // 相对路径
			nodeNow = pwdNode;
			output = pwd + "/";
		}
		for (int j = 0; j < paths[i].length(); ++j) {
			if (paths[i][j] == '/') {
				continue;
			}
			else if (paths[i][j] == '.') {
				if (j < paths[i].length() - 1 && paths[i][j + 1] == '.' && nodeNow!=root) {//若是根目录，将不再返回
					nodeNow = nodeNow->parent;
					output.erase(output.end() - 3, output.end());
					j += 1;
				}
				else {
					continue;
				}
			}
			else {
				//cout<< "p is"<< nodeNow->name <<endl;

				nodeNow = nodeNow->children.at(paths[i].substr(j, 2));
				output.append(nodeNow->name + "/");
				j += 1;//之后出循环还要+1，所以等价于这个循环里加了2
			}
		}
		if (output.length()!=1) { output.erase(output.end() - 1, output.end()); } //不是根目录需要去除末尾多余的"/"
		cout << output << endl;
	}
	return 0;
}
