// 一维01背包模板题
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t, m, p;
const int T = 1e3 + 20, M = 1e3 + 20;
// 代价 价值
int k1, k2;
struct node
{
  // 当前节点的价值和接口大小
  int v, l;
};
// dp为当约束条件为i时的最优解.一维背包问题,只需要一维数组.
node dp[T];
signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  // 输入数据
  cin >> m >> p >> t;
  // 01背包DP
  for (int i = 1; i <= m; i++)
  {
    cin >> k1 >> k2;
    for (int j = t; j >= k1; j--)
    {
      if (dp[j - k1].v + k2 > dp[j].v)
      {
        dp[j].v = dp[j - k1].v + k2, dp[j].l = max(k1, dp[j - k1].l);
      }
      else if (dp[j - k1].v + k2 == dp[j].v)
      {
        dp[j].l = min(max(k1, dp[j - k1].l), dp[j].l);
      }
    }
  }

  // 输出最后一个结果
  for (int i = 1; i <= t; i++)
  {
    if (dp[i].v >= p)
    {
      cout << dp[i].l << endl;
      return 0;
    }
  }
  cout << "No Solution!" << endl;
  return 0;
}