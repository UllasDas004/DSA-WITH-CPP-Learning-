#include<iostream>
using namespace std;
class Node
{
    public:
    int val;
    Node* next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
class Stack
{
    public:
    Node* head;
    int size;
    Stack()
    {
        head = NULL;
        size = 0;
    }
    void push(int val)
    {
        Node* temp = new Node(val);
        temp->next = head;
        head = temp;
        size++;
    }
    void pop()
    {
        if(head == NULL)
        {
            cout<<"Stack is empty!"<<endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        free(temp);
        size--;
    }
    int top()
    {
        if(head == NULL)
        {
            cout<<"Stack is empty!"<<endl;
            return -1;
        }
        return head->val;
    }
    void print(Node* head)
    {
        if(head == NULL) return;
        print(head->next);
        cout<<head->val<<" ";
    }
    void display()
    {
        Node* temp = head;
        print(temp);
        cout<<endl;
    }
};
int main()
{
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.display();
    cout<<st.size<<endl;
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.size<<endl;
    cout<<st.top()<<endl;
    st.display();
    return 0;
}