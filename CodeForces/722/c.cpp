#include <bits/stdc++.h>

# pragma GCC optimize ("O3")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#define x first
#define y second
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>

using namespace std;

ll l[(int)1e5+5], r[(int)1e5+5];
vector<int> adj[(int)1e5+5];
bool v[(int)1e5+5];
ll dp[(int)1e5+5][2];

void solve(int here) {
    v[here] = 1;
    for (int t : adj[here]) {
        if (!v[t]) {
            v[t] = 1;
            solve(t);
            dp[here][0] += max(dp[t][0] + abs(l[t]-l[here]), dp[t][1] + abs(r[t]-l[here]));
            dp[here][1] += max(dp[t][0] + abs(l[t]-r[here]), dp[t][1] + abs(r[t]-r[here]));
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        for (int i=0; i<n; i++) {
            cin >> l[i] >> r[i];
            adj[i].clear();
            v[i] = 0;
            dp[i][0] = 0;
            dp[i][1] = 0;
        }
        for (int i=0; i<n-1; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        solve(0);
        cout << max(dp[0][0], dp[0][1]) << '\n';
    }

    return 0;
}