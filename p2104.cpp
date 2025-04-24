#include <bits/stdc++.h>

using namespace std;
int n,m;
string s;
char a[1100000000];

int main()
{
    cin >> n >> m;
    cin >> a;
    cin >> s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='*')
        {
            a[n++]='0';
        }else if(s[i]=='/')
        {
            
            n--;
        }else if(s[i]=='+')
        {
            for (int i = n - 1; i >= 0; i--) 
            {
                if (a[i] == '0') 
                {
                    a[i] = '1';
                    break;
                } else 
                {
                    a[i] = '0';
                }
            }
        }else
        {
            for (int i = n - 1; i >= 0; i--)
            {
                if (a[i] == '1') 
                {
                    a[i] = '0';
                    break;
                } else 
                {
                    a[i] = '1';
                }
            }
        }
    }
   // cout << a;
   for(int i=0;i<n;i++)
   {
        cout << a[i];
   }
   // system("pause");
    return 0;
}
