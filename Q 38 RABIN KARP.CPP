#include<bits/stdc++.h>
using namespace std;
#define d 256
int main()
{
    string text,pat;
    cin>>text>>pat;
    int m=pat.length();
    int n=text.length();
    int i,j;
    int p=0;
    int t=0;
    int h=1;
    int q=101;
    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;
    for (i = 0; i < m; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= n - m; i++)
    {

        // Check the hash values of current window of text
        // and pattern. If the hash values match then only
        // check for characters one by one
        if ( p == t )
        {
            bool flag = true;
            /* Check for characters one by one */
            for (j = 0; j < m; j++)
            {
                if (text[i+j] != pat[j])
                {
                  flag = false;
                  break;
                }
                  if(flag)
                  cout<<i<<" ";

            }

            // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]

            if (j == m)
                cout<<"Pattern found at index "<< i<<endl;
        }

        // Calculate hash value for next window of text: Remove
        // leading digit, add trailing digit
        if ( i < n-m )
        {
            t = (d*(t - text[i]*h) + text[i+m])%q;

            // We might get negative value of t, converting it
            // to positive
            if (t < 0)
            t = (t + q);
        }
    }
}
