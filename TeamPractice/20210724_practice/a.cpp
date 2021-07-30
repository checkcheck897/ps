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
    
    ll n, k;
    cin >> n >> k;
    ll a[n];
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a, a+n);
    for (int i=0; i<k; i++) {
        ll l, r, c;
        cin >> l >> r >> c;
        ll b[n];
        int f1=0, f2=l-1, f3=r;
        for (int j=0; j<n; j++) {
            ll m1=2e18, m2=2e18, m3=2e18;
            if (f1 < l-1) m1 = a[f1];
            if (f2 < r) m2 = a[f2]+c;
            if (f3 < n) m3 = a[f3];

            if (m1!=2e18 && m1<=m2 && m1<=m3) {
                b[j] = m1; 
                f1++;
            } else if (m2!=2e18 && m2<=m1 && m2<=m3) {
                b[j] = m2;
                f2++;
            } else{
                b[j] = m3;
                f3++;
            }
        }
        for (int j=0; j<n; j++) a[j] = b[j];
    }
    for (int i=0; i<n; i++) cout << a[i] << ' ';

    return 0;
}