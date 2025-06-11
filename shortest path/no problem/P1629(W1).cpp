//一个错误点:忘记判定重边

#include <bits/stdc++.h>

#define ll long long
using namespace std;
int n, m;
const int N = 1e3 + 20, M = 1e5 + 20;
ll edges[N][N];

void input()
{
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i != j)
        edges[i][j] = INT_MAX;
    }
  }
  for (int i = 0; i < m; i++)
  {
    ll u, v, w;
    cin >> u >> v >> w;
    //没有判定重边!!!!!!!!!!!!!!!!!!!!!
    edges[u - 1][v - 1] = min(edges[u - 1][v - 1], w);
  }
}
void floyd()
{
  for (int k = 0; k < n; k++)
  {
    for (int i = 0; i < n; i++)
    {
      if (i == k)
        continue;
      for (int j = 0; j < n; j++)
      {
        if (i == j || j == k)
          continue;
        edges[i][j] = min(edges[i][j], edges[i][k] + edges[k][j]);
      }
    }
  }
}
ll ans;
void output()
{
  for (int i = 1; i < n; i++)
  {
    ans += edges[0][i] + edges[i][0];
  }
  cout << ans;
}
signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  input();
  floyd();
  output();
  return 0;
}