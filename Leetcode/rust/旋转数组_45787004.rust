impl Solution {
    fn reverse(nums: &mut Vec<i32>, mut l: i32, mut r:i32) {
        while l<r {
            nums[l as usize] ^= nums[r as usize];
            nums[r as usize] ^= nums[l as usize];
            nums[l as usize] ^= nums[r as usize];
            l+=1;
            r-=1;
        }
    }

    pub fn rotate(nums: &mut Vec<i32>, k: i32) {
        let len = nums.len() as i32;
        let k = (k % len);
        let mut s1len = k;

        Self::reverse(nums,0,len-1);
        Self::reverse(nums,0,s1len-1);
        Self::reverse(nums,s1len,len-1);

    }
}