//为什么这个一维背包问题就只能使用二维数组了?难道是因为排序吗

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

int n;
const int N = 1e3 + 20, M = 1e5 + 20;
int v[N]; // 当前砝码质量
int sumv; // 砝码总质量
int dp[N][M];
int ans;

signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out1.txt", "w", stdout);
#endif
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    cin >> v[i];
    sumv += v[i];
  }
  for (int i = 1; i <= n; i++)
  {

    for (int j = sumv; j >= 1; j--)
    {
        if (j == v[i])
          dp[i][j] = 1;
        // a-v=j;
        //如果使用一维数组的话,这句话的判定将会和二维数组含义不一致
        else if (dp[i - 1][v[i] + j])
          dp[i][j] = 1;
        else if (dp[i - 1][abs(j - v[i])])
          dp[i][j] = 1;
        else if (dp[i - 1][j])
          dp[i][j] = 1;
    }
  }
  // 最后计数不能带上0
  for (int i = 1; i <= sumv; i++)
    if (dp[n][i])
      ans++;
  cout << ans;
  return 0;
}