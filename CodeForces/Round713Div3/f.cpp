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
        ll n, c;
        cin >> n >> c;

        ll a[n];
        for (int i=0; i<n; i++) cin >> a[i];

        ll b[n-1];
        for (int i=0; i<n-1; i++) cin >> b[i];
        ll ans = 1e10;
        ans = min(ans, (c-1)/a[0] + 1);
        ll days = 0;
        ll diff = 0;
        for (int i=1; i<n; i++) {
            diff = (b[i-1]-1)/a[i-1] + 1;
            days += diff;
            c -= diff * a[i-1] - b[i-1];
            if (c<=0) break;
            days++;
            ans = min(ans, days + (c-1)/a[i]+1);
        }
        cout << ans << '\n';
    }
    return 0;
}