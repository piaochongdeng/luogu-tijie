#include <bits/stdc++.h>

using namespace std;
const int N=1100000;
bool x1[N];
void ai()
{
    x1[1]=x1[0]=1;
    for(int i=2;i<=N;i++)
    {
        if(x1[i]==0)
        {
            for(int j=i+i;j<=N;j+=i)
            {
                x1[j]=1;
            }
        }
    }
}
int a1[11000][11000];
int main()
{
    ai();
    int n,x,y;
    cin >> n >> x >> y;
    int a=1,b=1;
    int m=1;
    while(1)
    {
        if(a1[a+1][b]||a1[a][b+1]||a1[a-1][b]||a1[a][b-1])
        {
            break;
        }
        if()
    }
    //system("pause");
    return 0;
}
