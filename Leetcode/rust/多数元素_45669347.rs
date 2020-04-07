impl Solution {
    pub fn majority_element(nums: Vec<i32>) -> i32 {
        let mut counter = 0;
        let mut ans = nums[0];
        for n in nums {
            if ans == n {
                counter += 1;
            } else {
                counter -= 1;
                if counter == 0 {
                    ans = n;
                    counter = 1;
                }
            }
        }
        ans
    }
}