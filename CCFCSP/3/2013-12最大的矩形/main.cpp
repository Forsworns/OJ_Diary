#include <iostream>
//横向扫描，不要被输入影响去竖着看。类似之前做过的水槽储量题，逐层看连着的块数作为矩形 
using namespace std;
int height[1000];
int main() {
	freopen("test.txt","r",stdin);
	int n;
	cin>>n;
	int maxium = 0;
	for(int i=0;i<n;++i){
		cin>>height[i];
		maxium = max(maxium,height[i]);
	}
	int answer = 0;
	for(int i=maxium;i>0;--i){
		int max_length=0;
		int length=0;
		if(height[0]){
			length++;
			height[0]--;	
		}
		for(int j=0;j<n-1;++j){
			if(height[j+1]){
				length++;
				height[j+1]--;
			}else{
				length = 0;
			}
			max_length = max(length,max_length);//不能仅仅在出现0时才更新否则会错过 1 1 1 7这种最高在末尾的情况，或者反向扫描一次也可以消除问题 
		}
		answer = max(answer,max_length*(maxium-i+1));
	}
	cout<<answer;
}
