#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

Node *top = NULL;

// Node *NewNode(int val)
// {

//     Node *temp = new Node();
//     temp->data = val;
//     temp->next = NULL;
//     return temp;
// }

void Push(int val)
{
    Node *temp = new Node();
    temp->data = val;
    temp->next = top;
    top = temp;
}

void Pop()
{
    if (top == NULL)
        return;
    Node *temp = top;
    top = temp->next;
    delete temp;
}

void Display()
{

    if (top == NULL)
        cout << "Nothing\n";

    else
    {
        Node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main()
{
    Push(4);
    Push(3);
    Push(9);
    Push(6);
    Display();
    Pop();
    Display();
}