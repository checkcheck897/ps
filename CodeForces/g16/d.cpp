#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

# pragma GCC optimize ("O3")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#define x first
#define y second
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
ll a[305];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        ll n, m;
        cin >> n >> m;
        ll ans = 0;
        pll c[n*m];
        for (int i=0; i<n*m; i++) {
            ll f;
            cin >> f;
            c[i] = {f, i};
        }
        sort(c, c+n*m);
        for (int i=0; i<n; i++) {
            ordered_set X;
            vector<pll> v;
            for (int j=0; j<m; j++) {
                v.push_back({c[i*m+j].y, c[i*m+j].x});
            }
            sort(v.begin(), v.end());
            for (int j=0; j<m; j++) {
                a[j] = v[j].y;
                ans += X.order_of_key({a[j], -j});
                X.insert({a[j], -j});
            }
        }
        cout << ans;
        cout << '\n';
    }

    return 0;
}