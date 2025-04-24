#include <bits/stdc++.h>

using namespace std;
int a[11000];
int main()
{
    int T,n=92;
    
    a[1]=1;
    for(int i=2;i<=46;i++)
    {
        a[i]=a[i-1]+a[i-2];
    }
    // for(int i=1;i<=46;i++)
    // {
    //     cout <<i << " "<< a[i] << "\n";
    // }
    cin >> T;
    while(T--)
    {
        cin >> n;
        int l=1;
        int r=46;
        bool x=0;
        int ans=0;
        cout << n << "=";
        while(l<=r)
        {
            if(ans+a[l]==n)
            {
                
            }
        }
        if(x!=1)
        {
            for(int i=1;i<=n;i++)
            {
                if(a[i]==n)
                {
                    cout << n ;
                    break;
                }
            }
        }
        cout << endl;
    }
    system("pause");
    return 0;
}
