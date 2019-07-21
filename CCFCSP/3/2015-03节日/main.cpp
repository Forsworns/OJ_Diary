#pragma warning(disable:4996) 
#include <iostream>
#include <string>
#include <map> 
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>

using namespace std;

const int daysNormal[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
const int daysLeep[] = { 31,29,31,30,31,30,31,31,30,31,30,31 };

bool isLeep(int year) {
	return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
}

bool verify(int year, int month, int day) {
	if (isLeep(year)) {
		return day <= daysLeep[month - 1];
	}
	else {
		return day <= daysNormal[month - 1];
	}
}

void print(int year,int month,int day) {
	bool exist = false;
	exist = verify(year, month, day);
	if (exist) {
		cout << year << "/";
		cout.setf(ios::right);
		cout.width(2);
		cout.fill('0');
		cout << month;
		cout.width(1); 
		cout << "/";
		cout.width(2);
		cout<< day << endl;
	}
	else {
		cout.width(4);
		cout << "none" << endl;
	}
}

int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int a, b, c;
	int y1, y2;
	cin >> a >> b >> c >> y1 >> y2;

	int day;
	int startRecord[201]; // 每一年的a月的第一天是星期几
	// 先求1850年的, 1850/01/01 是星期二
	startRecord[0] = 2;
	for (int month = 1; month < a;++month) { // 1850年的a月开头是算小于a的所有月份
		startRecord[0] = (startRecord[0] + daysNormal[month - 1]) % 7;
		if (startRecord[0] == 0) {
			startRecord[0] = 7; // 对星期日需要进行特殊处理
		}
	}
	for (int year = 1851; year <= 2050;++year) {
		if (isLeep(year - 1)) {
			startRecord[year - 1850] = (startRecord[year - 1851] + 366) % 7;
		}
		else {
			startRecord[year - 1850] = (startRecord[year - 1851] + 365) % 7;
		}
		if (startRecord[year - 1850] == 0) {
			startRecord[year - 1850] = 7; // 对星期日需要进行特殊处理
		}
	}

	// 对每年的a月进行遍历
	for (int year = y1; year <= y2;++year) {
		day = (b - 1) * 7 + (c - startRecord[year -1850]+1); // 注意要加一，因为如果月初本身是一号
		print(year, a, day);
	}
	return 0;
}
