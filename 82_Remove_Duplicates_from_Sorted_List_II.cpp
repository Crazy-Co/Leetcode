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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        map<int,int> arr;
        while(curr){
            arr[curr->val]++;
            curr = curr->next;
        }

        ListNode* list = new ListNode(0);
        ListNode* temp = list;

        for(auto i:arr){
            if(i.second > 1) continue;
            else if(i.second == 1){
                temp->next = new ListNode(i.first);
                temp = temp->next;
            }
        }
        return list->next;
    }
};