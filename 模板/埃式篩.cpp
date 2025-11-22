#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(0), cin.tie(0),cout.tie(0);
#define ll long long
#define pp pair<int,int>
using namespace std;
int n,q;
vector<bool>flagprim;
vector<int>prim;



int main(){
	speed
	cin>>n>>q;
	flagprim.assign(n+1,true);
	flagprim[0]=flagprim[1]=false;
	for(int i=2;i*i<=n;i++){
		if(flagprim[i]){
			for(int j=i*i;j<=n;j+=i){
				flagprim[j]=false;
			}
		}
	}
	for(int i=2;i<=n;i++){
		if(flagprim[i])prim.push_back(i);
	}
	while(q--){
		int k;
		cin>>k;
		cout<<prim[k-1]<<"\n";
	}
}
