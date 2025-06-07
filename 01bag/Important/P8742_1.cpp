#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
int n, ans, sum, w[101], dp[101][100001];
int main()
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out2.txt", "w", stdout);
#endif

  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
  {
    scanf("%d", &w[i]);
    sum += w[i];
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = sum; j; j--)
    {
      if (j == w[i])
        dp[i][j] = 1;
      else if (dp[i - 1][j])
        dp[i][j] = 1;
      else if (dp[i - 1][j + w[i]])
        dp[i][j] = 1;
      else if (dp[i - 1][abs(j - w[i])])
        dp[i][j] = 1;
    }
  }
  for (int i = 1; i <= sum; i++)
    if (dp[n][i])
    {
      std::cout << i << " ";
      ans++;
    }
  cout << endl;
  printf("%d", ans);
  return 0;
}