#include <bits/stdc++.h>

#define ll long long
using namespace std;

int m, n;
const int M = 1e4 + 20, N = 1e2 + 20;
int dp[M][N];
int num[N];
int result;
void input()
{
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  {
    cin >> num[i];
  }
}
void bag()
{
  if (m == 0)
  {
    result = 1;
    return;
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      dp[j][i] = dp[j][i - 1];
      if (j >= num[i])
      {
        dp[j][i] += dp[j - num[i]][i - 1];
      }
      int a = dp[j][i];
      if (num[i] == j)
      {
        dp[j][i]++;
        a++;
      }
    }
  }
}
void output()
{
  cout << dp[m][n] << endl;
}

signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  input();
  bag();
  output();
  return 0;
}