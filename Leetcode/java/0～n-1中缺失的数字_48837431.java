class Solution {
    private int missingNumber(int[] nums,int l,int r){
        // l will never be equal to the r
        if(l+1==r){
            if(nums[l]==l){
                return r;
            }else{
                return l;
            }
        }
        int idx = (l+r)/2;
        if(nums[idx]==idx){
            return missingNumber(nums,idx,r);
        }else{
            return missingNumber(nums,l,idx);
        }
    }

    public int missingNumber(int[] nums) {
        return missingNumber(nums,0,nums.length);
    }
}