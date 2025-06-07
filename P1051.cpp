#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n;

string result1;
int result2, result3;

signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    string name;
    int a, b;  // 期末平均成绩,班级评议成绩
    char c, d; // 是否班干,是否西部
    int e;     // 论文数
    cin >> name >> a >> b >> c >> d >> e;
    int mid = 0;
    if (a > 80 && e >= 1)
    {
      mid += 8000;
    }
    if (a > 85 && b > 80)
    {
      mid += 4000;
    }
    if (a > 90)
    {
      mid += 2000;
    }
    if (a > 85 && d == 'Y')
    {
      mid += 1000;
    }
    if (b > 80 && c == 'Y')
    {
      mid += 850;
    }
    if (mid > result2)
    {
      result1 = name, result2 = mid;
    }
    result3 += mid;
  }
  cout << result1 << endl
       << result2 << endl
       << result3 << endl;
  return 0;
}