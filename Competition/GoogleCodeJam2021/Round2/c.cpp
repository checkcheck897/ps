#include <bits/stdc++.h>
# pragma GCC optimize ("O3")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#define x first
#define y second
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    int test_case = t;

    while(t--) {
        int n;
        cin >> n;
        ll a[n];
        for (int i=0; i<n; i++) cin >> a[i];

        vector<int> v;
        for (int j=0; j<n; j++) v.push_back(j+1);
        ll ans = 0;
        ll dp[14];
        for (int i=0; i<14; i++) dp[i] = 0;
        do {
            if (n==1) {
                ans = 1;
                break;
            }
            for (int i=0; i<n; i++) {
                ll h = 0;
                for (int j=0; j<i; j++) {
                    if (v[i] > v[j]) h = max(h, dp[j]);
                }
                dp[i] = h+1;
                if (dp[i] != a[i]) break;
                if (i==n-1) ans++;
            }
        } while(next_permutation(v.begin(), v.end()));
        cout << "Case #" << test_case - t << ": " << ans << "\n";
    }
    return 0;
} 