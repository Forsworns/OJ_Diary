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
	sort(buyRecordVec.begin(), buyRecordVec.end(), [](Record a, Record b) -> bool {return a.price > b.price; }); // �����ô���
	sort(sellRecordVec.begin(), sellRecordVec.end(), [](Record a, Record b) -> bool {return a.price < b.price; }); // ������С�� 
	sort(allRecordVec.begin(), allRecordVec.end(), [](Record a, Record b)->bool {return a.price > b.price; }); // �����ô��ڣ���Ŀ�趨�����ܴ�����Ҫ�Ӵ�Ŀ�ʼ����
	
	// ���ܳɽ�����������������ͼۺ��򷽵���߼�֮��ļ۸񣬷��򲻻��н��״��
	double maxPrice = buyRecordVec.begin()->price;
	double minPrice = sellRecordVec.begin()->price;
	int maxAmount=0, buyAmount=0, sellAmount=0;
	double dealPrice = 0;
	auto it = allRecordVec.begin(); // ��ǰ�۸񣬼۸�һ�������ڱ���֮�У�û�б�Ҫ��������������֮�䣨��Ŀ�趨�۸񾡿��ܸ�
	while(it->price > maxPrice) {
		++it;
	}
	// ��������ļ۸������ڵļ۸��������ɽ���
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
