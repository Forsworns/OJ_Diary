//�������λ��cout << fixed << setprecision(N) ȥ��fixedΪ����
//�ǵ�ɾ��freopen
//dev c++�Ӷϵ��Ժ����ִ�У���ѡ�����ı��ƶ������Կ����������� 

// 201809-2 ���
/* 
 int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int nums = 0;
	cin >> nums;
	int totalTime = 0;
	pair<int, int> *H = new pair<int,int>[nums];
	pair<int, int> *W = new pair<int,int>[nums];
	for (int i = 0; i < nums;++i) {
		cin >> H[i].first>>H[i].second;
	}
	for (int i = 0; i < nums; ++i) {
		cin >> W[i].first >> W[i].second;
	}
	int j = 0;
	for (int i = 0; i < nums;++i) {
		if (j >= nums) {
			break;
		}
		else {
			while(j<nums) {
				if (H[i].first <= W[j].first && H[i].second<=W[j].second && H[i].second - W[j].first > 0) {
					totalTime += H[i].second - W[j].first;
					break;
				}
				else if (H[i].first <= W[j].first && H[i].second >= W[j].second) {
					totalTime += W[j].second - W[j].first;
					j++;
				}
				else if (H[i].first >= W[j].first && H[i].second <= W[j].second) {
					totalTime += H[i].second - H[i].first;
					break;
				}
				else if (H[i].first >= W[j].first && H[i].second >= W[j].second) {
					if (W[j].second - H[i].first > 0) {
						totalTime += W[j].second - H[i].first;
					}
					j++;
				}
				else {
					break;
				}
			}
		}
	}
	cout << totalTime;
	return 0;
}
*/
 
//201803-2 ��ײ��С��
/*
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct ball{
	int pos;
	int id;
};
bool my_compare_pos(ball b1,ball b2){
	return b1.pos<b2.pos;
}
bool my_compare_id(ball b1,ball b2){
	return b1.id<b2.id;
}//���벻�ǰ�λ������ģ�����Ҫ�ָ����� 

int main() {
	freopen("test.txt","r",stdin);
	int n,L,t;
	cin>>n>>L>>t;
	ball *balls = new ball[n];
	for(int i=0;i<n;i++){
		cin>>balls[i].pos;
		balls[i].id = i;
	}
	sort(balls,balls+n,my_compare_pos);//��Ҫ��������Ϊ֮���ж������ڵ���ײʱ��ֻ���������������������Ҫ���ǳ�ʼλ�ã��������벻������
	while(t-->0){//ģ�ⲿ�� 
		for(int i=0;i<n;++i){	
			if(abs(balls[i].pos)==L||abs(balls[i].pos)==0) balls[i].pos = -balls[i].pos;//���Ĵ����˶���������ͳһ��++Ϊÿ���λ�ñ仯����Ϊ�����˶��൱�ڸ��ļ���1�����ҵ����������㷽ʽһ�� 
			balls[i].pos++;
			if(i==0){
				if(abs(balls[0].pos)==abs(balls[1].pos)){
					balls[0].pos*=-1;
					balls[1].pos*=-1;
				}
			}
			else if(i==n-1){
				if(abs(balls[n-1].pos)==abs(balls[n-2].pos)){
					balls[n-1].pos*=-1;
					balls[n-2].pos*=-1;
				}
			}
			else{
				if(abs(balls[i].pos)==abs(balls[i-1].pos)){
					balls[i].pos*=-1;
					balls[i-1].pos*=-1;
				}
				if(abs(balls[i].pos)==abs(balls[i+1].pos)){
					balls[i].pos*=-1;
					balls[i+1].pos*=-1;
				}
			}
		}
	}
	sort(balls,balls+n,my_compare_id);//�ٰ���Ŀ����������±��������һ�Σ���֤����Ϸ� 
	for(int i=0;i<n;++i){
		cout<<abs(balls[i].pos)<<" ";
	}
	return 0;
}*/


//201712-2	��Ϸ
/*#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	vector<int> people;
	for(int i=1;i<=n;++i){
		people.push_back(i);
	}
	int number = 1;
	int pos=0;
	while(people.size()>1){
		if(number%k==0||number%10==k){
			people.erase(people.begin()+pos);//ɾ����ǰԪ������ǰ�Ʋ���Ҫ������λ�ü��� 
		}else{
			pos++;
		}
		if(pos==people.size()) pos = 0;
		number++;
	}
	cout<<*people.begin();
	return 0;
}*/


