#pragma warning (disable:4996)
#include<iostream>
#include<cstdlib>
using namespace std;
int t,count;int a[400],b[400];//输入菜价，所求菜价 
bool f[301][301][301];//储存状态信息，也就是dfs的n,x,y 

// 在保证各家价格合法的情况下，深度优先搜索至最后一家也满足条件
void dfs(int n,int x,int y)//分别是搜到第n家，b[n-1]（求到了第n-1家的菜价）,b[n]（求到了第n家的菜价）
{ 	
	if(f[n][x][y])return;
	f[n][x][y]=true;	
	//最后一家菜价特殊处理，所以n只用等于t-1就够了，在这里直接检验最后一个是否合法就行了
	if(n==t-1) {		
		//最后一家菜价合法
		if((3 * a[n] - x) / 2 == a[t] || (3 * a[n] - x + 1) / 2 == a[t] || (3 * a[n] - x + 2) / 2 == a[t]) {	// 用第t家第二天的限制					
			for(int i=1;i<=n;++i)    //输出 			
				cout<<b[i]<<" ";			
			for(int i=0;i<3;++i) {
				//输出最后一家菜价	
				if((3*a[n]-x+i)/2==a[t]) {					
					cout<<3*a[n]-x-y+i;		// 用t-i家第二天的算			
					exit(0);  //直接结束程序，这样用时更短 				
				}			
			}		
		}		
		return;	
	}	
	for(int i=0;i<3;++i) { // 这里保证了是字典序最小的，因为搜索的时候是从小的开始搜的
		b[n+1]=3*a[n]-x-y+i; //递推关系式 		
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
		b[1]=i,b[2]=2*a[1]-i;  //第一家菜价，有两种可能 		
		dfs(2,i,b[2]);		
		b[1]=i,b[2]=2*a[1]-i+1; //第二种可能 		
		dfs(2,i,b[2]);	
	} 	
	return 0;
}
