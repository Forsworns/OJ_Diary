// 思路是从后往前看，因为nums1后面是空着的
impl Solution {
    pub fn merge(nums1: &mut Vec<i32>, m: i32, nums2: &mut Vec<i32>, n: i32) {
        let (m,n) = (m as usize, n as usize); // index要用usize
        let mn = (m + n);
        let mut mm = (m - 1);
        let mut nn = (n - 1);

        for it in (0..mn).rev() {
            if mm >= m { // usize 越界溢出为正数
                nums1[it] = nums2[nn];
                nn -= 1;
                continue;
            }
            if nn >= n {
                nums1[it] = nums1[mm];
                mm -= 1;
                continue;
            }

            if nums1[mm] < nums2[nn] {
                nums1[it] = nums2[nn];
                nn -= 1;
            } else {
                nums1[it] = nums1[mm];
                mm -= 1;
            }
        }





    }
}