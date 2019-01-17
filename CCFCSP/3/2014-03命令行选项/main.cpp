
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <utility>
using namespace std;
const string FLAG = " ";
void splitString(const std::string &s, std::vector<std::string> &v, const std::string &c)
{
	//工具函数，按某个字符串划分string，存入vector中
	string::size_type pos1, pos2;
	pos2 = s.find(c);
	pos1 = 0;
	while (pos2 != string::npos)
	{
		v.push_back(s.substr(pos1, pos2 - pos1));

		pos1 = pos2 + c.size();
		pos2 = s.find(c, pos1);
	}
	if (pos1 != s.length())
		v.push_back(s.substr(pos1));
}
int main() {
	freopen("test.txt","r",stdin);
	string format;
	cin>>format;
	int N;
	cin>>N;
	char argument;
	string value;
	set<char> arguments;
	map<char,string> arg_value_table;
	for(int i=0;i<format.size();++i){
		if(format[i]!=':'){
			arguments.insert(format[i]);
		}else{
			arg_value_table.insert(pair<char,string>(format[i-1],""));
		}
	}
	cin.get();
	string instruction;
	for(int i=0;i<N;++i){
		set<char> case_arg;
		vector<string> instructions;
		getline(cin,instruction);
		//cout<<instruction<<endl;
		splitString(instruction,instructions,FLAG);
		for(map<char,string>::iterator it=arg_value_table.begin();it!=arg_value_table.end();++it){
			arg_value_table[(*it).first]="";
		}
		for(vector<string>::iterator it=instructions.begin();it<instructions.end();++it){
			if(arguments.count((*it)[1])&&(*it)[0]=='-'&&(*it).size()==2){//这里必须判断参数是否满足一个字符的要求……= = 
				case_arg.insert((*it)[1]);
				if(arg_value_table.count((*it)[1])){
					char temp = (*it)[1];
					++it;
					if(it<instructions.end()) arg_value_table[temp]=*it;
				}
			}else{
				if(it!=instructions.begin()) break;
			}
		}
		cout<<"Case "<<i+1<<":";
		for(set<char>::iterator it=case_arg.begin();it!=case_arg.end();++it){//set本身排序保证了字典序 
			cout<<" -"<<(*it);
			if(arg_value_table.count(*it)){
				cout<<" "<<arg_value_table[*it];
			}
		}
		if(i!=N-1)cout<<endl;
	}
	return 0;
}

