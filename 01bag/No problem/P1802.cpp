// 一维01背包模板题
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// t是容量,m是物品个数
int t, m;
const int T = 1e3 + 20, M = 1e3 + 20;
// 代价 价值1 价值2
int k1, k2, k3;
// dp为当约束条件为i时的最优解.一维背包问题,只需要一维数组.
ll dp[T];
signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  // 输入数据
  cin >> m >> t;
  // 01背包DP
  for (int i = 1; i <= m; i++)
  {
    cin >> k3 >> k2 >> k1;
    for (int j = t; j >= 0; j--)
      if (j < k1)
      {
        dp[j] += k3;
      }
      else
      {
        dp[j] = max(dp[j - k1] + k2, dp[j] + k3);
      }
  }

  // 输出最后一个结果
  cout << 5 * dp[t] << endl;
  return 0;
}