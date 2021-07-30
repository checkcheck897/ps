#include <bits/stdc++.h>

# pragma GCC optimize ("O3")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#define x first
#define y second
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>

using namespace std;

ll n, m;

vector<ll> adj[1005];
bool v[1005];
bool check;

void dfs(int here, int root, int depth) {
    v[here] = 1;
    for (auto i : adj[here]) {
        if (i==root && depth%2==1) check = true;
        if (!v[i]) dfs(i, root, depth+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for (int i=0; i<n; i++) {
            adj[i].clear();
            v[i] = 0;
        }
        for (int i=0; i<m; i++) {
            ll a, b;
            cin >> a >> b;
            adj[a-1].push_back(b-1);
            adj[b-1].push_back(a-1);
        }

        int cnt = 0;
        check = false;
        for (int i=0; i<n; i++) {
            if (!v[i]) {
                dfs(i, i, 1);
            }
        }

        if (check) cout << "impossible\n";
        else cout << "possible\n";
    }

    return 0;
}