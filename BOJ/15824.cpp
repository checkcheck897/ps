#include <bits/stdc++.h>

# pragma GCC optimize ("O3")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#define x first
#define y second
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>

using namespace std;

ll p = 1e9+7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;

    ll a[n], b[n];
    for (int i=0; i<n; i++) cin >> a[i];
    ll tot = 0;
    sort(a, a+n);
    b[0] = 1;

    for (int i=1; i<n; i++) {
        b[i] = (b[i-1]*2) %p;
    }
    for (int i=0; i<n; i++) {
        tot -= a[i] * b[n-1-i];
        tot %= p;
    }
    for (int i=0; i<n; i++) {
        tot += a[i] * b[i];
        tot %=p;
    }

    cout << tot;
    return 0;
}