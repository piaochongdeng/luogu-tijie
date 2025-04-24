#include <bits/stdc++.h>
using namespace std;
int n;
unordered_map<int , int> m;
int a[1100000];
int cnt=0;

inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
        x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int main() {
    cin >>n ;
    for(int i=1;i<=n;i++)
    {
        int x=read();
        if(m[x]==1)
        {
            int x1= x;
            while(m[x1]!=0)
            {
                x1++;
            }
            m[x1]++;
            a[++cnt]=x1;
        }else
        {
            m[x]++;
            a[++cnt]=x; 
        }
        
    }
    for(int i=1;i<=cnt;i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
