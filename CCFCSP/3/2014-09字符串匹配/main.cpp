#include <iostream>
#include <string> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
// KMP算法 
int* getNext(string str){
	int *next = new int[str.size()];
	next[0] = -1;
	int k = -1;
	int j = 1;
	while(j<str.size()){
		if(k==-1 || str[j] == str[k]){
			next[j++] = ++k;
		}else{
			k = next[k];	
		}
	}
	return next;
} 

bool contain(const string &input, const string &target){
	int *next = getNext(target);
	int i=0,j=0;
	while(i<input.size() && j<int(target.size())){//这个强制转换int很重要，否则认为是无符号数比较 
		if(j==-1 || input[i]==target[j]){
			i++;
			j++;
		}else{
			j = next[j];
		}	
	}
	
	if(j==target.size()){
		return true;	
	}else{
		return false;
	}
}

string transform2capital(const string &input){
	string output="";
	int length = input.size();
	for(int i=0;i<length;++i){
		if(input[i]<='z'&&input[i]>='a'){
			output+=(input[i]-'a'+'A');
		}else{
			output+=input[i];
		}
		
	}
	return output;
}

int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	string target;
	int capital = 0;
	int num = 0;
	cin>>target;
	cin>>capital;
	cin>>num;
	
	if(capital==0){
		target = transform2capital(target);
		string input;
		for(int i=0;i<num;++i){
			cin>>input;
			if(contain(transform2capital(input),target)){
				cout<<input<<endl;
			}
		}
	}else{
		string input;
		for(int i=0;i<num;++i){
			cin>>input;
			if(contain(input,target)){
				cout<<input<<endl;
			}
		}
	}
	
	return 0;
}
