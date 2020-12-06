#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template<class T>
class Node
{
    public:
        T *Data;
        Node *Next;
        Node(T *data)
        {
            Data = data;
            Next = NULL;
        }
};

template<class T>
class LinkedList
{
    Node<T> *head, *tail;
    Node<T> *current;
    public:
        LinkedList()
        {
            head = tail = NULL;
        }
        void Add(T *data)
        {
            if(head == NULL)
            {
                head = tail = new Node<T>(data);
            }
            else
            {
                Node<T> *newNode = new Node<T>(data);
                tail->Next = newNode;
                tail = newNode;
            }
        }
        T* BeginIteration()
        {
            current = head;
            return current != NULL ? current->Data : NULL;
        }
        T* GetNext()
        {
            current = current->Next;
            return current != NULL ? current->Data : NULL;
        }
};

#endif // LINKEDLIST_H
