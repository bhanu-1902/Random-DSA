#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

Node *head = NULL;

void InsertAtEnd(int val)
{
    Node *temp1;
    Node *temp = new Node();
    temp->data = val;

    if (head != NULL)
    {
        temp1 = head;
        while (temp1->next != NULL)
        {
            temp1 = temp1->next;
        }
        temp1->next = temp;
        temp->next = NULL;
    }

    else
    {
        head = temp;
        head->next = NULL;
    }
}

void InsertAtPos(int val, int pos)
{
    int count = 1;
    Node *temp1 = head;
    Node *temp = new Node();
    temp->data = val;

    if (pos == 1)
    {
        temp->next = head;
        head = temp;
    }

    else
    {
        while (count < pos - 1)
        {
            temp1 = temp1->next;
            count++;
        }
        temp->next = temp1->next;
        temp1->next = temp;
    }
}

void InsertAtBeg(int val)
{
    Node *temp = new Node();
    temp->data = val;
    temp->next = head;
    head = temp;
}

void DeleteAtPos(int pos)
{
    int count = 1;
    Node *prev = head, *after = head;

    if (pos == 1)
    {
        head = prev->next;
        delete prev;
        return;
    }

    while (count < pos - 1)
    {
        after = after->next;
        prev = prev->next;
        count++;
    }
    after = after->next;
    prev->next = after->next;
    delete after;
}

void Reverse()
{
    Node *prev = NULL;
    Node *curr = head;
    Node *temp;

    while (curr != NULL)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
}

void ReverseRecursion(Node *temp)
{

    if (temp->next == NULL)
    {
        head = temp;
        return;
    }

    ReverseRecursion(temp->next);
    Node *prev = temp->next;
    prev->next = temp;
    temp->next = NULL;
}

void Print(Node *temp)
{

    if (temp == NULL)
    {
        cout << endl;
        return;
    }
    cout << temp->data << " ";
    temp = temp->next;
    Print(temp);
}

void ReversePrint(Node *temp)
{

    if (temp == NULL)
    {
        cout << endl;
        return;
    }
    ReversePrint(temp->next);
    cout << temp->data << " ";
}

void PrintMiddle()
{

    Node *fast = head, *slow = head;
    if (head != NULL)
    {
        while (fast->next != NULL && fast->next->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        cout << slow->data;
    }
}

void Display()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool DetectLoop()
{
    //     Node *temp=head;

    //    unordered_set<Node*> s;

    //    while(temp!=NULL){

    //        if(s.find(temp)!=s.end()) return true;

    //        s.insert(temp);

    //        temp=temp->next;
    //    }

    Node *slow = head, *fast = head;

    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }

    return false;
}

int main()
{
    int n, val;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> val;
        InsertAtEnd(val);
    }

    //head->next->next->next->next = head;

    cout << DetectLoop() << endl;
    //ReverseRecursion(head);

    //PrintMiddle();

    // ReversePrint(head);

    // Display();

    // DeleteAtPos(1);

    // Reverse();

    // Display();
}
