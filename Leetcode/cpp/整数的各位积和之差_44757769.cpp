class Solution {
private:
    vector<int> split(int n){
        vector<int> res;
        while((n+9)/10){
            res.push_back(n%10);
            n = n/10;
        }
        return res;
    }
public:
    int subtractProductAndSum(int n) {
        int product = 1, sum = 0;
        vector<int> nums = split(n);
        for(auto &x:nums){
            product*=x;
            sum+=x;
        }
        return product-sum;
    }
};