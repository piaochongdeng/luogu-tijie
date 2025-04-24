#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int l,r;
        cin >> l >> r;
        if(l==1&&r==2||(l==2&&r==1))
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
    //system("pause");
    return 0;
}
