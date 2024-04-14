class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n == 0) return NULL;
        vector<int>v;

        for(int i=0; i<n; i++){
            ListNode* list = lists[i];
            while(list != NULL){
                v.push_back(list->val);
                if(list) list = list->next;
            }
        }
        sort(v.begin(), v.end());
        ListNode* list = new ListNode(0);
        ListNode* temp = list;

        for(int i=0; i<v.size(); i++){
            temp->next = new ListNode(v[i]);
            temp = temp->next;
        }
        v.clear();
        temp->next = NULL;
        list = list->next;

        return list;
    }
};