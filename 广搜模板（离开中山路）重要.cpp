#include<iostream>
using namespace std;
struct point
{
	int x;
	int y;
	int step;
};
point p[1000005];
int d[4][2]= {{0,1},{1,0},{0,-1},{-1,0}};
char a[1005][1005];
int check[1005][1005];
int main()
{
	int sx,sy,ex,ey,head=1,tail=1,n;
	cin>>n;
	for(int i =1; i <=n; i++)
	{
		for(int j =1; j <=n; j++)
		{
			cin>>a[i][j];
		}
	}
	cin>>sx>>sy>>ex>>ey ;
	p[tail].x =sx;
	p[tail].y =sy;
	p[tail].step=0;
	tail++;
	check[sx][sy]=1;
	while(head<tail)
	{
		int dx,dy;
		for(int i =0; i <4; i++)
		{
			dx=p[head].x +d[i][0];
			dy=p[head].y +d[i][1];
			if(dx<1||dx>n||dy<1||dy>n)
			{
				continue;
			}
			if(check[dx][dy]==0&&a[dx][dy]=='0')
			{
				p[tail].x =dx;
				p[tail].y =dy;
				p[tail].step=p[head].step +1;
				tail++;
				check[dx][dy]=1;
				if(dx==ex&&dy==ey)
				{
					cout<<p[tail-1].step <<endl;
					return 0;
				}
			}
		}
		head++;
	}
	return 0;
}