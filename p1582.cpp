#include <bits/stdc++.h>

using namespace std;
int n,k;
int ans;
int main()
{
    //cout << __builtin_popcount(13);
    
    cin >> n >> k;
    while(__builtin_popcount(n)>k)
    {
        ans+=n&-n;
        n+=n&-n;
    }
    cout << ans;
    //system("pause");
    return 0;
}
