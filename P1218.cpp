#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> sp = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

bool sushu(int x)
{
    if (x <= 1)
        return false;
    for (int p : sp)
    {
        if (x == p)
            return true;
        if (x % p == 0)
            return false;
    }
    if (x <= 3)
        return true;
    if (x % 2 == 0 || x % 3 == 0)
        return false;
    int limit = sqrt(x);
    for (int i = 5; i <= limit; i += 6)
    {
        if (x % i == 0 || x % (i + 2) == 0)
            return false;
    }
    return true;
}

int n;
void dfs(int num, int pos)
{
    if (pos == n)
    {
        cout << num << '\n';
        return;
    }
    for (int i : {1, 3, 7, 9})
    {
        int all = num * 10 + i;
        if (sushu(all))
        {
            dfs(all, pos + 1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int x : {2, 3, 5, 7})
    {
        dfs(x, 1);
    }
    return 0;
}
//