class Solution {
private:
    bool isVowel(char a){
        return a=='a'||a=='e'||a=='i'||a=='o'||a=='u'||a=='A'||a=='E'||a=='I'||a=='O'||a=='U';
    }
    void reverse(string &input){
        char temp;
        for(int i=0;i<input.length()/2;++i){
            temp = input[i];
            input[i] = input[input.length()-1-i];
            input[input.length()-1-i] = temp;
        }
    }
public:
    string reverseVowels(string s) {
        string ans = "";
        vector<pair<char,int>> unvowels;
        string vowels = "";
        for(int i=0;i<s.length();++i){
            if(isVowel(s[i])){
                vowels+=s[i]; // 元音
            }else{
                unvowels.push_back(make_pair(s[i],i-1-unvowels.size())); // 辅音，记录其位置
            }
        }
        
        reverse(vowels);
        
        int vecIdx = 0;
        for(;vecIdx<unvowels.size();++vecIdx){
            if(unvowels[vecIdx].second==-1){
                ans+=unvowels[vecIdx].first;
            }else{
                break;
            }
        }
        
        for(int i=0;i<vowels.size();++i){
            ans+=vowels[i];
            for(;vecIdx<unvowels.size();++vecIdx){
                if(unvowels[vecIdx].second==i){
                    ans+=unvowels[vecIdx].first;
                }else{
                    break;
                }
            }   
        }
        for(;vecIdx<unvowels.size();++vecIdx){
                ans+=unvowels[vecIdx].first;
        }
        
        return ans; // 该题和只反转数字那题一模一样
    }
};