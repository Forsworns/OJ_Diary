class Solution {
    bool deleted = false;
public:
    bool validPalindrome(string s) {
        int idxL = 0, idxR = s.length()-1;
        while(idxL<idxR){
            if(s[idxL]==s[idxR]){
                idxL++;
                idxR--;
            }else{
                if(deleted){
                    return false;
                }else{
                    deleted = true; // 递归一次的时候，再出现不等就会直接返回false
                    if(validPalindrome(s.substr(idxL+1,idxR-idxL))){ // 删除idxL
                        idxL+=2;
                        idxR--;
                    }else if(validPalindrome(s.substr(idxL,idxR-idxL))){ // 删除idxR
                        idxL++;
                        idxR-=2;
                    }else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
