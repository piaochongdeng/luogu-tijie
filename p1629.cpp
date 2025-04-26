#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int v, w;
};
vector<edge> g[1000005], g_rev[1000005]; 
struct path
{
    int v, d;
    bool operator<(const path &b) const
    {
        return d > b.d;
    }
};
priority_queue<path> q;
int dis[1000005], dis_rev[1000005]; 

void dijkstra(int start, int n, vector<edge> g[], int dis[])
{
    memset(dis, 0x3f, sizeof(int) * (n + 1));
    dis[start] = 0;
    q.push({start, 0});

    while (!q.empty())
    {
        int u = q.top().v;
        int d = q.top().d;
        q.pop();

        if (dis[u] < d)
            continue;

        for (auto &e : g[u])
        {
            int v = e.v;
            int w = e.w;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                q.push({v, dis[v]});
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});     
        g_rev[v].push_back({u, w});
    }
    dijkstra(1, n, g, dis);
    dijkstra(1, n, g_rev, dis_rev);

    int all = 0;
    for (int i = 2; i <= n; i++)
    {
        if (dis[i] != 0x3f3f3f3f && dis_rev[i] != 0x3f3f3f3f)
        {
            all += dis[i] + dis_rev[i]; // 送货和返回的时间
        }
    }

    cout << all << "\n";

    return 0;
}