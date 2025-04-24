#include <bits/stdc++.h>
using namespace std;

int a[110000], b[110000];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i]>>b[i];
    }
    int mk=0, ms=1;
    for(int s=1;s<=5;s++){
        int c=0, m=0;
        for(int i=1;i<=n;i++){
            if(a[i]==s || b[i]==s){
                c++;
                if(c > m) m=c;
            }
            else c=0;
        }
        if(m > mk || (m == mk && s < ms)){
            mk = m;
            ms = s;
        }
    }
    cout<<mk<<" "<<ms;
}