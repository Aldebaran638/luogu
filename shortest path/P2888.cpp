#include <bits/stdc++.h>

#define ll long long
using namespace std;

#define MINT INT_MAX

int n, m, t;
const int N = 300 + 20;

ll edges[N][N];

void input()
{
  cin >> n >> m >> t;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i == j)
        edges[i][j] = 0;
      else
        edges[i][j] = INT_MAX;
    }
  }
  for (int i = 0; i < m; i++)
  {
    int a, b, w;
    cin >> a >> b >> w;
    edges[a - 1][b - 1] = edges[a - 1][b - 1] < w ? edges[a - 1][b - 1] : w;
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
      // 这里也是无向的(j<i)
      for (int j = 0; j < n; j++)
      {
        if (j == k)
          continue;
        // 注意这里初始状态下也是默认路径是无向的,需要修改
        edges[i][j] = min(edges[i][j], max(edges[i][k], edges[k][j]));
      }
    }
  }
}

void output()
{
  for (int i = 0; i < t; i++)
  {
    int a, b;
    cin >> a >> b;
    ll mid = edges[a - 1][b - 1];
    if (mid == INT_MAX)
      cout << -1 << endl;
    else
      cout << mid << endl;
  }
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