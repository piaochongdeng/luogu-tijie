#include <iostream>

using namespace std;
int x1,x2,y1,y2;
int dis[2][2]={{1,0},{0,1}};
int a[1100][1100];
int ans;
bool check[1100][1100];
void dfs(int x,int y)
{   
    if(x==x1&&y==y1)
    {
        //cout << "666\n";
        ans++;
        return;
    }
    if (x > x1 || y > y1 || x < 0 || y < 0)
    {
        return;
    }
        
    if (a[x][y])
    {
        return;
    }
        
    dfs(x + 1, y);
    dfs(x, y + 1);
}  
int main()
{
    cin >> x1 >> y1 >> x2>> y2;
    a[x2][y2]=1;
    a[x2-2][y2+1]=1;
	a[x2-1][y2+2]=1;
	a[x2+1][y2+2]=1;
	a[x2+2][y2+1]=1;
	a[x2+2][y2-1]=1;
	a[x2+1][y2-2]=1;
	a[x2-1][y2-2]=1;
	a[x2-2][y2-1]=1;
    dfs(0,0);
    cout << ans;
    //system("pause");
    return 0;
}
