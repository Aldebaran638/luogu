#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Edmonds-Karp 算法求最大流（邻接矩阵版）
const int N = 200 + 20;
const ll INF = (ll)1e18;

int n, m, s, t;
ll capacity[N][N], flow[N][N];
bool vis[N];
int pre[N]; // 前驱索引：正向存父节点编号，反向存-父节点编号

void input()
{
  cin >> n >> m >> s >> t;
  memset(capacity, 0, sizeof(capacity));
  memset(flow, 0, sizeof(flow));
  for (int i = 0; i < m; ++i)
  {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    capacity[u][v] += w; // 支持多条边累加
  }
}

// BFS 找增广路径，返回增广量
ll bfs()
{
  memset(pre, 0, sizeof(pre));
  memset(vis, 0, sizeof(vis));
  queue<int> q;
  q.push(s);
  vis[s] = true;

  while (!q.empty())
  {
    int u = q.front();
    q.pop();
    for (int v = 1; v <= n; ++v)
    {
      if (vis[v])
        continue;
      // 正向残量
      if (capacity[u][v] > flow[u][v])
      {
        vis[v] = true;
        pre[v] = u; // 正向边 u->v
        if (v == t)
          goto end_bfs;
        q.push(v);
      }
      // 反向残量 🚩【修正反向判断】
      else if (flow[v][u] > 0)
      { // 🚀 从 v->u 退流时检查 flow[v][u]
        vis[v] = true;
        pre[v] = -u; // 反向边 v->u 表示可退流
        if (v == t)
          goto end_bfs;
        q.push(v);
      }
    }
  }
  return 0;
end_bfs:
  // 计算瓶颈
  ll aug = INF;
  int cur = t;
  while (cur != s)
  {
    int p = pre[cur];
    if (p > 0)
    {
      // 正向边
      aug = min(aug, capacity[p][cur] - flow[p][cur]);
      cur = p;
    }
    else
    {
      // 反向边 🚩【修正退流方向】
      int u = -p;
      aug = min(aug, flow[cur][u]); // 🚀 使用 flow[cur][u] 来退流
      cur = u;
    }
  }
  // 更新流量
  cur = t;
  while (cur != s)
  {
    int p = pre[cur];
    if (p > 0)
    {
      flow[p][cur] += aug;
      cur = p;
    }
    else
    {
      int u = -p;
      flow[cur][u] -= aug; // 🚀 退流时用 flow[cur][u] -= aug
      cur = u;
    }
  }
  return aug;
}

ll EdmondsKarp()
{
  ll maxflow = 0;
  while (true)
  {
    ll aug = bfs();
    if (aug == 0)
      break;
    maxflow += aug;
  }
  return maxflow;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  input();
  cout << EdmondsKarp();
  return 0;
}
