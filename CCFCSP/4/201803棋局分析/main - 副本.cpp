#pragma warning(disable:4996) 
#include <iostream>
#include <string>
#include <map> 
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>

using namespace std;

// 记忆化搜索的思路，使用一个状态表来标记是否访问过该状态。

int chess[4][4];
int unvisited;
int states[20000];
long long state;

// 转换未三进制，因为区分状态的只有0/1/2三种，所以不必用十进制来区分状态，这里把之前的状态压缩成三进制
int turn(long long x, int scale) { 
	int re = 0;    
	int t[9];    
	for (int i = 0; i < 9; i++) { 
		t[i] = x % 10;        
		x = x / 10; 
	}    
	for (int i = 8; i >= 0; i--) { 
		re = re * scale + t[i]; 
	}    
	return re; 
}

#define turn(num) turn(num,3) 

bool check(long long now) {
	int x1[9], x2[9], y1[9], y2[9]; // 记录alice和bob的落子位置
	int tot = 0; // 空格数
	int a, b, x, y;
	a = b = 0; // alice和bob的落子数
	for (int i = 1; i < 4; i++) {
		for (int j = 1; j < 4; j++) { 
			if (chess[i][j] == 0) { 
				tot++; 
			}
			else if (chess[i][j] == 1) { // 是alice的落子 
				a++;             
				x1[a] = i; 
				y1[a] = j; 
			}
			else { // 是bob的落子
				b++;             
				x2[b] = i; 
				y2[b] = j; 
			}
		}
	}
	if (a < 3 && b < 3) { return false; } // 此时不可能有人获胜
	if (a >= 3) { // alice可能获胜
		for (int i = 1; i < a; i++) {
			for (int j = i + 1; j <= a; j++) { 
				x = x1[j] * 2 - x1[i];          
				y = y1[j] * 2 - y1[i];          
				if (x > 0 && x < 4 && y>0 && y < 4) {
					if (chess[x][y] == 1) {
						states[turn(now)] = tot + 1;
						return true;
					}
				} 
			}
		}
	}

	if (b >= 3) { // bob可能获胜
		for (int i = 1; i < b; i++) {
			for (int j = i + 1; j <= b; j++) {
				x = x2[j] * 2 - x2[i];
				y = y2[j] * 2 - y2[i];
				if (x > 0 && x < 4 && y>0 && y < 4) {
					if (chess[x][y] == 2) { 
						states[turn(now)] = -(tot + 1);              
						return true; 
					}
				}
			}
		}                                      
	}
	if (tot == 0) { 
		states[turn(now)] = 0;    
		return true; 
	}   
	return false;
}

long long calculateAfter() { // 计算落子后的状态编号
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
	if (states[turn(now)] != unvisited) { // 已经访问过了，返回
		return;
	}
	if (check(now)) {
		return;
	}
	for (int i = 1; i < 4; ++i) {
		for (int j = 1; j < 4; ++j) {
			if (chess[i][j] == 0) {
				chess[i][j] = who;// 填who表示这里会上 alice（1） 或 bob（2）
				after = calculateAfter(); // 计算下一个该遍历哪个
				dfs(after, 3 - who); // 换对方执子，所以是3-who
				if (states[turn(now)]==unvisited) {
					states[turn(now)] = states[turn(after)];
				}
				if (who == 1 && states[turn(after)] > states[turn(now)]) { // alice先走，下一步分数更大的话，填充到当前
					states[turn(now)] = states[turn(after)];
				}
				if (who == 2 && states[turn(after)] < states[turn(now)]) { // bob先走，下一步得到的分数更小的话，填到当前
					states[turn(now)] = states[turn(after)];
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

	memset(states, 127, sizeof(states)); // 将状态全部改为 127 = 2^8-1，二进制下的 11111111
	unvisited = states[1];
	for (int t = 0; t < T; ++t) {
		state = 0;
		memset(chess, 0, sizeof(chess));
		int answer = 0;
		for (int i = 1; i < 4; ++i) {
			for (int j = 1; j < 4; ++j) {
				cin >> chess[i][j];
				state = chess[i][j] + state * 10;// 用一个十进制数来表示状态
			}
		}
		dfs(state, 1);
		answer = states[turn(state)];
		cout << answer << endl;
	}
}
