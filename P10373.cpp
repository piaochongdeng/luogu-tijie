#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

// 求和公式
ll sum_k(ll n) {
    return n * (n + 1) / 2;
}

ll sum_k2(ll n) {
    return n * (n + 1) * (2 * n + 1) / 6;
}

ll sum_k3(ll n) {
    ll s = n * (n + 1) / 2;
    return s * s;
}

ll calc(ll x) {
    ll c = (ll)cbrt(x + 0.5);  // 计算立方根下取整
    ll n = c - 1;
    ll S1 = 3 * sum_k3(n) + 3 * sum_k2(n) + sum_k(n);
    ll remain = x - c * c * c + 1;
    ll S2 = c * remain;
    ll total = S1 + S2;
    return total;
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        ll x;
        cin >> x;
        cout << calc(x) << endl;
    }
    return 0;
}