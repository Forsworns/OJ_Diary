impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        let mut i = 0;
        loop {
            if i+1 < nums.len() {
                if nums[i]==nums[i+1] {
                    nums.remove(i);
                } else {
                    i+=1;
                }
            } else {
                break;
            }
        }
        nums.len() as i32
    }
}