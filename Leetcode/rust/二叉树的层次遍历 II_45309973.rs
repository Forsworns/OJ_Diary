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
// dfs过程中记录depth
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    fn dfs(node: Option<Rc<RefCell<TreeNode>>>, depth: usize, nodes: &mut Vec<Vec<i32>>) {
        if node.is_none() {
            return
        }
        while nodes.len() <= depth {
            nodes.push(vec![]);
        }
        let val = node.as_ref().unwrap().borrow().val;
        nodes[depth].push(val);
        Self::dfs(node.as_ref().and_then(|nd| nd.borrow().left.clone()), depth+1, nodes);
        Self::dfs(node.as_ref().and_then(|nd| nd.borrow().right.clone()), depth+1, nodes);
    }
    pub fn level_order_bottom(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
        let mut res = vec![];
        Self::dfs(root,0,&mut res);
        res.reverse();
        res
    }
}