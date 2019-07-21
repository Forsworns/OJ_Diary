#pragma warning (disable:4996)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

// 1000位
#define MAX_N 1005
#define STATES 6  
#define CONST 1000000007
// 六个状态时因为，从高位向低位写，由于2在3前，0在1前，0不能为最高位，于是可能出现下面六种情况
// 222222 这种，那么只用了2，其它都没有用
// 用了2，0，剩下1，3
// 用了2，3，剩下0，1
// 用了2，0，1，剩下3
// 用了2，0，3，剩下1
// 以及全部用了满足题意的数字

typedef long long ll;

ll dp[MAX_N][STATES]; // dp[i][j]，用了i位时j状态的数字数目


int main()
{
	ll n;
	cin >> n;
	for (ll i = 0; i < n; ++i) {
		dp[0][i] = 0;
	}
	//  不要用memset，过不了
	for (ll i = 0; i < n; ++i) {
		ll j = i - 1;
		dp[i][0] = 1;
		dp[i][1] = (dp[j][1] * 2 + dp[j][0]) % CONST;
		dp[i][2] = (dp[j][2] + dp[j][0]) % CONST; // 对状态一的数字后面只能补3，不能补2，否则违反规则
		dp[i][3] = (dp[j][3] * 2 + dp[j][1]) % CONST;
		dp[i][4] = (dp[j][4] * 2 + dp[j][1] + dp[j][2]) % CONST;
		dp[i][5] = (dp[j][5] * 2 + dp[j][4] + dp[j][3]) % CONST; //状态五的数字可以补1或3，所以要乘2
	}
	cout << dp[n - 1][5];
	return 0;
}
