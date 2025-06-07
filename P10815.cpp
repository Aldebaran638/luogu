#include <bits/stdc++.h>

#define ll long long
using namespace std;

ll n, mid;
ll sum;

signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  char c;
  ll k;
  bool flag = 0;
  cin >> n;
  getchar();
  while (1)
  {
    c=getchar();
    if (c == '\n' || c == EOF)
      break;
    else if (c == '-')
    {
      flag = 1;
    }
    else if (c == ' ')
    {
      if (flag)
      {
        sum -= k;
      }
      else
      {
        sum += k;
      }
      flag = 0;
    }
    else if (c >= '0' && c <= '9')
    {
      k = (k * 10) + c - '0';
    }
  }
  cout << sum << endl;
  return 0;
}