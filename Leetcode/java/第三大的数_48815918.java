class Solution {
    public int thirdMax(int[] nums) {
        if(nums.length==1){
            return nums[0];
        }
        if(nums.length==2){
            return Math.max(nums[0],nums[1]);
        }
        int max1, max2, max3;
        if(nums[0]>nums[1]){
            if(nums[1]>nums[2]){
                max1 = nums[0];
                max2 = nums[1];
                max3 = nums[2];
            }else if(nums[0]>nums[2]){
                max1 = nums[0];
                max2 = nums[2];
                max3 = nums[1];
            }else{
                max1 = nums[2];
                max2 = nums[0];
                max3 = nums[1];
            }
        }else{
            if(nums[1]<nums[2]){
                max1 = nums[2];
                max2 = nums[1];
                max3 = nums[0];
            }else if(nums[0]<nums[2]){
                max1 = nums[1];
                max2 = nums[2];
                max3 = nums[0];
            }else{
                max1 = nums[1];
                max2 = nums[0];
                max3 = nums[2];
            }
        }

        for(int i=3;i<nums.length;++i){
            if(nums[i]>max3){
                if(nums[i]>max2){
                    if(nums[i]>max1){
                        max3 = max2;
                        max2 = max1;
                        max1 = nums[i];
                    }else if(nums[i]<max1){
                        max3 = max2;
                        max2 = nums[i];
                    }
                }else if(max1==max2){
                        max2 = nums[i];
                }else if(nums[i]<max2){
                    max3 = nums[i];
                }
            } else if(max2==max3){
                max3 = nums[i];
            }
        }
        
        if(max1==max2||max2==max3){
            return max1;
        }
        return max3;
    }
}