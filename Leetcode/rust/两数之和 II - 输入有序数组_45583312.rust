impl Solution {
    pub fn two_sum(numbers: Vec<i32>, target: i32) -> Vec<i32> {
        let len = numbers.len();
        let mut res = Vec::with_capacity(2);
        let (mut i, mut j) = (0, len-1);
        loop {
            let temp = numbers[i] + numbers[j];
            if target == temp {
                break;
            } else if target < temp {
                j -= 1;
            } else {
                i += 1;
            }
        }
        res.push((i+1) as i32);
        res.push((j+1) as i32);
        res
    }
}