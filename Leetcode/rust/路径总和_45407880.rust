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
// 注意是到到叶节点...
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn has_path_sum(root: Option<Rc<RefCell<TreeNode>>>, sum: i32) -> bool {
        if root.is_none() {
            return false
        }
        let val = root.as_ref().unwrap().borrow().val;
            match (root.as_ref().unwrap().borrow().left.clone(), root.as_ref().unwrap().borrow().right.clone()) {
                (None, None) => val == sum,
                (None, nd) | (nd,None) => Self:: has_path_sum(nd,sum-val),
                (l,r) => Self:: has_path_sum(l,sum-val) || Self::has_path_sum(r, sum-val)
            }
           
    }
}