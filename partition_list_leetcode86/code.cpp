# Partition List – Leetcode 86This repository contains the C++ 


###  Problem Statement
Given the head of a linked list and a value `x`, partition it such that:
- All nodes with values **less than `x`** come **before** nodes with values **greater than or equal to `x`**.
- You **must preserve** the original relative order of the nodes in each of the two partitions.

---

###  Approach Explained

I’ve solved this using a **two-list dummy node** technique:

1. **dummy1** is used to maintain the original list (with `>= x` values).
2. **dummy2** builds a new list with nodes `< x`.
3. Nodes are moved one by one while keeping their relative order.
4. Finally, connect the tail of the `< x` list to the head of the rest of the list.

This avoids creating new nodes and ensures **O(n)** time and **O(1)** space.

---

### Code

```cpp
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        ListNode* dummy1 = new ListNode(0);
        dummy1->next = head;
        ListNode* prev = dummy1;

        ListNode* dummy2= new ListNode(0);
        ListNode* tail = dummy2;
        ListNode* curr = head;

        while(curr!=NULL){
            if(curr->val < x){
                ListNode* ford = curr->next;
                tail->next = curr;
                tail = tail->next;
                prev->next = ford;
                curr = ford;
            } else {
                prev = prev->next;
                curr = curr->next;
            }
        }

        tail->next = dummy1->next;
        delete dummy1;

        ListNode* temp = dummy2->next;
        delete dummy2;

        return temp;
    }
};
