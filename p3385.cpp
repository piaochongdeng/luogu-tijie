#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

struct Edge
{
    int v, w;
};

vector<Edge> to[1000005];
queue<int> q;
int dis[1000005];
bool inq[1000005]; 
int n, m, s;

bool spfa()
{
    int cnt[1000005];
    memset(cnt, 0, sizeof(cnt));
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        inq[now] = false; 

        for (auto &e : to[now])
        {
            int nxt = e.v, w = e.w;
            if (dis[nxt] > dis[now] + w)
            {
                dis[nxt] = dis[now] + w;
                if (!inq[nxt])
                {
                    q.push(nxt);
                    inq[nxt] = true;
                    cnt[nxt]++;
                    if (cnt[nxt] > n)
                    {
                        return false; 
                    }
                }
            }
        }
    }
    return true; 
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            to[i].clear();
        }
        fill(dis, dis + n + 1, 0x3f3f3f3f);  
        memset(inq, 0, sizeof(inq)); 
        for (int i = 1; i <= m; i++)
        {       
            int u, v, w;
            cin >> u >> v >> w;
            to[u].push_back({v, w});
        }

        dis[1] = 0; 
        q.push(1);  

        if (spfa())
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }

    return 0;
}