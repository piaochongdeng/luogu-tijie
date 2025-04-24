#include <bits/stdc++.h>
using namespace std;

int n;
char a[1100][1100];
char b1[1100][1100];
int dis[8][2] = { {0,-1}, {-1,0}, {1,0}, {0,1}, {-1,-1}, {1,1}, {1,-1}, {-1,1} };

int main()
{
    memset(b1, '*', sizeof(b1));
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin >> a[i][j];
        }
    }
    string s = "yizhong";
    int len = s.size();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j] == 'y'){
                for(int k=0; k<8; k++){
                    int dx = i, dy = j;
                    bool f = true;
                    for(int l=1; l<len; l++){
                        dx += dis[k][0];
                        dy += dis[k][1];
                        if(dx <1 || dx >n || dy <1 || dy >n || a[dx][dy] != s[l]){
                            f = false;
                            break;
                        }
                    }
                    if(f){
                        dx = i;
                        dy = j;
                        for(int l=0; l<len; l++){
                            b1[dx][dy] = a[dx][dy];
                            dx += dis[k][0];
                            dy += dis[k][1];
                        }
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
        {
            cout << b1[i][j];
        }
        cout << endl;
    }
    return 0;
}