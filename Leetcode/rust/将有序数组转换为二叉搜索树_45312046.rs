// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn sorted_array_to_bst(nums: Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
        if nums.len() == 0 {
            return None
        }
        else if nums.len() == 1 {
            return Some(Rc::new(RefCell::new(TreeNode::new(nums[0]))))
        }
        else{
            let mut nums = nums.clone(); // clone to mutable
            let idx = nums.len()/2;
            let mut right = nums.split_off(idx);
            let left = nums;
            let mut node = TreeNode::new(right.remove(0));
            node.left = Self::sorted_array_to_bst(left);
            node.right = Self::sorted_array_to_bst(right);
            return Some(Rc::new(RefCell::new(node)))
        }
    }
}