#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* temp1=l1;
    ListNode* temp2=l2;
    ListNode* dummy= new ListNode(0);
    ListNode* temp3=dummy;
    
    int carry = 0;
    while(temp1!=NULL || temp2!=NULL){
        int x = temp1!=NULL?temp1->val:0;
        int y = temp2 !=NULL?temp2->val:0;
        int sum = x+y+carry;
        carry = sum/10;
        
        temp3->next = new ListNode(sum%10);
        if(temp1!=NULL) temp1=temp1->next;
        if(temp2!=NULL)  temp2=temp2->next;
        if(temp3!=NULL)  temp3=temp3->next;
    }
    
    if(carry>0){
        temp3->next = new ListNode(carry);
    }
    
    return dummy->next;
}


int main(){
    

    return 0;
}