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
// 直接暴力比较是O(n^2)的复杂度，因为重复了计算高度
// 应该提前记录是否不平衡，根节点不需要子树的高度，只需要知道它是否是平衡的就行了
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    fn dfs(node: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        match node {
            None => 0,
            Some(nd) => {
                let (ld, rd) = (Self::dfs(nd.borrow().left.clone()),Self::dfs(nd.borrow().right.clone()));
                if ld != -1 && rd!=-1 && (ld == rd || ld+1 == rd|| ld == rd+1) {
                    return 1+std::cmp::max(ld,rd)
                }
                return -1
            }
        } 
    }

    pub fn is_balanced(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        match root {
            None => true,
            rt => {
                Self::dfs(rt) != -1
            }
        }        
    }
}