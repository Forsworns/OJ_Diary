#pragma warning (disable:4996)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

// 1000λ
#define MAX_N 1005
#define STATES 6  
#define CONST 1000000007
// ����״̬ʱ��Ϊ���Ӹ�λ���λд������2��3ǰ��0��1ǰ��0����Ϊ���λ�����ǿ��ܳ��������������
// 222222 ���֣���ôֻ����2��������û����
// ����2��0��ʣ��1��3
// ����2��3��ʣ��0��1
// ����2��0��1��ʣ��3
// ����2��0��3��ʣ��1
// �Լ�ȫ�������������������

typedef long long ll;

ll dp[MAX_N][STATES]; // dp[i][j]������iλʱj״̬��������Ŀ


int main()
{
	ll n;
	cin >> n;
	for (ll i = 0; i < n; ++i) {
		dp[0][i] = 0;
	}
	//  ��Ҫ��memset��������
	for (ll i = 0; i < n; ++i) {
		ll j = i - 1;
		dp[i][0] = 1;
		dp[i][1] = (dp[j][1] * 2 + dp[j][0]) % CONST;
		dp[i][2] = (dp[j][2] + dp[j][0]) % CONST; // ��״̬һ�����ֺ���ֻ�ܲ�3�����ܲ�2������Υ������
		dp[i][3] = (dp[j][3] * 2 + dp[j][1]) % CONST;
		dp[i][4] = (dp[j][4] * 2 + dp[j][1] + dp[j][2]) % CONST;
		dp[i][5] = (dp[j][5] * 2 + dp[j][4] + dp[j][3]) % CONST; //״̬������ֿ��Բ�1��3������Ҫ��2
	}
	cout << dp[n - 1][5];
	return 0;
}
