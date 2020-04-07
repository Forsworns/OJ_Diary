impl Solution {
    pub fn title_to_number(s: String) -> i32 {
        let mut ans = 0;
        let len = s.len() as u32;
        let base = 26 as i32;
        for (i,c) in s.chars().enumerate() {
            let i = i as u32;
            ans = ans + (c as u8 as i32 - 'A' as u8 as i32 +1) * base.pow(len-1-i);
        } 
        ans
    }
}