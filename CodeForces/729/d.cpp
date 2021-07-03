#include <bits/stdc++.h>

# pragma GCC optimize ("O3")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#define x first
#define y second
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>

using namespace std;
ll mod = 998244353;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll n;
    cin >> n;

    ll a[n];
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        if (s == "-") a[i] = -1;
        else {
            cin >> a[i];
        }
    }
    ll ans = 0;
    for (int i=0; i<n; i++) {

        if (a[i]==-1) continue;
        ll dp[n+1][2*n+1];
        for (int j=0; j<2*n+1; j++) {
            for (int k=0; k<=n; k++) dp[k][j] = 0;
        }
        dp[0][n] = 1;
        for (int j=0; j<n; j++) {
            if (j < i) {
                for (int k=n; k<2*n; k++) {
                    if (a[j]==-1) {
                        dp[j+1][max(k-1, (int)n)] += dp[j][k];
                        dp[j+1][max(k-1, (int)n)] %= mod;
                    } else if (a[j] <= a[i]) {
                        dp [j+1][k+1] += dp[j][k];
                        dp [j+1][k+1] %= mod;
                    } else {
                        dp[j+1][k] += dp[j][k];
                        dp[j+1][k] %= mod; 
                    }
                    dp[j+1][k] += dp[j][k];
                    dp[j+1][k] %= mod;
                }
            } else if (j > i) {
                for (int k=1; k<2*n; k++) {
                    if (a[j]==-1) {
                        dp[j+1][k-1] += dp[j][k];
                        dp[j+1][k-1] %= mod;
                    } else if (a[j] < a[i]) {
                        dp [j+1][k+1] += dp[j][k];
                        dp [j+1][k+1] %= mod;
                    } else {
                        dp[j+1][k] += dp[j][k];
                        dp[j+1][k] %= mod; 
                    }
                    dp[j+1][k] += dp[j][k];
                    dp[j+1][k] %= mod;
                }
            } else {
                for (int k=n; k<=2*n; k++) dp[j+1][k] = (dp[j][k])%mod;
            }
        }
        for (int j=0; j<=n; j++) {
            ans = (ans + (dp[n][j+n]*a[i])%mod)%mod;
        }
    }
    cout << ans;
    return 0;
}