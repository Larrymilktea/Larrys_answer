#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(0), cin.tie(0),cout.tie(0);
#define ll long long
#define pp pair<int,int>
using namespace std;

int main(){
	speed
	int n;
	cin>>n;
	vector<int> num(n);
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	vector<pp> dp;
	vector<int>v(n);
	for(int i=0;i<n;i++){
		int it=lower_bound(dp.begin(),dp.end(),pp{num[i],INT_MIN})-dp.begin();
		if(it==dp.size())dp.push_back({num[i],i});
		else dp[it]={num[i],i};
		v[i]=it!=0?dp[it-1].second:-1;
	}
	vector<int>ans;
	for(int i=dp.back().second;~i;i=v[i]){
		ans.push_back(i);
	}
	cout<<dp.size()<<endl;
	for(int i=ans.size()-1;i>=0;i--){
		if(i!=ans.size()-1)cout<<' ';
		cout<<ans[i];
	}
	cout<<endl;
	
}

