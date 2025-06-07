#include <iostream>
#include <vector>
using namespace std;

vector<int> a;
int n;

int calculate_len(int i)
{

  if (i >= n)
    return 1;
  int x = a[i], y = a[i + 1];
  if (x == y)
    return 1;
  int len = 2;
  int expected = x;
  for (int j = i + 2; j <= n; ++j)
  {
    if (a[j] == expected)
    {
      len++;
      expected = (expected == x) ? y : x;
    }
    else
    {
      break;
    }
  }
  return len;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  cin >> n;
  a.resize(n + 2);
  for (int i = 1; i <= n; ++i)
    cin >> a[i];

  int global_max = 1;
  for (int i = 1; i <= n; ++i)
  {
    int current = calculate_len(i);
    if (current > global_max)
      global_max = current;
  }
  cout << global_max << endl;

  int q;
  cin >> q;
  while (q--)
  {
    int k, c;
    cin >> k >> c;
    a[k] = c;
    global_max = 1;
    for (int i = 1; i <= n; ++i)
    {
      int current = calculate_len(i);
      if (current > global_max)
        global_max = current;
    }
    cout << global_max << endl;
  }
  return 0;
}