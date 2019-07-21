class Solution {
// 与二进制加法那道一样，倒序相加解决进位问题
private:
    int myatoi(char a){
        return a-'0';
    }
    char itoa(int i){
        return i+'0';
    }
    void reverse(string &input){
        for(int i=0;i<input.length()/2;++i){
            char temp = input[i];
            input[i] = input[input.length()-1-i];
            input[input.length()-1-i] = temp;
        }   
    }
    string add(string num1,string num2){
        int i=0;
        string ans = "";
        bool carry = false;
        for(;i<min(num1.length(),num2.length());++i){
            int n1 = myatoi(num1[i]), n2 = myatoi(num2[i]);
            if(carry){
                ans+=itoa((1+n1+n2)%10);
                carry = (1+n1+n2)/10;
            }else{
                ans+=itoa((n1+n2)%10);
                carry = (n1+n2)/10;
            }
        }
        for(;i<num1.length();++i){
            int n1 = myatoi(num1[i]);
            if(carry){
                ans+=itoa((1+n1)%10);
                carry = (1+n1)/10;
            }else{
                ans+=itoa(n1);
                carry = false;
            }
        }
        for(;i<num2.length();++i){
            int n2 = myatoi(num2[i]);
            if(carry){
                ans+=itoa((1+n2)%10);
                carry = (1+n2)/10;
            }else{
                ans+=itoa(n2);
                carry = false;
            }
        }
        if(carry){
            ans+="1";
        }
        return ans;
    }
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        reverse(num1);
        reverse(num2);
        
        ans = add(num1,num2);
        
        reverse(ans);
        return ans;
    }
};