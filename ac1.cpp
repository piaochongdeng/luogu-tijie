#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    getline(cin,s);
    int now=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==' ')
        {
            cout << s.substr(now,i);
            cout << ',';
            now=i+1;
        }
    }
    if(!now)
    {
        cout << s ;
    }
    //system("pause");
    return 0;
}
