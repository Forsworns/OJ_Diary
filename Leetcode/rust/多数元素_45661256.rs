use std::collections::HashMap;

impl Solution {
    pub fn majority_element(nums: Vec<i32>) -> i32 {
        let mut num_map = HashMap::new();
        for n in nums {
            let counter = num_map.entry(n).or_insert(0);
            *counter += 1;
        }
        let mut maximum = 0;
        let mut ans = 0;
        for (i,n) in num_map.into_iter() {
            if n > maximum {
                ans = i;
                maximum = n;
            }
        }
        ans
    }
}