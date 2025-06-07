#include <iostream>
using namespace std;
int n;
int f[10010];//a(长度)
int a[10010];//num
long long v[10010];//b(结果)
int main()
{
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    v[i] = a[i];
    if (i > 1)
      for (int j = 1; j < i; j++)
        if (a[j] <= a[i])
          if (f[i] <= f[j])
            f[i] = f[j] + 1, v[i] = v[j] + a[i];
    cout << v[i] << " ";
  }
  return 0;
}
// comment:
// 这是题解