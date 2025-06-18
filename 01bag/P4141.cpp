#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n;
const int N = 1e3 + 20;
struct node
{
  int num;
  int r;
} num[N];
double tt;

signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    num[i].r = i;
    cin >> num[i].num;
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n - i; j++)
    {
      if (num[j].num > num[j + 1].num)
        swap(num[j], num[j + 1]);
    }
  }
  for (int i = 1; i <= n; i++)
  {
    cout << num[i].r << " ";
    tt += (num[i].num) * (n - i);
  }
  cout << endl;
  cout << fixed << setprecision(2) << tt / n << endl;

  return 0;
}