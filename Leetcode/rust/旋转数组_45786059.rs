impl Solution {
    pub fn rotate(nums: &mut Vec<i32>, k: i32) {
        let len = nums.len();
        let k = k as usize % len;
        let mut count = 0;

        for start in (0..k) {
            let mut current = start;
            let mut prev = nums[current];
            loop {
                current = (current+k)%len;
                let temp = nums[current];
                nums[current] = prev;
                prev = temp;
                count += 1;
                if current == start {
                    break;
                }
            }
            if count == len {
                break;
            }
        }

    }
}