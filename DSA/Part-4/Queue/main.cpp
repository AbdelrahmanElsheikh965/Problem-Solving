#include <iostream>

using namespace std;

/*
    Queue Data Structure implemented using linked list.
        ○ Enqueue
        ○ Dequeue
        ○ IsEmpty
*/

class Node
{
    public:
        int  data;
        Node*  next;

        Node(){
            data = 0;
            next = nullptr;
        }

        ~Node()
        {
            // Destructor is very important to make sure every node object is deleted
        }
};

class Queue
{
    public:
        Node* head;
        Node* tail;
        int qSize;

        Queue(){
            head = nullptr;
            tail = nullptr;
            qSize = 0;
        }

        Queue(const Queue& QueueList){
            this->head  = QueueList.head;
            this->qSize = QueueList.qSize;
        }

        void enqueue(Node n)
        {
            Node * last = new Node;
            last = head;
            if(head == nullptr) // Means the queue is empty
            {
                head = &n;
                tail = &n;
                qSize++;
            }else if(qSize == 1)
            {
                head->next = &n;
                tail = &n;
                qSize++;
            }else
            {
                while(last->next != nullptr)
                {
                    last = last->next;
                }
                last->next = &n;
                tail = &n;
                qSize++;
            }
        }

        // Remove from the end of the queue.
        void dequeue()
        {
            Node* queueIterator = new Node;
            queueIterator = head;

            if(queueIterator != nullptr)
            {
                if (queueIterator->next == nullptr)     // Means qSize == 1
                {
                    head = nullptr;
                    tail = nullptr;
                    qSize = 0;
                }else
                {
                    while(queueIterator->next != tail)
                    {
                        queueIterator = queueIterator->next;
                    }
                    tail = queueIterator;
                    qSize--;
                }
            }else
            {
                cout<<"Queue is already empty!"<<endl;
            }
        }

        string isEmpty()
        {
            return (qSize > 0) ? "Not Empty" : "Empty";
        }

        /* takes function pointer as a parameter to perform callback() */
        void display( void (*loop)(Node* HeadPtr, Node* TailPtr) )
        {
            loop(head, tail);
        }

        ~Queue()
        {
            //
        }

};


// Try to let this function take callback() function as a parameter and run instead of 2 cout.
void loop(Node* HeadPtr, Node* TailPtr)
{
    Node * currNode = new Node;
    currNode = HeadPtr;

    if(currNode != nullptr)
    {
        while(currNode != TailPtr)
        {
            cout<<currNode->data;
            currNode = currNode->next;
        }
        cout<<currNode->data;
    }else
    {
        cout << "No nodes in the list"<<endl;
    }
}


int main()
{
    Queue s1;

    Node test;
    Node* n1 = &test;
    n1->data = 9;
    s1.enqueue(*n1);

    Node* n2 = new Node;
    n2->data = 6;
    s1.enqueue(*n2);

    Node* n3 = new Node;
    n3->data = 8;
    s1.enqueue(*n3);

    cout<<"Head : "<<s1.head->data<<endl;
    cout<<"Tail : "<<s1.tail->data<<endl;

    Queue& s2 = s1;
    s2.display(loop);

    cout<<endl;

    s1.dequeue();
    s1.display(loop);

    cout <<endl<<"---------------------"<<endl;
    cout<<"Size : "<<s2.qSize<<endl;

    return 0;
}

