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
        for (int i=0; i<n; i++) {
            cin >> a[i];
            b[i] = 0;
        }
        for (int i=0; i<n; i++) {
            b[a[i]-1]++;
        }
        sort(b, b+n);

        int now = b[n-1];
        ll ans = b[n-1];
        for (int i=n-2; i>=0; i--) {
            if (now==0) break;
            if (now<=b[i]) {
                now--;
                ans += now;
            } else {
                now = b[i];
                ans += now;
            }
        }
        cout << ans;
        cout << '\n';
    }

    return 0;
}