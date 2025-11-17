#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(0), cin.tie(0),cout.tie(0);
#define ll long long
#define pp pair<int,int>
using namespace std;
int main(){
    speed
    int n,m,k;
    cin>>n>>m>>k;
    map<int,int>mp;
    for(int i=1;i<=n;i++){
        cin>>mp[i];
    }
    vector<vector<int>>edge(n+1,vector<int>());
    for(int i=0,a,b;i<m;i++){
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    queue<int>q;
    q.push(1);
    vector<int>dis(n+1,INT_MAX);
    vector<bool>vis(n+1,false);
    dis[1]=0;
    while(q.size()){
        int u=q.front();
        q.pop();
        if(vis[u])continue;
        vis[u]=true;
        for(int v:edge[u]){
            if(dis[u]+1<dis[v])dis[v]=dis[u]+1,q.push(v);
        }
    }
    vector<int>ans(k+1,0);
    for(auto i:mp){
        ans[i.second]=max(ans[i.second],dis[i.first]);
    }
    for(int i=1;i<=k;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
