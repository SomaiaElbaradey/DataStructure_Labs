#include <iostream>

using namespace std;
class Node
{
public:
    int data;
    Node* prev;
    Node* next;
};
class LinkedList
{
private:
    Node* head;
    Node* tail;
public:
    LinkedList()
    {
        head=tail=NULL;
    }
    static Node* createNode(int data)
    {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->prev = newNode-> next = NULL;
        return newNode;
    }
    void addNode(Node* newNode)
    {
        if(head == NULL)
        {
            head = tail = newNode;
            head->next = NULL;
            tail->prev = NULL;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            tail->next = NULL;
        }
    }
    void display()
    {
        Node* current = head;
        while(current!=NULL)
        {
            cout<< current->data << endl;
            current= current->next;
        }
    }
    Node* searchNode(int data)
    {
        Node* current = head;
        while(current!= NULL)
        {
            if(current->data==data)
            {
                cout << "the searched node with value: " << data << ", exist!" <<endl;
                return current;
            }
            else
            {
                current=current->next;
            }
        }
        cout << "the searched node with value: " << data << ", doesn't exist!" << endl;
        return NULL;
    }
    void deleteNode(Node* deletedNode)
    {
        if(deletedNode == head && deletedNode == tail)
        {
            head = tail = NULL;
        }
        else if(deletedNode == head)
        {
            head->next->prev = NULL;
            head = head->next;
            head->prev = NULL;
        }
        else if(deletedNode == tail)
        {
            tail = tail->prev;
            tail->next = NULL;
        }
        else if(this->searchNode(deletedNode->data))
        {
            deletedNode->prev->next = deletedNode->next;
            deletedNode->next->prev = deletedNode->prev;
            deletedNode->next = deletedNode->prev = NULL;
        }
        else
        {
            cout << "the deleted node with the value: " << deletedNode->data << ", doesn't exist" << endl;
        }
    }
    void insertAfter(Node* newNode, Node* beforeNew)
    {
        if(beforeNew == tail)
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        else
        {
            newNode->next = beforeNew->next;
            newNode->prev = beforeNew;
            newNode->next->prev = newNode;
            beforeNew->next = newNode;
        }
    }
};
int main()
{
    Node n1;
    n1.data=1;
    Node n2;
    n2.data=20;
    LinkedList l1;
    l1.addNode(&n1);
    l1.addNode(l1.createNode(10));
    l1.addNode(&n2);
    l1.insertAfter(l1.createNode(5),&n2);
    l1.display();
    Node* n3 = l1.searchNode(10);
    Node* n4 = l1.searchNode(70);
    Node n5;
    n5.data = 80;
    l1.deleteNode(&n5);
    l1.display();
    return 0;
}
