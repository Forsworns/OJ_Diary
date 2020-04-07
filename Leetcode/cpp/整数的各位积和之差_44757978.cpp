class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1, sum = 0;
        while((n+9)/10){
            int num = (n%10);
            n = n/10;
            product*=num;
            sum+=num;
        }
        return product-sum;
    }
};