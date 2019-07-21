#pragma warning (disable:4996)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>

using namespace std;

struct Pos {
	int x, y, t;
	Pos(int x,int y, int t):x(x),y(y),t(t) {}
};

const int MAXN = 105;
const int MAXM = 105;
const int MAXT = 1000;

int n,m,dangerNum;
int totalTime = MAXT;

int dangerFrom[MAXN][MAXM];
int dangerTo[MAXN][MAXM] = { 0 };
bool visited[MAXN][MAXM][MAXT] = { 0 };
int moveX[] = { 0,0,1,-1 };
int moveY[] = { 1,-1,0,0 };
vector<int> probableAns;


void bfs(int row,int col, int t) {
	queue<Pos> q;
	q.emplace(row,col,t);
	while (!q.empty()) {
		Pos now = q.front();
		q.pop();
		
		row = now.x;
		col = now.y;
		t = now.t;

		if (row<1 || row>n || col<1 || col>m) {
			continue;
		}
		if (visited[row][col][t]) {
			continue;
		}
		visited[row][col][t] = true;
		if (!probableAns.empty() && t >= probableAns[0]) { // 超过已有的第一个时间就不用跑了，已经不可能是最优的了
			continue;
		}
		if (t >= dangerFrom[row][col] && t <= dangerTo[row][col]) {
			continue;
		}
		if (row == n && col == m) {//到了终点
			probableAns.push_back(t);
			continue;
		}
		for (int i = 0; i < 4; ++i) {
			q.emplace(row + moveX[i], col + moveY[i], t + 1);
		}
	}
}

int main()
{
	freopen("test.txt","r",stdin);
	cin >> n >> m >> dangerNum;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			dangerFrom[i][j] = MAXT;
		}
	}
	for (int i = 0; i < dangerNum; ++i) {
		int row, col, ta, tb;
		cin >> row >> col >> ta >> tb;
		dangerFrom[row][col] = ta;
		dangerTo[row][col] = tb;
	}
	bfs(1, 1, 0);
	for (auto x : probableAns) {
		totalTime = min(totalTime, x);
	}
	cout << totalTime;
	return 0;
}
