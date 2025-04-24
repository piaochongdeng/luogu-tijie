#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int l = 0, r = s.size() - 1;
    while(l <= r)
    {
        if((s[l] == 'q' && s[r] != 'p') ||
           (s[l] == 'p' && s[r] != 'q') ||
           (s[l] == 'b' && s[r] != 'd') ||
           (s[l] == 'd' && s[r] != 'b'))
        {
            cout << "No\n";
            return 0;
        }
        l++;
        r--;
    }
    cout << "Yes\n";
    return 0;
}