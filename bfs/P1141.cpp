//bfs��Ŀ(����Ҫbfs�Ż���������.���ﵥ��дһ��BFS���仯����ֻ��70��.�����˾����� 
//getchar()������������������ϵ���RE 
//������һ��δ�����ϵ�����.getchar����RE,while�ĵ�����if©�˴����ŵ���BFSͣ������
//BFS����memset�����˳�ʼ��havarrive[x][y]=1֮��,���³���
//memsetʹ�ô�����memset��Ч
 
 
//�������������ֻ������ʮ��.Ҫ��������Ҫ�����ͨ��(��Ȼûѧ����֪��) 
#include<bits/stdc++.h>
#define endl '\n' 

using namespace std;

int n,m;
const int N=1e3+1,M=1e5+20;
int num[N][N];
bool havarrive[N][N];

int a[4]={-1,0,1,0};
int b[4]={0,-1,0,1};

struct node{
	int x,y;
};

void outhavarrive(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<havarrive[i][j];
		}
		cout<<endl;
	}
}

int fresult(int x,int y){
	int result=0;
	memset(havarrive,0,sizeof(havarrive));
	
	queue<node> q;
	node node1;
	node1.x=x,node1.y=y;
	q.push(node1);
	havarrive[x][y]=1;
	result++;
	
	while(!q.empty()){
		node nownode=q.front();
		int _x=nownode.x,_y=nownode.y;
		for(int i=0;i<4;i++){
			if((_x+a[i]>=1&&_x+a[i]<=n)&&(_y+b[i]>=1&&_y+b[i]<=n)){
				if(!havarrive[_x+a[i]][_y+b[i]]){
					//outhavarrive();
					if(num[_x+a[i]][_y+b[i]]!=num[_x][_y]){
						havarrive[_x+a[i]][_y+b[i]]=1;
						node newnode;
						newnode.x=_x+a[i],newnode.y=_y+b[i];
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



signed main(){
	//ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	cin>>n>>m;
	char c;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>c;
			num[i][j]=c-'0';
		}
	}

	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		cout<<fresult(x,y)<<endl;
	}
}
