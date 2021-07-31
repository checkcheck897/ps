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
        ll ans = 1e18;
        for (int i=0; i<30; i++) {
            for (int j=0; j<40; j++) {
                ll newn = n - 10*i - 8*j;
                if (newn < 0) {
                    ans = min ( ans, (ll)25*i + 20*j);
                    continue;
                }
                ans = min (ans, (newn+5)/6 * 15 + 25*i + 20*j);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}