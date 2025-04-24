#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        string s1,s2;
        cin >> s1 >> s2;
        transform(s1.begin(), s1.end(), s1.begin(),
                   [](unsigned char c) { return std::tolower(c); });
        transform(s2.begin(), s2.end(), s2.begin(),
                   [](unsigned char c) { return std::tolower(c); });
        //string s3;
        int ans=0;
        for(int i=0;i<s2.size()-s1.size()+1;i++)
        {
            string s3;
            for(int j=i;j<i+s1.size();j++)
            {
                s3+=s2[j];
            }
            if(s3==s1)
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
    //system("pause");
    return 0;
}
