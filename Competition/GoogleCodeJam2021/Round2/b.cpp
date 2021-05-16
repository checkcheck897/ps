#include <bits/stdc++.h>
# pragma GCC optimize ("O3")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#define x first
#define y second
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>

using namespace std;

vector<pll> dp[(int)1e6+5];
ll ans[(int)1e6+5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    int test_case = t;

    for (int i=3; i<=1e3; i++) {
        dp[i].push_back({1, i});
        ans[i] = max(ans[i], (ll)1);
        for (pll k : dp[i]) {
            for (int j=2; i+k.y*j<=1e3; j++) {
                dp[i+k.y*j].push_back({k.x+1, k.y*j});
                ans[i+k.y*j] = max(ans[i+k.y*j], k.x+1);
            }
        }
    }

    while(t--) {
        int n;
        cin >> n;
        cout << "Case #" << test_case - t << ": "  << ans[n] << "\n";
    }
    return 0;
} 