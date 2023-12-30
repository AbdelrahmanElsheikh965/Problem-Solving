#include <iostream>

using namespace std;

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

class SingleLL
{
    public:
        Node* head;
        int vSize;

        SingleLL(){
            head = nullptr;
            vSize = 0;
        }

        // Shallow Copy - auto-written by compiler
        SingleLL(const SingleLL& singleNodeList){
            this->head  = singleNodeList.head;
            this->vSize = singleNodeList.vSize;
        }

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

        string isEmpty()
        {
            return (vSize > 0) ? "Not Empty" : "Empty";
        }

        Node* searchIn(int number)
        {
            Node* last = new Node;

            last = head;
            while(last->next != nullptr)
            {
                if(last->data == number)
                {
                    return last;
                }else
                {
                    last = last->next;
                }
            }
            return nullptr;
        }

        void InsertAfter(int posValue, Node* newNode)
        {
            Node* oldNode = new Node;
            oldNode      = searchIn(posValue);

            Node* temp   = new Node;
            temp         = oldNode->next;

            oldNode->next = newNode;
            newNode->next = temp;
            vSize++;
        }


        void deleteNode(int num)
        {
            Node * nodeIterator = new Node;
            nodeIterator = head;

            while(nodeIterator != nullptr)
            {

                // Handling if the target was the first node.
                if(nodeIterator->data == head->data && num == head->data)
                {
                    head = nodeIterator->next;
                    vSize--;
                    return;
                }
                else if(nodeIterator->next->data == num)
                {
                    // Handling if the target was in the middle of the list.
                      nodeIterator->next = nodeIterator->next->next;
                      vSize--;
                      return;
                }
                else if(nodeIterator->next->data == num && nodeIterator->next->next == nullptr )
                {
                    // Handling if the target was at the end of the list.
                    nodeIterator->next = nullptr;
                    vSize--;
                    return;
                }
                nodeIterator = nodeIterator->next;
            }

        }

        void clearList()
        {
            head = nullptr;
        }

        void bubbleSort();

        /* takes function pointer as a parameter to perform callback() */
        void display( void (*loop)(Node* HeadPtr) )
        {
            loop(head);
        }

};


// Try to let this function take callback() function as a parameter and run instead of 2 cout.
void loop(Node* HeadPtr)
{
    Node * currNode = new Node;
    currNode = HeadPtr;

    if(currNode != nullptr)
    {
        while(currNode->next != nullptr)
        {
            cout<<currNode->data;
            currNode = currNode->next;
        }
        cout<<currNode->data;
    }else
    {
        cout << "No nodes in the list";
    }
}


int main()
{
    SingleLL s1;

    Node test;
    Node* n1 = &test;
    n1->data = 9;
    s1.add(*n1);

    Node* n2 = new Node;
    n2->data = 6;
    s1.add(*n2);

    Node* n3 = new Node;
    n3->data = 8;
    s1.add(*n3);

    cout <<"---------------------Before Insert"<<endl;
    s1.display(loop);

    cout <<endl<<"---------------------After Insert"<<endl;
    Node* n4 = new Node;
    n4->data = 3;
    s1.InsertAfter(6, n4);
    s1.display(loop);

    cout <<endl<<"---------------------After Cloning s1 SLL object"<<endl;
    SingleLL& s2 = s1;
    s2.display(loop);

    cout <<endl<<"---------------------After Clearing s3 list"<<endl;
//    s1.clearList();
//    s1.display(loop);

    cout <<endl<<"---------------------After Bubble sort of s4"<<endl;
    s1.bubbleSort();
    s1.display(loop);

    cout <<endl<<"---------------------After Searching for Node(6)"<<endl;
    cout<<s1.searchIn(6)->data;

    cout <<endl<<"---------------------After Deleting Node(9)"<<endl;
    s1.deleteNode(9);
    s1.display(loop);

    cout <<endl<<"---------------------Size"<<endl;
    cout<<"Size : "<<s1.vSize<<endl;

    return 0;
}


void SingleLL::bubbleSort()
{
    Node * currNode = new Node;
    currNode = head;
    int temp;

    if(currNode != nullptr)
    {
        int flag = 1;

        while(currNode->next != nullptr)
        {
            if(currNode->data > currNode->next->data)
            {
                temp                    = currNode->data;
                currNode->data          = currNode->next->data;
                currNode->next->data    = temp;
                flag++;
                currNode = currNode->next;
            }else
            {
                currNode = currNode->next;
            }
        }

        if(flag == 1)
            return;
        else
            bubbleSort();

    }else
    {
        cout << "No Nodes To Sort";
    }
}
