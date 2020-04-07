impl Solution {
    pub fn two_sum(numbers: Vec<i32>, target: i32) -> Vec<i32> {
        let len = numbers.len();
        let mut res = Vec::with_capacity(2);
        for i in 0..len {
            for j in i+1..len {
                let temp = numbers[i]+numbers[j];
                if temp == target {
                    res.push((i+1) as i32);
                    res.push((j+1) as i32);
                } else if temp > target {
                    break;
                }
            }
        }
        res
    }
}