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

// 题目数据
int n, v;
const int N = 30 + 20, M = 20000+20;
int num[N];

// dp表格
int dp[N][M];

signed
main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif

  cin >> v >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> num[i];
  }
  sort(num, num + n + 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= v; j++)
    {
      if (num[i] <= j)
        dp[i][j] = max(dp[i - 1][j - num[i]] + num[i], dp[i - 1][j]);
      else
        dp[i][j] = dp[i - 1][j];
    }

  cout << v - dp[n][v] << endl;
  return 0;
}