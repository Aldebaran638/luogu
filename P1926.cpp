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

int n, m, k, r;
const int N = 10 + 10, M = 10 + 10, R = 150 + 20;
int n1[N]; // 题目时间
int k1[M]; // 作业时间
int k2[M]; // 作业分数

int dp[M][R];

signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  cin >> n >> m >> k >> r;
  for (int i = 0; i < n; i++)
  {
    cin >> n1[i];
  }
  sort(n1, n1 + n);
  for (int i = 1; i <= m; i++)
  {
    cin >> k1[i];
  }
  for (int i = 1; i <= m; i++)
  {
    cin >> k2[i];
  }
  // 给题目根据所花费时间排序
  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= m - 1 - i; j++)
    {
      if (k1[j] > k1[j + 1])
      {
        swap(k1[j], k1[j + 1]), swap(k2[j], k2[j + 1]);
      }
    }
  }
  // 背包
  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= r; j++)
    {
      // 如果塞不下新题
      if (j < k1[i])
      {
        // 继承自上一行的数据
        dp[i][j] = dp[i - 1][j];
      }
      // 如果塞得下新题
      else
      {
        // 比较塞下新题和不塞新题(就是上一行的数据)哪个大一点,就取哪个
        dp[i][j] = max(dp[i - 1][j - k1[i]] + k2[i], dp[i - 1][j]);
        // 如果已经及格,就不用继续算下去了.
        if (dp[i][j] >= k)
          break;
      }
    }
  }
  // 寻找及格所需最小的时间.
  int minr = 200;
  for (int i = 0; i <= r; i++)
  {
    for (int j = 0; j <= m; j++)
    {
      // 如果找到最小时间,跳出循环
      if (dp[j][i] >= k)
      {
        minr = i;
        break;
      }
    }
    // 如果已经找到最小时间,跳出循环
    if (minr != 200)
    {
      break;
    }
  }
  int result = 0;
  r -= minr;
  for (int i = 0; i < n; i++)
  {
    if (r >= n1[i])
    {
      r -= n1[i];
      result++;
    }
  }
  cout << result << endl;
  return 0;
}