#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(0), cin.tie(0),cout.tie(0);
#define ll long long
#define pp pair<int,int>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>num(n);
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    vector<int>pre(n);
    vector<int>suf(n);
    pre[0]=num[0];
    suf[n-1]=num[n-1];
    for(int i=1;i<n;i++){
        pre[i]=__gcd(pre[i-1],num[i]);
    }
    for(int i=n-2;i;i--){
        suf[i]=__gcd(suf[i+1],num[i]);
    }
    
    ll ans=0;
    for(int i=0;i<n;i++){
        ans+=min(pre[i],suf[i]);
    }
    cout<<ans<<endl;
    return 0;
}
