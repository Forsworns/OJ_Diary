class Solution {
private:
    vector<int> factors;
    void calFactor(const int &n){ // 计算因子
        for(int i=1;i<=n/2;i++){
            if(n%i==0){
               factors.push_back(i); 
            }
        }
    }
public:
    bool repeatedSubstringPattern(string s) {
        calFactor(s.length());
        for(auto &fa : factors){
            bool patternSucc = true;
            string pattern = s.substr(0,fa);
            for(int i = 1;i<s.length()/fa;++i){
                if(pattern!=s.substr(fa*i,fa)){
                    patternSucc = false;
                    break;
                }
            }   
            if(patternSucc){
                return true;
            }
        }
        return false;
    }
};