#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    s.append(" ");
    for(int i=0;i<s.size()-1;i++)
    {
        if(i==0)
        {
            if(s[i]==')')
            {
                cout << "()";
            }
            else if(s[i]=='[')
            {
                cout << "[]";
            }
        }
        if(s[i]=='('&&s[i+1]!=')')
        {
            cout << "()";
        }
        else if(s[i]=='['&&s[i+1]!=']')
        {
            cout << "[]";
        }
        else if(s[i]==']'&&s[i-1]!='[')
        {
            cout << "[]";
        }
        else if(s[i]==')'&&s[i-1]!='(')
        {
            cout << "()";
        }
        else
        {
            cout << s[i];
        }
    }
}