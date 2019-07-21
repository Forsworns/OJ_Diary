#pragma warning(disable:4996) 
#include <iostream>
#include <string>
#include <map> 
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>

using namespace std;

const int DAYS_NORMAL[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
const int DAYS_LEEP[] = { 31,29,31,30,31,30,31,31,30,31,30,31 };

bool isLeep(int year) {
	return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
}

int startRecord[130][12]; // 每一年的每月的第一天是星期几

int weekday(int year, int month, int day) {
	int output = (startRecord[year - 1970][month - 1] + day - 1) % 7;
	if (output==0) {
		output = 7;
	}
	return output;
}

int str2int(const string &integer) {
	int output = 0;
	for (auto x:integer) {
		output = output * 10 + (x - '0');
	}
	return output;
}

string int2strWrapped(int integer) {
	string output = "";
	int digit = 0;
	while (integer > 0) {
		output.push_back(integer % 10 + '0');
		integer /= 10;
	}
	reverse(output.begin(), output.end());
	return output;
}

string int2str(int integer) {
	// 也可以这里不做特殊处理，之后单独输出，用cout.setw(2);cout.setfill('0');控制填充0
	string output = "";
	if (integer == 0) {
		output = "00";
	}
	else if (integer > 0 && integer < 10){
		output = "0";
		output.push_back(integer + '0');
	}
	else {
		output = int2strWrapped(integer);
	}
	return output;
}

// formated time yyyymmddHHMM
void formatedTime2Str(string &formated, const int &year, const int& month, const int &day, const int &hour, const int &minute) {
	formated.append(int2str(year));
	formated.append(int2str(month));
	formated.append(int2str(day));
	formated.append(int2str(hour));
	formated.append(int2str(minute));
}

void formatedStr2Time(const string &formated, int &year, int& month, int &day, int &hour, int &minute) {
	year = str2int(formated.substr(0, 4));
	month = str2int(formated.substr(4, 2));
	day = str2int(formated.substr(6, 2));
	hour = str2int(formated.substr(8, 2));
	minute = str2int(formated.substr(10, 2));
}


const bool MONTH = true;
const string MONTHS[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
const bool DAYOFWEEK = false;
const string WEEKDAYS[] = { "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" };


int getMonth(string monthStr) {
	for (int i = 0; i < 12; ++i) {
		if (MONTHS[i] == monthStr) {
			return i + 1;
		}
	}
}

int getWeekday(string weekdayStr) {
	for (int i = 0; i < 7; ++i) {
		if (WEEKDAYS[i] == weekdayStr) {
			return i + 1;
		}
	}
}

const int INFINITE_NEG = -10000;
const int INFINITE_POS = 10000;

void input(vector<pair<int,int>> &vec) {
	char dilimeter;
	int low, high;
	bool isLow = true;
	string temp = "";
	cin.get(dilimeter);
	while (dilimeter != ' ') {
		if (dilimeter == ',') {
			if (isLow) {
				low = str2int(temp);
			}
			high = str2int(temp);
			vec.emplace_back(low,high);
			low = INFINITE_NEG;
			high = INFINITE_POS;
			isLow = true;
			temp = "";
		}
		else if (dilimeter == '-') {
			low = str2int(temp);
			high = INFINITE_POS;
			isLow = false;
			temp = "";
		}
		else if (dilimeter == '*') {
			low = INFINITE_NEG;
			high = INFINITE_POS;
			vec.emplace_back(low, high);
			cin.get(dilimeter); // 这里要return，所以吃一个必然出现的空格
			return;
		}
		else {
			temp.push_back(dilimeter);
		}
		cin.get(dilimeter);
	}
	if (isLow) {
		low = str2int(temp);
		high = str2int(temp);
		vec.emplace_back(low, high);
	}
	else if (!isLow) {
		high = str2int(temp);
		vec.emplace_back(low, high);
	}
}

void input(vector<pair<int, int>> &vec, bool monthOrDay) {
	char dilimeter;
	int low, high;
	bool isLow = true;
	string temp = "";
	cin.get(dilimeter);
	while (dilimeter != ' ') {
		if (dilimeter == ',') {
			if (isLow) {
				if (temp[0]<'0' || temp[0]>'9') {
					if (monthOrDay) {
						low = getMonth(temp);
					}
					else {
						low = getWeekday(temp);
					}
				}
				else {
					low = str2int(temp);
				}
			}
			if (temp[0]<'0' || temp[0]>'9') {
				if (monthOrDay) {
					high = getMonth(temp);
				}
				else {
					high = getWeekday(temp);
				}
			}
			else {
				high = str2int(temp);
			}
			vec.emplace_back(low, high);
			low = INFINITE_NEG;
			high = INFINITE_POS;
			isLow = true;
			temp = "";
		}
		else if (dilimeter == '-') {
			if (temp[0]<'0' || temp[0]>'9') {
				if (monthOrDay) {
					low = getMonth(temp);
				}
				else {
					low = getWeekday(temp);
				}
			}
			else {
				low = str2int(temp);
			}
			high = INFINITE_POS;
			isLow = false;
			temp = "";
		}
		else if (dilimeter == '*') {
			low = INFINITE_NEG;
			high = INFINITE_POS;
			vec.emplace_back(low, high);
			cin.get(dilimeter); // 这里要return，所以吃一个必然出现的空格
			return;
		}
		else {
			temp.push_back(dilimeter);
		}
		cin.get(dilimeter);
	}
	if (isLow) {
		if (temp[0]<'0' || temp[0]>'9') {
			if (monthOrDay) {
				low = getMonth(temp);
			}
			else {
				low = getWeekday(temp);
			}
		}
		else {
			low = str2int(temp);
		}
		high = low;
		vec.emplace_back(low, high);
	}
	else {
		if (temp[0]<'0' || temp[0]>'9') {
			if (monthOrDay) {
				high = getMonth(temp);
			}
			else {
				high = getWeekday(temp);
			}
		}
		else {
			high = str2int(temp);
		}
		vec.emplace_back(low, high);
	}
	
}

int main(int argc, char** argv) {
	freopen("test.txt", "r", stdin);
	// 先做一个万年历
	// 先求1970年的, 1970/01/01 是星期四
	startRecord[0][0] = 4;
	// 先算1970年各月
	for (int month = 1; month < 12; ++month) { // 1850年的a月开头是算小于a的所有月份
		startRecord[0][month] = (startRecord[0][month - 1] + DAYS_NORMAL[month - 1]) % 7;
		if (startRecord[0][month] == 0) {
			startRecord[0][month] = 7; // 对星期日需要进行特殊处理
		}
	}
	// 再算各年一月
	for (int year = 1971; year <= 2099; ++year) {
		if (isLeep(year - 1)) {
			startRecord[year - 1970][0] = (startRecord[year - 1971][0] + 366) % 7;
		}
		else {
			startRecord[year - 1970][0] = (startRecord[year - 1971][0] + 365) % 7;
		}
		if (startRecord[year - 1970][0] == 0) {
			startRecord[year - 1970][0] = 7; // 对星期日需要进行特殊处理
		}
	}

	for (int year = 1971; year <= 2099; ++year) {
		if (isLeep(year)) {
			for (int month = 1; month < 12; ++month) { // 1850年的a月开头是算小于a的所有月份
				startRecord[year - 1970][month] = (startRecord[year - 1970][month - 1] + DAYS_LEEP[month - 1]) % 7;
				if (startRecord[year - 1970][month] == 0) {
					startRecord[year - 1970][month] = 7; // 对星期日需要进行特殊处理
				}
			}
		}
		else {
			for (int month = 1; month < 12; ++month) { // 1850年的a月开头是算小于a的所有月份
				startRecord[year - 1970][month] = (startRecord[year - 1970][month - 1] + DAYS_NORMAL[month - 1]) % 7;
				if (startRecord[year - 1970][month] == 0) {
					startRecord[year - 1970][month] = 7; // 对星期日需要进行特殊处理
				}
			}
		}
	}

	int n;
	string s, t;
	cin >> n >> s >> t; cin.get(); // 记得吃掉换行，否则input函数里都在处理换行


	string process;
	map<string, vector<vector<pair<int, int>>>> processList;
	for (int i = 0; i < n; ++i) {
		vector<pair<int, int>> minutesVec, hoursVec, dayVec, monthVec, dayOfWeekVec;
		input(minutesVec);
		input(hoursVec);
		input(dayVec);
		input(monthVec,MONTH);
		input(dayOfWeekVec,DAYOFWEEK);
		cin >> process;
		cin.get(); // 记得吃掉换行，否则input函数里都在处理换行
		vector<vector<pair<int, int>>> temp;
		temp.push_back(minutesVec);
		temp.push_back(hoursVec);
		temp.push_back(dayVec);
		temp.push_back(monthVec);
		temp.push_back(dayOfWeekVec);
		processList.emplace(process, temp);
	}


	int yearStart, monthStart, dayStart, hourStart, minuteStart;
	int yearEnd, monthEnd, dayEnd, hourEnd, minuteEnd;
	formatedStr2Time(s, yearStart, monthStart, dayStart, hourStart, minuteStart);
	formatedStr2Time(t, yearEnd, monthEnd, dayEnd, hourEnd, minuteEnd);
	int year = yearStart, month= monthStart, day = dayStart, hour = hourStart, minute = minuteStart;
	while (year != yearEnd || month != monthEnd || day != dayEnd || hour != hourEnd || minute != minuteEnd) {
		for (auto task : processList) {
			bool valid;

			bool valids[5] = { false };
			vector<int> now;
			now.push_back(minute);
			now.push_back(hour);
			now.push_back(day);
			now.push_back(month);
			now.push_back(weekday(year, month, day));


			for (int i = 0; i < 5; ++i) {
				for (auto x : task.second.at(i)) {
					if (x.first <= now.at(i) && x.second >= now.at(i)) {
						valids[i] = true;
					}
				}
			}

			valid = valids[0] && valids[1] && valids[2] && valids[3] && valids[4];
			if (valid) {
				string time;
				formatedTime2Str(time, year, month, day, hour, minute);
				//cout << weekday(year, month, day) << " ";
				cout << time << " " << task.first << endl;
			}
		}

		int monthDays;
		if (isLeep(year)) {
			monthDays = DAYS_LEEP[month] + 1;
		}
		else {
			monthDays = DAYS_NORMAL[month] + 1;
		}

		minute += 1;
		hour = hour + minute/60;
		day = day + hour/24;
		month = month + day / monthDays;
		year = year + month / 13;

		minute %= 60;
		hour %= 24;
		day %= monthDays;
		month %= 13;
	}


	return 0;
}
