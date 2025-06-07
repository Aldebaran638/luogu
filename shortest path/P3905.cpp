#include <bits/stdc++.h>

#define ll long long
using namespace std;

#define MINT INT_MAX

int n, m, s, d;
const int N = 1e2 + 20;
ll edges[N][N];
bool isdestory[N][N];

int A, B;

struct node
{
  int pos;
  int dis;
  node(int _pos, int _dis) : pos(_pos), dis(_dis) {}
  bool operator<(const node &_node) const
  {
    return dis > _node.dis;
  }
};

priority_queue<node> pq;

ll result[N];

void input()
{
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      edges[i][j] = INT_MAX;
    }
  }
  for (int i = 0; i < m; i++)
  {
    ll a, b, w;
    cin >> a >> b >> w;
    edges[a - 1][b - 1] = edges[b - 1][a - 1] = min(edges[a - 1][b - 1], w);
  }
  cin >> d;
  for (int i = 0; i < d; i++)
  {
    int a, b;
    cin >> a >> b;
    isdestory[a - 1][b - 1] = isdestory[b - 1][a - 1] = 1;
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (!isdestory[i][j] && edges[i][j] != INT_MAX)
      {
        edges[i][j] = edges[j][i] = 0;
      }
    }
  }
  cin >> A >> B;
  A--, B--;
  s = A;
}

void dijkstra()
{
  pq.push(node(s, 0));

  for (int i = 0; i < n; i++)
    result[i] = INT_MAX;

  while (!pq.empty())
  {
    node mid = pq.top();
    pq.pop();

    if (mid.dis > result[mid.pos])
      continue;

    result[mid.pos] = mid.dis;

    for (int j = 0; j < n; j++)
      if (result[mid.pos] + edges[mid.pos][j] < result[j])
        pq.emplace(j, result[mid.pos] + edges[mid.pos][j]);

    // if (result[mid.pos] + edges[mid.pos][i].second < result[edges[mid.pos][i].first])
    //   pq.emplace(edges[mid.pos][i].first, edges[mid.pos][i].second + result[mid.pos]);
  }
}

void output()
{
  cout << result[B] << endl;
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
