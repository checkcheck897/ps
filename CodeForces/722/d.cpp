#include <bits/stdc++.h>

# pragma GCC optimize ("O3")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#define x first
#define y second
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>

using namespace std;

ll dp[(int)1e6+5] = {1,1,1,1,1};
ll tot[(int)1e6+5] = {1, 2};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll mod = 998244353;

    for (int i=2; i<=1e6; i++) {
        dp[i] = 1;
    }
    for (int i=2; i<=1e6; i++) {
        dp[i] = (dp[i-1]+dp[i])%mod;
    }
    // for (int i=2; i<=1e6; i++) {
    //     dp[i] = (dp[i-1]+dp[i])%mod;
    // }
    ll n;
    cin >> n;
    cout << dp[n];

    return 0;
}