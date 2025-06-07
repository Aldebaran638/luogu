#include <bits/stdc++.h>

#define ll long long
using namespace std;

// 城市个数
int n;
const int N = 1e2 + 20;

// 初始道路灰尘度
int edges[N][N];
// 最低灰尘度
int l[N][N];
int minl[N][N];

// 要求指标
ll Q;
// 天数
ll d;
int t;

void input()
{
  cin >> n >> Q;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> edges[i][j];
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> l[i][j];
    }
  }
}

void floyd()
{
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      minl[i][j] = edges[i][j];
  for (int k = 0; k < n; k++)
  {
    for (int i = 0; i < n; i++)
    {
      if (i == k)
        continue;
      for (int j = i + 1; j < n; j++)
      {
        if (j == k)
          continue;
        minl[i][j] = minl[j][i] = minl[i][j] < minl[i][k] + minl[k][j] ? minl[i][j] : minl[i][k] + minl[k][j];
      }
    }
  }
}

int judge()
{
  ll p = 0;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      p += minl[i][j];
  p *= 2;
  // 已经达到目标;
  if (p <= Q)
    return 1;
  // 一个周期内一次都没有修改
  if (t == n)
  {
    d = -1;
    return -1;
  }
  return 0;
}



void improve()
{
  d++;
  int aim = (d - 1) % n;
  bool ischange = 0;
  for (int j = 0; j < n; j++)
  {
    if (edges[aim][j] > l[aim][j])
    {
      ischange = 1;
      edges[aim][j]--;
    }
  }
  if (!ischange)
    t++;
  else
    t = 0;
}

void run()
{
  //时间复杂度如何算?
  while (1)
  {
    //n3
    // 弗洛伊德给minl算上最小值
    floyd();
    // 判断是否达到要求(P<=Q或在一个周期内一条道路都没有改善(就是全都改成极限了))
    int result = judge();
    if (result || result == -1)
    {
      break;
    }
    improve();
  }
}

void output()
{
  cout << d << endl;
}

signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  input();
  run();
  output();
  return 0;
}