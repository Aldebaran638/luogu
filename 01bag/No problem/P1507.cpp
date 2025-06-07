//二维背包dp
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

int maxh, maxt, n;

const int H = 400, T = 400, N = 50;

int h, t, k;

int dp[H][T];

signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  cin >> maxh >> maxt >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> h >> t >> k;
    for (int j = maxh; j >= h; j--)
    {
      for (int l = maxt; l >= t; l--)
      {
        dp[j][l] = max(dp[j][l], dp[j - h][l - t] + k);
      }
    }
  }
  cout << dp[maxh][maxt];
  return 0;
}