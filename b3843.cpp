#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s_temp;
    cin >> s_temp;
    string s[11000];
    int cnt = 1;
    for(int i = 0; i < s_temp.size(); i++)
    {
        if(s_temp[i] == ',')
        {
            cnt++;
            continue;
        }
        
        s[cnt] += s_temp[i];
    }

    for(int i = 1; i <= cnt; i++)
    {
        if(s[i].size() > 12 || s[i].size() < 6)
        {
            continue;
        }
        int x = 0;
        int ans = 0;
        int ans1 = 0;
        int l = 0, u = 0, d = 0, o = 0; 

        for(int j = 0; j < s[i].size(); j++)
        {
            if(s[i][j] >= 'a' && s[i][j] <= 'z')
            {
                l = 1;
                ans++;
            }
            else if(s[i][j] >= 'A' && s[i][j] <= 'Z')
            {
                u = 1;
                ans++;
            }
            else if(s[i][j] >= '0' && s[i][j] <= '9')
            {
                d = 1; 
                ans++;
            }
            else if(s[i][j] == '!' || s[i][j] == '@' || s[i][j] == '#' || s[i][j] == '$')
            {
                o = 1; 
                ans1++;
            }

            
            if(!((s[i][j] >= 'a' && s[i][j] <= 'z') ||
                 (s[i][j] >= 'A' && s[i][j] <= 'Z') ||
                 (s[i][j] >= '0' && s[i][j] <= '9') ||
                 s[i][j] == '!' || s[i][j] == '@' || s[i][j] == '#' || s[i][j] == '$'))
            {   
                x = 1;
                break;
            }
        }

        
        if(x == 0 && (l + u + d) >= 2 && o >= 1)
        {
            cout << s[i] << endl;
        }
    }

    return 0;
}