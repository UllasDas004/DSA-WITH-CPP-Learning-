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
            cout<<temp->val<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};
int main()
{
    cout<<"Enter first list."<<endl;
    cout<<"Enter value1:- ";
    int value;
    cin>>value;
    ListNode* list1 = new ListNode(value);
    ListNode* temp = list1;
    int ch;
    cout<<"Do you want to add more values?(1 for yes/0 for no):- ";
    cin>>ch;
    int i=2;
    while(ch)
    {
        int value1;
        cout<<"Enter value"<<i++<<":- ";
        cin>>value1;
        ListNode* node = new ListNode(value1);
        temp->next = node;
        temp = temp->next;
        cout<<"Do you want to add more values?(1 for yes/0 for no):- ";
        cin>>ch;
    }
    cout<<"Enter second list."<<endl;
    cout<<"Enter value1:- ";
    cin>>value;
    ListNode* list2 = new ListNode(value);
    temp = list2;
    cout<<"Do you want to add more values?(1 for yes/0 for no):- ";
    cin>>ch;
    while(ch)
    {
        int i=2;
        cout<<"Enter value"<<i++<<":- ";
        cin>>value;
        ListNode* node = new ListNode(value);
        temp->next = node;
        temp = temp->next;
        cout<<"Do you want to add more values?(1 for yes/0 for no):- ";
        cin>>ch;
    }
    cout<<"First list.\n";
    list1->display(list1);
    cout<<"second list.\n";
    list2->display(list2);
    ListNode* c = new ListNode(100);
    temp = c;
    while(list1 != NULL && list2 != NULL)
    {
        if(list1->val <= list2->val)
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
    cout<<"Merged list.\n";
    c->next->display(c->next);
    return 0;
}