#include<iostream>
using namespace std;
class Node
{
    public:
    Node *prev; // STORES ADDRESS OF PREVIOUS NODE
    int val;
    Node *next; // STORES ADDRESS OF NEXT NODE
    // CONSTRUCTOR
    Node (int val)
    {
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

class DoublyList
{
    public:
    Node* head;
    Node* tail;
    int size = 0;
    void display()
    {
        Node* temp = head;
        while(temp != NULL)
        {
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    void insertAtTail(int val)
    {
        Node* temp = new Node(val);
        if(size == 0) tail = head = temp;
        else
        {
            tail->next = temp;
            temp->prev = tail; // EXTRA
            tail = temp;
        }
        size++;
    }
    void insertAtHead(int val)
    {
        Node* temp = new Node(val);
        if(size == 0) tail = head = temp;
        else
        {
            temp->next = head;
            head->prev = temp; // EXTRA
            head = temp;
        }
        size++;
    }
    void insertAtIdx(int idx,int val)
    {
        if(idx<0 || idx>size) cout<<"Invalid index."<<endl;
        else if(idx == 0) insertAtHead(val);
        else if(idx == size) insertAtTail(val);
        else
        {
            Node* newnode = new Node(val);
            Node* temp = head;
            for(int i=1;i<=idx-1;i++) // TRAVERSING TO THE PREVIOUS POSITION OF INSERTING POSITION
            temp = temp->next;
            newnode->next = temp->next;
            temp->next = newnode;
            newnode->next->prev = newnode; // EXTRA
            newnode->prev = temp; // EXTRA
            size++;
        }
    }
    int getAtIdx(int idx)
    {
        if(idx<0 || idx>=size)
        {
            cout<<"Invalid index."<<endl;
            return -1;
        }
        else if(idx == 0) return head->val;
        else if(idx == size-1) return tail->val;
        else
        {
            Node* temp = head;
            for(int i=1;i<=idx;i++)
            temp = temp->next;
            return temp->val;
        }
    }
    void deleteAtHead()
    {
        if(size == 0) cout<<"List is empty!"<<endl;
        else
        {
            Node *temp = head->next;
            head->next = NULL;
            head = temp; //EXTRA
            head->prev = NULL; //EXTRA
            size--;
        }
    }
    void deleteAtTail()
    {
        if(size == 0) cout<<"List is empty!"<<endl;
        else
        {
            Node* temp = head;
            while(temp->next != tail)
            temp = temp->next;
            temp->next = NULL;
            tail->prev = NULL; //EXTRA
            tail = temp;
            size--;
        }
    }
    void deleteAtIdx(int idx)
    {
        if(size == 0) cout<<"List is empty!"<<endl;
        else if(idx<0 || idx>=size) cout<<"Invalid idx!"<<endl;
        else if(idx == 0) deleteAtHead();
        else if(idx == size) deleteAtTail();
        else
        {
            Node* temp = head;
            for(int i=1;i<=idx;i++)
            temp = temp->next;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            temp->next = NULL;
            temp->prev = NULL;
            size--;
        }
    }
};
int main()
{
    DoublyList list;
    list.insertAtTail(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.display();
    list.insertAtTail(40);
    list.display();
    list.insertAtHead(50);
    list.display();
    list.insertAtIdx(3,60);
    list.display();
    list.deleteAtHead();
    list.display();
    list.deleteAtTail();
    list.display();
    list.deleteAtIdx(2);
    list.display();
}