// 指数增大，O(logN)复杂度
impl Solution {
    fn split(x:i32,mut l:u64,mut u:u64) -> i32 {
        if l == u {
            return l as i32
        } 
        if u*u == x as u64 {
            u as i32
        } else if u*u < x as u64 {
            l = u;
            u *= 2;
            Self::split(x,l,u)
        } else  {
            u = (u+l)/2;
            Self::split(x,l,u)
        }
    }

    pub fn my_sqrt(x: i32) -> i32 {
        if x == 0 || x == 1 {
            return x
        }
        Self::split(x,0,2)
    }
}