//201709-2 ����Կ�׺�
/*#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	freopen("test.txt","r",stdin);
	int N,K;
	cin>>N>>K;
	int *keys = new int[K];
	int *start = new int[K];
	int *time = new int[K];
	int *end = new int[K];
	int total_end = 0;
	for(int i=0;i<K;++i){
		cin>>keys[i]>>start[i]>>time[i];
		end[i] = start[i] + time[i];
		total_end = max(total_end,end[i]);
	}
	int *box = new int[N];//ʯ��־������д����= = 
	for(int i=0;i<N;++i){
		box[i] = i+1;
	}
	while(total_end-->0){
		for(int i=0;i<K;++i){
			start[i]--;
			end[i]--;
		}
		vector<int> keys_return;
		for(int i=0;i<K;++i){
			if(end[i]==0){
				keys_return.push_back(keys[i]); 
			}
		}
		sort(keys_return.begin(),keys_return.end());
		for(int i=0;i<N;++i){
			if(keys_return.size()==0) break;
			if(box[i]==0) {
				box[i]=keys_return.front();
				keys_return.erase(keys_return.begin());
			}
		}
		for(int i=0;i<K;++i){
			if(start[i]==0){
				for(int j=0;j<N;++j){
					if(box[j]==keys[i]) {
						box[j]=0;
					}
				}
			}
		}
	}
	for(int i=0;i<N;++i){
		cout<<box[i]<<" ";
	}
	return 0;
}*/


//201703-2 ѧ���Ŷ�
/*#include<iostream>
using namespace std;
int main(){
	freopen("test.txt","r",stdin);
	int n;
	cin>>n;
	int *students = new int[n+1];
	for(int i=1;i<n+1;++i){
		students[i] = i;
	}
	int m;
	cin>>m;
	int id,move;
	for(int i=0;i<m;++i){
		cin>>id>>move;
		int old_pos = students[id];
		students[id]+=move;
		if(move>0){
			for(int j=1;j<=n;++j){//�����õ��Ǵ�1�ŵ�n�ţ���Ҫ����� 
				if(students[j]<=students[id]&&students[j]>old_pos&&j!=id){
					students[j]--;
				}
			}
		}else{
			for(int j=1;j<=n;++j){
				if(students[j]>=students[id]&&students[j]<old_pos&&j!=id){
					students[j]++;
				}
			}	
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(students[j]==i) cout<<j<<" ";
		}
	}
	return 0;
}*/

//201612-2 ���ʼ��� 
/*#include<iostream>
using namespace std;
int main(){
	int S,T;
	cin>>T;
	if(T<3500){
		S=T;
	}else{
		for(S=3500;;S+=100){
			int A = S-3500;
			int temp = S;
			if(A>80000){
				temp-=(A-80000)*0.45;
				A = 80000;
			}
			if(A>55000){
				temp-=(A-55000)*0.35;
				A = 55000;
			}
			if(A>35000){
				temp-=(A-35000)*0.30;
				A = 35000;
			}
			if(A>9000){
				temp-=(A-9000)*0.25;
				A = 9000;
			}
			if(A>4500){
				temp-=(A-4500)*0.20;
				A = 4500;
			}
			if(A>1500){
				temp-=(A-1500)*0.10;
				A = 1500;
			}
			temp-=A*0.03;
			if(temp==T){
				break;
			}
		}	
	}
	cout<<S;
}*/


//201609-2 �𳵹�Ʊ
/*#include<iostream>
using namespace std;
int seats[20][5]={0};
int main(){
	freopen("test.txt","r",stdin);
	int n;
	cin>>n;
	int p;
	for(int i=0;i<n;++i){
		cin>>p;
		int *tickets = new int[p];
		bool flag = false;
		for(int j=0;j<20;++j){
			for(int k=0;k<6-p;++k){
				int sum = 0;
				for(int l=0;l<p;++l){
					sum+=seats[j][k+l];
				}
				if(sum==0) {
					flag=true;
					for(int l=0;l<p;++l){
						tickets[l]=j*5+k+l;
						seats[j][k+l] = 1;
					}
					break;
				}
			}
			if(flag){
				break;
			}
		}
		if(!flag){
			int pos=0;
			for(int j=0;j<20;++j){
				for(int k=0;k<5;++k){
					if(pos==p){
						break;
					}
					if(seats[j][k]==0){
						tickets[pos++]=5*j+k;
						seats[j][k]=1;
					}	
				}
			}
		}
		for(int j=0;j<p;++j){
			cout<<tickets[j]+1<<" ";
		}
		cout<<endl;
	}
	return 0;
}*/


