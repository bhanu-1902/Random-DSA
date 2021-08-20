#include <iostream>
using namespace std;

int main()
{
    int rows;
    cin >> rows;

    for (int i = 0; i < rows; i++)
    {
        if (i == rows - 1)
            for (int j = 0; j < rows * 2 - 1; j++)
                cout << "*";

        else
        {
            for (int j = 0; j < rows * 2 - 1; j++)
            {
                if (j == rows - 1 + i || j == rows - 1 - i)
                    cout << "*";

                else
                    cout << " ";
            }
        }

        cout << endl;
    }
}