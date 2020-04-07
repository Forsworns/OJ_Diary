class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        int sum = 0;
        string ans = "";
        vector<int> counter(10,0);
        for(int x:digits){
            sum += x;
            counter[x]++;
        }
        
        int flag = sum%3;
        if(flag==1){
            for(int i=1;i<=9;i+=3){
                if(counter[i]>0){
                    counter[i]--;
                    flag--;
                    break;
                }
            }   
        }
        if(flag==2){
            for(int i=2;i<=9;i+=3){
                if(counter[i]>0){
                    counter[i]--;
                    flag-=2;
                    break;
                }
            }
        }
        if(flag==2){
            for(int i=1;i<=9;i+=3){
                while(counter[i]>0){
                    counter[i]--;
                    flag--;
                    if(flag==0) break;
                }
            }
        }
        
        if(flag==0){
            for(int i=9;i>=1;--i){
                for(int j=0;j<counter[i];++j){
                    ans+=to_string(i);
                }
            } 
        }else{
            for(int i=9;i>=1;i-=3){
                for(int j=0;j<counter[i];++j){
                    ans+=to_string(i);
                }
            } 
        }
        
        if(ans==""){
            if(counter[0]>0){
                ans="0";
            }
        }else{
            for(int j=0;j<counter[0];++j){
                ans+="0";
            }
        }
        return ans;
    }
};