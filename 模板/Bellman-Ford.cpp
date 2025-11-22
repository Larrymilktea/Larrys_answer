#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(0), cin.tie(0),cout.tie(0);
#define ll long long
#define pp pair<ll,int>
using namespace std;

const int maxn=1e6;
const ll inf=1e16+555;
int head[maxn],cnt;

struct node{
	int to,pre;
	ll w;
}edge[maxn];

inline void add_edge(int u,int v,ll w){
	edge[++cnt].to=v;
	edge[cnt].w=w;
	edge[cnt].pre=head[u];
	head[u]=cnt;
}

int main(){
	speed
	int n,m;
	cin>>n>>m;
	memset(head,-1,sizeof head);
	for(int i=0,a,b,c;i<m;i++){
		cin>>a>>b>>c;
		add_edge(a,b,-c);
	}
	vector<ll>dis(n+1,1e15);
	vector<bool>vis(n+1,false);
	vector<int>cnt(n+1,0);
	
	queue<int>q;
	q.push(1);
	dis[1]=0;
	vis[1]=true;
	
	function<ll()>BF=[&]()->ll{
	    for(int k=1;k<n;k++){
		    for(int j=1;j<=n;j++){
			    for(int i=head[j],y;~i;i=edge[i].pre){
				    y=edge[i].to;
					if(dis[y]>dis[j]+edge[i].w)dis[y]=dis[j]+edge[i].w;
				}
			}
		}
		ll tmp=dis[n];
		for(int k=1;k<n;k++){
			for(int j=1;j<=n;j++){
				for(int i=head[j],y;~i;i=edge[i].pre){
					y=edge[i].to;
					if(dis[y]>dis[j]+edge[i].w)dis[y]=dis[j]+edge[i].w;
				}
			}
		}
		if(tmp!=dis[n])return inf<<1;
		else return tmp;
	};
	ll ans=BF();
	if(ans==inf<<1)cout<<"inf"<<endl;
	else cout<<-ans<<endl;
}
