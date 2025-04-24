#include <bits/stdc++.h>

using namespace std;
int a[110000];
int cnt=0;
int n;
int ans;
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    cnt =n;
    for(int i=1;i<=cnt;i++)
    {
        for(int j=1;j<=cnt;j++)
        {
            //cout << a[i] << " " << a[j] << endl;
            if(i==j||a[i]<a[j]||a[i]%a[j]!=0)
            {
                continue;
            }
            else 
            {
                ans++;
            }
        }
    }
    cout << ans;
    //system("pause");
    return 0;
}
