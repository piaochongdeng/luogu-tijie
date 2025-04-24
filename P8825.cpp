#include <bits/stdc++.h>

using namespace std;
int n,k;
int ans=0;
void dfs(int pos,int all)
{
    if(pos==n)
    {
        //cout << all << endl;
        if(all%k==0)
        {
            ans++;
        }
        return;
    }
    for(int i=1;i<=6;i++)
    {
        dfs(pos+1,all*10+i);
    }
}
int main()
{
    cin >> n >> k;    
    dfs(0,0);
    cout << ans;
    //system("pause");
    return 0;
}
