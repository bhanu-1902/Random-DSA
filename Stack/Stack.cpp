#include <iostream>
using namespace std;

int a[100];
int top = -1;

bool Push(int data)
{
    if (top == 99)
        return false;
    top++;
    a[top] = data;
}

bool Pop()
{
    if (top == -1)
        return false;
    top--;
}

void Display()
{
    for (int i = 0; i <= top; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
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