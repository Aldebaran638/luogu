// 二维01背包模板题
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

int n, m, x;
const int N = 100 + 20;
const int M = 1e3 + 20;
const int X = 1000 + 20;
// 第一种代价,第二种代价
int p1, p2;
// 价值
int a;
// dp数组.二维背包问题就使用二维dp数组
// 代表当伪装能力为m,花费x元时,最优解是什么
int dp[M][X];

signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  cin >> n >> m >> x;
  // 此处01dp实际上和一维的长得特别像,算是模板了已经
  for (int i = 1; i <= n; i++)
  {
    cin >> a >> p1 >> p2;
    for (int j = m; j >= p1; j--)
      for (int k = x; k >= p2; k--)
        dp[j][k] = max(dp[j - p1][k - p2] + a, dp[j][k]);
  }
  cout << dp[m][x] << endl;
  return 0;
}