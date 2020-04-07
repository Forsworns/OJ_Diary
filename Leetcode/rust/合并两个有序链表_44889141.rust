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
    pub fn merge_two_lists(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        // initialize
        let mut head = Some(Box::new(ListNode::new(std::i32::MIN)));
        let mut l = &mut head;
        let mut l1 = l1.as_ref();
        let mut l2 = l2.as_ref();
        loop {
            match (l1,l2) {
                (Some(b1), Some(b2)) => {
                    if b1.val<b2.val {
                        l.as_mut().unwrap().next = Some(Box::new(ListNode::new(b1.val))); 
                        l1 = b1.next.as_ref();
                    } 
                    else{                        
                        l.as_mut().unwrap().next = Some(Box::new(ListNode::new(b2.val))); 
                        l2 = b2.next.as_ref();
                    }
                    l = &mut l.as_mut().unwrap().next; 
                },
                (None, _) => break,
                (_, None) => break,
            }
        }
        loop {
            l1 = match l1 {
                Some(b1) => {
                    l.as_mut().unwrap().next = Some(Box::new(ListNode::new(b1.val))); 
                    l = &mut l.as_mut().unwrap().next;
                    b1.next.as_ref()
                },
                None => break,
            }
        }
        loop {
            l2 = match l2 {
                Some(b2) => {
                    l.as_mut().unwrap().next = Some(Box::new(ListNode::new(b2.val))); 
                    l = &mut l.as_mut().unwrap().next;
                    b2.next.as_ref()
                },
                None => break,
            }
        }
        head.unwrap().next
    }
}