#include <iostream>
using namespace std;

int main()
{
    int rows;
    cin >> rows;

    for (int i = 0; i < rows; i++)
    {
        // for (int j = 0; j < i; j++)
        //     cout << " ";

        if (i == 0 || i == rows - 1)
        {
            for (int j = 0; j < i; j++)
                cout << " ";
            for (int j = 0; j < rows; j++)
                cout << "*";
        }

        else
        {
            for (int j = 0; j < rows + i; j++)
            {
                if (j == i || j == rows + i - 1)
                    cout << "*";
                else
                    cout << " ";
            }
        }

        cout << endl;
    }
}