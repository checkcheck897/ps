#include<bits/stdc++.h>
int n;
int a[251], b[251];
int sum;
int ans;
int dp[2][250*250+1];
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    	cin>>n;
    	sum = 0;
    	ans = 10000000;
    	for(int i=1; i<n+1; i++){
    		cin>>a[i]>>b[i];
    		sum += b[i];
		}
		for(int i=1; i<n+1; i++){
    		for(int j=0; j<250*250+1; j++){
    			dp[i%2][j] = dp[(i-1)%2][j];
    			if(j<a[i]) {	}
    			else dp[i%2][j] = max(dp[i%2][j], dp[(i-1)%2][j-a[i]]+b[i]);
				ans = min(ans, max(j, sum-dp[i%2][j]));
			}
		}
		cout<<ans<<"\n";	
    return 0;
}