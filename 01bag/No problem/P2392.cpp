// 一维01背包模板题
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 20 + 20, M = 1200 + 20;

signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int s[4];
  for (int i = 0; i < 4; i++)
  {
    cin >> s[i];
  }
  ll ans = 0;
  for (int k = 0; k < 4; k++)
  {
    ll dp[M];
    memset(dp, 0, M);
    int num[N];
    num[0] = 0;
    int m = 0;
    for (int i = 1; i <= s[k]; i++)
    {
      cin >> num[i];
      m += num[i];
    }
    for (int i = 1; i <= s[k]; i++)
    {
      for (int j = m / 2; j >= num[i]; j--)
      {
        dp[j] = max(dp[j], dp[j - num[i]] + num[i]);
      }
    }
    ans += m - dp[m / 2];
  }
  cout << ans;
}