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
        ll a[n];
        ll b[n];
        for (int i=0; i<n; i++) cin >> a[i];
        for (int i=0; i<n; i++) cin >> b[i];
        ll psuma[n+1] = {0};
        ll psumb[n+1] = {0};
        for (int i=0; i<n; i++) {
            psuma[i+1] = psuma[i] + a[n-1-i];
            psumb[i+1] = psumb[i] + b[i];
        }
        ll ans = 1e18;
        for (int i=0; i<n; i++) {
            ans = min(ans, max(psuma[i], psumb[n-1-i]));
        }
        cout << ans << '\n';
    }

    return 0;
}