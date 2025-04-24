#include <bits/stdc++.h>

using namespace std;
map<int , int> m;
int main()
{
    int a[11000];
    a[1]=1;
    m[1]=1;
    int n;
    for(int i=2;i<=46;i++)
    {
        a[i]=a[i-1]+a[i-2];
        m[a[i]]=1;
    }
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        if(m[i]==1)
        {
            cout<< "O";
        }else
        {
            cout << "o";
        }
    }
    cout << endl;
    //system("pause");
    return 0;
}
