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
    fn dfs(node: Option<Rc<RefCell<TreeNode>>>) -> usize {
        match node {
            None => 0,
            Some(nd) => {
                return 1+std::cmp::max(Self::dfs(nd.borrow().left.clone()),Self::dfs(nd.borrow().right.clone()))
            }
        } 
    }

    pub fn is_balanced(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        match root {
            None => true,
            Some(rt) => {
                let (l,r) = (rt.borrow().left.clone(), rt.borrow().right.clone());
                let (ld,rd) = (Self::dfs(l.clone()), Self::dfs(r.clone()));
                (ld == rd || ld == rd+1 || ld+1 ==rd) && Self::is_balanced(l.clone()) && Self::is_balanced(r.clone())
            }
        }        
    }
}