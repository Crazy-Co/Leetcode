/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* Next = NULL;
        while(curr){
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;
    }

    int pairSum(ListNode* head) {
        if (head == NULL)
            return 0;

        ListNode* temp = head;
        ListNode* rev = reverse(head);

        int twinSum = 0, x,y;
        while(rev){
            x = temp ? temp->val:0;
            y = rev ? rev->val:0;
            twinSum = max(x+y, twinSum);
            
            if (temp) temp = temp->next;
            if (rev) rev = rev->next;
        }
        return twinSum;
    }
};