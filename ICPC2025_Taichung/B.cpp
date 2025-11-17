#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(0), cin.tie(0),cout.tie(0);
#define ll long long
#define pp pair<int,int>
using namespace std;
const int maxn=1e6;
int n,m,l;
double x,y;
pp bus[maxn];
pp person[maxn];
double ans[maxn];

signed main(){
	speed
	scanf("%d %d %d %lf %lf",&n,&m,&l,&x,&y);
	for(int i=0;i<n;i++){
		scanf("%d %d",&bus[i].first,&bus[i].second);
	}
	for(int i=0;i<m;i++){
		scanf("%d",&person[i].first);
		person[i].second=i;
	}
	sort(bus,bus+n);
	sort(person,person+m);
	double minn=1e18;
	int tmp=0;
	for(int i=0;i<m;i++){
		int endpt=person[i].first;
		int idx=person[i].second;
		
		while(tmp<n && bus[tmp].first<=endpt){
			int left=bus[tmp].first;
			int right=bus[tmp++].second;
			minn=min(minn,(double)((right-left)/x)+(double)((l-right)/y));
		}
		ans[idx]=min(minn,(double)((l-endpt)/y));
	}
	for(int i=0;i<m;i++)printf("%lf\n",ans[i]);
	return 0;
}
