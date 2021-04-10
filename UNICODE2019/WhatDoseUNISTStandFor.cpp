#include<bits/stdc++.h>

using namespace std;
int p = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int dp[n][6];
    string a = "UNIST?";
    string s;
    cin>>s;
    dp[0][0] = 1;
    for(int i=1; i<6; i++){
        dp[0][i] = 0;
        for(int j=0; j<i; j++){
            if(s[j]!=a[j]) break;
            if(j==i-1) dp[0][i] = 1; 
        }
    }
    for(int i=1; i<n; i++){
        cin>>s;
        for(int j=0; j<6; j++) dp[i][j] = dp[i-1][j];
        for(int j=0; j<6; j++){
            for(int k=1; j+k<6; k++){
                if(s[k-1]==a[j+k-1]){
                    dp[i][j+k] += dp[i-1][j];
                    dp[i][j+k] %= p;
                }
                else break;
            }
        }
    }
    cout<<dp[n-1][5];
    return 0;
}