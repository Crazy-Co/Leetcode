class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* list = new ListNode(0);
        ListNode* head = list;
        while(list1 || list2){
            int val1, val2;
            val1 = list1 ? list1->val : 100;
            val2 = list2 ? list2->val : 100;
            
            if(val1 > val2){
                head->next = new ListNode(val2);
                if(list2) list2 = list2->next;
            }else{
                head->next = new ListNode(val1);
                if(list1) list1 = list1->next;
            }
            if(head) head = head->next;
        }
        return list->next;
    }
};