#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    Constructor       Copy Constructor
    Add (at the end)  Display       ClearList
    IsEmpty           Search        Delete
    InsertAfter       Bubble sort (optional)
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
            //
        }
};

class SingleLL
{
    public:
        Node* head;
        int vSize;

        SingleLL(){
            head = nullptr;
            vSize = 0;
        }

//        SingleLL(SingleLL& nodeList){
//            vRow = nodeList.vRow;
//            head = nodeList.head;
//        }

        void add(Node n)
        {
            Node * last = new Node;
            last = head;
            if(head == nullptr) // means list is empty
            {
                head = &n;
                vSize++;
            }else if(vSize == 1)
            {
                head->next = &n;
                vSize++;
            }else
            {
                while(last->next != nullptr)
                {
                    last = last->next;
                }
                last->next = &n;
                vSize++;
            }
        }

        void deleteNode(int num)
        {
           //
        }

        void clearList()
        {
           // make every node points to null - search
        }


        string isEmpty()
        {
            return (vSize > 0) ? "Not Empty" : "Empty";
        }

//        Node searchIn(int number)
//        {
//            Node* last = new Node;
//            last = head;
//            while(last->next != nullptr)
//            {
//                if(last->data == number)
//                {
//                    return *last;
//                }else
//                {
//                    last = last->next;
//                }
//            }
//        }

        // 4 5   6 8 9
        // 4 5 2 6 8 9
//        void InsertAfter(int posValue, Node newNode)
//        {
//            Node oldNode = searchIn(posValue);
//            Node * temp    = oldNode.next;
//            oldNode.next = &newNode;
//            newNode.next = temp;
//        }

        // takes function pointer as a parameter to perform callback()
        void display( void (*loop)(Node* HeadPtr) )
        {
            loop(head);
        }

//        friend void loop() {};
};

// Try to let this function take callback() function as a parameter and run instead of 2 cout.
void loop(Node* HeadPtr)
{
    Node * currNode = new Node;
    currNode = HeadPtr;

    while(currNode->next != nullptr)
    {
        cout<<currNode->data;
        currNode = currNode->next;
    }
    cout<<currNode->data;
}


int main()
{
    SingleLL s1;

    Node test;
    Node* n1 = &test;   // = new Node;
    n1->data = 9;
    s1.add(*n1);

    Node* n2 = new Node;
    n2->data = 6;
    s1.add(*n2);

    Node* n3 = new Node;
    n3->data = 8;
    s1.add(*n3);

    s1.display(loop);
//    cout<<s1.searchIn().data;

    return 0;
}




