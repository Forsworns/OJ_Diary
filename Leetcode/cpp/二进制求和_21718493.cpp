class Solution {
// 不要转换成十进制处理，会溢出，longlong也不够，直接字符串处理
// 一个trick是倒过来求和，大数求和也使用了这个trick，主要是方便进位
private:
    char itoa(const int& i){
        return i+'0';
    }
    int myatoi(const char& a){
        return a-'0';
    }
    void reverse(string &str){
        char temp;
        for(int i=0;i<str.length()/2;++i){
            temp = str[i];
            str[i] = str[str.length()-1-i];
            str[str.length()-1-i] = temp;
        }
    }
    string add(const string &a, const string &b){
        string ans = "";
        bool carry = false;
        int i=0;
        for(;i<min(a.length(),b.length());++i){
            int digit = 0;
            if(carry){
                digit+=1;
            }
            digit += (myatoi(a[i])+myatoi(b[i]));
            carry = bool(digit/2);
            ans += itoa(digit%2);
        }
        for(;i<a.length();++i){ // 类似归并排序的时候，不必考虑具体是哪个多了，直接在for这里限制
            int digit = 0;
            if(carry){
                digit+=1;
            }
            digit += (myatoi(a[i]));
            carry = bool(digit/2);
            ans += itoa(digit%2);
        }
        for(;i<b.length();++i){
            int digit = 0;
            if(carry){
                digit+=1;
            }
            digit += (myatoi(b[i]));
            carry = bool(digit/2);
            ans += itoa(digit%2);
        }
        if(carry){ // 最后检查一下是否发生进位
            ans += "1";
        }
        return ans;
    }
public:
    string addBinary(string a, string b) {
        string ans = "";
        reverse(a);
        reverse(b);
        ans = add(a,b);
        reverse(ans);
        return ans;
    }
};