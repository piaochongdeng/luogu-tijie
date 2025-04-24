#include <bits/stdc++.h>

using namespace std;
int n,x;
struct cmp {
    bool operator()(const int &a, const int &b) const {
        return a > b;
    }
};
map<int , int,cmp > m;
int main()
{
    cin >>n;
    for(int i=1;i<=n;i++)
    {
        int t;
        cin >> t;
        m[t]++;
    }
    cin >> x;
    int a[110000];
    int b[110000];
    int cnt=0;
    int cnt1=1;
    for(auto &i : m)
    {
        for(int j=1;j<=i.second;j++)
        {
            a[++cnt]=i.first;
            b[cnt]=cnt1;
        }
        cnt1=cnt;
    }
    for(int i=1;i<=cnt;i++)
    {
        if(a[i]==x)
        {
            cout << b[i] <<endl;
            return 0;
        }
    }

    //system("pause");
    return 0;
}
