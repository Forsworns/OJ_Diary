#pragma warning (disable:4996)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

//原来的dist[j]不满足约束条件，也就是dist[j] - dist[i] > k，更新后一定满足约束条件，更新后的dist[j]就满足dist[j] - dist[i]≤k，
//dist[i]就相当xi，也就是xj - xi≤k！而且这个更新后得到的序列是字典序最大的，为什么 ? 
//很简单，因为当dist[j] - dist[i] > k时让dist[j] - dist[i]≤k, dist[j]可以更新到dist[i] + k - n，n可以取任意正整数都满足条件，但这里的更新就相当于n取零，使得dist[j]有最大值。
//然而这道题要求字典序最小，怎么办呢 ? 很简单，我们把所有的不等式都变成xi - xj≥k，反过来求最长路即可

// 差分思路，同时不是转最短路，而是转化成最长路（因为要最小字典序
#define MAX_N 305
#define INFINITE 10000000

int dist[MAX_N]; // 前i项a之和，也是单源最长路径；为了把和转换成差的形式
int b[MAX_N];
int n;
int route[MAX_N][MAX_N];

void relax(int u,int v, int uv) {
	if (dist[v] < dist[u] + uv) { // 这里是求最长路
		dist[v] = dist[u] + uv;
	}
}

bool BF() {
	for (int ite = 0; ite <= n; ++ite) {
		// 循环n次对每条边进行放松
		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j <= n; ++j) {
				if (route[i][j]!=INFINITE) {
					relax(i,j,route[i][j]);
				}
			}
		}
	}
	// 如果已经松弛过了，仍然不满足距离的关系，则必有负环
	for (int ite = 0; ite <= n; ++ite) {
		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j <= n; ++j) {
				if (route[i][j] != INFINITE) {
					if (dist[j] < dist[i] + route[i][j]) {
						return false;
					}
				}
			}
		}
	}

	return true;
}

int main()
{
	freopen("test.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i <= n;++i) {
		for (int j = 0; j <= n; ++j) {
			route[i][j] = INFINITE;
		}
	}
	// 到创建的虚拟结点均为0
	for (int i = 0; i <= n; ++i) {
		dist[i] = 0;
	}
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
	}
	
	// 设置图中边的长度
	for (int i = 0; i < n; ++i) {
		route[i][i + 1] = 1;
	}
	for (int i = 0; i <= n; ++i) {
		route[0][i] = 0;
	}
	route[0][2] = 2*b[1]; route[2][0] = -(2*b[1] + 1);
	route[n-2][n] = 2*b[n]; route[n][n-2] = -(2*b[n] + 1);
	for (int i = 2; i <= n - 1; ++i) {
		route[i-2][i+1] = 3 * b[i]; route[i + 1][i - 2] = -(3 * b[i] + 2);
	}

	BF();
	for (int i = 1; i <= n;++i) {
		cout << dist[i] - dist[i - 1] << " ";
	}
	return 0;
}
