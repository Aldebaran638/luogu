//想出来了百分之八十(即充要条件已经全部想出来,但是却不知道他是充要条件)
//这道题关于充要条件的证明思路很值得学习
//思路如下:
/*
首先可以根据 i = j 时的限制计算出一个上界 a_i <= sqrt(i^2 + 2025)，但是这个条件并不是充分的。
不过它引出了一个重要观察：当 i >= 1013 时一定有 a_i <= i。

注意到 1 位置只可以填 1,2，考虑每个位置和 2025 的限制，有 2025*a_i <= 2025*i + 2025，即 a_i <= i + 1。

接下来我们证明 a_i <= min(sqrt(i^2 + 2025), i + 1) 就是充要条件，必要性已经在前面完成证明。此时会有

a_i <= { i + 1  i < 1013
          i      i >= 1013
*/

/*
将 i, j (i <= j) 分为三类：
- i, j >= 1013，此时 a_i * a_j <= i * j <= i * j + 2025。
- i < 1013 <= j，此时 a_i * a_j <= (i + 1) * j = i * j + j <= i * j + 2025。
- i, j < 1013，此时 a_i * a_j <= (i + 1) * (j + 1) = i * j + i + j + 1 <= i * j + 2025。

因此上述条件是充要的。
*/

//这道题尚未解决的部分:
//1.这道题的充分必要性证明思路没有理解
//2.关于%,为什么我不开longlong就会出错?

#include <bits/stdc++.h>

#define ll long long
#define endl '\n';
using namespace std;

const int n = 2025;
const ll p = 1e9 + 7;

// 快速幂.底数和幂数
ll fm(int num, int q)
{
  if (q == 0)
  {
    return 1;
  }
  else if (q == 1)
  {
    return num;
  }
  else
  {
    ll result = fm(num, q / 2);
    result = (result * result ) % p;
    if (q % 2 != 0)
    {
      result = (result * num ) % p;
    }
    return result;
  }
}

signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  cout << fm(2, 1012);
  return 0;
}