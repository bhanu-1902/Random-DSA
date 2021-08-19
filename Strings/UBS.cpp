#include <iostream>
using namespace std;

int main()
{
    string P = "giraffe", Q = "01111001111111111011111111";

    int K = 2, ans = 0, left = 0, right = 0, count = 0;

    if(K==0) ans=0;

    while (right < P.length())
    {

        while (right < P.length() && count <= K)
        {

            int pos = P[right] - 'a';

            if (Q[pos] == '0')
            {

                if (count + 1 > K)
                    break;

                else count++;
            }

            right++;

            if (count <= K)
                ans = max(ans, right - left);
        }

        while (left < right)
        {

            int pos = P[left] - 'a';

            left++;

            if (Q[pos] == '0')
                count--;

            if (count < K)
                break;
        }
    }

    cout<<ans;
    
}
