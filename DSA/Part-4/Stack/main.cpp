#include <iostream>

using namespace std;

/*
    Stack Data Structure implemented using linked list.
        ○ Push
        ○ Pop
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

class Stack
{
    public:
        Node* stk;
        int tos;
        int sSize;

        Stack(){
            stk = nullptr;
            sSize = 0;
        }

        Stack(const Stack& stackList){
            this->stk  = stackList.stk;
            this->sSize = stackList.sSize;
        }

        void push(Node n)
        {
            Node * last = new Node;
            last = stk;
            if(stk == nullptr) // means list is empty
            {
                stk = &n;
                sSize++;
            }else if(sSize == 1)
            {
                stk->next = &n;
                tos = stk->data;
                sSize++;
            }else
            {
                while(last->next != nullptr)
                {
                    last = last->next;
                }
                last->next = &n;
                sSize++;
            }
        }

        // Remove from the heading of the list
        void pop()
        {
            if(stk != nullptr && stk->next != nullptr)
            {
                stk = stk->next;
                sSize--;
            }else
            {
                cout<<"Stack is already empty!"<<endl;
            }
        }

        string isEmpty()
        {
            return (sSize > 0) ? "Not Empty" : "Empty";
        }


        /* takes function pointer as a parameter to perform callback() */
        void display( void (*loop)(Node* stkPtr) )
        {
            loop(stk);
        }

        ~Stack()
        {
            //
        }

};


// Try to let this function take callback() function as a parameter and run instead of 2 cout.
void loop(Node* stkPtr)
{
    Node * currNode = new Node;
    currNode = stkPtr;

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
        cout << "No nodes in the list"<<endl;
    }
}


int main()
{
    Stack s1;

    Node test;
    Node* n1 = &test;
    n1->data = 9;
    s1.push(*n1);

    Node* n2 = new Node;
    n2->data = 6;
    s1.push(*n2);

    Node* n3 = new Node;
    n3->data = 8;
    s1.push(*n3);

    cout<<"Top of Stack (tos) : "<<s1.tos<<endl;

    Stack& s2 = s1;
    s2.display(loop);

    cout<<endl;

    s1.pop();
    s1.display(loop);

    cout <<endl<<"---------------------"<<endl;
    cout<<"Size : "<<s2.sSize<<endl;

    return 0;
}

