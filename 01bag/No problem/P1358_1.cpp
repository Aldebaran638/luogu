#include <cstdio>
using namespace std;
void in(int &n) // 快读
{
  n = 0;
  int f = 1;
  char c = getchar();
  while (c < '0' || '9' < c)
  {
    if (c == '-')
      f *= -1;
    c = getchar();
  }
  while ('0' <= c && c <= '9')
  {
    n = n * 10 + (c - '0');
    c = getchar();
  }
  n *= f;
}
int p[100005], b[100005];
int s;
int cal(int n, int x)
{
  int ans = 0;
  while (n > 0)
    ans += n /= x;
  return ans;
}
long long C(int n, int m, int mod) // 求C(n,m)%mod
{
  long long ans = 1;
  for (int i = 0; i < s; i++)
  {
    int k = cal(n, p[i]) - cal(m, p[i]) - cal(n - m, p[i]);
    // 求C(n,m)中因子为p[i]的个数
    for (int j = 0; j < k; j++) // 把k个p[i]相乘
      ans = (ans * p[i]) % mod;
  }
  return ans;
}
int a[105];
int main()
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif

  b[0] = b[1] = 1;
  for (int i = 2; i <= 100000; i++) // 埃筛
    if (!b[i])
    {
      for (int j = 2 * i; j <= 100000; j += i)
        b[j] = 1;
      p[s++] = i;
    }
  int n, m;
  in(n);
  in(m);
  int sum = 0;
  for (int i = 0; i < m; i++)
  {
    in(a[i]);
    sum += a[i];
  }
  if (sum > n)
  {
    printf("0");
    return 0;
  }
  long long ans = 1ll;
  for (int i = 0; i < m; i++)
  {
    ans = (ans * C(n, a[i], 10007)) % 10007;
    n -= a[i];
  }
  printf("%lld", ans); // 输出
  return 0;
}