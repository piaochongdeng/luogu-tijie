#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2000005;
int a[maxn];

int main(){
    ll n;
    cin >> n;
    for(ll i=0;i<n;i++){
        cin >> a[i];
    } 
    for(ll i=1;i<=n;i++){
        for(ll j=0;j<i/2;j++){
            int t = a[j];
            a[j] = a[i-1-j];
            a[i-1-j] = t;
        }
        for(ll j=0;j<i;j++){
            a[j] = 1 - a[j];
        }
    }
    for(ll i=0;i<n;i++){
        cout << a[i];
        if(i<n-1){
            cout << " ";
        } 
        else{
            cout << "\n";
        } 
    }
    return 0;
}