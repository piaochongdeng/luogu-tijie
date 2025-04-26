#include <iostream>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
map<int, int> m;
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    int n;
    int a[110000];
    cin >> n;
    for (int i = 1; i <= pow(2, n); i++)
    {
        cin >> a[i];
        m[a[i]] = i;
    }
    n = pow(2, n);
    sort(a + 1, a + 1 + n / 2, cmp);
    sort(a + 1 + n / 2 , a + 1 + n, cmp);
    // for (int i = 1; i <= n / 2;i++)
    // {
    //     cout << a[i] << " ";
    // }
    // cout << "\n\n";
    // for (int i = n / 2; i <= n;i++)
    // {
    //     cout << a[i] << " ";
    // }
    // cout << "\n";
    int first = a[1], second = a[n/2 + 1];
    cout << (first < second ? m[first] : m[second]) << endl;
}