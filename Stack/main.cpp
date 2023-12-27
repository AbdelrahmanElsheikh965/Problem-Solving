#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    Operations
        push
        pop
*/

class Node
{
    public:
        int  data;

        Node(){
            data = 0;
        }

        ~Node()
        {
            //
        }
};

class Stack
{

    public:
        vector<Node> vRow;
        Node* head;

        Stack(){
            head = nullptr;
        }

        Stack(Stack& s){
            vRow = s.vRow;
        }

        void push(Node n){
            auto it = vRow.begin() + 0;
            vRow.insert(it, n);
            head = &n;
        }

        void pop(Node n)
        {
            auto it = vRow.begin() + 0;
            vRow.erase(it);
            head = &vRow[0];
        }


        void display(){
            if(head != nullptr)
            {
                for (int i = 0; i < vRow.size(); i++)
                {
                    cout<< vRow[i].data << " ";
                }
            }else
            {
                cout<< "No data";
            }
        }
};

int main()
{
    Stack s1;

    Node n1;
    n1.data = 9;

    Node n2;
    n2.data = 6;

    s1.push(n1);
    s1.push(n2);
    s1.pop(n2);
    s1.display();
    cout<<endl;
    cout<<"Head : "<<s1.head->data;

    return 0;
}
