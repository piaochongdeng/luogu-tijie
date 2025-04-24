#include <bits/stdc++.h>

using namespace std;
int dis[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
int a[11000][11000];
struct p{
    int x,y,step,heart;
};
int check[1100][1100];
p point[11000000];
int main()
{
    int n,m;
    int sx,sy,ex,ey;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin >> a[i][j];
            if(a[i][j]==2)
            {
                sx=i;
                sy=j;
            }
            else if(a[i][j]==3)
            {
                ex=i;
                ey=j;
            }
        }
    }
    int tail=1,head=1;
    point[tail].x=sx;
    point[tail].y=sy;
    point[tail].step=0;
    point[tail].heart=0;
    check[sx][sy]=1;
    tail++;
    bool running=1;
    while(tail > head && running)
    {
        int disx,disy;
        for(int i=0;i<4;i++)
        {
            disx=dis[i][0]+point[head].x;
            disy=dis[i][1]+point[head].y;
            if(disx>n||disx<1||disy>m||disy<1||a[disx][disy]==0)
            {
                continue;
            }
            if(check[disx][disy] == 0)
            {
                point[tail].x=disx;
                point[tail].y=disy;
                point[tail].step=point[head].step+1;
                point[tail].heart=point[head].heart-1;
                check[disx][disy]=1;
                if(a[disx][disy]==4)
                {
                    point[tail].heart=6;
                }
                if(point[tail].heart <= 0)
                {
                    continue;
                }
                
                
                if(disx==ex && disy == ey)
                {
                    cout << point[tail].step << endl;
                    return 0;
                    //running = 0;
                    //break;
                }
                tail++;
            }
            //heart++;
        }
        head++;
    }
    cout << -1 << endl;
    //system("pause");
    return 0;
}
