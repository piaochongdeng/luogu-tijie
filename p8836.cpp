#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<map<int, int>> p(3, map<int, int>());
    for(int i=0;i<3;i++) {
        for(int j=0;j<n;j++){
            int c;
            cin >> c;
            p[i][c]++;
        }
    }
    vector<vector<pair<int, int>>> g(3, vector<pair<int, int>>());
    for(int i=0;i<3;i++){
        for(auto &[c, cnt]: p[i]){
            g[i].emplace_back(cnt, c);
        }
        sort(g[i].begin(), g[i].end(), [&](const pair<int,int> &a, const pair<int,int> &b)->bool{
            if(a.first != b.first) return a.first < b.first;
            return a.second < b.second;
        });
    }
    pair<int, int> cur = {-1, -1};
    int cp =0, lp = -1, pc=0;
    while(1){
        if(cur.first == -1){
            if(g[cp].empty()){
                pc++;
            }
            else{
                pair<int, int> c = g[cp][0];
                cur = c;
                g[cp].erase(g[cp].begin());
                p[cp][c.second]--;
                if(p[cp][c.second]==0){
                    p[cp].erase(c.second);
                }
                if(p[cp].empty()){
                    cout << (cp+1);
                    return 0;
                }
                lp = cp;
                pc=0;
            }
        }
        else{
            bool f=false;
            for(auto it=g[cp].begin(); it!=g[cp].end();it++){
                if(it->first > cur.first || (it->first == cur.first && it->second > cur.second)){
                    cur = *it;
                    g[cp].erase(it);
                    p[cp][cur.second]--;
                    if(p[cp][cur.second]==0){
                        p[cp].erase(cur.second);
                    }
                    if(p[cp].empty()){
                        cout << (cp+1);
                        return 0;
                    }
                    lp = cp;
                    pc=0;
                    f=true;
                    break;
                }
            }
            if(!f){
                pc++;
            }
        }
        if(pc ==2){
            cur = {-1, -1};
            cp = lp;
            pc=0;
            continue;
        }
        cp = (cp +1)%3;
    }
}