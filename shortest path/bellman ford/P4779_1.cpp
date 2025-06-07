#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n, m, s;
const int N = 1e4 + 20, M = 5e5 + 20;
struct node
{
  int start;
  int end;
  int dis;
  node() = default;
  node(int _start, int _end, int _dis) : start(_start), end(_end), dis(_dis) {}
};
vector<node> edges;
ll result[N];

void input()
{
  cin >> n >> m >> s;
  s -= 1;
  for (int i = 0; i < m; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    edges.emplace_back(u - 1, v - 1, w);
  }
}
void bellmanford()
{
  for (int i = 0; i < n; i++)
    result[i] = INT_MAX;
  result[s] = 0;

  bool ischange = 0;
  for (int i = 0; i < n - 1; i++)
  {
    ischange = 0;
    for (int j = 0; j < edges.size(); j++)
    {
      if (result[edges[j].end] > result[edges[j].start] + edges[j].dis)
      {
        result[edges[j].end] = result[edges[j].start] + edges[j].dis;
        ischange = 1;
      }
    }
    if (!ischange)
    {
      break;
    }
  }
}
void output()
{
  for (int i = 0; i < n; i++)
    cout << result[i] << " ";
  cout << endl;
}

signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  input();
  bellmanford();
  output();
  return 0;
}