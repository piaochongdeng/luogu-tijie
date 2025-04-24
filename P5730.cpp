#include <bits/stdc++.h>
using namespace std;

int main(){
    string s1[10][5] = {
        {"XXX", "X.X", "X.X", "X.X", "XXX"},
        {"..X", "..X", "..X", "..X", "..X"}, 
        {"XXX", "..X", "XXX", "X..", "XXX"}, 
        {"XXX", "..X", "XXX", "..X", "XXX"}, 
        {"X.X", "X.X", "XXX", "..X", "..X"}, 
        {"XXX", "X..", "XXX", "..X", "XXX"}, 
        {"XXX", "X..", "XXX", "X.X", "XXX"}, 
        {"XXX", "..X", "..X", "..X", "..X"}, 
        {"XXX", "X.X", "XXX", "X.X", "XXX"}, 
        {"XXX", "X.X", "XXX", "..X", "XXX"}  
    };
    
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    string a = "", b = "", c = "", d = "", e = "";
    
    for(int i = 1; i <= n; i++){
        int x = s[i-1] - '0';
        for(int j = 0; j < 3; j++){
            a += s1[x][0][j];
            b += s1[x][1][j];
            c += s1[x][2][j];
            d += s1[x][3][j];
            e += s1[x][4][j];
        }
        if(i != n){
            a += '.';
            b += '.';
            c += '.';
            d += '.';
            e += '.';
        }
    }
    cout << a << "\n" << b << "\n" << c << "\n" << d << "\n" << e << "\n";
    
    return 0;
}