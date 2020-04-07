impl Solution {
    pub fn rotate(nums: &mut Vec<i32>, k: i32) {
        let len = nums.len() as i32;
        let k = (k % len);
        let len = len as usize;
        for _ in 0..k {
            let last = nums[len-1];
            for i in (1..len).rev() {
                nums[i] = nums[i-1];
            } 
            nums[0] = last;
        }
    }
}