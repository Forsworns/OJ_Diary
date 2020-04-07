// 二分查找
impl Solution {
    pub fn search_insert(nums: Vec<i32>, target: i32) -> i32 {
        let mut temp = nums;
        let size = temp.len();
        if size == 1 {
            if temp[0] < target {
                return 1 as i32
            } else {
                return 0 as i32 // 大于等于都是要放在左边
            }
        }
        if temp[size/2] > target {
            temp.split_off(size/2);
            Self::search_insert(temp, target) as i32
        } else {
            (size/2) as i32 + Self::search_insert(temp.split_off(size/2),target)
        }
    }
}