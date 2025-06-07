//很正常的01背包.只是如果不打标签的话我可能看不出来这个是01背包

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

int s;
const int S = 1e3 + 20;
const int N = S;

// 求约数和
int sums(int num)
{
  int s = 0;
  for (int i = 1; i <= num / 2; i++)
    if (num % i == 0)
      s += i;
  return s;
}
// dp[i][j]:当选取到第i个数的时候,当和不超过S,选取到的最大约数之和
int dp[S][S];

signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  cin >> s;
  for (int i = 1; i <= s; i++)
    for (int j = s; j >= 1; j--)
      if (i > j)
        dp[i][j] = dp[i - 1][j];
      else
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - i] + sums(i));
  // for (int i = 0; i <= s; i++)
  // {
  //   for (int j = 0; j <= s; j++)
  //     cout << dp[i][j] << " ";
  //   cout << endl;
  // }
  cout << dp[s][s] << endl;
  return 0;
}