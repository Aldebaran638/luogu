// 2025年6月18日
// 算法：弗洛伊德
#include <bits/stdc++.h>

#define ll long long
using namespace std;

mutex mtx;
chrono::time_point<std::chrono::steady_clock> startt;
chrono::time_point<std::chrono::steady_clock> endt;

int n, m, a, b;
const int N = 2e3 + 20, M = 1e6 + 20;
double num[N][N];

signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  mtx.lock();
  startt = std::chrono::steady_clock::now();
#endif
  cin >> n >> m;

  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      num[i][j] = num[j][i] = 100;

  int x, y, z;
  for (int i = 1; i <= m; i++)
  {
    cin >> x >> y >> z;
    num[x][y] = num[y][x] = z;
  }

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      for (int k = j + 1; k <= n; k++)
        num[j][k] = num[k][j] = min(num[j][i] + (100 - num[j][i]) * num[i][k] * 0.01, num[j][k]);
  cin >> a >> b;
  cout << 100 / (1-num[a][b]/100.0) << endl;
#ifndef ONLINE_JUDGE
  endt = std::chrono::steady_clock::now();
  mtx.unlock();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endt - startt);
  int count = duration.count();
  cout << "运行时间:" << count << " 微秒";
#endif
  return 0;
}