#include <bits/stdc++.h>

using namespace std;
int dis[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int a[1100][1100];
struct p {
    int x, y, step, heart;
};
int check[1100][1100];
p point[10000];

int main() {
    int n, m;
    int sx, sy, ex, ey;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 2) {
                sx = i;
                sy = j;
            } else if (a[i][j] == 3) {
                ex = i;
                ey = j;
            }
        }
    }


    int tail = 1, head = 1;
    point[tail].x = sx;
    point[tail].y = sy;
    point[tail].step = 0;
    point[tail].heart = 6; 
    check[sx][sy] = 6;
    tail++;

    while (tail > head) {
        int x = point[head].x;
        int y = point[head].y;
        int step = point[head].step;
        int heart = point[head].heart;
        head++;

        for (int i = 0; i < 4; i++) {
            int disx = x + dis[i][0];
            int disy = y + dis[i][1];
            if (disx > n || disx < 1 || disy > m || disy < 1 || a[disx][disy] == 0) {
                continue;
            }

            int next_heart = heart - 1; 
            if (next_heart <= 0) {
                continue; 
            }

            if (a[disx][disy] == 4) {
                next_heart = 6;
            }

            if (next_heart > check[disx][disy]) { 
                check[disx][disy] = next_heart;
                point[tail].x = disx;
                point[tail].y = disy;
                point[tail].step = step + 1;
                point[tail].heart = next_heart;
                tail++;

                if (disx == ex && disy == ey) {
                    cout << point[tail - 1].step << endl;
                    return 0;
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}