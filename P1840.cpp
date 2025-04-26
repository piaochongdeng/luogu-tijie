#include <iostream>
using namespace std;
int nxt[200005];
int main()
{
    int n, m, ans;
    cin >> n >> m;
    ans = n;
    for (int i = 1; i <= n + 1; i++)
    {
        nxt[i] = i;
    }
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        int cur = l;
        while (cur <= r)
        {
            if (nxt[cur] == cur)
            {
                nxt[cur] = r + 1;
                ans--;
                cur++;
            }
            else
            {
                cur = nxt[cur];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}