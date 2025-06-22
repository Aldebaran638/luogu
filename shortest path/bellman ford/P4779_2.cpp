// 2025年6月22日
// 算法：bellmanford
// bellmanford算法重温

#include <bits/stdc++.h>

#define ll long long
using namespace std;

mutex mtx;
chrono::time_point<std::chrono::steady_clock> startt;
chrono::time_point<std::chrono::steady_clock> endt;

int n, m, s;
const int N = 1e5+20, M = 2e5 + 20;
struct node
{
  int start;
  int end;
  ll w;
  node() = default;
  node(int _start, int _end, ll _w) : start(_start), end(_end), w(_w) {}
};
vector<node> edges;
ll result[N];
const ll INF = LLONG_MAX / 1e2;
void input()
{
  cin >> n >> m >> s;
  int u, v, w;
  for (int i = 0; i < m; i++)
  {
    cin >> u >> v >> w;
    edges.emplace_back(u, v, w);
  }
}

void bellman_ford()
{
  for (int i = 1; i <= n; i++)
    result[i] = INF;
  result[s] = 0;
  bool ischange = 0;
  for (int i = 0; i < n - 1; i++)
  {
    ischange = 0;
    node mid;
    for (int j = 0; j < edges.size(); j++)
    {
      mid = edges[j];
      if (result[mid.start] + mid.w < result[mid.end])
      {
        result[mid.end] = result[mid.start] + mid.w;
        ischange = 1;
      }
    }
    if (!ischange)
      break;
  }
  // 循环完成以后再进行一次循环，
  // 有变化就说明由负权环，无法计算出答案
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
  bellman_ford();
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