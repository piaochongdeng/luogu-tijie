#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Edge
{
    int v, w;
};
vector<Edge> to[100005];
queue<int> q;
int dis[100005];
int n, m, s;
int main()
{
    cin >> n >> m >> s;
    fill(dis, dis + 1 + n, 0x3f3f3f3f);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        to[u].push_back({v, w});
    }
    dis[s] = 0;

    q.push(s);
    while (q.size())
    {
        int now = q.front();
        q.pop();
        for (auto &e : to[now])
        {
            int nxt = e.v, w = e.w;
            if (dis[nxt] > dis[now] + w)
            {
                dis[nxt] = dis[now] + w;
                q.push(nxt);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dis[i] << " ";
    }
}