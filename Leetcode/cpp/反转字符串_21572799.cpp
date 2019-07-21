class Solution {
public:
    void reverseString(vector<char>& s) {
        const int L = s.size()-1;
        for(int i = 0; i < L/2.0; ++i){ // 注意用2.0强制成小数，否则自动转换成了int
            char temp = s[i];
            s[i] = s[L-i];
            s[L-i] = temp;
        }
    }
};