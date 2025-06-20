// 2025年6月20日
// 算法：dijkstra
// 迪杰斯特拉算法重温

#include <bits/stdc++.h>

#define ll long long
using namespace std;

mutex mtx;
chrono::time_point<std::chrono::steady_clock> startt;
chrono::time_point<std::chrono::steady_clock> endt;

int n, m, s;
const int N = 1e5 + 20, M = 2e5 + 20;

vector<pair<int, ll>> edges[N];

ll result[N];

struct node
{
  int pos;
  ll dis;
  node(int _pos, ll _dis) : pos(_pos), dis(_dis) {}
  bool operator<(const node &_node) const
  {
    return dis > _node.dis;
  }
};

priority_queue<node> pq;

// 每条边最大长度为1e9，最多2e5个边，所以最长路径是2e14.
// 而LLONG_MAX约为9e19
const ll INF = LLONG_MAX / 1e2;

void input()
{
  cin >> n >> m >> s;
  int u, v, w;
  for (int i = 0; i < m; i++)
  {
    cin >> u >> v >> w;
    // 此处并没有考虑重边情况，邻接表也不好处理这种情况
    edges[u].emplace_back(v, w);
  }
  for (int i = 1; i <= n; i++)
    result[i] = INF;
}
void dijkstra()
{
  pq.emplace(s, 0);
  while (!pq.empty())
  {
    node mid = pq.top();
    pq.pop();
    if (result[mid.pos] <= mid.dis)
      continue;
    result[mid.pos] = mid.dis;
    for (int i = 0; i < edges[mid.pos].size(); i++)
      if (mid.dis + edges[mid.pos][i].second < result[edges[mid.pos][i].first])
        pq.push(node(edges[mid.pos][i].first, edges[mid.pos][i].second + mid.dis));
  }
}
void output()
{
  for (int i = 1; i <= n; i++)
    cout << result[i] << " ";
  cout << endl;
}

void Solution()
{
  input();
  dijkstra();
  output();
}

signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  mtx.lock();
  startt = std::chrono::steady_clock::now();
#endif

  Solution();

#ifndef ONLINE_JUDGE
  endt = std::chrono::steady_clock::now();
  mtx.unlock();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endt - startt);
  int count = duration.count();
  cout << "运行时间:" << count << " 微秒";
#endif
  return 0;
}