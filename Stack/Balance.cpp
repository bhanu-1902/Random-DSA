#include <iostream>
#include <stack>
using namespace std;

bool IsPair(char open, char close)
{
    if (open == '[' && close == ']')
        return true;
    if (open == '{' && close == '}')
        return true;
    if (open == '(' && close == ')')
        return true;
    return false;
}

bool CheckBalance(string str)
{
    stack<char> s;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            s.push(str[i]);

        else
        {
            if (s.empty() || !IsPair(s.top(), str[i]))
                return false;
            else
            {
                s.pop();
            }
        }
    }
    
    return s.empty();
}

int main()
{
    string str;
    cin >> str;
    cout << CheckBalance(str) << endl;
}
