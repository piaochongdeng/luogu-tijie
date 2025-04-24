#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s[11000];
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> s[i];
    }
    int x;
    for(int i=1;i<=m;i++)
    {
        cin >> x;
        if(x==1)
        {
            int a,b,c,d;
            cin >>b >> c >> d;
            s[c].insert(d,s[b]);
        }else if(x==2)
        {
            int a;
            cin >> a;
            cout << s[a] << endl;
            //cout << s[1] << " " << s[2] << endl;
        }
    }
    return 0;
}
