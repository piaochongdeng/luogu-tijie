#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[11000];
    a[1]=1;
    //m[1]=1;
    int n;
    for(int i=2;i<=46;i++)
    {
        a[i]=a[i-1]+a[i-2];
        //m[a[i]]=1;
    }
    cin >> n;
    cout << a[n] << " " << a[n+1] << endl;
    //system("pause");
    return 0;
}
