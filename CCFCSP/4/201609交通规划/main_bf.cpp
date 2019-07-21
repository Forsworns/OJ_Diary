#pragma warning (disable:4996)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

const int MAXN = 10005;
const int MAXM = 100005;
const int MAXC = 1005;

// ����С��������ʱ������·�ϵı���ѡ
struct Edge {
	int from, to;
	int cost;
	Edge(int f, int t, int c) : from(f), to(t), cost(c) {}
};

vector<Edge> edges;
// vector<Edge> edges[MAXN];// Ӧ�øĳ��������Ҫ��from/toȥ���ֱ�
int dist[MAXN];
int pre[MAXN]; // ǰ�����

int n, m; // ����������

int query(int from, int to) { // ���ﲻ�ԣ���������ж�����ͬ���ȵ�ֱ������
	for (auto x : edges) {
		if (x.from==from && x.to==to) {
			return x.cost;
		}
	}
}

void relax(int from,int to,int cost) {
	if (dist[to] > dist[from] + cost) {
		dist[to] = dist[from] + cost;
		pre[to] = from;
	}
	else if (dist[to] == dist[from] + cost) {
		int costOld = query(pre[to],to);
		if (cost < costOld) { // ���������ظ�ʹ�õıߴ�һЩ
			dist[to] = dist[from] + cost;
			pre[to] = from;
		}
	}
}

void initialize() {
	dist[1] = 0;
	for (int i = 2; i <= n;++i) {
		dist[i] = MAXC;
	}
}

void BF() {
	initialize();
	for (int i = 0; i < n; ++i) {
		for (auto e : edges) {
			relax(e.from, e.to, e.cost);
		}
	}
}

int main()
{
	freopen("test.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int from, to, cost;
		cin >> from >> to >> cost;
		edges.emplace_back(from, to, cost);
		edges.emplace_back(to, from, cost);
	}
	
	int ans = 0;
	BF();
	
	/*for (auto x : edges) { // ��������⣬ͬ������Ϊ��������ֱ���ж�����ͬ�ı�����
		if (x.from == pre[x.to]) {
			ans += x.cost;
		}
	}*/
	
	for (int i = 1; i <= n; ++i){
		ans += (dist[i]-dist[pre[i]]);
	}
	
	cout << ans;
	return 0;
}

