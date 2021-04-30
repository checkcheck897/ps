#include <bits/stdc++.h>

# pragma GCC optimize ("O3")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#define x first
#define y second
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>

using namespace std;
ll dp[5000][5000];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll n;
    cin >> n;
    ll a[n], b[n];
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> b[i];
    ll ans = 0;
    ll sum = 0;
    for (int i=0; i<n; i++) sum += a[i]*b[i];
    for (int i=0; i<n-1; i++) {
        dp[1][i] -= a[i]*b[i] + a[i+1]*b[i+1] - a[i]*b[i+1] - a[i+1]*b[i];
        ans = max (ans, dp[1][i]);
    }
    for (int i=0; i<n-2; i++) {
        dp[2][i] -= a[i]*b[i] + a[i+1]*b[i+1] + a[i+2]*b[i+2] - a[i]*b[i+2] - a[i+1]*b[i+1] - a[i+2]*b[i];
        ans = max (ans, dp[2][i]);
        
    }

    for (int i=3; i<n; i+=2) {
        for (int j=0; j<n-i; j++) {
            dp[i][j] -= -dp[i-2][j+1] + a[j]*b[j] + a[j+i]*b[j+i] - a[j]*b[j+i] - a[j+i]*b[j];
            ans = max (ans, dp[i][j]);
        }
    }

    for (int i=4; i<n; i+=2) {
        for (int j=0; j<n-i; j++) {
            dp[i][j] -= -dp[i-2][j+1] + a[j]*b[j] + a[j+i]*b[j+i] - a[j]*b[j+i] - a[j+i]*b[j];
            ans = max (ans, dp[i][j]);
        }
    }
    cout << ans + sum;
    return 0;
}