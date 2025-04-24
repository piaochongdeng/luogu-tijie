#include <bits/stdc++.h>

using namespace std;
map<int , int > m;
int main()
{
    int n,m1,k;
    cin >> n >> m1 >> k;
    for(int i=1;i<=k;i++)
    {
        int x;
        cin >> x;
        m[x]=1;
    }
    int ans=0;
    int cnt=0;
    while(1)
    {
        if(cnt >= n)
        {
            cout << ans << "\n";
            return 0;
        }
        if(m[cnt]==1)
        {
            m1++;
        }
        ans++;
        cnt+=m1;
    }
    system("pause");
    return 0;
}
