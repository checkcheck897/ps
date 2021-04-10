#include<bits/stdc++.h>
int n;
int k;
int value[1001][2];
int dp[1001][10001];
using namespace std;
void input(){
	cin>>k>>n;
	for(int i=1; i<n+1; i++) cin>>value[i][1]>>value[i][0];
}
void print(){
	cout<<dp[n][k];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    for(int i=1; i<n+1; i++){
    	for(int j=1; j<k+1; j++){
    		dp[i][j] = dp[i-1][j];
    		if(j<value[i][0]) {	}
    		else dp[i][j] = max(dp[i][j], dp[i-1][j-value[i][0]]+value[i][1]);
		}
	}
    print();
    return 0;
}