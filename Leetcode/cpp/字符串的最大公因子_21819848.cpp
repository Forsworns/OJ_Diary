class Solution {
// 原始的思路是：先求长度的公因子，然后逐个筛选
// 事实上，不需要各个因数逐个筛选，只要核对最大公因数就行了……因为只要长度是因子，那么短的字符串是字符串因子的时候，长的肯定也是)
// 同时，也不需要核对……因为只要A+B!=B+A，则必然不可能是同一子字符串重复生成的……
private:
    vector<int> factors;
    int num1,num2;
    void calFactor(){ // 公因子用gcd算法更好…… QAQ我好辣鸡咋哪部分都不对……
        for(int i=1;i<=min(num1,num2);++i){
            if(num1%i==0 && num2%i==0){
                factors.push_back(i);
            }
        }
    }
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2!=str2+str1){
            return ""; 
        }
        num1 = str1.length(), num2 = str2.length();
        calFactor();
        int factor = factors.back();
        string pattern = str1.substr(0,factor);
            
        return pattern;
    }
};