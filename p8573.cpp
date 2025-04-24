#include <bits/stdc++.h>
using namespace std;

string s[100001], t[100001];
int d[100001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    while(cin >> n){
        long long c = 0;
        long long k = 0;
        for(long long i = 0; i < n; i++){
            string m;
            cin >> m;
            if(m == "CapsLock"){
                k++;
            }
            else{
                c++;
                s[c] = m;
                d[c] = k;
                if(k % 2 == 1){
                    string y = "";
                    for(char ch : m){
                        if(ch >= 'a' && ch <= 'z'){
                            y += char(ch - 'a' + 'A');
                        }
                        else if(ch >= 'A' && ch <= 'Z'){
                            y += char(ch - 'A' + 'a');
                        }
                        else{
                            y += ch;
                        }
                    }
                    t[c] = y;
                }
                else{
                    t[c] = s[c];
                }
            }
        }
        long long q;
        cin >> q;
        while(q--){
            long long x;
            cin >> x;
            if(c == 0){
                cout << "No\n";
                continue;
            }
            long long y = (x - 1) / c;
            long long p = (x - 1) % c + 1;
            long long tot = y * k + d[p];
            if(tot % 2 == 1){
                cout << t[p] << "\n";
            }
            else{
                cout << s[p] << "\n";
            }
        }
    }
    return 0;
}