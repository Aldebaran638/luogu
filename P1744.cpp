// 无向图弗洛伊德算法模板题

#include <bits/stdc++.h>

#define ll long long
using namespace std;

#define MINT INT_MAX

// 点的个数,边的个数
int n, m;
const int N = 1e2 + 20;
// 邻接矩阵
double sides[N][N];

// 存储点的坐标
struct node
{
  double x, y;
  node() = default;
  node(double _x, double _y) : x(_x), y(_y) {}
};
vector<node> points;

int s, t;

// 根据n的大小输入图的邻接矩阵sides
void input()
{
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i == j)
        sides[i][j] = 0;
      else
        sides[i][j] = INT_MAX;
    }
  }

  for (int i = 0; i < n; i++)
  {
    double x, y;
    cin >> x >> y;
    points.emplace_back(x, y);
  }
  cin >> m;
  for (int i = 0; i < m; i++)
  {
    int a, b;
    double w;
    cin >> a >> b;
    a--, b--;
    w = sqrt((points[a].x - points[b].x) * (points[a].x - points[b].x) + (points[a].y - points[b].y) * (points[a].y - points[b].y));
    sides[a][b] = sides[b][a] = sides[a][b] < w ? sides[a][b] : w;
  }
  cin >> s >> t;
  s--, t--;
}

// 使用弗洛伊德算法更新邻接矩阵sides
void floyd()
{
  // 将每个点作为中间点更新
  for (int k = 0; k < n; k++)
  {
    // 遍历每一行
    for (int i = 0; i < n; i++)
    {
      if (i == k)
        continue;
      // 遍历该行的每一列
      for (int j = 0; j < i; j++)
      {
        if (j == k)
          continue;
        // 取 经过这个点 和 原来的路径 两种路径中最短的
        sides[i][j] = sides[j][i] = min(sides[i][j], sides[i][k] + sides[k][j]);
      }
    }
  }
}

// 将最终得到的邻接矩阵输出
void output()
{
  cout << fixed << setprecision(2) << round(sides[s][t] * 100.0) / 100.0 << endl;
}

signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  input();
  floyd();
  output();
  return 0;
}