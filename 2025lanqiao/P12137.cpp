// 这题解的解题方法太妙了

#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n;
ll s, result, mid;
ll p = 1e9 + 7;

signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> mid, result = ((3 * result - s + (s ^= mid)) % p);
  cout << result;
  return 0;
}