//201503-2	��������
/*#include<iostream>
#include<stdio.h>
using namespace std;

int times[1001]={0};

int main(){
  freopen("test.txt","r",stdin);
  int input_num=0;
  cin>>input_num;
  for(int i=0;i<input_num;++i){
    int pos=0;
    cin>>pos;
    times[pos]++;
  }
  int max=-1;
  int max_pos=-1;
  bool begin=true;
  while(true){
    max=-1;
    for(int i=0;i<1001;++i){
      if(times[i]>max){
        max=times[i];
        max_pos=i;
      }
    }
    if(max==0) break;
    else {
      if(!begin) cout<<endl;//���һ�в�Ҫ�����з� 
	}
	begin=false;
    cout<<max_pos<<" "<<max;
    times[max_pos]=0;
  }
  return 0;
}*/


//201604-2  ����˹���� 
/*#include<iostream> //80
using namespace std;
int matrix[15][10] = {0};
int block[4][4] = {0};
int main(){
	freopen("test.txt","r",stdin);
	for(int i=0;i<15;++i){
		for(int j=0;j<10;++j){
			cin>>matrix[i][j];
		}
	}
	for(int i=0;i<4;++i){
		for(int j=0;j<4;++j){
			cin>>block[i][j];
		}
	}
	int col_start;
	cin>>col_start;
	int matrix_pos[4]={15,15,15,15};//��¼1���ֵ������λ�ã��ǵó�ʼ����ֻ��0���Բ���Ĭ�ϵ��б��ʼ�� 
	int block_pos[4]={-15,-15,-15,-15};//ȷ�����б����� 
	for(int i=0;i<15;++i){//matrix������������С�ģ���ӽ��Ϸ��� 
		for(int j=col_start-1;j<col_start+4;++j){
			if(matrix[i][j]) matrix_pos[j-col_start+1] = min(matrix_pos[j-col_start+1],i);
		}
	}
	for(int i=0;i<4;++i){
		for(int j=0;j<4;++j){//block�������������ģ���Զ���Ϸ��� 
			if(block[i][j]) block_pos[j] = max(block_pos[j],i);
		}
	}
	//��ȡ1��λ�ü�ֵ��Ϣ���������½���������� 
	int down_rows_num = 16;//matrixȫ0��block�ڵ�һ�м�Ϊ�½�15�� 
	for(int i=0;i<4;++i){
		down_rows_num = min(down_rows_num,matrix_pos[i]-block_pos[i]);//�����½�������������Ŀ�ſ������Ҫ����ϸ� 
	}
	down_rows_num = min(down_rows_num,15);
	for(int i=down_rows_num-1;i<down_rows_num+4&&i<15;++i){
		for(int j=col_start-1;j<col_start+4;++j){
			matrix[i][j]+=block[i+1-down_rows_num][j-col_start+1];
		}
	}
	for(int i=0;i<15;++i){
		for(int j=0;j<10;++j){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}*/
/*#include<iostream> //100
using namespace std;
int matrix[16][10] = {0};
int block[4][4] = {0};
struct pos{
	int row;
	int col;
};
pos position[4];
int main(){
	freopen("test.txt","r",stdin);
	for(int i=0;i<15;++i){
		for(int j=0;j<10;++j){
			cin>>matrix[i][j];
		}
	}
	for(int i=0;i<4;++i){
		for(int j=0;j<4;++j){
			cin>>block[i][j];
		}
	}
	int col_start;
	cin>>col_start;
	for(int i=0;i<10;++i){//����һ����յײ�ʹ�߼�ͳһ 
		matrix[15][i] = 1;
	}
	int k=0;
	for(int i=0;i<4;++i){//��¼�����ĸ������λ�� 
		for(int j=0;j<4;++j){
			if(block[i][j]==1){	
				position[k].row = i;
				position[k].col = j;
				k++;
			}
		}
	}
	bool stop = false;
	int row_stop=0;
	for(row_stop=0;row_stop<15;++row_stop){//ģ������½� 
		stop = false;
		for(k=0;k<4;++k){
			if(matrix[row_stop+position[k].row][col_start-1+position[k].col]){
				stop = true;
				break;
			}	
		}
		if(stop) break;
	}
	row_stop--;
	for(k=0;k<4;++k){
		matrix[row_stop+position[k].row][col_start-1+position[k].col] = 1;			
	}
	for(int i=0;i<15;++i){
		for(int j=0;j<10;++j){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}*/


