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

    sort (a, a+n);
    ll tot = 0;
    ll b[n-1];
    for (int i=0; i<n-1; i++) {
        tot += a[i+1]-a[i];
        b[i] = a[i+1]-a[i];
    }

    sort(b, b+n-1);

    for (int i=0; i<k-1; i++) {
        tot -= b[n-2-i];
    }

    cout << tot;

    return 0;
}