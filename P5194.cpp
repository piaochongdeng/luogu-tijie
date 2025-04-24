#include <bits/stdc++.h>

using namespace std;
int n,c;
int check[1100];
int a[1100];
int minn=1e9;
void dfs(int pos,int last)
{
    if(pos>c)

    {
        minn=min(pos-last,minn);
    }
    for(int i=1;i<=n;i++)
    {
        if(check[i]==0)
        {
            check[i]=1;
            
        }
    }
}
int main()
{
    cin >> n >> c;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
   // system("pause");
    return 0;
}
