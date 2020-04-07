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
    pub fn min_depth(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        if root.is_none() { // special case: []
            0
        } else{
            let (l,r) = (root.as_ref().unwrap().borrow().left.clone(),root.as_ref().unwrap().borrow().right.clone());
            match (l,r) {
                (None, None) => 1,
                (None, nd) | (nd,None) => 1+Self::min_depth(nd),
                (l,r) => 1+std::cmp::min(Self::min_depth(l),Self::min_depth(r))   
            }
        }
    }
}