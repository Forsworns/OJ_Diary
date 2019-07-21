class Solution {
// 先求长度的公因子，然后逐个筛选
private:
    vector<int> factors;
    int num1,num2;
    void calFactor(){
        for(int i=1;i<=min(num1,num2);++i){
            if(num1%i==0 && num2%i==0){
                factors.push_back(i);
            }
        }
    }
public:
    string gcdOfStrings(string str1, string str2) {
        string ans = "";
        num1 = str1.length(), num2 = str2.length();
        calFactor();
        for(int i=factors.size()-1;i>=0;--i){
            int factor = factors[i];
            string pattern = str1.substr(0,factor);
            
            bool patternSucc = true;
            for(int j=1;j<num1/factor;++j){
                if(pattern!=str1.substr(j*factor,factor)){
                    patternSucc = false;
                    break;
                }
            }
            if(patternSucc){
                for(int j=0;j<num2/factor;++j){
                    if(pattern!=str2.substr(j*factor,factor)){
                        patternSucc = false;
                        break;       
                    }
                }
            }
            if(patternSucc){
                ans = pattern;
                break;
            }
        }
        return ans;
    }
};