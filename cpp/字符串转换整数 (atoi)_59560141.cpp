class Solution {
public:
    int myAtoi(string str) {
        int ans = 0;
        int order = 0;
        int blankAndSign = 0;
        bool inNum = false, positive=true, outbounded = false;
        for(int i=0;i<str.length();++i){
            if(str[i]!=' '){
                if(str[i]=='+'){
                    positive = true;
                    ++blankAndSign;
                    break;
                } else if(str[i]=='-'){
                    positive = false;
                    ++blankAndSign;
                    break;
                } else if(str[i]<'0'||str[i]>'9'){
                    return ans;
                } else {
                    break;
                }
            }
            ++blankAndSign;
        }
        string num = "";
        for(int i=blankAndSign;i<str.length();++i){
            if(str[i]<='9'&&str[i]>='0'){
                num+=str[i];
            }else{
                break;
            }
        }
        // 倒序
        for(int i=num.length()-1;i>=0;i--){
            if(INT_MAX-abs(ans)<(num[i]-'0')*pow(10,num.length()-1-i)){ // 作差检查，不能求和检查，求和操作本身可能溢出
                outbounded = true;
                break;
            }
            ans += (num[i]-'0')*pow(10,num.length()-1-i);
        }
        if(outbounded){
            if(positive){
                return INT_MAX;  
            }else{
                return INT_MIN;
            }
        }else{
            if(positive){
                return ans;  
            }else{
                return -ans;
            }
        }
    }
};