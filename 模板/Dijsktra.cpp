#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e7;

int cnt, head[maxn]; // head node;

struct node{
	int to, w, pre;
}edge[maxn];

inline void add_edge(int u,int v,int w){
	edge[++cnt].to=v;
	edge[cnt].w=w;
	edge[cnt].pre=head[u];
	head[u]=cnt;
}
int main(){
	int n, m, s;
	cin >> n >> m >> s;
	memset(head, -1, sizeof head);
	for(int i = 1 ; i <= m ; i++){
		int a, b, c;
		cin >> a >> b >> c;
		add_edge(a,b,c);
	}
	//wight, u
	using Pair = pair<int,int>; // use pair<int,int> x Pair o
	priority_queue<Pair,vector<Pair>,greater<Pair>> pq;
	//queue<type,vector<type>,greater<type>>
	//proirity_queue<pair<int,int>,vector<pair<int,int>>,greater<int,int>> 
	auto dis = vector<int>(n+1,INT_MAX);
	//vector<int> dis(n+1,INT_MAX)
	auto vis = vector<bool>(n+1,false);
	pq.push({0,s});
	dis[s] = 0;
	while(pq.size()){
		int u = pq.top().second;//current
		pq.pop();
		if(vis[u]) continue;//visited
		vis[u] = true;
		for(int i = head[u] ; ~i ; i = edge[i].pre){
			int v = edge[i].to;
			if(dis[v] > dis[u] + edge[i].w){
				dis[v] = dis[u] + edge[i].w;
				pq.push({dis[v],v});
			}
		}
  }
	for(int i = 1 ; i <= n ; i++) cout << dis[i] << " ";
}
