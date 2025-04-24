#include <bits/stdc++.h>

using namespace std;
int n;
int a[11000];
int b[11000];
int minn=1e9;

void dfs(int s,int b1,int pos, bool flag)
{
    if(pos == n+1)
    {
        if(flag)
        {
            minn=min(minn,abs(s-b1));
        }
        return ;
    }
    dfs(s,b1,pos+1, flag);
    dfs(s*a[pos],b1+b[pos],pos+1, 1);
}

int main()
{
    cin>> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i] >> b[i];
    }
    dfs(1,0,1,0);
    cout << minn << endl;
    return 0;
}   