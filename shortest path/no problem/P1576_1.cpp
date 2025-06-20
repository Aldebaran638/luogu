// 2025年6月20日
// 算法：dijkstra.
// 用迪杰斯特拉算法解决floyd解决不了的P1576

#include <bits/stdc++.h>

#define ll long long
using namespace std;

mutex mtx;
chrono::time_point<std::chrono::steady_clock> startt;
chrono::time_point<std::chrono::steady_clock> endt;

int n, m, s, b;
const int N = 2e3 + 20, M = 1e5 + 20;

vector<pair<int, double>> edges[N];

double result[N];

struct node
{
  int pos;
  double dis;
  node(int _pos, double _dis) : pos(_pos), dis(_dis) {}
  bool operator<(const node &_node) const
  {
    return dis > _node.dis;
  }
};

priority_queue<node> pq;

const ll INF = 100;

void input()
{
  cin >> n >> m;
  int u, v;
  double w;
  for (int i = 0; i < m; i++)
  {
    cin >> u >> v >> w;
    // 唯一卡住的地方是没看到题目要求的是无向图
    edges[u].emplace_back(v, w);
    edges[v].emplace_back(u, w);
  }
  for (int i = 1; i <= n; i++)
    result[i] = INF;
  cin >> s >> b;
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
    {
      double a = mid.dis;
      double b = edges[mid.pos][i].second;
      if (mid.dis + (100 - mid.dis) * 0.01 * edges[mid.pos][i].second < result[edges[mid.pos][i].first])
        pq.push(node(edges[mid.pos][i].first, mid.dis + (100 - mid.dis) * 0.01 * edges[mid.pos][i].second));
    }
  }
}
void output()
{
  cout << fixed << setprecision(8) << 100 * 100.0 / (100.0 - result[b]) << endl;
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