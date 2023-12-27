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
        Node* next;

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
        vector<Node> vRow;
        Node* head;

        SingleLL(){
            head = nullptr;
        }

        SingleLL(SingleLL& nodeList){
            vRow = nodeList.vRow;
            head = nodeList.head;
        }

        void add(Node n){
            vRow.push_back(n);

            if (vRow.size() == 1)
                cout<<"";   // Not to give unexpected result
                head = &vRow[0];

            if(vRow.size() > 1)
                vRow[vRow.size()-2].next = &vRow[vRow.size()-1];
        }

        void deleteNode(int num)
        {
            int i = search_inVRow(num);
            auto it = vRow.begin() + i;
            vRow.erase(it);
            vRow[i].next = &vRow[i+1];
        }

        void clearList()
        {
            head = nullptr;
            for (int i = 0; i < vRow.size(); i++)
            {
                vRow[i].next = nullptr;
            }
        }

        void InsertAfter(int pos, Node n)
        {
            if(pos >= 0 && pos <= vRow.size())
            {
                /* Make an iterator pointing to position & auto for detecting the correct data type in the run time.*/
                auto it = vRow.begin() + pos;
                vRow.insert(it, n);

                int headFlag = 0;
                for (int i = 0; i < vRow.size()-1; i++)
                {
                    if(head != nullptr  || vRow[0].next != nullptr )
                    {
                        if(headFlag == 0)
                        {
                            head = &vRow[0];
                            i = -1;
                            headFlag = 1;
                            continue;
                        }
                        vRow[i].next = &vRow[i+1];
                    }else
                    {
                        cout<< "No data";
                        break;
                    }
                }
            }else{
                cout<<"invalid operation for an empty vector";
            }
        }

        bool isEmpty()
        {
            if(vRow.size() == 0)
            {
                return 0;   // Empty
            }
            return 1;   // Not Empty
        }

        int search_inVRow(int number){
            for (int i = 0; i < vRow.size(); i++)
            {
                if(number == vRow[i].data)
                    return i;
            }
        }

        void display(){
            // Print head + nodes according to their addresses.
            int headFlag = 0;
            for (int i = 0; i < vRow.size()-1; i++)
            {
                if(head != nullptr  || vRow[0].next != nullptr )
                {
                    if(headFlag == 0)
                    {
                        cout<<this->head->data<<" ";
                        i = -1;
                        headFlag = 1;
                        continue;
                    }
                    cout << vRow[i].next->data << " ";
                }else
                {
                    cout<< "No data";
                    break;
                }
            }
        }
};

int main()
{
    SingleLL s1;

    Node n1;
    n1.data = 9;
    s1.add(n1);

    Node n2;
    n2.data = 6;
    s1.add(n2);

    Node n3;
    n3.data = 4;
    s1.add(n3);

    Node n5;
    n5.data = 8;

    Node n4;
    n4.data = 5;
    s1.add(n4);

    s1.InsertAfter(3, n5);

    s1.display();

    /* cin.get(); */
    return 0;
}
