#include<iostream>
using namespace std;
class ListNode
{
    public:
    int val;
    ListNode* next;
    ListNode (int val)
    {
        this->val = val;
        this->next = NULL;
    }
    void display(ListNode* head)
    {
        ListNode* temp = head;
        while(temp != NULL)
        {
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};
ListNode* merge(ListNode* list1,ListNode* list2)
{
    ListNode *c = new ListNode(100);
    ListNode *temp = c;
    while(list1 != NULL && list2 != NULL)
    {
        if(list1->val<=list2->val)            
        {
        temp->next = list1;
        list1 = list1->next;
        }
        else            
        {
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }
    if(list1 == NULL) temp->next = list2;
    else temp->next = list1;
    return c->next;
}
ListNode* sortList(ListNode* head)
{
    if(head == NULL || head->next == NULL) return head;
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *a = head;
    ListNode* b = slow->next;
    slow->next = NULL;
    a = sortList(a);
    b = sortList(b);
    ListNode* c = merge(a,b);
    return c;
}
int main()
{
    cout<<"Enter list."<<endl;
    cout<<"Enter value1:- ";
    int value;
    cin>>value;
    ListNode* list = new ListNode(value);
    ListNode* temp = list;
    int ch;
    cout<<"Do you want to add more values?(1 for yes/0 for no):- ";
    cin>>ch;
    int i=2;
    while(ch)
    {
        int value;
        cout<<"Enter value"<<i++<<":- ";
        cin>>value;
        ListNode* node = new ListNode(value);
        temp->next = node;
        temp = temp->next;
        cout<<"Do you want to add more values?(1 for yes/0 for no):- ";
        cin>>ch;
    }
    cout<<"Original list.\n";
    list->display(list);
    cout<<"Sorted list.\n";
    list = sortList(list);
    list->display(list);
    return 0;
}