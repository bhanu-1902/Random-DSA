#include <iostream>
using namespace std;

int main()
{
    int rows;
    cin >> rows;

    // for (int i = rows; i > 0; i--)          //for number of rows
    // {
    //     for (int k = rows; k > i; k--)      //for inserting spaces before triangle
    //         cout << " ";

    //     for (int j = 0; j < i * 2 - 1; j++) //for printing stars
    //     {
    //         if (i == rows)                  //condition to print first row
    //             cout << "*";

    //         else
    //         {
    //             if (j == 0 || j == i * 2 - 2) //condition to print starting and ending stars
    //                 cout << "*";

    //             else
    //                 cout << " ";
    //         }
    //     }
    //     cout << endl;
    //}

    for (int i = rows; i > 0; i--)
    {
        if (i == rows)
            for (int j = 0; j < rows * 2 - 1; j++)
                cout << "*";

        else
        {
            for (int j = 0; j < rows * 2 - 1; j++)
            {
                if (j ==  i  - 1|| j == 2*rows - i - 1)
                    cout << "*";

                else
                    cout << " ";
            }
        }

        cout << endl;
    }
}