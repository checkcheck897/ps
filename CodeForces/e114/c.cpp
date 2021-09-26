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
    vector<ll> a(n);
    ll tot = 0;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        tot += a[i];
    }
    sort(a.begin(), a.end());
    ll m;
    cin >> m;
    for (int i=0; i<m; i++) {
        ll c, d;
        cin >> c >> d;
        ll idx = lower_bound(a.begin(), a.end(), c) - a.begin();
        if (idx !=0) idx--;
        ll diff = max((ll)0, c-a[idx]);
        ll l = tot;
        if (c-a[idx] < 0) {
            l += +c-a[idx];
        }
        ll p = tot+c-a[idx+1];
        if (c-a[idx+1] > 0) {
            p = tot;
        }
        cout << min(max(diff, c+d-l), max(max((ll)0, c-a[idx+1]), c+d-p));
        cout << "\n";
    }

    return 0;
}