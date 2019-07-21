#pragma warning (disable:4996)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

#define MAXN 1005
#define MAXM 1000005

struct Edge {
	int from, to;
	int cost;
	Edge(int f,int t,int c):from(f),to(t),cost(c) {}
	Edge():from(0), to(0), cost(0) {}
};

int n, m; // ����������

Edge edges[MAXM];

// ���鼯
int parent[MAXN];
int ranks[MAXN];

void initSet() {
	for (int i = 1; i <= n;++i) {
		parent[i] = i;
		ranks[i] = 0;
	}
}

int find(int ver) { // Ѱ�Ҹ���û�ҵ������ϻ��ݡ������ѹ����֧�������ڵ㲻�Ǹ��Ķ��Ƶ����ϡ�
	return ver == parent[ver] ? ver : parent[ver] = find(parent[ver]);
}

void unit(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) { //ͬһ�ڵ㲻�ٺϲ�
		return;
	}
	if (ranks[x]<ranks[y]) { // ��rank�����Ϊparent
		parent[x] = y;
	}
	else {
		parent[y] = x;
		if (ranks[x] == ranks[y]) { // ���rank��ͬ������Ҫ��һ
			ranks[x]++;
		}
	}
}

bool sameRoot(int x, int y) {
	return find(x) == find(y);
}

long long kruskal() {
	initSet();
	sort(edges, edges + m, [](Edge x, Edge y){return x.cost < y.cost; }); // ��������
 	long long result = 0;
	for (int i = 0; i < m;++i) {
		auto e = edges[i];
		if (sameRoot(e.from, e.to)) {
			continue; // ����Ƿ��Ѿ�����ͨ�����Ѿ���ͨ�����������
		}
		unit(e.from, e.to);
		result += e.cost;
	}
	return result;
}


int main()
{
	freopen("test.txt","r",stdin);
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int from, to, cost;
		cin >> from >> to >> cost;
		edges[i] = Edge(from,to,cost);
	}

	long long answer = kruskal();
	cout << answer;
	return 0;
}
