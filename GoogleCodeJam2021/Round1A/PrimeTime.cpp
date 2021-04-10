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
        int m;
        cin >> m;
        pll v[m];
        ll tot = 0;

        for (int i=0; i<m; i++) {
            ll a, b;
            cin >> a >> b;
            v[i] = {a, b};
            tot += a*b;
        }
        ll up = tot - 2;
        ll bo = max(tot - 1000000, (ll)0);
        ll ans = 0;

        while (up > bo) {
            ll nup = up;
            ll temp = tot;
            for (int i=0; i<m; i++) {
                ll num= v[i].y;
                while (num>0 && nup%v[i].x == 0) {
                    nup /= v[i].x;
                    num--;
                    temp -= v[i].x;
                }
            }
            if (nup == 1 && temp == up) {
                ans = up;
                break;
            }
            up--;
        }
        cout << "Case #" << test_case - t << ": " << ans << '\n';
    }
    return 0;
} 