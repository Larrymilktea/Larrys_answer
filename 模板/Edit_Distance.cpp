#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(0), cin.tie(0),cout.tie(0);
#define ll long long
#define pp pair<int,int>
using namespace std;
 
const int maxn=1e9;
 
int main(){
	speed
    string s,t;
    cin>>s>>t;
    int n=s.size(),m=t.size();
    s.insert(s.begin(),'$');
    t.insert(t.begin(),'$');
    vector<vector<int>>dp(n+1,vector<int>(m+1,maxn));
    dp[0][0]=0;
    for(int i=1;i<=n;i++)dp[i][0]=i;
    for(int j=1;j<=m;j++)dp[0][j]=j;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		if(s[i]==t[j])dp[i][j]=dp[i-1][j-1];
    		else{
    			dp[i][j]=min({dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+1});
    		}
    	}
    }
    cout<<dp[n][m];
}
