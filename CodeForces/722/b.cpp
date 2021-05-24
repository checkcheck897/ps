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

        for (int i=0; i<n; i++) cin >> a[i];
        sort(a, a+n);
        ll diff = 2e9;
        int ans = 1;
        for (int i=0; i<n-1; i++) {
            diff = min(diff, abs(a[i]-a[i+1]));
            if (a[i+1] > diff) break;
            ans++;
        }
        cout << ans << '\n';
    }

    return 0;
}