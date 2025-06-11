// KMP算法模板题,字符串匹配
#include <bits/stdc++.h>

#define int long long
#define endl '\n';

using namespace std;

string s1, s2;

// s2的next数组
vector<int> nexts;
vector<int> result;

void getnext()
{
	int len = 0, i = 1;
	nexts.push_back(0);
	while (i < s2.size())
	{
		if (s2[i] == s2[len])
		{
			nexts.push_back(++len);
			i++;
		}
		else
		{
			if (len == 0)
			{
				nexts.push_back(0);
				i++;
			}
			else
			{
				len = nexts[len - 1];
			}
		}
	}
}

void getresult()
{
	int len = 0, i = 0;
	while (i < s1.size())
	{
		if (s2[len] == s1[i])
		{
			len++, i++;
		}
		else
		{
			if (len == 0)
			{
				i++;
			}
			else
			{
				len = nexts[len - 1];
			}
		}
		if (len == s2.size())
		{
			len = nexts[len - 1];
			result.push_back(i - s2.size() + 1);
		}
	}
}

void coutvector(vector<int> &a)
{
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin >> s1 >> s2;
	// 生成next数组
	getnext();
	// 匹配字符串
	getresult();

	// 输出结果
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << endl;
	}

	for (int i = 0; i < nexts.size(); i++)
	{
		cout << nexts[i] << " ";
	}
	cout << endl;

	// 匹配字符串
}
