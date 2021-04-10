#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
bool dp[3001][3001];
int cnt[3001][3001];
int x[3000], y[3000], psumx[3001], psumy[3001], posx[3001], posy[3001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int z=0; z<t; z++){
        int n,k;
        cin>>n>>k;
        for(int i=0; i<n; i++){
            cin>>x[i];
            psumx[i+1] = psumx[i] + x[i];
        }
        int j= 0;
        for(int i=1; i<=n; i++){
            while(i>j && psumx[i]-psumx[j]>k) j++;
            posx[i] = j;
        }
        for(int i=0; i<n; i++){
            cin>>y[i];
            psumy[i+1] = psumy[i] + y[i];
        }
        j= 0;
        for(int i=1; i<=n; i++){
            while(i>j && psumy[i]-psumy[j]>k) j++;
            posy[i] = j;
        }
        dp[0][0] = 0;
        for(int i=0; i<=n; i++){
            for(int j=0; j<=n; j++){
                if(i!=0 || j!=0) dp[i][j] = 1;
                else{
                    cnt[0][0] = 0;
                    continue;
                }
                if(i==1 && j==0){
                    dp[i][j] == 1;
                    cnt[i][j] = cnt[i-1][j]+1;
                    continue;
                }
                if(i==0 && j==1){
                    dp[i][j] == 1;
                    cnt[i][j] = cnt[i][j-1]+1;
                    continue;
                }
                if(i != 0){
                    int pos = posx[i];
                    int tot =0;
                    if(j==0) tot = cnt[i-1][j]-cnt[max(pos-1, 0)][j];
                    else tot = cnt[i-1][j]-cnt[max(pos-1, 0)][j]-cnt[i-1][j-1]+cnt[max(pos-1, 0)][j-1];
                    if(pos==0){
                        if(j==0) tot = cnt[i-1][j];
                        else tot = cnt[i-1][j]-cnt[i-1][j-1];
                    }
                    if(tot>0){
                        dp[i][j] = 0;
                        if(j==0) cnt[i][j] = cnt[i-1][j];
                        else cnt[i][j] = cnt[i-1][j]+cnt[i][j-1]-cnt[i-1][j-1];
                        continue;
                    }
                }
                if(j != 0){
                    int pos = posy[j];
                    int tot =0;
                    if(i==0) tot = cnt[i][j-1]-cnt[i][max(pos-1, 0)];
                    else tot = cnt[i][j-1]-cnt[i][max(pos-1, 0)]-cnt[i-1][j-1]+cnt[i-1][max(pos-1, 0)];
                    if(pos==0){
                        if(i==0) tot = cnt[i][j-1];
                        else tot = cnt[i][j-1]-cnt[i-1][j-1];
                    }
                    if(tot>0){
                        dp[i][j] = 0;
                        if(i==0) cnt[i][j] = cnt[i][j-1];
                        else cnt[i][j] = cnt[i-1][j]+cnt[i][j-1]-cnt[i-1][j-1];
                        continue;
                    }
                }
                if(dp[i][j]==1){
                    if(i==0) cnt[i][j] = cnt[i][j-1]+1;
                    else if(j==0) cnt[i][j] = cnt[i-1][j]+1;
                    else cnt[i][j] = cnt[i-1][j]+cnt[i][j-1]-cnt[i-1][j-1]+1;
                }
            }
        }
        cout<<"Case #"<<z+1<<"\n";
        cout<<(n+1)*(n+1)-cnt[n][n]<<" "<<cnt[n][n]<<"\n";
    }
    return 0;
}