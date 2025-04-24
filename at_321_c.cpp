#include <bits/stdc++.h>

using namespace std;
int a[11000];
int main()
{
    int n;
    int cnt=1;
    cin >> n;
    for(int i=1;i<=10000000;i++)
    {
        if(cnt==n)
        {
            break;
        }
        string s=to_string(i);
        bool x=0;
        for(int j=0;j<s.size();j++)
        {
            if(s[j]!=s[j+1]+1)
            {
                x=1;
                break;
            }
        }
        if(!x)
        {
            a[cnt] = i;
            cnt++;
        }
    }
    cout << a[n] << endl;
    system("pause");
    return 0;
}
