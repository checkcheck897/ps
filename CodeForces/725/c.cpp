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
        ll n, l, r;
        cin >> n >> l >> r;
        ll a[n];
        for (int i=0; i<n; i++) cin >> a[i];
        sort(a, a+n);
        ll ans = 0;
        for (int i=0; i<n; i++) {
            int ma =lower_bound(a, a+n, r-a[i]+1)-a;
            int mi =lower_bound(a, a+n, l-a[i])-a;
            ma = max(ma, i+1);
            mi = max(mi, i+1);
            ans += (ma-mi);
        }
        cout << ans << '\n';
    }

    return 0;
}