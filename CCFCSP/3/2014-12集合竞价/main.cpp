#pragma warning(disable:4996) 
#include <iostream>
#include <string>
#include <map> 
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Record{
	bool buyOrSell; // true for buy
	int amount;
	double price;
}; // use price to sort 

int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	char kind[10];
	map<int,Record> records;
	int row=0;
	while(cin>>kind){
		if(kind[0]=='c'){
			int pos;
			cin>>pos;
			records.erase(pos);
		}else{
			Record r;
			r.buyOrSell = (kind[0]=='b');
			cin>>r.price;
			cin>>r.amount;	
			records.emplace(make_pair(++row,r));		
		}
	}
	
	vector<Record> buyRecordVec, sellRecordVec, allRecordVec;
	for(auto &x:records){
		if(x.second.buyOrSell){
			buyRecordVec.emplace_back(x.second);
		}else{
			sellRecordVec.emplace_back(x.second);
		}
		allRecordVec.emplace_back(x.second);
	}
	sort(buyRecordVec.begin(), buyRecordVec.end(), [](Record a, Record b) -> bool {return a.price > b.price; }); // 降序用大于
	sort(sellRecordVec.begin(), sellRecordVec.end(), [](Record a, Record b) -> bool {return a.price < b.price; }); // 升序用小于 
	sort(allRecordVec.begin(), allRecordVec.end(), [](Record a, Record b)->bool {return a.price > b.price; }); // 降序用大于（题目设定尽可能大，所以要从大的开始遍历
	
	// 可能成交的区间是卖方的最低价和买方的最高价之间的价格，否则不会有交易达成
	double maxPrice = buyRecordVec.begin()->price;
	double minPrice = sellRecordVec.begin()->price;
	int maxAmount=0, buyAmount=0, sellAmount=0;
	double dealPrice = 0;
	auto it = allRecordVec.begin(); // 当前价格，价格一定出现在报价之中，没有必要出现在两个报价之间（题目设定价格尽可能高
	while(it->price > maxPrice) {
		++it;
	}
	// 遍历合理的价格区间内的价格，依次求解成交量
	while (it->price > minPrice) {
		buyAmount = 0;
		sellAmount = 0;
		for (auto x:buyRecordVec) {
			if (x.price>=it->price) {
				buyAmount += x.amount;
			}
			else {
				break;
			}
		}
		for (auto x:sellRecordVec) {
			if (x.price<=it->price) {
				sellAmount += x.amount;
			}
			else {
				break;
			}
		}
		if (maxAmount < min(sellAmount, buyAmount)) {
			maxAmount = min(sellAmount, buyAmount);
			dealPrice = it->price;
		}
		++it;
	}
	cout.flags(ios::fixed);
	cout.precision(2);
	cout << dealPrice << " " <<maxAmount;
	return 0;
}
