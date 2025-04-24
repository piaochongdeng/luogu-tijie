#include <bits/stdc++.h>
using namespace std;

int n;
char a[1100][1100];
int c[1100][1100];
bool f[1100000];

void dfs(int x, int y, int id) {
    c[x][y] = id;
    int dx[4] = {0, 1, 0, -1}; 
    int dy[4] = {1, 0, -1, 0};
    for(int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(nx >= 1 && nx <= n && ny >= 1 && ny <= n && a[nx][ny] == '#' && c[nx][ny] == 0) {
            dfs(nx, ny, id);
        }
    }
}

bool hui(int x, int y) {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    for(int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(nx < 1 || nx > n || ny < 1 || ny > n || a[nx][ny] == '.') {
            return 0;
        }
    }
    return 1;
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    int id = 0;
    memset(c, 0, sizeof(c));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(a[i][j] == '#' && c[i][j] == 0) {
                id++;
                dfs(i, j, id);
                f[id] = true; 
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(a[i][j] == '#') {
                if(hui(i, j)) {
                    f[c[i][j]] = false;
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= id; i++) {
        if(f[i]) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}