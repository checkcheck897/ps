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
        ll w, h;
        cin >> w >> h;
        ll x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ll a, b;
        cin >> a >> b;
        if (x2-x1+a > w && y2-y1+b > h) cout << -1;
        else {
            ll ans = 1e18;
            ll zero = 0;
            if (x2-x1+a<=w) {
                ans = min(max(zero, a-x1), max(a-w+x2, zero));
            } if (y2-y1+b<=h) {
                ans = min(ans, min(max(zero, b-y1), max(zero, b-h+y2)));
            }
            cout << ans;
        }
        cout << '\n';
    }

    return 0;
}