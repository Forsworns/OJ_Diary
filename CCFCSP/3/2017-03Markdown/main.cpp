#pragma warning(disable:4996) 
#include <iostream>
#include <string>
#include <map> 
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>

using namespace std;

string line;

bool isSpaceLine() {
	return line == "";
}

string dealWithEm(string input) {
	string output="";
	bool inEm = false;

	for (auto x:input) {
		if (!inEm && x=='_') {
			output.append("<em>");
			inEm = true;
		}
		else if(inEm && x=='_') {
			output.append("</em>");
			inEm = false;
		}
		else {
			output.push_back(x);
		}
	}

	return output;
}

string dealWithLink(string input) {
	string output = "";
	bool inText=false;
	bool inLink=false;
	
	string text;
	string link;

	for (auto x:input) {
		if (!inText && x == '[') {
			text = "";
			inText = true;
		}
		else if (inText && x == ']') {
			
			inText = false;
		}
		else if (inText) {
			text.push_back(x);
		}
		else if (inLink && x == '(') {
			link = "";
			inLink = true;
		}
		else if (inLink && x == ')') {
			output.append("<a href=\"");
			output.append(link);
			output.append("\">");
			output.append(text);
			output.append("</a>");
			inLink = false;
		}
		else if(inLink) {
			link.push_back(x);
		}
		else {
			output.push_back(x);
		}
	}

	return output;
}

int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);

	while (getline(cin,line)) {
		if (isSpaceLine()) {
			continue;
		}
		else if (line[0]=='#') {
			string output = "";
			int i, count = 1;
			for (i = 1; i < line.length(); ++i) {
				if (line[i] == '#') {
					count++;
				}
				else if (line[i]!=' ') {
					break;
				}
			}			
			output.append("<h");
			output.push_back(count + '0');
			output.push_back('>');
			output.append(line.substr(i,line.length()-i));
			output.append("</h");
			output.push_back(count + '0');
			output.push_back('>');
			output = dealWithLink(output);
			output = dealWithEm(output);
			cout << output << endl;
		}
		else if(line[0]=='*') {
			cout << "<ul>" << endl;

			bool succ = true;
			while (succ && !isSpaceLine()) {
				succ = false;
				string output = "<li>";
				int i;
				for (i = 1; i < line.length(); ++i) {
					if (line[i] != ' ') {
						break;
					}
				}
				output.append(line.substr(i, line.length() - i));
				output.append("</li>");
				output = dealWithLink(output);
				output = dealWithEm(output);
				cout << output << endl;
				if (getline(cin, line)) {
					succ = true;
				}
			}
			
			cout << "</ul>" << endl;
		}
		else {
			cout << "<p>";
			string output = line;
			bool succ = false;
			if (getline(cin, line)) {
				succ = true;
			}
			while (succ && !isSpaceLine()) {
				succ = false;
				cout << output << endl;
				output = line;
				if (getline(cin, line)) {
					succ = true;
				}
			}
			output = dealWithLink(output);
			output = dealWithEm(output);
			cout << output << "</p>" << endl;
		}
	}

	return 0;
}