//201512-2	��������Ϸ
/*#include<iostream>
using namespace std;
int main(){
	freopen("test.txt","r",stdin);
	int n,m;
	cin>>n>>m;
	int **matrix = new int*[n];
	for(int i=0;i<n;++i){
		matrix[i] = new int[m];
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cin>>matrix[i][j];
		}
	}
	int **answer = new int*[n];
	for(int i=0;i<n;++i){
		answer[i] = new int[m];
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			answer[i][j]=matrix[i][j];
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(matrix[i][j]!=0){
				int col_num=1,row_num=1;
				int col = j,row=i;
				while(col>0&&matrix[i][col-1]==matrix[i][j]){
					col_num++;
					col--;
				}
				col = j;
				while(col<m-1&&matrix[i][col+1]==matrix[i][j]){
					col_num++;
					col++;
				}
				while(row>0&&matrix[row-1][j]==matrix[i][j]){
					row_num++;
					row--;
				}
				row=i;
				while(row<n-1&&matrix[row+1][j]==matrix[i][j]){
					row_num++;
					row++;
				}
				if(col_num>=3){
					col = j;
					while(col>0&&matrix[i][col-1]==matrix[i][j]){
						answer[i][col-1] = 0;
						col--;
					}
					col = j;
					while(col<m-1&&matrix[i][col+1]==matrix[i][j]){
						answer[i][col+1] = 0;
						col++;
					}
				}
				if(row_num>=3){
					row = i;
					while(row>0&&matrix[row-1][j]==matrix[i][j]){
						answer[row-1][j] = 0;
						row--;
					}
					row = i;
					while(row<n-1&&matrix[row+1][j]==matrix[i][j]){
						answer[row+1][j] = 0;
						row++;
					}
				}
				if(col_num>=3||row_num>=3) answer[i][j]=0;
			}
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cout<<answer[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
*/

//201509-2	���ڼ���
/*#include<iostream>
using namespace std;
int main(){
	int y,d;
	cin>>y>>d;
	int month,day;
	if(y%400==0||y%4==0&&y%100!=0){
		if(d>=1&&d<=31){
			month = 1;
			day = d;
		}
		if(d>=32&&d<=60){
			month = 2;
			day = d-31;
		}
		if(d>=61&&d<=91){
			month = 3;
			day = d-60;
		}
		if(d>=92&&d<=121){
			month = 4;
			day = d-91;
		}
		if(d>=122&&d<=152){
			month = 5;
			day = d-121;
		}
		if(d>=153&&d<=182){
			month = 6;
			day = d-152;
		}
		if(d>=183&&d<=213){
			month = 7;
			day = d-182;
		}
		if(d>=214&&d<=244){
			month = 8;
			day = d-213;
		}
		if(d>=245&&d<=274){
			month = 9;
			day = d-244;
		}
		if(d>=275&&d<=305){
			month = 10;
			day = d-274;
		}
		if(d>=306&&d<=335){
			month = 11;
			day = d-305;
		}
		if(d>=336&&d<=366){
			month = 12;
			day = d-335;
		}
	}else{
		if(d>=1&&d<=31){
			month = 1;
			day = d;
		}
		if(d>=32&&d<=59){
			month = 2;
			day = d-31;
		}
		if(d>=60&&d<=90){
			month = 3;
			day = d-59;
		}
		if(d>=91&&d<=120){
			month = 4;
			day = d-90;
		}
		if(d>=121&&d<=151){
			month = 5;
			day = d-120;
		}
		if(d>=152&&d<=181){
			month = 6;
			day = d-151;
		}
		if(d>=182&&d<=212){
			month = 7;
			day = d-181;
		}
		if(d>=213&&d<=243){
			month = 8;
			day = d-212;
		}
		if(d>=244&&d<=273){
			month = 9;
			day = d-243;
		}
		if(d>=274&&d<=304){
			month = 10;
			day = d-273;
		}
		if(d>=305&&d<=334){
			month = 11;
			day = d-304;
		}
		if(d>=335&&d<=365){
			month = 12;
			day = d-334;
		}
	}
	cout<<month<<endl<<day;
	return 0;
}*/

