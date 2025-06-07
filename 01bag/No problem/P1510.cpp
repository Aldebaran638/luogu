#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n, c, v;
const int N = 1e4 + 20, C = 1e4 + 20;
struct node
{
  int m, k;
  bool operator<(const node &_node)
  {
    return m < _node.m;
  }
};
node num[N];
int dp[C];

bool issuccess;

void input()
{
  cin >> v >> n >> c;
  for (int i = 1; i <= n; i++)
  {
    cin >> num[i].k >> num[i].m;
  }
  sort(num, num + n);
}
void bag()
{
  for (int i = 1; i <= n; i++)
    for (int j = c; j >= num[i].m; j--)
      dp[j] = max(dp[j - num[i].m] + num[i].k, dp[j]);
}
void output()
{
  for (int i = 0; i <= c; i++)
  {
    if (dp[i] >= v)
    {
      issuccess = 1;
      cout << c - i << endl;
      break;
    }
  }
  if (!issuccess)
  {
    cout << "Impossible" << endl;
  }
}

signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  input();
  bag();
  output();
  return 0;
}