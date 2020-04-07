// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }

// 刚刚那个循环写法恶心人，递归就清爽多了！
impl Solution {
    pub fn merge_two_lists(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        match (l1, l2) {
            (Some(mut l), Some(mut r))=>{
                if l.val < r.val {
                    l.next = Self::merge_two_lists(l.next,Some(r));
                    Some(l)
                }else{
                    r.next = Self::merge_two_lists(Some(l),r.next);
                    Some(r)
                }
            },
            (l, None) => {
                l
            },
            (None, r) => {
                r
            },
            (None, None) => {
                None
            }
        }
    }
}