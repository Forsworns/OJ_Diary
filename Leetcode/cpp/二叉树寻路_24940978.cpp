class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int level = log2(label)+1;
        vector<int> ans;
        ans.push_back(label);
        while(level!=1){
            int pos = label-pow(2,level-1)+1;
            label = label-pos-floor((pos-1)/2.0); // (pos-1)/2
            level--;
            ans.push_back(label);
        }
        std::reverse(ans.begin(),ans.end());
        return ans;
    }
};