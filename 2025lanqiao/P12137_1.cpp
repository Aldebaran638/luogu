//暴力模拟做的,虽然知道这样做必TLE.这道题确实没想到正解能这样做(脑筋急转弯了属于是)

#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n;
const int N = 1e5;
int num[N];

// 参数:
// i:模拟到第几个数了
// pn:前一个数字是什么
// pc:前一个非异或符号是什么.1+2-
// nc:当前要计算的符号
// nr:当前累计结果
inline int ccl(int i, int pn, int pc, int nc, int nr)
{

  // if (i == 2 && nc == 3)
  // {
  //   cout << 1 << endl;
  //   fflush(stdout);
  // }

  if (nc == 1)
  {
    nr += num[i];
    pc = nc;
    pn = num[i];
    // result.push_back('+');
  }
  else if (nc == 2)
  {
    nr -= num[i];
    pc = nc;
    pn = num[i];
    // result.push_back('-');
  }
  else if (nc == 3)
  {
    if (pc == 1)
    {
      nr -= (pn);
      nr += (pn ^ num[i]);
      pn ^= num[i];
    }
    else if (pc == 2)
    {
      nr -= (-pn);
      nr += (-((pn) ^ num[i]));
      pn = (pn) ^ num[i];
    }
    // result.push_back('^');
  }

  // result.push_back(num[i] + '0');
  if (i == n - 1)
  {
    // for (int j = 0; j < result.size(); j++)
    // {
    //   cout << result[j] << " ";
    // }
    // cout << "= " << nr << endl;
    // fflush(stdout);
    return nr;
  }
  return ccl(i + 1, pn, pc, 1, nr) + ccl(i + 1, pn, pc, 2, nr) + ccl(i + 1, pn, pc, 3, nr);
}

signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> num[i];
  cout << ccl(0, 0, 0, 1, 0);
  return 0;
}