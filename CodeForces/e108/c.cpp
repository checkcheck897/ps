#include <bits/stdc++.h>

# pragma GCC optimize ("O3")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#define x first
#define y second
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        priority_queue<ll> p[n];
        ll u[n];
        ll ans[n];
        for (int i=0; i<n; i++) {
            cin >> u[i];
            ans[i] =0;
        }

        ll s;
        for (int i=0; i<n; i++) {
            cin >> s;
            p[u[i]-1].push(s);
        }

        for (int i=0; i<n; i++) {
            ll tot = 0;
            int j = 0;
            ll last = 0;
            ll si = p[i].size();
            ll dp[si];
            for (int k=0; k<si; k++) dp[k] = 0;
            while(!p[i].empty()) {
                ll temp = p[i].top();
                last = temp;
                p[i].pop();
                tot += temp;
                dp[j] += tot;
                j++;
            }
            for (int i=1; i<=si; i++) {
                ans[i-1] += dp[si-1-si%i];
            }
            j = 0;
        }
        for (int i=0; i<n; i++) cout << ans[i] << ' ';
        cout << '\n';
    }

    return 0;
}