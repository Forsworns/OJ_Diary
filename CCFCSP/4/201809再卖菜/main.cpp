#pragma warning (disable:4996)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

//ԭ����dist[j]������Լ��������Ҳ����dist[j] - dist[i] > k�����º�һ������Լ�����������º��dist[j]������dist[j] - dist[i]��k��
//dist[i]���൱xi��Ҳ����xj - xi��k������������º�õ����������ֵ������ģ�Ϊʲô ? 
//�ܼ򵥣���Ϊ��dist[j] - dist[i] > kʱ��dist[j] - dist[i]��k, dist[j]���Ը��µ�dist[i] + k - n��n����ȡ����������������������������ĸ��¾��൱��nȡ�㣬ʹ��dist[j]�����ֵ��
//Ȼ�������Ҫ���ֵ�����С����ô���� ? �ܼ򵥣����ǰ����еĲ���ʽ�����xi - xj��k�����������·����

// ���˼·��ͬʱ����ת���·������ת�����·����ΪҪ��С�ֵ���
#define MAX_N 305
#define INFINITE 10000000

int dist[MAX_N]; // ǰi��a֮�ͣ�Ҳ�ǵ�Դ�·����Ϊ�˰Ѻ�ת���ɲ����ʽ
int b[MAX_N];
int n;
int route[MAX_N][MAX_N];

void relax(int u,int v, int uv) {
	if (dist[v] < dist[u] + uv) { // ���������·
		dist[v] = dist[u] + uv;
	}
}

bool BF() {
	for (int ite = 0; ite <= n; ++ite) {
		// ѭ��n�ζ�ÿ���߽��з���
		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j <= n; ++j) {
				if (route[i][j]!=INFINITE) {
					relax(i,j,route[i][j]);
				}
			}
		}
	}
	// ����Ѿ��ɳڹ��ˣ���Ȼ���������Ĺ�ϵ������и���
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
	// ���������������Ϊ0
	for (int i = 0; i <= n; ++i) {
		dist[i] = 0;
	}
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
	}
	
	// ����ͼ�бߵĳ���
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
