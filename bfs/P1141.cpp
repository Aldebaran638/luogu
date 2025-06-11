// bfs题目(但是要bfs优化才能满分.这里单纯写一个BFS记忆化搜索只能70分.尽力了尽力了
// getchar()读不到东西会在洛谷上导致RE
// 出现了一堆未曾意料的问题.getchar导致RE,while的第三个if漏了大括号导致BFS停不下来
// BFS函数memset放在了初始化havarrive[x][y]=1之下,导致出错
// memset使用错误导致memset无效

// 我现在这个代码只能拿七十分.要拿满分需要结合联通块(当然没学过不知道)
#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int n, m;
const int N = 1e3 + 1, M = 1e5 + 20;
int num[N][N];
bool havarrive[N][N];

int a[4] = {-1, 0, 1, 0};
int b[4] = {0, -1, 0, 1};

struct node
{
	int x, y;
};

void outhavarrive()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << havarrive[i][j];
		}
		cout << endl;
	}
}

int fresult(int x, int y)
{
	int result = 0;
	memset(havarrive, 0, sizeof(havarrive));

	queue<node> q;
	node node1;
	node1.x = x, node1.y = y;
	q.push(node1);
	havarrive[x][y] = 1;
	result++;

	while (!q.empty())
	{
		node nownode = q.front();
		int _x = nownode.x, _y = nownode.y;
		for (int i = 0; i < 4; i++)
		{
			if ((_x + a[i] >= 1 && _x + a[i] <= n) && (_y + b[i] >= 1 && _y + b[i] <= n))
			{
				if (!havarrive[_x + a[i]][_y + b[i]])
				{
					// outhavarrive();
					if (num[_x + a[i]][_y + b[i]] != num[_x][_y])
					{
						havarrive[_x + a[i]][_y + b[i]] = 1;
						node newnode;
						newnode.x = _x + a[i], newnode.y = _y + b[i];
						q.push(newnode);
						result++;
					}
				}
			}
		}
		q.pop();
	}
	return result;
}

signed main()
{
	// ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	cin >> n >> m;
	char c;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> c;
			num[i][j] = c - '0';
		}
	}

	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		cout << fresult(x, y) << endl;
	}
}
