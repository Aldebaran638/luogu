// 这题其实和弗洛伊德没关系

#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t;

int gcd(int a, int b)
{
  if (!(a % b))
  {
    return b;
  }
  return gcd(b, a % b);
}

signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin >> t;
  while (t--)
  {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < q; i++)
    {
      int x, y;
      cin >> x >> y;
      cout << x + y - 2 * gcd(x, y) << endl;
    }
  }
  return 0;
}