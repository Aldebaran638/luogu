#include <bits/stdc++.h>

#define ll long long
using namespace std;

int d, p, c, f;

const int C = 300 + 20;
ll edges[C][C];

ll ans;

void input()
{
  cin >> d >> p >> c >> f;
  for (int i = 0; i < c; i++)
  {
    for (int j = 0; j < c; j++)
    {
      if (i != j)
        edges[i][j] = INT_MAX;
    }
  }
  for (int i = 0; i < p; i++)
  {
    int a, b;
    cin >> a >> b;
    edges[a - 1][b - 1] = -d;
  }
  for (int i = 0; i < f; i++)
  {
    int a, b, _f;
    cin >> a >> b >> _f;
    if (edges[a - 1][b - 1] == INT_MAX)
      edges[a - 1][b - 1] = _f - d;
  }
}

void floyd()
{
  for (int k = 0; k < c; k++)
    for (int i = 0; i < c; i++)
    {
      if (i == k)
        continue;
      for (int j = 0; j < c; j++)
      {
        if (j == k)
          continue;
        else
          edges[i][j] = min(edges[i][j], edges[i][k] + edges[k][j]);
      }
    }
}

void output()
{
  for (int i = 0; i < c; i++)
  {
    for (int j = 0; j < c; j++)
    {
      ans = min(ans, edges[i][j]);
      if (i != j && edges[i][j] != INT_MAX && edges[j][i] != INT_MAX && edges[i][j] + edges[j][i] < 0)
        ans = -INT_MAX;
      else if (i == j && edges[i][i] < 0)
        ans = -INT_MAX;
    }
  }
  if (ans == -INT_MAX)
    cout << "orz" << endl;
  else
    cout << (-ans) + 100 << endl;
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