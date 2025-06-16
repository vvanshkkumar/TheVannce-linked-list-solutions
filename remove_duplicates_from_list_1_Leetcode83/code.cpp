// Leetcode 83: Remove Duplicates from Sorted List
// Problem link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
// Video explanation: https://youtu.be/UFMnvPvtbqY

/*
Approach:
- Use two pointers: curr1 (current node), curr2 (next node)
- Traverse the list while curr2 is not NULL
- If both curr1 and curr2 have the same value:
    → skip curr2 by linking curr1->next to curr2->next
- Else:
    → move both pointers ahead
- This removes all duplicates in-place with O(n) time and O(1) space
*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        if(head == NULL){
            return head;
        }

        ListNode* curr1 = head;
        ListNode* curr2 = head->next;

        while(curr2 != NULL){
            if(curr1->val == curr2->val){
                curr2 = curr2->next;
                curr1->next = curr2;
            }
            else {
                curr1 = curr1->next;
                curr2 = curr2->next;
            }
        }

        return head;
    }
};
