#include <bits/stdc++.h>

using namespace std;
map<string , string> m;
string find(string s)
{
    if(s!=m[s])
    {
        m[s]=find(m[s]);
    }
    return m[s];
}
int main()
{
    string now_name_first;
    while(1)
    {
        char c;
        string name;
        cin >> c;
        if(c=='$')
        {
            return 0;
        }
        cin >> name;
        if(c=='#')
        {
            now_name_first=name;
            if(m[name]=="")
            {
                m[name]=name;
            }
        }
        else if(c=='+')
        {
            m[name]=now_name_first;
        }
        else if(c=='?')
        {
            cout << name <<" "<< find(name) << endl;
        }
        
    }
    system("pause");
    return 0;
}
