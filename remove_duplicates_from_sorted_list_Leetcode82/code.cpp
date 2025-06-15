// Leetcode 82. Remove Duplicates from Sorted List II
// Problem link: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii
// Related GFG article: https://www.geeksforgeeks.org/remove-duplicates-from-a-sorted-linked-list/
// My custom approach explained on YouTube with a blackboard walkthrough
// GitHub: https://github.com/TheVannce/Leetcode-Problems

/*
Approach:
- Use a dummy node before the head to handle cases where head itself is part of duplicates
- Use two pointers (curr1 and curr2) to detect a sequence of duplicates
- If duplicates are found, skip the entire block
- Update prev->next to point to the next non-duplicate node
*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;

        while (prev->next != NULL && prev->next->next != NULL) {

            ListNode* curr1 = prev->next;
            ListNode* curr2 = prev->next->next;

            if (curr1->val != curr2->val) {
                prev = prev->next;
            } else {
                while (curr2 != NULL && curr1->val == curr2->val) {
                    curr1 = curr1->next;
                    curr2 = curr2->next;
                }
                prev->next = curr2;
            }
        }

        ListNode* result = dummy->next;
        delete dummy;

        return result;
    }
};
