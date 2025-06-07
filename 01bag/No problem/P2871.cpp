
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

int t, m;
const int T = 12880 + 20, M = 3402 + 20;

int k1, k2;

int dp[T];
signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif

  cin >> m >> t;

  for (int i = 1; i <= m; i++)
  {
    cin >> k1 >> k2;
    for (int j = t; j >= k1; j--)
      dp[j] = max(dp[j - k1] + k2, dp[j]);
  }

  cout << dp[t] << endl;
  return 0;
}