#include <bits/stdc++.h>

using namespace std;
int n,m;
int check[1100][1100];
int dis[4][2]={{0,-1},{-1,0},{1,0},{0,1}};
char a[1100][1100];
int step=0;
void dfs(int x,int y)
{
    for(int i=0;i<4;i++)
    {
        int disx=dis[i][0]+x;
        int disy=dis[i][1]+y;
        if(a[disx][disy]=='#'||disx > n || disx < 1 || disy > m || disy <1)
        {
            continue;
        }
        if(check[disx][disy]==0&&a[disx][disy]=='.')
        {
            check[disx][disy]=1;
            step++;
            dfs(disx,disy);
        }
    }
}
int main()
{
    cin >> m >> n;
    int sx,sy;
    step++;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin >> a[i][j];
            if(a[i][j]=='@')
            {
                sx=i,sy=j;
            }
        }
    }
    check[sx][sy]=1;
    dfs(sx,sy);
    cout << step;
    //system("pause");
    return 0;
}
