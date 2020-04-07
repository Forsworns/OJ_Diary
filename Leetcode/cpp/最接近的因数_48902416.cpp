class Solution {
public:
    vector<int> closestDivisors(int num) {
        vector<int> ans;
        
        int num1 = num+1;
        int l1 = floor(sqrt(num1));
        int r1 = num1/l1;
        
        while(l1*r1!=num1){
            l1--;
            r1 = num1/l1;
        }
        
        int num2 = num+2;
        int l2 = floor(sqrt(num2));
        int r2 = num2/l2;
        
        while(l2*r2!=num2){
            l2--;
            r2 = num2/l2;
        }
        
        if(r1-l1>r2-l2){
            ans.push_back(l2);
            ans.push_back(r2);
        }else{
            ans.push_back(l1);
            ans.push_back(r1);
        }
        
        return ans;
    }
};