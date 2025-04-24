#include <bits/stdc++.h>

using namespace std;
int a[1100000];
int main()
{
    int n;
    cin >> n;
    
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for(int i=1;i<=n;i++)
    {
        ans+=max(a[i],a[i-1]);
    }
    cout << ans- a[1];
    system("pause");
    return 0;
}
