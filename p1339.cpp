#include <bits/stdc++.h>
using namespace std;
struct edge
{
    int v, w;
};
vector<edge> g[1000005];
struct path
{
    int v, d;
    bool operator<(const path &b) const
    {
        return d > b.d;
    }
};
priority_queue<path> q;
int s, t, dis[1000005];
int main()
{
    int n, m;
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    memset(dis, 0x3f, sizeof(dis));

    q.push({s, 0});
    // 第二种需要加这个
    // dis[s] = 0;
    while (!q.empty())
    {
        int u = q.top().v;
        int d = q.top().d;
        q.pop();
        if (dis[u] > d)
        {
            dis[u] = d;
            for (int i = 0; i < g[u].size(); i++)
            {
                int v = g[u][i].v;
                int w = g[u][i].w;
                if (dis[v] > dis[u] + w)
                {
                    q.push({v, dis[u] + w});
                }
            }
        }
    }
    cout << dis[t];
}