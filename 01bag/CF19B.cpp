#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n, m;
const int N = 4e3 + 20, M = 4e3 + 20;
int k1[N];
ll k2[N];
ll dp[M];
ll ans = LLONG_MAX;
signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> k1[i] >> k2[i];
    k1[i]++;
    m = max(m, k1[i]);
  }
  m += n;
  memset(dp, 0x7f, sizeof(dp));
  dp[0] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = m; j >= k1[i]; j--)
      dp[j] = min(dp[j], dp[j - k1[i]] + k2[i]);
  for (int i = n; i <= m; i++)
    ans = min(ans, dp[i]);
  cout << ans << endl;
  return 0;
}