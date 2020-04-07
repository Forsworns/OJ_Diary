class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int ans[] = new int[num_people];
        int times = 0;
        int temp = candies;
        for(int i=0;;++i){
            temp-=(i*num_people*num_people+num_people*(num_people+1)/2);
            if(temp>0){
                times++;
            }else{
                break;
            }
        }
        temp = 0;
        for(int i=0;i<num_people;++i){
            ans[i] = (i+1)*times+times*(times-1)/2*num_people;
            temp+=ans[i];
        }
        int idx=0;
        temp = candies-temp;
        while(true){
            int now = idx+1+times*num_people;
            if(temp>=now){
                ans[idx]+=now;
                temp-=now;
                idx++;
            }else{
                ans[idx]+=temp;
                break;
            }
        }
        return ans;
    }
}