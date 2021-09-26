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
    
    ll n;
    cin >> n;
    ll a[n];
    ll tot = 0;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        tot += a[i];
    }
    sort(a, a+n);
    ll m;
    cin >> m;
    for (int i=0; i<m; i++) {
        ll c, d;
        cin >> c >> d;
        int idx = lower_bound(a, a+n, c) - a;
        ll m = a[idx];
        ll diff = c-a[idx];
        if (idx < n-1) {
            cout << min(max(diff, c+d-(tot-diff)), c+d-(tot+c-a[idx+1]));
        }
        else cout << max(diff, c+d-(tot-diff));
    }

    return 0;
}