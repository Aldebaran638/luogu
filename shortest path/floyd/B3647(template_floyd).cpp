// 无向图弗洛伊德算法模板题

#include <bits/stdc++.h>

#define ll long long
using namespace std;

#define MINT INT_MAX

// 点的个数,边的个数
int n, m;
const int N = 1e3 + 20;
// 邻接矩阵
ll edges[N][N];

// 根据n的大小输入图的邻接矩阵edges
void input()
{
  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i == j)
        edges[i][j] = 0;
      else
        edges[i][j] = INT_MAX;
    }
  }
  for (int i = 0; i < m; i++)
  {
    int a, b, w;
    cin >> a >> b >> w;
    edges[a - 1][b - 1] = edges[b - 1][a - 1] = edges[a - 1][b - 1] < w ? edges[a - 1][b - 1] : w;
  }
}

// 使用弗洛伊德算法更新邻接矩阵edges
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
        edges[i][j] = edges[j][i] = min(edges[i][j], edges[i][k] + edges[k][j]);
      }
    }
  }
}

// 将最终得到的邻接矩阵输出
void output()
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cout << edges[i][j] << " ";
    cout << endl;
  }
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