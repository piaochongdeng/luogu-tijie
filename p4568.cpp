#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
struct edge
{
    int to, w, t;
    bool operator<(const edge &rhs) const
    {
        return w > rhs.w;
    }
};
vector<edge> g[3005];
priority_queue<edge> pq;
int n, m, k, s, t, dis[10005][115];
int main()
{
    cin >> n >> m >> k >> s >> t;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(edge{v, w});
        g[v].push_back(edge{u, w});
    }
    memset(dis, 0x3f, sizeof(dis));
    dis[s][0] = 0;
    pq.push(edge{s, 0});
    while (pq.size())
    {
        int now = pq.top().to;
        int w = pq.top().w;
        int cs = pq.top().t;
        pq.pop();
        if (w == dis[now][cs])
        {
            for (edge e : g[now])
            {
                int nxt = e.to;
                int d = e.w;
                if (dis[nxt][cs] > dis[now][cs] + d)
                {
                    dis[nxt][cs] = dis[now][cs] + d;
                    pq.push(edge{nxt, dis[nxt][cs], cs});
                }
                if (dis[nxt][cs + 1] > dis[now][cs]&&cs+1<=k)
                {
                    dis[nxt][cs + 1] = dis[now][cs];
                    pq.push(edge{nxt, dis[nxt][cs + 1], cs + 1});
                }
            }
        }
    }
    int ans = 1e9;
    for (int i = 0; i <= k;i++)
    {
        ans = min(ans, dis[t][i]);
    }
    if(ans==1e9)
    {
        cout << -1;
    }else
    {
        cout << ans;
    }
}
