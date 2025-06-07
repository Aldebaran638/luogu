#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n;
const int N = 1e2 + 20;
int num[N];

signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> num[i];
  int l[N], r[N];
  // 初始化，每个人自己就是一个长度为1的队形
  for (int i = 1; i <= n; i++)
    l[i] = 1, r[i] = 1;
  // 计算左侧最长递增子序列
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j < i; j++)
    {
      if (num[j] < num[i])
      {
        l[i] = max(l[i], l[j] + 1);
      }
    }
  }
  // 计算右侧最长递减子序列
  for (int i = n; i >= 1; i--)
  {
    for (int j = n; j > i; j--)
    {
      if (num[j] < num[i])
      {
        r[i] = max(r[i], r[j] + 1);
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
  {
    ans = max(ans, l[i] + r[i] - 1);
  }
  cout << n - ans << endl;
  return 0;
}