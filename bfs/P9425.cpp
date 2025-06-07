//bfs题目
//错误点:在这道题目中,一个点可以被多次经过.hack数据:
//2 2 10
//AA
//AB 
 
#include<bits/stdc++.h>
#define endl '\n' 

using namespace std;

int n,m,k;
const int N=1e3+20,M=1e3+20,K=15;
char _map[N][M];
bool isarv[N][M][K];

int test[N][M];

void outtest(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<test[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<endl;
}

struct node {
	int x,y,_k;
	char lett;
};

int ans=-1;

void bfs(){
	int result=0;
	queue<node> q1;
	queue<int> q2;
	int a[4]={0,1,0,-1};
	int b[4]={1,0,-1,0};

	node node1;
	node1.x=1,node1.y=1,node1._k=0,node1.lett='A';
	if(node1._k%k==k-1){
		node1.lett='B';
	}
	q1.push(node1);
	q2.push(0);
	isarv[1][1][node1._k]=1;
	
	while(!q1.empty()){
		node fnode=q1.front();
		int x=fnode.x,y=fnode.y,_k=fnode._k;
		char lett=fnode.lett;
		int _step=q2.front();
		
		if(x==n&&y==m){
			ans=_step;
			return;
		}
		else{
			test[x][y]++;
			for(int i=0;i<4;i++){
				int _x=a[i],_y=b[i];
				if((x+_x>=1&&x+_x<=n)&&(y+_y)>=1&&y+_y<=m){
					if(_map[x+_x][y+_y]==lett){
						if(!isarv[x+_x][y+_y][(_k+1)%k]){
							node newnode;
							newnode.x=x+_x,newnode.y=y+_y,newnode._k=(_k+1)%k;
							if((_k+1)%k==k-1){
								newnode.lett=(lett=='A'?'B':'A');
							}
							else{
								newnode.lett=lett;
							}
							q1.push(newnode);
							q2.push(_step+1);
							isarv[x+_x][y+_y][(_k+1)%k]=1;
						}
					}
				}
			}	
		}
		q1.pop(),q2.pop();
		outtest();
	}
}



signed main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>_map[i][j];
		}
	}
	bfs();
	cout<<ans<<endl;
}
