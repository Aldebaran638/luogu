//求组合数法(如果按最暴力的方法求组合数,会发现求出来的数可能超过ll范围导致wa.所以要用杨辉三角)

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>
#include <cstdio>
#include <cctype>

#define ll long long
using namespace std;

int n, m;
const int M = 1e2 + 20, N = 1e4 + 20;
int a[M];
// 要模的数
int p = 10007;
ll C[M][N]; // 预处理组合数

void preprocess_combinations()
{
  for (int i = 0; i <= N-19; i++)
  {
    C[0][i] = 1; // C(0, b) = 1
    for (int j = 1; j <= i && j <= M-19; j++)
    {
      C[j][i] = (C[j - 1][i - 1] + C[j][i - 1]) % p;
    }
  }
}

// // 计算 x 在模 p 下的乘法逆元，使用快速幂
// ll modInverse(ll x, ll p)
// {
//   ll res = 1, exp = p - 2; // 根据费马小定理，x^(p-1) ≡ 1 (mod p)，所以 x^(p-2) ≡ x^(-1) (mod p)
//   while (exp)
//   {
//     if (exp % 2 == 1)
//       res = (res * x) % p;
//     x = (x * x) % p;
//     exp /= 2;
//   }
//   return res;
// }

// // 求组合数C(a,b),b个里面挑a个
// ll cb(ll a, ll b)
// {
//   ll result = 1;
//   for (int i = 0; i < a; i++)
//   {
//     result = (result * (b - i)) % p;              // 每次乘法后取模
//     result = (result * modInverse(i + 1, p)) % p; // 每次除法转为乘法逆元
//   }
//   return result;
// }

// dp[i][j]:要给前i个人,使用j张牌分发时,有几种分法
ll dp[M][N];

signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  cin >> n >> m;
  preprocess_combinations();
  for (int i = 0; i <= n; i++)
  {
    dp[0][i] = 1;
  }
  for (int i = 1; i <= m; i++)
    cin >> a[i];
  for (int i = 1; i <= m; i++)
    for (int j = a[i]; j <= n; j++)
      dp[i][j] = (dp[i - 1][j - a[i]] * (C[a[i]][j]) % p) % p;
  for (int i = 0; i <= N-19; i++)
  {
    for (int j = 1; j <= i&&j<=M-19; j++)
    {
      cout << C[i][j] << " ";
    }
    cout << endl;
  }
  for (int i = 0; i <= m; i++)
  {
    for (int j = 0; j <= n; j++)
      cout << dp[i][j] << " ";
    cout << endl;
  }

  cout << dp[m][n] % p;
  return 0;
}