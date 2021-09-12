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
    
    int n;
    cin >> n;
    pll p[n];
    ll tot = 0;
    for (int i=0; i<n; i++) {
        ll a, b;
        cin >> a >> b;
        p[i] = {a, b};
        tot += b;
    }
    sort (p, p+n);
    ll tsum = 0;
    for (int i=0; i<n; i++) {
        tsum += p[i].y;
        if (2*tsum >= tot) {
            cout << p[i].x;
            break;
        }
    }

    return 0;
}