//201412-2	Z����ɨ��
/*#include<iostream>
using namespace std;
int main(){
	freopen("test.txt","r",stdin);
	int n;
	cin>>n;
	int **matrix = new int*[n];
	for(int i=0;i<n;++i){
		matrix[i] = new int[n];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;++j){
			cin>>matrix[i][j];
		}
	}
	int x=0,y=0;//ע��˴�x���У�y���� 
	cout<<matrix[x][y]<<" ";
	bool direction = false;//true��ʾ������ 
	while(!(x==n-1&&y==n-1)){
		if(direction){
			x++;
			y--;
		}else{
			x--;
			y++;
		}
		if(y>n-1){
			y=n-1;
			x+=2;
			direction = true;
		}
		if(x>n-1){
			x=n-1;
			y+=2;//�����²������ҵ��ǰ�direction��������һ�����Ծ���������� 
			direction = false;
		}
		if(y<0){//ע��Ҫ���ȶԳ������жϣ���Ϊ�ڶԽ����ϻ����y<0��x>n-1ͬʱ��������� 
			y=0;
			direction = false;
		}
		if(x<0){
			x=0;
			direction = true;
		}
		cout<<matrix[x][y]<<" ";
	}
	return 0;
}*/

//201409-2	��ͼ
/*#include<iostream>
using namespace std;
const int SIZE = 101;
bool matrix[SIZE][SIZE];//����ģ�� 
int main(){
	freopen("test.txt","r",stdin);
	int n;
	cin>>n;
	int answer=0;
	for(int k=0;k<n;++k){
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		for(int i=x1;i<=x2-1;++i){
			for(int j=y1;j<=y2-1;++j){
				matrix[i][j]=true;
			}
		}
	}
	for(int i=0;i<SIZE;++i){
		for(int j=0;j<SIZE;++j){//С��ȡ������ȥ�� 
			if(matrix[i][j]){
				answer++; 
			}
		}
	}
	cout<<answer;
	return 0;
}*/

//201403-2	����
/*#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class window{
public:
	int id;
	int x1,x2,y1,y2;
	int pri;
	bool operator < (window &w) const{
		return pri < w.pri; 
	}
};
bool inScreen(window win,int x,int y){
	return x>=win.x1&&y>=win.y1&&x<=win.x2&&y<=win.y2;//���ڽ���Ҳ�� 
}
int main(){
	freopen("test.txt","r",stdin);
	int N,M;
	int answer;
	cin>>N>>M;
	vector<window> windows;
	for(int i=0;i<N;++i){
		window win;
		cin>>win.x1>>win.y1>>win.x2>>win.y2;
		win.id = i+1;
		win.pri = -i;
		windows.push_back(win);
	}
	int min = -N+1;
	sort(windows.begin(),windows.end());//Ĭ�ϴ�С���� 
	for(int i=0;i<M;++i){
		int x,y;
		cin>>x>>y;
		int answer=0;
		for(vector<window>::iterator it = windows.begin();it<windows.end();++it){
			if(inScreen(*it,x,y)){
				it->pri = (min--)-1;//���ȼ����ʹ����Ƶ���̨ 
				answer = it->id;
				break;
			}
		}
		if(answer>0){
			cout<<answer<<endl;
		}else{
			cout<<"IGNORED"<<endl;
		}
		sort(windows.begin(),windows.end());
	}
	return 0;
}*/

//201312-2	ISBN���� 
/*#include<iostream>
#include<string>
using namespace std;
int main(){
	string ISBN;
	cin>>ISBN;
	bool valid;
	int recognition = 0;//��Ȼ�ܴ����ǽ�Լʱ��
	recognition = (ISBN[0]-'0')*1 + (ISBN[2]-'0')*2 + (ISBN[3]-'0')*3 + (ISBN[4]-'0')*4 + (ISBN[6]-'0')*5 + (ISBN[7]-'0')*6 + (ISBN[8]-'0')*7 + (ISBN[9]-'0')*8 + (ISBN[10]-'0')*9;
	recognition%=11;
	if(ISBN[ISBN.size()-1]==recognition+'0' || ISBN[ISBN.size()-1]=='X'&&recognition==10){
		cout<<"Right";
	}else{
		ISBN.erase(ISBN.size()-1);
		if(recognition==10) ISBN+='X';
		else{
			ISBN+='0'+recognition;
		}
		cout<<ISBN;
	}
	return 0;
}*/
