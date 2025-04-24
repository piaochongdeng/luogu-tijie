#include <bits/stdc++.h>

using namespace std;
int maxn=
int main()
{
    string s;
    getline(cin,s);
    transform(s.begin(),s.end(),s.begin(),::tolower);
    s.erase(remove(s.begin(),s.end(),' '),s.end());
    for(int i=0;i<s.size();i++)
    {
        if(!(s[i]>='a'&&s[i]<='z')||s[i]==' ')
        {
            s.erase(i,1);
        }
    }
    
    cout << s;
    //system("pause");
    return 0;
}
