#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverse(ListNode *l)
{
    ListNode *curr = l;
    ListNode *prev = NULL;
    ListNode *Next = NULL;

    while (curr)
    {
        Next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Next;
    }
    return prev;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    l1 = reverse(l1);
    l2 = reverse(l2);
    ListNode *head = new ListNode(1);
    ListNode *temp = head;

    // 3 4 2 7
    // 4 6 5

    int sum = 0;

    while (l1 || l2)
    {
        if (l1)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2)
        {
            sum += l2->val;
            l2 = l2->next;
        }
        temp->next = new ListNode(sum % 10);
        temp = temp->next;
        sum = sum / 10;
    }

    if (sum)
        temp->next = new ListNode(sum);

    head = head->next;
    head = reverse(head);
    return head;
}

int main()
{
    ListNode *l1 = new ListNode(7);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    l1->next->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode *l3 = addTwoNumbers(l1,l2);
    ListNode *head = l3; // 7807
    while(head){
        cout<<head->val<<" ";
        head = head->next;
    }   cout<<endl;

    return 0;
}