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
    fn child_symmetric(left: Option<Rc<RefCell<TreeNode>>>, right: Option<Rc<RefCell<TreeNode>>>) ->bool {
        match (left, right) {
            (None, None) => true,
            (None,_) | (_,None) => false,
            (Some(l),Some(r)) => {
                let (l,r) = (l.borrow(),r.borrow());
                if l.val == r.val {
                    Self::child_symmetric(l.left.clone(),r.right.clone()) && Self::child_symmetric(l.right.clone(),r.left.clone())
                } else {
                    false
                }
            }
        }
    }

    pub fn is_symmetric(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        match root {
            None => true,
            Some(node) => {
                let node = node.borrow();
                Self::child_symmetric(node.left.clone(),node.right.clone())
            }
        }
    }
}