//int占用4字节，32比特，数据范围为-2147483648~2147483647[-2^31~2^31-1]
//cmath: max min abs power
//algorithm: sort(数组名,数组名+长度)
//不要忘了输入某个值，不要忘了注释掉freopen()

//201312-1	出现次数最多的数
/*#include<iostream>
#include<stdio.h>
using namespace std;

int numbers[10001]={0};

int main(){
  freopen("test.txt","r",stdin);
  int input_num;
  cin>>input_num;
  int pos;
  for(int i=0;i<input_num;++i){
    cin>>pos;
    numbers[pos]++;
  }
  int max=0;
  pos=0;
  for(int i=0;i<10001;++i){
    if(numbers[i]>max){
      pos = i;
      max = numbers[i];
    }
  }
  cout<<pos;
  return 0;
}*/

//201503-1	图像旋转
/*#include<iostream>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int **matrix = new int*[n];
	for(int i=0;i<n;++i){
		matrix[i] = new int[m]();
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cin>>matrix[i][j];
		}
	}
	int **answer = new int*[m];
	for(int i=0;i<m;++i){
		answer[i] = new int[n]();
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			answer[m-1-j][i]=matrix[i][j];
		}
	}
	bool first_row = true;
	for(int i=0;i<m;++i){
		if(!first_row) cout<<endl;
		for(int j=0;j<n;++j){
			cout<<answer[i][j]<<" ";
		}
		first_row = false;
	}
}*/

//201403-1 相反数
/*#include<iostream>
#include<cmath>
using namespace std;

int numbers[2001] = {0};

int main(){
	freopen("test.txt","r",stdin);
	int input_num,pos;
	cin>>input_num;
	for(int i=0;i<input_num;++i){
		cin>>pos;
		if(pos>0) numbers[pos]++;
		else numbers[1000-pos]++;
	}
	int sum = 0;
	for(int i=1;i<=1000;++i){
		sum+=min(numbers[i],numbers[i+1000]);
	}
	cout<<sum;
	return 0;
}*/

//201409-1 相邻数对
/*#include<iostream>
#include<cmath>
using namespace std;

int numbers[10001] = {0};

int main(){
	freopen("test.txt","r",stdin);
	int input_num,pos;
	cin>>input_num;
	for(int i=0;i<input_num;++i){
		cin>>pos;
		numbers[pos]++;
	}
	int sum = 0;
	for(int i=1;i<10000;++i){
		sum+=min(numbers[i],numbers[i+1]);
	}
	cout<<sum;
	return 0;
}*/

//201803-1 跳一跳
/*#include<iostream>
using namespace std;
int main(){
	freopen("test.txt","r",stdin);
	int sum = 0, step_score = 1,step = 0;
	cin>>step;
	while(step!=0){
		if(step==1){
			step_score=1;
		}else if(step==2&&step_score==1){
			step_score=2;
		}else{
			step_score+=2;
		}
		sum+=step_score;
		cin>>step;
	}
	cout<<sum;
	return 0;
}*/

//201712-1 最小差值
/*#include<iostream>
using namespace std;
int numbers[10001]={0};
int main(){
	freopen("test.txt","r",stdin);
	int n,pos,answer=10000;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>pos;
		numbers[pos]++;
	}
	int last=-10000;//避免对第一个位置的特殊处理 
	for(int i=0;i<10001;++i){
		if(numbers[i]>1){
			answer = 0;
			break;
		}else if(numbers[i]==1){
			int temp=0;
			temp = i-last;
			if(temp<answer) answer = temp;
			last=i;
		}
	}
	cout<<answer;
	return 0;
}*/

//201709-1 打酱油
/*#include<iostream>
using namespace std;
int main(){
	int N,answer;
	cin>>N;
	answer = N/50*7+(N-N/50*50)/30*4+(N-N/50*50-(N-N/50*50)/30*30)/10;
	cout<<answer;
	return 0;
}*/

//201703-1 分蛋糕
/*#include<iostream>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	int *cakes = new int[n];
	for(int i=0;i<n;++i){
		cin>>cakes[i];
	}
	int cake=0,answer=0;
	for(int i=0;i<n;++i){
		if(cake<k){
			cake+=cakes[i];
		}else{
			answer++;
			cake=cakes[i];
		}
	}
	answer++;
	cout<<answer;
	return 0;
}*/

//201412-1 门禁系统
/*#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int *record = new int[n]();
	int *people = new int[n+1]();//必须显式（）初始化 
	for(int i=0;i<n;++i){
		cin>>record[i];
		people[record[i]]++;
		cout<<people[record[i]]<<" ";
	}
	return 0;
}*/

//201509-1 数列分段
/*#include<iostream>
using namespace std;
int main(){
	int n,answer=1;
	cin>>n;
	int input,last;
	cin>>last;
	for(int i=1;i<n;++i){
		cin>>input;
		if(input!=last) answer++;
		last = input;
	}
	cout<<answer;
	return 0;
}*/

//201512-1 数位之和
/*#include<iostream>
using namespace std;
int main(){
	int input;
	int answer=0;
	cin>>input;
	while(input>0){
		answer+=input%10;
		input/=10;
	}
	cout<<answer;
	return 0;
}*/

//201604-1 折点计数
/*#include<iostream>
using namespace std;
int main(){
	int n,answer=0;
	int last,today;
	bool up_down;
	cin>>n;
	cin>>last;
	cin>>today;
	up_down = today>last;
	last=today;
	for(int i=2;i<n;++i){
		cin>>today;
		if(up_down != (today>last)){
			answer++;
			up_down = today>last;
		}
		last = today;
	}
	cout<<answer;
	return 0;
} */

//201612-1 中间数
/*#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n,answer=-1;
	cin>>n;
	int *numbers = new int[n];
	for(int i=0;i<n;++i){
		cin>>numbers[i];
	}
	sort(numbers,numbers+n);
	int left = 0, right = 0;
	for(int i=0;i<n/2;++i){
		left=numbers[i];
		right=numbers[n-1-i];
		if(left==numbers[n/2]&&right!=numbers[n/2]) break;
		if(right==numbers[n/2]&&left!=numbers[n/2]) break;
		if(left==right){
			answer = left;
			break;
		}
	}
	if(n%2){
		if(numbers[n/2]!=numbers[n/2-1]&&numbers[n/2]!=numbers[n/2+1]) answer=numbers[n/2];
	}
	cout<<answer;
} */

//201609-1 最大波动
/*#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n;
	cin>>n;
	int answer = 0;
	int last,today;
	cin>>last;
	for(int i=1;i<n;++i){
		cin>>today;
		int temp = abs(today-last);
		answer = max(answer,temp);
		last = today;
	}
	cout<<answer;
} */
