#include <iostream>
using namespace std;
int a[1100];
int main()
{
    int n;
    for (int i = 1; i <= 1000; i++)
    {
        a[i] = 2 * i - 1;
    }
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        int all = 0;
        int k=x;
        for (int i = 1; i <= x; i += 2)
        {
            
            for (int j = 1; j <= k; j++)
            {
                all += a[j];
            }
            k-=2;
        }
        k=x-1;
        for (int i = 1; i <= x; i += 2)
        {
            
            all+=(1+k)*k/2;
            k-=2;
        }
        cout << all << endl;
    }
}