#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(0), cin.tie(0),cout.tie(0);
#define ll long long
#define pp pair<int,int>
using namespace std;

const int maxn=1e6;

int edge[maxn][25];
vector<int>grid[maxn];
int timing=1;
int in[maxn],out[maxn];
int n,q;

void dfs(int u){
    in[u] = timing++;//這時進入u
    for(int v : grid[u]){//跑過所有孩子
        dfs(v);
    }
    out[u] = timing++;//這時離開u
}

bool is_ancestor(int u,int v){
    return ( in[u] < in[v] && out[v] < out[u] );
}

void init(int n){
	for(int i=1;i<20;i++){
		for(int j=1;j<=n;j++){ // 從跳2^1次枚舉到跳2^logn次
			edge[j][i]=edge[edge[j][i-1]][i-1];
		}
	}
}

int getlca(int x, int y){
    if(is_ancestor(x, y))return x; // 如果 u 為 v 的祖先則 lca 為 u
    if(is_ancestor(y, x))return y; // 如果 v 為 u 的祖先則 lca 為 u
    for(int i=log2(n);i>=0;i--){    // 判斷 2^logN, 2^(logN-1),...2^1, 2^0 倍祖先
        if(!is_ancestor(edge[x][i], y)) // 如果 2^i 倍祖先不是 v 的祖先
            x = edge[x][i];            // 則往上移動
    }
    return edge[x][0]; // 回傳此點的父節點即為答案
}

int main(){
	speed
	cin>>n>>q;
	edge[1][0]=1;
	for(int i=2,a;i<=n;i++){
		cin>>a;
		edge[i][0]=a;//指向他的father
		grid[a].push_back(i);// 紀錄樹,給時間戳記用
	}
	
	init(n);// 初始化
	dfs(1);// 時間戳記

	while(q--){
		int a,b;
		cin>>a>>b;
		if(a==b)cout<<a<<endl; // 特判如果是自己和自己的LCA,那LCA是自己
		else cout<<getlca(a,b)<<endl;
	}
	return 0;
}
