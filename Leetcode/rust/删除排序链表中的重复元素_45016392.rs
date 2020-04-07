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
impl Solution {
    pub fn delete_duplicates(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut new_head = Some(Box::new(ListNode::new(std::i32::MIN)));
        let mut new_node = &mut new_head;
        let mut ite = head.as_ref();

        loop {
            match ite {
                Some(b) => {
                    if b.val != new_node.as_mut().unwrap().val {
                        new_node.as_mut().unwrap().next = Some(Box::new(ListNode::new(b.val)));
                        new_node = &mut new_node.as_mut().unwrap().next;
                    }
                    ite = b.next.as_ref();
                },
                None => break,
            }
        }


        return new_head.unwrap().next
    }
}