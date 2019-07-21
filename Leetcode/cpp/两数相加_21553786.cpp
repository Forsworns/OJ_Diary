/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *ans = new ListNode(0);
		ListNode *start = ans;
		bool flag = false;
		while (l1 !=NULL && l2 != NULL) {
			ans->val = (l1->val + l2->val + int(flag)) % 10;
			flag = bool((l1->val + l2->val + int(flag)) / 10);
			if (l1->next != NULL || l2->next != NULL || flag) {
				ans->next = new ListNode(0); 
				ans = ans->next;
			}
			l1 = l1->next;
			l2 = l2->next;
		}
		while (l1 != NULL) {
			ans->val = (l1->val + int(flag)) % 10;
			flag = bool((l1->val + int(flag)) / 10);
			if (l1->next != NULL || flag) {
				ans->next = new ListNode(0);
				ans = ans->next;
			}
			l1 = l1->next;
		}
		while (l2 != NULL) {
			ans->val = (l2->val + int(flag)) % 10;
			flag = bool((l2->val + int(flag)) / 10);
			if (l2->next != NULL || flag) { 
				ans->next = new ListNode(0); 
				ans = ans->next;
			}
			l2 = l2->next;
		}
		if (flag) {
			ans->val = 1;
		}
		return start;
	}
};