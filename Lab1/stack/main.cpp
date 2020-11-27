#include <iostream>

using namespace std;
class Node
{
public:
    int data;
    Node* prev;
    Node* next;
};
class Stack
{
private:
    Node* tail;
    Node* head;
public:
    Stack()
    {
        tail = head = NULL;
    }
    Node* createNode(int data)
    {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->prev = newNode->next = NULL;
        return newNode;
    }
    void push(Node* newNode)
    {
        if(head == NULL)
        {
            head = tail = newNode;
            head->next = NULL;
            tail->prev = NULL;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
            tail->next = NULL;
        }
    }
    Node* pop()
    {
        if(head == NULL)
        {
            cout << "can't pop, your stack is empty" << endl;
            return NULL;
        }
        else if(head == tail)
        {
            Node* newNode = head;
            head = tail = NULL;
            return newNode;
        }
        else
        {
            Node* newNode = tail;
            tail->prev->next = NULL;
            tail = tail->prev;
            return newNode;
        }
    }
    void display()
    {
        Node* current = head;
        if(current == NULL)
        {
            cout << "the displayed queue is empty" <<endl;
        }
        while(current!=NULL)
        {
            cout<< current->data << endl;
            current = current->next;
        }
    }
};
int main()
{
    Node n1;
    n1.data = 10;
    Node n2;
    n2.data = 20;
    Node n3;
    n3.data = 30;
    Stack s1;
    s1.push(&n1);
    s1.push(&n2);
    s1.push(&n3);
    cout << "the stack:" << endl;
    s1.display();
    Node* n4 = s1.pop();
    cout << "the popped value:" << endl;
    cout << n4->data<<endl;
    cout << "the stack after first pop:" << endl;
    s1.display();
    cout << "the stack after second pop:" << endl;
    s1.pop();
    s1.display();
    cout << "the stack after third pop:" << endl;
    s1.pop();
    s1.display();
    cout << "the stack after fourth pop:" << endl;
    s1.pop();
    s1.display();
    return 0;
}
