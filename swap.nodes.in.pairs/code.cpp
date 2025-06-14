// Leetcode 24. Swap Nodes in Pairs
// https://leetcode.com/problems/swap-nodes-in-pairs/

// My approach: 
// - Used a dummy node to simplify edge handling.
// - Swapped nodes in pairs iteratively.
// - Maintained clear pointer updates for prev, curr1, curr2, and next.
// - Time: O(n), Space: O(1)



class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next =head;

        ListNode* prev = dummy;

        while(prev->next!=NULL && prev->next->next!=NULL){

            ListNode* curr1= prev->next;
            ListNode* curr2= prev->next->next;
            ListNode* ford = curr2->next;
            
            prev->next=curr2;
            curr2->next=curr1;
            curr1->next=ford;

            prev=curr1;

        }

        ListNode* temp = dummy->next;
        delete dummy;

        return temp;


        
    }
};