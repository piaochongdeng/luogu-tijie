#include <bits/stdc++.h>
using namespace std;

char s[1002][1002];
int v[1002][1002];

int main(){

    int T;
    cin>>T;
    while(T--){
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            cin>>(&s[i][1]);
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                v[i][j]=0;
            }
        }
        v[x][y]=1;
        int c=1;
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        for(int i=0;i<k;i++){
            int p = x + dx[d];
            int q = y + dy[d];
            if(p>=1 && p<=n && q>=1 && q<=m && s[p][q]=='.'){
                x = p;
                y = q;
                if(v[x][y]==0){
                    v[x][y]=1;
                    c++;
                }
            }
            else{
                d = (d + 1) % 4;
            }
        }
        cout<<c<<"\n";
    }
    return 0;
}