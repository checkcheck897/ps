#include <bits/stdc++.h>

# pragma GCC optimize ("O3")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#define x first
#define y second
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>

using namespace std;

ll dp[2005][2005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll n;
    cin >> n;
    ll a[n];
    for (int i=0; i<n; i++) cin >> a[i];

    for (int i=0; i<2005; i++) {
        for (int j=0; j<2005; j++) {
            dp[i][j] = -1e15;
        }
    }
    dp[0][0] = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<=i; j++) {
            if (dp[i][j] != -1e15) {
                dp[i+1][j] = max(dp[i][j], dp[i+1][j]);
                if (dp[i][j]+a[i]>=0) {
                    dp[i+1][j+1] = max(dp[i][j]+a[i], dp[i+1][j+1]); 
                }
            }
        }
    }
    ll ans = 0;
    for (int i=0; i<=n; i++) {
        if (dp[n][i] != -1e15) ans = i;
    }
    cout << ans;
    return 0;
}