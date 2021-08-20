#include <iostream>
using namespace std;

int main()
{
    int rows;
    cin >> rows;

    for (int i = 0; i < rows; i++)
    {
        if (i == 0 || i == rows - 1)
        {
            for (int j = 0; j < rows; j++)
                cout << "*";
        }

        else
        {
            for (int j = 0; j < rows; j++)
            {
                if (j == 0 || j == rows - 1)
                    cout << "*";

                else
                    cout << " ";
            }
        }

        cout << endl;
    }
}
