impl Solution {
    pub fn get_row(row_index: i32) -> Vec<i32> {
        let row_index = row_index as usize;
        let mut res = vec![0;row_index+1];
        res[0] = 1;
        for i in 1..row_index {
            res[i] = 1;
            for j in (1..i+1).rev() {
                res[j] = res[j-1] + res[j];
            }
        }
        res[row_index] = 1;
        res
    }
}