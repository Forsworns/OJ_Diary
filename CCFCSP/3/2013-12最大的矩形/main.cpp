#include <iostream>
//����ɨ�裬��Ҫ������Ӱ��ȥ���ſ�������֮ǰ������ˮ�۴����⣬��㿴���ŵĿ�����Ϊ���� 
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
			max_length = max(length,max_length);//���ܽ����ڳ���0ʱ�Ÿ��·������ 1 1 1 7���������ĩβ����������߷���ɨ��һ��Ҳ������������ 
		}
		answer = max(answer,max_length*(maxium-i+1));
	}
	cout<<answer;
}
