#include <bits/stdc++.h>
using namespace std;

struct node {
    double x, y;
} a[16]; 

int n;
int check[16];
double maxn = 1e9;
double d[16][16]; 
double m[16];  

void dfs(int pos, double ansx, int last) {
    if (ansx >= maxn) {
        return;
    }
    double rem = 0;
    for (int i = 1; i <= n; i++) {
        if (check[i] == 0) {
            rem += m[i];
        }
    }
    if (ansx + rem >= maxn) {
        return;
    }

    if (pos == n) {
        maxn = ansx;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (check[i] == 0) {
            check[i] = 1;
            dfs(pos + 1, ansx + d[last][i], i);
            check[i] = 0;
        }
    }
}

int main() {
    cin >> n;
    a[0].x = 0;
    a[0].y = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            d[i][j] = sqrt((a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y - a[j].y));
        }
    }
    for (int i = 1; i <= n; i++) {
        m[i] = 1e9;
        for (int j = 0; j <= n; j++) {
            if (i != j) {
                m[i] = min(m[i], d[i][j]);
            }
        }
    }

    memset(check, 0, sizeof(check));
    dfs(0, 0.0, 0);
    printf("%.2lf\n", maxn);
    return 0;
}