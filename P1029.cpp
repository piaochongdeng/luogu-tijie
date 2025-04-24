#include <bits/stdc++.h>

using namespace std;
long long __lcm(long long a,long long b)
{
    return a/__gcd(a,b)*b;
}
int main()
{
    int a,b;
    long long ans=0;
    cin >>a >>b;
    if(a==b)
    {
        ans=-1;
    }
    for(int i=1;i<=sqrt(a*b);i++)
    {
        if(a*b%i==0&&__gcd(i,a*b/i)==a)
        {
            ans++;
        }
    }
    cout << ans*2;
    //system("pause");
    return 0;
}
