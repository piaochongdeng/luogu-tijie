#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1000000;
bool x[N + 1];
vector<int> c;

void ai()
{
    for(int i=2;i<=N;i++)
    {
        if(!x[i])
        {
            c.push_back(i);
            for(int j=i+i;j<=N;j+=i)
            {
                x[j]=1;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ai();
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        int ans=0;
        for(int p : c)
        {
            if((ll)p * p > n) 
            {
                break;
            }
            while(n % p ==0)
            {
                ans ^= p;
                n /= p;
            }
        }
        if(n >1)
        {
            ans ^= n;
        }
            
        cout << ans << '\n';
    }
    return 0;
}