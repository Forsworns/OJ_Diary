class Solution {
// O(n)的空间自然是想用map存储，但是题目推荐O(1)空间
private:
    int numLen(int num){
        int ans=1;
        while(num/10){
            ans++;
            num = num/10;
        }
        return ans;
    }
public:
    int compress(vector<char>& chars) {
        char now='/0';
        int amount=0, ans=0;
        for(int i=0;i<chars.size();++i){
            if(chars[i]==now){
                amount++;
            }else{
                if(amount!=0){
                    chars[ans] = now;
                    ans++;
                    if(amount!=1){
                        int len = numLen(amount);
                        for(int i=len-1;i>=0;--i){
                            chars[ans] = amount/int(pow(10,i))+'0';
                            amount = amount%int(pow(10,i));
                            ans++;
                        }
                    }
                }
                now = chars[i];
                amount = 1;
            }
        }
        if(amount!=0){
            chars[ans] = now;
            ans++;
            if(amount!=1){
                int len = numLen(amount);
                for(int i=len-1;i>=0;--i){
                    chars[ans] = amount/int(pow(10,i))+'0';
                    amount = amount%int(pow(10,i));
                    ans++;
                }
            }
        }
        return ans;
    }
};