#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    string s = to_string(n);
    int len = s.size();
    ll ans = 0;
    for(int i = 1; i <= len; i++)
    {
        ll total = pow(3, i);

        ll count = 0;
        for(int j = 1; j < (1 << 3); j++)
        {
            int bits = __builtin_popcount(j);
            ll temp = pow(2, i);
            if(bits == 1)
                count += temp;
            else if(bits == 2)
                count -= temp;
            else
                count += 0;
        }
        ans += (pow(3, i) - 3 * pow(2, i) + 3);
    }

    function<void(string, bool, int, int, int)> dfs = [&](string cnt, bool tight, int cnt3, int cnt5, int cnt7) {
        if(cnt.size() > s.size())
            return;
        if(cnt.size() > 0)
        {
            ll num = stoll(cnt);
            if(num > n)
                return;
            if(cnt3 > 0 && cnt5 > 0 && cnt7 > 0)
                ans++;
        }
        if(cnt.size() == s.size())
            return;
        for(char digit : {'3', '5', '7'})
        {
            if(tight && digit > s[cnt.size()])
                continue;
            dfs(cnt + string(1, digit), tight && (digit == s[cnt.size()]), 
                cnt3 + (digit == '3' ? 1 : 0), 
                cnt5 + (digit == '5' ? 1 : 0), 
                cnt7 + (digit == '7' ? 1 : 0));
        }
    };

    dfs("", true, 0, 0, 0);
    cout << ans/2;
    return 0;
}