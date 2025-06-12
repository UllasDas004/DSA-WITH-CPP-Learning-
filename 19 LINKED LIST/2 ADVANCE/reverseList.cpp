#include<iostream>
using namespace std;
class ListNode
{
    public:
    int val;
    ListNode *next;
    ListNode (int val)
    {
        this->val = val;
        this->next = NULL;        
    }
};
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
void enter(ListNode* head)
{
    ListNode* temp = head;
    int ch,i=2;
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
}
ListNode* reverseList(ListNode* head)
{
    ListNode* prev = NULL,*curr = head,*Next = head;
    while(curr != NULL)
    {
        Next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Next;
    }
    return prev;
}
ListNode* reverseListRec(ListNode* head)
{
    if(head == NULL || head->next == NULL) return head;
    ListNode* newHead = reverseListRec(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}
int main()
{
    int value;
    cout<<"Enter value1:- ";
    cin>>value;
    ListNode* list = new ListNode(value);
    int ch;
    cout<<"Do you want to add more values?(1 for yes/0 for no):- ";
    cin>>ch;
    if(ch) enter(list);
    cout<<"Original list.\n";
    ListNode* temp = list;
    display(list);
    cout<<"Chose method(1 for iterative/2 for recursive):- ";
    cin>>ch;
    if(ch == 1)
    {
        ListNode* revList = reverseList(list);
        cout<<"Reverse list(iterative method).\n";
        display(revList);
    }
    else if(ch == 2)
    {
        ListNode* revListRec = reverseListRec(list);
        cout<<"Reverse list(recursive method).\n";
        display(revListRec);
    }
    else cout<<"Invalid input."<<endl;
    return 0;
}