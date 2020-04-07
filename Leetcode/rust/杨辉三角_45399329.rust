impl Solution {
    pub fn generate(num_rows: i32) -> Vec<Vec<i32>> {
        if num_rows == 0 {
            return vec![]
        }
        let num_rows = num_rows as usize;
        let mut res = vec![vec![1]];
        for i in (1..num_rows){
            res.push(vec![1]);
            for j in (1..i){
                let v = res[i-1][j-1] + res[i-1][j];
                res[i].push(v);
            }
            res[i].push(1);
        }
        res
    }
}