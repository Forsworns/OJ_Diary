#pragma warning(disable:4996) 
#include <iostream>
#include <string>
#include <map> 
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>

using namespace std;

// ���仯������˼·��ʹ��һ��״̬��������Ƿ���ʹ���״̬��

int chess[4][4];
int unvisited;
int states[222222223];
long long state;

bool check(long long now) {
	int x1[9], x2[9], y1[9], y2[9]; // ��¼alice��bob������λ��
	int tot = 0; // �ո���
	int a, b, x, y;
	a = b = 0; // alice��bob��������
	for (int i = 1; i < 4; i++) {
		for (int j = 1; j < 4; j++) { 
			if (chess[i][j] == 0) { 
				tot++; 
			}
			else if (chess[i][j] == 1) { // ��alice������ 
				a++;             
				x1[a] = i; 
				y1[a] = j; 
			}
			else { // ��bob������
				b++;             
				x2[b] = i; 
				y2[b] = j; 
			}
		}
	}
	if (a < 3 && b < 3) { return false; } // ��ʱ���������˻�ʤ
	if (a >= 3) { // alice���ܻ�ʤ
		for (int i = 1; i < a; i++) {
			for (int j = i + 1; j <= a; j++) { 
				x = x1[j] * 2 - x1[i];          
				y = y1[j] * 2 - y1[i];          
				if (x > 0 && x < 4 && y>0 && y < 4) {
					if (chess[x][y] == 1) {
						states[now] = tot + 1;
						return true;
					}
				} 
			}
		}
	}

	if (b >= 3) { // bob���ܻ�ʤ
		for (int i = 1; i < b; i++) {
			for (int j = i + 1; j <= b; j++) {
				x = x2[j] * 2 - x2[i];
				y = y2[j] * 2 - y2[i];
				if (x > 0 && x < 4 && y>0 && y < 4) {
					if (chess[x][y] == 2) { 
						states[now] = -(tot + 1);              
						return true; 
					}
				}
			}
		}                                      
	}
	if (tot == 0) { 
		states[now] = 0;    
		return true; 
	}   
	return false;
}

long long calculateAfter() { // �������Ӻ��״̬���
	long long after = 0;
	for (int i = 1; i < 4; ++i) {
		for (int j = 1; j < 4; ++j) {
			after = chess[i][j] + after * 10;
		}
	}
	return after;
}

void dfs(long long now,int who) {
	long long after;
	if (states[now] != unvisited) { // �Ѿ����ʹ��ˣ�����
		return;
	}
	if (check(now)) {
		return;
	}
	for (int i = 1; i < 4; ++i) {
		for (int j = 1; j < 4; ++j) {
			if (chess[i][j] == 0) {
				chess[i][j] = who;// ��who��ʾ������� alice��1�� �� bob��2��
				after = calculateAfter(); // ������һ���ñ����ĸ�
				dfs(after, 3 - who); // ���Է�ִ�ӣ�������3-who
				if (states[now]==unvisited) {
					states[now] = states[after];
				}
				if (who == 1 && states[after] > states[now]) { // alice���ߣ���һ����������Ļ�����䵽��ǰ
					states[now] = states[after];
				}
				if (who == 2 && states[after] < states[now]) { // bob���ߣ���һ���õ��ķ�����С�Ļ������ǰ
					states[now] = states[after];
				}
				chess[i][j] = 0;
			}
		}
	}
}

int main(int argc, char** argv) {
	freopen("test.txt", "r", stdin);
	int T;
	cin >> T;

	memset(states, 127, sizeof(states)); // ��״̬ȫ����Ϊ 127 = 2^8-1���������µ� 11111111
	unvisited = states[1];
	for (int t = 0; t < T; ++t) {
		state = 0;
		memset(chess, 0, sizeof(chess));
		int answer = 0;
		for (int i = 1; i < 4; ++i) {
			for (int j = 1; j < 4; ++j) {
				cin >> chess[i][j];
				state = chess[i][j] + state * 10;// ��һ��ʮ����������ʾ״̬
			}
		}
		dfs(state, 1);
		answer = states[state];
		cout << answer << endl;
	}
}
