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
#include <chrono>
#include <ctime>

#define ll long long
using namespace std;

int n;
int maxs = 0;

signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  cin >> n;
  int pm = 0, pd = 1, tm, td;
  std::tm p = {}, t = {};
  for (int i = 0; i < n + 1; i++)
  {
    if (i == 0)
    {
      pm = 0;
      pd = 1;
    }
    else
    {
      pm = tm, pd = td;
    }
    p = {};                  // 清零
    p.tm_year = 2000 - 1900; // 设置为从1900年开始的年份
    p.tm_mon = pm - 1;
    p.tm_mday = pd;
    p.tm_hour = 0;
    p.tm_min = 0;
    p.tm_sec = 0;
    if (i == n)
    {
      tm = 11;
      td = 31;
    }
    else
    {
      cin >> tm >> td;
    }

    t = {};                  // 清零
    t.tm_year = 2000 - 1900; // 设置为从1900年开始的年份
    t.tm_mon = tm - 1;
    t.tm_mday = td;
    t.tm_hour = 0;
    t.tm_min = 0;
    t.tm_sec = 0;
    time_t time_p = mktime(&p);
    time_t time_t = mktime(&t);
    double seconds = difftime(time_t, time_p);
    if (!(i == 0 || i == n))
    {
      seconds -= 24 * 60 * 60; // 减去一天的秒数
    }
    seconds = seconds / 366.0;
    seconds = round(seconds);
    maxs = max(maxs, static_cast<int>(seconds));
  }
  cout << maxs << endl;
  return 0;
}