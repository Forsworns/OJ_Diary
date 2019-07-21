#pragma warning(disable:4996) 
#include <iostream>
#include <string>
#include <map> 
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>

using namespace std;


void fill(int x,int y,char filled, char** canvas,int width, int height,bool** visited) {
	if (x<0 || y<0 || x>=width || y>=height || visited[x][y]) {
		return;
	}
	else {
		if (canvas[x][y] != '+' && canvas[x][y] != '-' && canvas[x][y] != '|') {
			canvas[x][y] = filled;
			visited[x][y] = true;
			fill(x + 1, y, filled, canvas, width, height, visited);
			fill(x - 1, y, filled, canvas, width, height, visited);
			fill(x, y + 1, filled, canvas, width, height, visited);
			fill(x, y - 1, filled, canvas, width, height, visited);
		}
	}
}

int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int width, height;
	int nums;
	cin >> width >> height >> nums;
	char** canvas = new char*[width];
	for (int i = 0; i < width;++i) {
		canvas[i] = new char[height];
	}
	for (int i = 0; i < width; ++i) {
		for (int j = 0; j < height; ++j) {
			canvas[i][j] = '.';
		}
	}
	bool** visited = new bool*[width];
	for (int i = 0; i < width; ++i) {
		visited[i] = new bool[height]();
	}

	for (int i = 0; i < nums;++i) {
		int type;
		cin >> type;
		if (type == 0) {
			int x1, x2, y1, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			if (x1==x2) {
				// »­ÊúÏß
				for (int j = y1; j <= y2; ++j) {
					canvas[x1][j] = (canvas[x1][j] == '-' ? '+' : '|');
				}
			}
			else {
				// »­ºáÏß
				for (int j = x1; j <= x2; ++j) {
					canvas[j][y1] = (canvas[j][y1] == '|' ? '+' : '-');
				}
			}
		}
		else {
			for (int i = 0; i < width; ++i) {
				for (int j = 0; j < height; ++j) {
					visited[i][j] = false;
				}
			}
			int x, y;
			char filled;
			cin >> x >> y >> filled;
			fill(x, y, filled, canvas,width,height,visited);
		}
	}
	for (int i = height - 1; i >= 0;--i) {
		for (int j = 0; j < width; ++j) {
			cout << canvas[j][i];
		}
		cout << endl;
	}
	return 0;
}
