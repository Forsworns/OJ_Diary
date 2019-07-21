class Solution {
// 应用KMP算法
private:
    void calNext(int next[], const string& str){ // 数组本身就是引用类型
        next[0] = -1;
        int k=-1;
        int j = 0; 
        while(j<str.length()-1){
            if(k==-1||str[j]==str[k]){
                ++j;
                ++k;
                next[j] = k;
            }else{
                k = next[k];
            }
        }
    }
public:
    int strStr(string haystack, string needle) {
        if(needle.length()==0){
            return 0;
        }
        int *next = new int[needle.length()]();
        
        calNext(next,needle);
        
        int i=0, j=0;
        while(i<haystack.length()){
            if(j==-1||haystack[i]==needle[j]){
                ++i;
                ++j;
            }else{
                j = next[j];
            }
            
            if(j==needle.length()){
                return i-j;
            }
        }
        
        return -1;
    }
};