#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

int a[] = {6,2,5,5,4,5,6,3,7,6};
int n;
char s1[5]; // 存储4位数字

void check_and_exit() {
    int d[4];
    for(int i=0; i<4; i++) d[i] = s1[i] - '0';
    
    sort(d, d+4);
    do {
        int hour = d[0]*10 + d[1];
        int minute = d[2]*10 + d[3];
        if(hour <= 23 && minute <= 59) {
            printf("%02d:%02d\n", hour, minute);
            exit(0);
        }
    } while(next_permutation(d, d+4));
}

void dfs(int pos, int n1) {
    if(pos == 4) {
        if(n1 == 0) {
            check_and_exit();
        }
        return;
    }
    
    for(int i=0; i<10; i++) {
        if(n1 >= a[i]) {
            s1[pos] = '0' + i;
            dfs(pos+1, n1 - a[i]);
        }
    }
}

int main() {
    cin >> n;
    if(n < 8 || n > 28) { 
        cout << "Impossible" << endl;
        return 0;
    }
    
    dfs(0, n);
    cout << "Impossible" << endl;
    return 0;
}