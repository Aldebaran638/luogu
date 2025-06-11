
//这种涉及环的不太会?
#include <bits/stdc++.h>

#define ll long long
using namespace std;

#define MINT INT_MAX

int n, m;
const int N = 1e2 + 20;
ll edges[N][N];

void input()
{
  cin >> n >> m;
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
    edges[a - 1][b - 1] = edges[b - 1][a - 1] = edges[a - 1][b - 1] < w ? edges[a - 1][b - 1] : w;
  }
}
ll ans = INT_MAX;
void floyd()
{
  for (int k = 0; k < n; k++)
  {
    ll edges1[N][N];
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        edges1[i][j] = edges[i][j];
      }
    }
    for (int i = 0; i < n; i++)
    {
      if (i == k)
        continue;
      for (int j = 0; j < i; j++)
      {
        if (j == k)
          continue;
        edges[i][j] = edges[j][i] = min(edges[i][j], edges[i][k] + edges[k][j]);
      }
    }
    for (int i = 0; i < n; i++)
    {
      if (i == k)
        continue;
      for (int j = 0; j < n; j++)
      {
        if (i == j || j == k)
          continue;
        ans = min(ans, edges1[i][j] + edges[j][k] + edges[k][i]);
      }
    }
  }
}

void output()
{
  if (ans == INT_MAX)
  {
    cout << "No solution." << endl;
  }
  else
  {
    cout << ans << endl;
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