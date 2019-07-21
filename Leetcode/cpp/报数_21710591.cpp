class Solution {
private:
    char num2char(int num){
        return '0'+num;
    }
private:
    string generate(int n){
        if(n==1){
            return "1";
        }else{
            string input = generate(n-1);
            string output = "";
            vector<pair<char,int>> numbers;
            char number='\0';
            int counter=-1;
            for(int i=0;i<input.length();++i){
                cout<<number<<endl;
                if(number!=input[i]){
                    if(counter == -1){ // 是否是开头，特殊处理
                        counter = 1;
                    }else{
                        numbers.push_back(make_pair(number,counter));
                        counter = 1;   
                    }
                    number = input[i];
                }else{
                    counter++;
                }
            }
            numbers.push_back(make_pair(number,counter));
            for(int i=0;i<numbers.size();++i){
                output+=num2char(numbers[i].second);
                output+=numbers[i].first;
            }
            return output;
        }
    }
public:
    string countAndSay(int n) {
        return generate(n);
    }
};