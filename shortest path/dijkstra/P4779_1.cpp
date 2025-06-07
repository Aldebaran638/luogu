#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n, m, s;
const int N = 1e4;
ll sides[N][N];

struct node
{
  int pos;
  int dis;
  node(int _pos, int _dis) : pos(_pos), dis(_dis) {};
  bool operator<(const node &_node) const
  {
    return dis > _node.dis;
  }
};
priority_queue<node> pq;
bool vis[N];
int result[N];

void input()
{
  cin >> n >> m >> s;
  s -= 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (i != j)
        sides[i][j] = INT_MAX;
  int a, b, w;
  for (int i = 0; i < m; i++)
  {
    cin >> a >> b >> w;
    // 取最小值是怕有重复边的情况
    sides[a - 1][b - 1] = sides[a - 1][b - 1] < w ? sides[a - 1][b - 1] : w;
    // 这样写会导致一堆WA
    // sides[a - 1][b - 1] = w;
  }
}

void dijkstra()
{
  // 初始化只需要往里面放一个初始元素即可,剩下的核心操作交给循环
  pq.push(node(s, 0));
  memset(result, -1, sizeof(result));

  while (!pq.empty())
  {
    node mid = pq.top();
    pq.pop();

    if (vis[mid.pos])
      continue;

    vis[mid.pos] = 1, result[mid.pos] = mid.dis;

    for (int j = 0; j < n; j++)
    {
      if (j != mid.pos && sides[mid.pos][j] != INT_MAX && !vis[j])
        pq.push(node(j, sides[mid.pos][j] + mid.dis));
    }
  }
}

void output()
{
  for (int i = 0; i < n; i++)
  {
    if (result[i] == -1)
      cout << INT_MAX << " ";
    else
      cout << result[i] << " ";
  }

  cout << endl;
}

signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  input();
  dijkstra();
  output();
  return 0;
}