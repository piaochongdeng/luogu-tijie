#include <bits/stdc++.h>

using namespace std;
string s[1100000];
int main()
{
    string n,m;
    int q;
    cin >> n >> m >> q;
    int cnt=0;

    while(q--)
    {
        char c=n[n.size()-1];
        int z=c-'0';
        string s1=to_string(z*z);
        char d;
        if(s1.size()==1)
        {
            d=s1[0];
        }
        else if(s1.size()==2)
        {
            d=s1[1];
        }
        string s2;
        if(d != '0') // 添加条件，避免插入'0'
            s2+=d;
        for(int i=0;i<n.size()-1;i++)
        {
            s2+=n[i];
        }
        n=s2;
        s[cnt]=s2;
        cnt++;
        if(s2==m)
        {
            for(int i=0;i<cnt;i++)
            {
                cout << s[i] << endl;
            }
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}