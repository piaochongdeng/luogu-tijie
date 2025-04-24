#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> s;
        int ans1,ans2;
        ans1=ans2=0;
        for(int j=0;j<s.size();j+=2)
        {
            ans1+=s[j]-'0';
            //ans2+=s[k]-'0';
            //cout <<ans1 << " " << ans2 << endl;
        }
        for(int k=1;k<s.size();k+=2)
        {
            ans2+=s[k]-'0';
        }
        if(ans1%11==ans2%11)
        {
            cout << "Yes\n";
        }else 
        {
            cout << "No\n";
        }
    }
    //system("pause");
    return 0;
}
