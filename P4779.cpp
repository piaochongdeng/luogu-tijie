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
int s, dis[1000005];
int main()
{
    int n, m;
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    memset(dis, 0x3f, sizeof(dis));

    q.push({s, 0});
    //x` 第二种需要加这个
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

        // 第二种方法

        // if(dis[u]==d)
        // {
        //     for (int i = 0; i < g[u].size(); i++)
        //     {
        //         int v = g[u][i].v;
        //         int w = g[u][i].w;
        //         if(dis[v] > dis[u] + w)
        //         {
        //             dis[v] = dis[u] + w;
        //             q.push({v, dis[v]});
        //         }
        //     }
        // }
    }
    for (int i = 1; i <= n; i++)
    {
        if (dis[i] == 0x3f3f3f3f)
        {
            cout << "2147483647" << " ";
            continue;
        }
        cout << dis[i] << " ";
    }
}
// 从s到t最小路径
//      cout << "Shortest path from " << s << " to t is: " << dis[t] << endl;

//     // 如果需要最大路径，我们就要对所有边的权重取反，再计算最短路径
//     // 对所有边的权重取反并执行Dijkstra
//     memset(dis, 0x3f, sizeof(dis));
//     dis[s] = 0;

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 0; j < g[i].size(); j++)
//         {
//             g[i][j].w = -g[i][j].w; // 将边权取反
//         }
//     }

//     // 重新计算
//     q.push({s, 0});
//     while (!q.empty())
//     {
//         int u = q.top().v;
//         int d = q.top().d;
//         q.pop();

//         if (dis[u] > d)
//         {
//             dis[u] = d;
//             for (int i = 0; i < g[u].size(); i++)
//             {
//                 int v = g[u][i].v;
//                 int w = g[u][i].w;

//                 // 对每个节点进行最大路径的计算（取反后变为最短路径）
//                 if (dis[v] > dis[u] + w)
//                 {
//                     q.push({v, dis[u] + w});
//                 }
//             }
//         }
//     }

//     // 输出最大路径
//     cout << "Maximum path from " << s << " to t is: " << -dis[t] << endl;
// }