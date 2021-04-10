#include <bits/stdc++.h>
 
using namespace std;
 
int dp[(int)1e7+5];
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    for(int i=1; i<=1e7; i++) {
        for(int j=i; j<=1e7; j += i) dp[j] += i;
    }
 
    for (int i=1e7; i>=1; i--) {
        if (dp[i] <= 1e7) {
            dp[dp[i]] = i;
        }
        dp[i] = 0;
    } 
    dp[1] = 1;
 
    int t;
    cin >> t;
 
    while(t--) {
        int n;
        cin >> n;
        cout << (dp[n]==0 ? -1 : dp[n]) << '\n';
    }
 
    return 0;
}
