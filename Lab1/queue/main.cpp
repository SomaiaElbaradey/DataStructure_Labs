#include <iostream>

using namespace std;
class Node
{
public:
    int data;
    Node* prev;
    Node* next;
};
class Queue
{
private:
    Node* tail;
    Node* head;
public:
    Queue()
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
    void enqueue(Node* newNode)
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
    Node* dequeue()
    {
        if(head == NULL)
        {
            cout << "can't dequeue, your queue is empty" << endl;
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
            Node* newNode = head;
            head->next->prev = NULL;
            head = head->next;
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
    Queue q1;
    q1.enqueue(&n1);
    q1.enqueue(&n2);
    q1.enqueue(&n3);
    cout << "the queue:" << endl;
    q1.display();
    Node* n4 = q1.dequeue();
    cout << "the dequeued value:" << endl;
    cout << n4->data<<endl;
    cout << "the queue after first dequeue:" << endl;
    q1.display();
    cout << "the queue after second dequeue:" << endl;
    q1.dequeue();
    q1.display();
    cout << "the queue after third dequeue:" << endl;
    q1.dequeue();
    q1.display();
    cout << "the queue after fourth dequeue:" << endl;
    q1.dequeue();
    q1.display();
    return 0;
}
