#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(0), cin.tie(0),cout.tie(0);
#define ll long long
using namespace std;

const int maxn=1e7;

int pre[maxn];

int root(int x){
	return pre[x]=pre[x]==x?x:root(pre[x]);
}

inline void merge(int x,int y){
	x=root(x);
	y=root(y);
	if(x==y)return ;
	pre[x]=y;
}

int main(){
	speed
	int n , m;
	cin>> n >> m;
	for(int i = 1 ; i<=n ; i++ ){
		pre[i] = i;
	}
	while( m-- ){
		int op , x , y;
		cin >> op >> x >> y;
		if(op == 1)merge(x,y);
		else cout<<(root(x)==root(y)? 'Y':'N')<<endl;
	}
}
