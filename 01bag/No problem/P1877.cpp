//听说这个叫 到达型背包问题?

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>
#include <cstdio>
#include <cctype>

#define ll long long
using namespace std;

int n, beginl, maxl;
const int N = 50 + 10, MAXL = 1e3 + 20, BEGINL = 1e3 + 20;
int c[N];

// dp[i][j]进行到第i首歌的时候,是否能达到音量j
int dp[N][MAXL];

signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  cin >> n >> beginl >> maxl;
  for (int i = 1; i <= n; i++)
    cin >> c[i];
  dp[0][beginl] = 1;
  for (int i = 1; i <= n; i++)
  {
    for (int j = maxl; j >= 0; j--)
    {
      if (j >= c[i])
      {
        if (dp[i - 1][j - c[i]])
        {
          dp[i][j] = 1;
        }
      }
      if (j + c[i] <= maxl)
      {
        if (dp[i - 1][j + c[i]])
        {
          dp[i][j] = 1;
        }
      }
    }
  }
  int ans = -1;
  for (int i = maxl; i >= 0; i--)
  {
    if (dp[n][i])
    {
      ans = i;
      break;
    }
  }
  cout << ans;
  return 0;
}