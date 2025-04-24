#include <bits/stdc++.h>

using namespace std;

string cheng(string a, string b) {
    int n = a.size(), m = b.size();
    string result(n+m, '0');
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            int mul = (a[i]-'0')*(b[j]-'0') + (result[i+j+1]-'0');
            result[i+j+1] = mul %10 + '0';
            result[i+j] += mul /10;
        }
    }
    size_t start = result.find_first_not_of('0');
    if(start == string::npos) return "0";
    return result.substr(start);
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        char c;
        cin >> n >> c;
        int ans=0;
        string s=to_string(n);
        for(int i=n-1;i>=1;i--)
        {
            s=cheng(s,to_string(i));
        }
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==c)
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
    //system("pause");
    return 0;
}
