#pragma warning (disable:4996)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

#define MAX_M 100005
#define MAX_N 50005

struct Edge {
	int from, to, time;
	Edge() :from(0), to(0), time(0) {}
};

Edge edges[MAX_M];
int n, m, root;

int parent[MAX_N];
int ranks[MAX_N];
void initSet() {
	for (int i = 0; i < n; ++i) {
		parent[i] = i;
		ranks[i] = 0;
	}
}

int find(int x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = find(parent[x]);
}

bool sameRoot(int x, int y) {
	return find(x) == find(y);
}

void unit(int x, int y) {
	x = find(x);
	y = find(y); // 注意对父节点操作
	if (x == y) {
		return;
	}
	if (ranks[x] < ranks[y]) {
		parent[x] = y;
	}
	else {
		parent[y] = x;
		if (ranks[x] == ranks[y]) {
			ranks[x]++;
		}
	}
}

typedef long long ll;
ll kruskal() {
	initSet();
	sort(edges, edges + m, [](Edge x, Edge y) {return x.time < y.time; });
	ll result;
	for (int i = 0; i < m; ++i) {
		if (sameRoot(edges[i].from, edges[i].to)) {
			continue;
		}
		else {
			unit(edges[i].from, edges[i].to);
			result = edges[i].time;
		}
	}
	return result;
}

int main()
{
	freopen("test.txt", "r", stdin);
	cin >> n >> m >> root;
	for (int i = 0; i < m; ++i) {
		cin >> edges[i].from >> edges[i].to >> edges[i].time;
	}
	cout << kruskal();
	return 0;
}
