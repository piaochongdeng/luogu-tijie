#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[110000];
        memset(a,0,sizeof(a));
        int maxn=-1;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            maxn=max(maxn,a[i]);
        }
        int x=1;
        for(int i=1;i<=n;i++)
        {
            if(maxn%a[i]!=0)
            {
                cout << "No\n";
                x=0;
                break;
            }
        }
        if(x)
        {
            cout << "Yes\n";
        }
    }
}