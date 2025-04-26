#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int size = pow(2, n);
    int a[128]; // 因为n<=7,所以最大是2^7=128

    // 读入每个队伍的能力值
    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }

    // 模拟淘汰赛
    while (size > 2)
    {
        for (int i = 0; i < size; i += 2)
        {
            // 每对队伍中能力值高的晋级
            a[i / 2] = max(a[i], a[i + 1]);
        }
        size /= 2;
    }

    // 最后剩下的两个队伍中,能力值低的是亚军
    cout << (a[0] < a[1] ? 1 : 2) << endl;

    return 0;
}