#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
int dp[300][300][301];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int z=0; z<t; z++){
        int n, k, m;
        cin>>n>>k>>m;
        if(n>300 || k>300) return 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int x=0; x<=k; x++) dp[i][j][x] = 1e5;
            }
        }
        for(int i=0; i<n; i++) dp[i][i][0] = 0;
        for(int d=0; d<k; d++){
            int a,b;
            cin>>a>>b;
            a--; b--;
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(dp[i][j][d]!=1e5){
                        if(j==a){
                            dp[i][b][d+1] = min(dp[i][j][d], dp[i][b][d+1]);
                            dp[i][j][d+1] = min(dp[i][j][d+1], dp[i][j][d]+1);
                        }
                        else if(j==b){
                            dp[i][a][d+1] = min(dp[i][j][d], dp[i][a][d+1]);
                            dp[i][j][d+1] = min(dp[i][j][d+1], dp[i][j][d]+1);
                        }
                        else{
                             dp[i][j][d+1] = min(dp[i][j][d+1], dp[i][j][d]);
                        }
                    }
                }
            }
        }
        long long ans = 0;
        cout<<"Case #"<<z+1<<"\n";
        for(int i=0; i<m; i++){
            int a,b;
            cin>>a>>b;
            a--; b--;
            if(dp[a][b][k]==1e5) ans -= 1;
            else ans += dp[a][b][k];
        }
        cout<<ans;
        cout<<"\n";
    }
    return 0;
}