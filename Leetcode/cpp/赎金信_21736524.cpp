class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> counterR;
        map<char,int> counterM;
        for(int i=0;i<ransomNote.length();++i){
            if(counterR.count(ransomNote[i])<0){
                counterR.insert(make_pair(ransomNote[i],1));
            }else{
                counterR[ransomNote[i]]++;
            }
        }
        for(int i=0;i<magazine.length();++i){
            if(counterM.count(magazine[i])<0){
                counterM.insert(make_pair(magazine[i],1));
            }else{
                counterM[magazine[i]]++;
            }
        }
        for(map<char,int>::iterator it=counterR.begin();it!=counterR.end();++it){
            if(counterM.count(it->first)==0){ // magzine中没有该字
                return false;
            }
            if(counterM[it->first]<it->second){ // magzine中该字不够
                return false;
            }
        }
        return true;
    }
};