impl Solution {
    pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
        let mut i=0;
        loop {
            if i < nums.len() {
                if nums[i] == val {
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