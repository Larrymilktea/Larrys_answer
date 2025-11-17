#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(0), cin.tie(0),cout.tie(0);
#define ll long long
#define pp pair<int,int>
using namespace std;

int main(){
	speed
	int n;
	cin>>n;
	vector<vector<int>>edge(n+1,vector<int>());
	vector<int>degree(n+1,0);
	for(int i=1;i<=n;i++){
		int v;
		while(cin>>v&&v){
			edge[i].push_back(v);
			degree[v]++;
		}
	}
	vector<int>ans;
	priority_queue<int,vector<int>,greater<int>>pq;
	for(int i=1;i<=n;i++){
		if(degree[i]==0)pq.push(i);
	}
	while(pq.size()){
		int u=pq.top();
		ans.push_back(u);
		pq.pop();
		for(auto i:edge[u]){
			degree[i]--;
			if(degree[i]==0)pq.push(i);
		}
	}
	for(auto i:ans)cout<<i<<' ';
}
