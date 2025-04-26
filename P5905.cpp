// judge: https://www.luogu.com.cn/problem/P5905
// johnson
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
struct edge
{
    int v, w;
    edge(int v, int w) : v(v), w(w) {}
    bool operator<(const edge &rhs) const
    {
        return w > rhs.w;
    }
};
vector<edge> g[3005];
priority_queue<edge> pq;
queue<int> q;
long long len[3005];
long long h[3005], dis[3005], vis[3005], n, m, ans;
bool SPFA()
{
    memset(h, 0x3f, sizeof(h));
    memset(len, 0, sizeof(len));
    memset(vis, 0, sizeof(vis));
    h[n + 1] = 0;
    vis[n + 1] = 1;
    q.push(n + 1);
    while (q.size())
    {
        int now = q.front();
        q.pop();
        vis[now] = 0;
        for (auto e : g[now])
        {
            int nxt = e.v, w = e.w;
            if (h[now] + w < h[nxt])
            {
                h[nxt] = h[now] + w;
                len[nxt] = len[now] + 1;
                if (len[nxt] > n)
                {
                    return false;
                }
                if (!vis[nxt])
                {
                    vis[nxt] = 1;
                    q.push(nxt);
                }
            }
        }
    }
    return true;
}
void dijkstra(int s)
{
    fill(dis + 1, dis + 1 + n, 1e9);
    dis[s] = 0;
    pq.push(edge{s, 0});
    while (pq.size())
    {
        int now = pq.top().v;
        int w = pq.top().w;
        pq.pop();
        if (w > dis[now])
            continue;
        for (auto e : g[now])
        {
            int nxt = e.v, w1 = e.w;
            if (dis[nxt] > dis[now] + w1)
            {
                dis[nxt] = dis[now] + w1;
                pq.push(edge{nxt, dis[nxt]});
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(edge(v, w));
    }
    for (int i = 1; i <= n; i++)
    {
        g[n + 1].push_back(edge(i, 0));
    }
    if (!SPFA())
    {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < (int)g[i].size(); j++)
        {
            int nxt = g[i][j].v, w = g[i][j].w;
            g[i][j].w = w + h[i] - h[nxt];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        dijkstra(i);
        long long ans = 0;
        for (int j = 1; j <= n; j++)
        {
            if (dis[j] < 1e9)
            {
                ans += j * (dis[j] - h[i] + h[j]);
            }else 
            {
                ans += j * 1e9;
            }
        }
        cout << ans << "\n";
    }
}