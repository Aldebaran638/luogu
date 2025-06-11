#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n, m;
const int N = 1e2 + 20, M = 1e4 + 20;
int a[M];
ll edges[N][N];

ll ans;
int now;
void input()
{
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int mid;
    cin >> mid;
    a[i] = --mid;
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      int mid;
      cin >> mid;
      edges[i][j] = mid;
    }
  }
}

void floyd()
{
  for (int k = 0; k < n; k++)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        edges[i][j] = min(edges[i][j], edges[i][k] + edges[k][j]);
      }
    }
  }
}
void output()
{
  for (int i = 0; i < m; i++)
  {
    ans += edges[now][a[i]];
    now = a[i];
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