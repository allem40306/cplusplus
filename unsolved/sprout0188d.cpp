#include <iostream>
#include <deque>
#include <cmath>
using namespace std;
const int N=100005;
int main(){
	cin.tie(NULL);
	int t,ti=0,n,k,c,a[N];
	long long dp[N],tt[N],ans;
	for(cin>>t;ti<t;ti++){
		cin>>n>>k>>c;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		deque<int>dq;
		ans=0;
		for(int i=0;i<n;i++){
			while(dq.size()&&(i-dq.front()>k)dq.pop_front();
			while(dq.size()&&dp[dq.back()]<dp[i])dq.pop_back();
			if(dq.size())dp[i]=a[i]-c*i+tt[dq.front()];
			else dp[i]=a[i];
			tt[i]=dp[i]+c*i;
			dq.push_back(i);
//			cout<<i<<' '<<dp[i]<<'\n';
			ans=max(ans,dp[i]);
		}
		cout<<ans<<'\n';
	}
}
