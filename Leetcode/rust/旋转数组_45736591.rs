impl Solution {
    pub fn rotate(nums: &mut Vec<i32>, k: i32) {
        let len = nums.len() as i32;
        let k = k % len; 
        let k = (len - k) as usize;
        let mut last_k = nums.split_off(k);
        last_k.append(nums);
        *nums = last_k;
    }
}