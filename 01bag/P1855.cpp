//二维01背包模板

#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n, M, T;
const int N = 120, CM = 220, CT = 220;
int m[N], t[N];
int num[CM][CT];

signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  cin >> n >> M >> T;
  for (int i = 1; i <= n; i++)
    cin >> m[i] >> t[i];
  for (int k = 1; k <= n; k++)
    for (int i = M; i >= m[k]; i--)
      for (int j = T; j >= t[k]; j--)
        num[i][j] = max(num[i - m[k]][j - t[k]] + 1, num[i][j]);
  cout << num[M][T] << endl;
  return 0;
}