#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    int dp[n][n+5][201];

    for(int i=0; i<n; i++){
        for(int k=0; k<201; k++) dp[i][0][k] = k-100;
    }
    for(int j=1; j<=n+1; j++){
        for(int i=0; i<n; i++){
            for(int k=0; k<201; k++){
                if(k>=100) dp[i][j][k] = min(dp[(i+1)%n][j-1][-a[i]+k], dp[i][j-1][-a[(i+j-1)%n]+k]);
                else dp[i][j][k] = max(dp[(i+1)%n][j-1][a[i]+k], dp[i][j-1][a[(i+j-1)%n]+k]);
            }
        }
    }
    int m = 1000000;
    int tot = 0;
    for(int i=0; i<n; i++){
        tot += a[i];
            m = min(m, dp[i][n][100]);
    }
    cout<<(tot-m)/2;
    return 0;
}