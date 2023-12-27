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

        LinkedList(){
            head = nullptr;
        }

        LinkedList(SingleLL& nodeList){
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

        int deleteNode(int num)
        {
            return search_inVRow(num);
//            vRow[i-1].next = &vRow[i+1];
        }

        void clearList()
        {
            for(auto i : vRow)
                vRow.clear();
            // we can also make every next pointer points to null.
        }

        void InsertAfter(int pos, int data)
        {
            if(pos >= 0 && pos <= vRow.size())
            {
                /* Make an iterator pointing to position & auto for detecting the correct data type in the run time.*/
                auto it = vRow.begin() + pos;
                Node n;
                n.data = data;
                vRow.insert(it, n);
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
            for (int i = 0; i < vRow.size(); i++)
                cout << vRow[i].data << " ";
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


    cout<< s1.head->data<<endl;
//    s1.display();
    for (int i = 0; i < s1.vRow.size(); i++)
            cout << s1.vRow[i].data << " ";

//    cout << "\n69 is found at index: "<<s1.search_inVRow(69);
//    s1.InsertAfter(0, 6);
//    Node n = *s1.head;
//    cout<<"Head data : "<< n.data;

    /* cin.get(); */
    return 0;
}
