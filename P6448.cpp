#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[1100];
    int n;
    for(int i=1;i<=5;i++)
    {
        cin >> a[i];
    }
    while(a[1]!=1&&a[2]!=2&&a[3]!=3&&a[4]!=4&&a[5]!=5)
    {
        if(a[1]> a[2])
        {
            swap(a[1],a[2]);
            for(int i=1;i<=5;i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
        }
        if(a[2]> a[3])
        {
            swap(a[2],a[3]);
            for(int i=1;i<=5;i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
        }
        if(a[3]> a[4])
        {
            swap(a[3],a[4]);
            for(int i=1;i<=5;i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
        }
        if(a[4]> a[5])
        {
            swap(a[4],a[5]);
            for(int i=1;i<=5;i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
        }
        
    }
    
    //system("pause");
    return 0;
}
