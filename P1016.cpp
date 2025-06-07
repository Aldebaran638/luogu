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

double D1, D2, C;
int n; // 站点总数(包括加油站和起点终点)
const int N = 6 + 2;
double p[N];
int mind[N]; // 距离当前加油站最近的,价格比它低的加油站
double d[N];

signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  cin >> D1 >> C >> D2 >> p[0] >> n;
  n += 2;
  for (int i = 1; i <= n - 2; i++)
  {
    cin >> d[i] >> p[i];
  }
  d[n - 1] = D1;
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (p[j] <= p[i])
      {
        mind[i] = j;
        break;
      }
    }
  }
  double result = 0; // 当前所花费的钱
  double c = 0;      // 当前油量
  for (int i = 0; i < n - 1; i++)
  {
    // 判断能不能到下一个站
    if ((d[i + 1] - d[i]) / D2 > C)
    {
      cout << "No Solution" << endl;
      return 0;
    }
    // 计算要加多少油
    double need = (d[mind[i]] - d[i]) / D2; // 到达目标所需要的油量
    // 如果加满都不够到达,就加满
    if (need >= C)
    {
      result += (C - c) * p[i];
      c = C;
    }
    // 否则就只加需要的
    else
    {
      if (need >= c)
      {
        result += (need - c) * p[i];
        c += (need - c);
      }
    }
    c -= (d[i + 1] - d[i]) / D2;
  }
  printf("%.2f", round(result * 100) / 100.0);
  return 0;
}