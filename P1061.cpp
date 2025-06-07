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

int s, t, w;
const int num = 5;
string s1;
string getnext(string s)
{

  for (int i = s.size() - 1; i >= 0; i--)
  {
    if (i == s.size() - 1)
    {
      if (s[i] - 'a' < t-1)
      {
        s[i]++;
        return s;
      }
    }
    else
    {
      if (s[i] < s[i + 1] - 1)
      {
        s[i]++;
        for (int j = i + 1; j < s.size(); j++)
        {
          s[j] = s[j - 1] + 1;
        }
        return s;
      }
    }
  }
  return "";
}

signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  cin >> s >> t >> w;
  cin >> s1;
  for (int i = 0; i < num; i++)
  {

    if ((s1 = getnext(s1)) != "")
    {
      cout << s1 << endl;
    }
    else
    {
      break;
    }
  }
  return 0;
}