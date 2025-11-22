#include<bits/stdc++.h>
using namespace std;
int main(){
    int n1,n2,t=0;
    while(cin>>n1>>n2&&(n1+n2)){
        t++;
        int a,b;
        int dp[n1+1][n2+1];
        vector<int> v1,v2;
        for(int i=0;i<n1;i++){
            cin>>a;
            v1.push_back(a);
        }
        for(int i=0;i<n2;i++){
            cin>>b;
            v2.push_back(b);
        }
        memset(dp,0,sizeof(dp));
        for (int i=1; i<=n1; i++) {
            for (int j=1; j<=n2; j++) {
                if (v1[i-1]==v2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else {
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        cout<<"Twin Towers #"<<t<<endl;
        cout<<"Number of Tiles : "<<dp[n1][n2]<<endl;
        cout<<endl;
    }
    return 0;
}
