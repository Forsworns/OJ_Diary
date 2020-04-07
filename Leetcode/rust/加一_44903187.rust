// 倒序做
impl Solution {
    pub fn plus_one(digits: Vec<i32>) -> Vec<i32> {
        let mut digits = digits;
        digits.reverse();
        let mut add = true;
        for d in &mut digits {
            if add {
                *d += 1;
                add = false;
                if *d == 10 {
                    *d = 0;
                    add = true;
                }
            }
        }
        let size = digits.len();
        if digits[size-1] == 0 {   
            digits.push(1);
        }
        digits.reverse();
        digits
    }
}