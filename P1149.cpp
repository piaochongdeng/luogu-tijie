#include <iostream>
#include <map>
using namespace std;
int a[]={6,2,5,5,4,5,6,3,7,6};
int n;
struct a{
    int first;
    int second;
}num[110000];
int main()
{
    int cnt=0;
    cin >> n;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            for(int k=0;k<10;k++)
            {
                if(a[i]+a[j]+a[k]+4==n&&i+j==k&&)
                {
                    num[cnt].first=i;
                    num[cnt].second=j;
                    cnt++;
                }
            }
        }
    }
}