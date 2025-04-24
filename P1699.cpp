#include <iostream>
#include <queue>
using namespace std;

char a[15][15];
bool check[15][15];
int d[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

int bfs(int sx, int sy, int ex, int ey, int n, int m) {
    queue<pair<int, int>> q;
    q.push({sx, sy});
    check[sx][sy] = 1;
    int s = 0;

    while (!q.empty()) {
        int c = q.size();
        for (int i = 0; i < c; i++) {
            auto [x, y] = q.front();
            q.pop();

            if (x == ex && y == ey) 
                return s;

            for (int j = 0; j < 4; j++) {
                int nx = x + d[j][0];
                int ny = y + d[j][1];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    if (!check[nx][ny] && (a[nx][ny] == '.' || a[nx][ny] == 'L')) { // 关键修改点
                        check[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
        s++;
    }
    return -1;
}

int main() {
    int sx, sy, ex, ey;
    for (int i = 0; i < 10; i++) { 
        for (int j = 0; j < 10; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'B') {
                sx = i; sy = j;
                a[i][j] = '.'; 
            } else if (a[i][j] == 'L') {
                ex = i; ey = j;
            } else if (a[i][j] == 'R') {
                check[i][j] = 1;
            }
        }
    }
    cout << bfs(sx, sy, ex, ey, 10, 10)-1;
}