#pragma warning (disable:4996)
#include<iostream>
#include<cstdlib>
using namespace std;
int t,count;int a[400],b[400];//����˼ۣ�����˼� 
bool f[301][301][301];//����״̬��Ϣ��Ҳ����dfs��n,x,y 

// �ڱ�֤���Ҽ۸�Ϸ�������£�����������������һ��Ҳ��������
void dfs(int n,int x,int y)//�ֱ����ѵ���n�ң�b[n-1]�����˵�n-1�ҵĲ˼ۣ�,b[n]�����˵�n�ҵĲ˼ۣ�
{ 	
	if(f[n][x][y])return;
	f[n][x][y]=true;	
	//���һ�Ҳ˼����⴦������nֻ�õ���t-1�͹��ˣ�������ֱ�Ӽ������һ���Ƿ�Ϸ�������
	if(n==t-1) {		
		//���һ�Ҳ˼ۺϷ�
		if((3 * a[n] - x) / 2 == a[t] || (3 * a[n] - x + 1) / 2 == a[t] || (3 * a[n] - x + 2) / 2 == a[t]) {	// �õ�t�ҵڶ��������					
			for(int i=1;i<=n;++i)    //��� 			
				cout<<b[i]<<" ";			
			for(int i=0;i<3;++i) {
				//������һ�Ҳ˼�	
				if((3*a[n]-x+i)/2==a[t]) {					
					cout<<3*a[n]-x-y+i;		// ��t-i�ҵڶ������			
					exit(0);  //ֱ�ӽ�������������ʱ���� 				
				}			
			}		
		}		
		return;	
	}	
	for(int i=0;i<3;++i) { // ���ﱣ֤�����ֵ�����С�ģ���Ϊ������ʱ���Ǵ�С�Ŀ�ʼ�ѵ�
		b[n+1]=3*a[n]-x-y+i; //���ƹ�ϵʽ 		
		if(b[n+1]>=1)		
			dfs(n+1,y,b[n+1]);	
	}
}

int main(){
	freopen("test.txt","r",stdin);
	cin>>t;	
	for(int i=1;i<=t;++i)	
		cin>>a[i];	
	for(int i=1;i<=2*a[1];++i) {		
		b[1]=i,b[2]=2*a[1]-i;  //��һ�Ҳ˼ۣ������ֿ��� 		
		dfs(2,i,b[2]);		
		b[1]=i,b[2]=2*a[1]-i+1; //�ڶ��ֿ��� 		
		dfs(2,i,b[2]);	
	} 	
	return 0;
}
