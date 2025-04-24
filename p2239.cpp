#include <bits/stdc++.h>
using namespace std;

int answer(int n, int x, int y) {
    int k = min({x-1, y-1, n-x, n-y});
    int a = n - 2*k; 
    
    if(a == 1) return n*n; 
    
    int st = 1 + 4*k*(n -k); 

    if(x == k+1 && y > k+1)         
        return st + (y - (k+1));
    else if(y == n-k && x > k+1)    
        return st + (a-1) + (x - (k+1));
    else if(x == n-k && y < n-k)    
        return st + 2*(a-1) + (n-k - y);
    else                            
        return st + 3*(a-1) + (n-k - x);
}

int main() {
    int n, i, j;
    cin >> n >> i >> j;
    cout << answer(n, i, j) << endl;
    return 0; 
}