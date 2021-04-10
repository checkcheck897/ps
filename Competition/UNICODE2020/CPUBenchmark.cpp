#include <bits/stdc++.h>

# pragma GCC optimize ("O3")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

#define x first
#define y second
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>

using namespace std;

ll p = 1e9+7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;

    cin >> n;

    ll m[n];

    for (int i=0; i<n-1; i++) cin >> m[i];

    ll dp[n];

    dp[0] = m[0];
    ll tot[n];
    tot[0] = dp[0];
    for (int i=0; i<n-2; i++)
    {
        dp[i+1] = (dp[i]*m[i+1]+m[i+1])%p;
        tot[i+1] = (tot[i]+dp[i+1])%p;
    }

    cout << tot[n-2];
    return 0;
}