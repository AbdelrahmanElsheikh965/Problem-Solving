#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    Operations
        enqueue
        dequeue
        isEmpty()
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

class Queue
{

    public:
        vector<Node> vRow;
        Node* head;
        Node* tail;

        Queue(){
            head = nullptr;
            tail = nullptr;
        }

        Queue(Queue& s){
            vRow = s.vRow;
        }

        void enqueue(Node n){
            auto it = vRow.begin() + 0;
            vRow.insert(it, n);
            if(vRow.size() == 1)
            {
                head = &n;
                tail = &n;
            }else
            {
                head = &n;
            }
        }

        void dequeue(){
            int endPosition = vRow.size()-1;
            auto it = vRow.begin() + endPosition;
            vRow.erase(it);
            if(vRow.size() == 1)
            {
                head = &vRow[0];
                tail = &vRow[0];
            }else
            {
                tail = &vRow[endPosition];
            }
        }

        string isEmpty()
        {
            if(vRow.size() == 0)
            {
                return "The queue is Empty";   // Empty
            }
            return "The queue is not Empty";
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
    Queue s1;

    Node n1;
    n1.data = 9;

    Node n2;
    n2.data = 6;

    Node n3;
    n3.data = 7;

    s1.enqueue(n1);
    s1.enqueue(n2);
    s1.enqueue(n3);
    s1.dequeue();
    s1.display();
    cout<<endl;
    cout<<"Head : "<<s1.head->data<<endl;
    cout<<s1.isEmpty();

    return 0;
}
