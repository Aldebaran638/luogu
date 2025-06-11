#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n, s;
const int N = 39 + 10, S = 780 + 20;
ll dp[S];

signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  cin >> n;
  // 没有考虑s为奇数的情况
  s = (n + 1) * n / 2;
  if (s % 2 == 0)
  {
    s /= 2;
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
      for (int j = s; j >= i; j--)
        if (dp[j - i])
          dp[j] += dp[j - i];
  }
  cout << dp[s] / 2 << endl;
  return 0;
}