// 一维01背包模板题
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// 容量和物品数
int t, m;
const int T = 5e4 + 20, M = 5e3 + 20;
// 代价 价值
int k1, k2;
// dp为当约束条件为i时的最优解.一维背包问题,只需要一维数组.
ll dp[T];
signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  // 输入数据
  cin >> t >> m;
  // 01背包DP
  for (int i = 1; i <= m; i++)
  {
    cin >> k1;
    k2 = k1;
    for (int j = t; j >= k1; j--)
      dp[j] = max(dp[j - k1] + k2, dp[j]);
  }

  // 输出最后一个结果
  cout << dp[t] << endl;
  return 0;
}