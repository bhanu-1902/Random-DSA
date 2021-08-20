#include <iostream>
using namespace std;

int main()
{
    int rows;
    cin >> rows;

    int num = rows;

    while (rows--)
    {

        for (int i = 0; i < num; i++)
            cout << "*";

        cout << endl;
    }
}