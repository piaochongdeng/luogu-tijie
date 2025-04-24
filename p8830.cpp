#include <bits/stdc++.h>

using namespace std;
int a[110000];
int main()
{
    int n;
    cin >> n ;
    int maxn=-1,minn=1e9;
    int all=0;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        maxn=max(maxn,a[i]);
        minn=min(minn,a[i]);
        all+=a[i];
        if(i>=3)
        {
            printf("%.2f\n",(all-minn-maxn)*1.0/(i-2));
            //cout <<  << endl;
        }
    }

    //system("pause");
    return 0;
}
