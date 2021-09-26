#include <bits/stdc++.h>

# pragma GCC optimize ("O3")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#define x first
#define y second
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>

using namespace std;
ll max(ll a, ll b, ll c) {
    return max(max(a, b), c);
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        ll a, b, c, n;
        cin >> a >> b >> c >> n;
        ll mx=5e18, mi=0;
        mx = min (mx, a+b+c-3);
        mi = max (mi, -(a+b+c)+2*max(a, b, c)-1);
        if (n <= mx && n >= mi) cout << "YES";
        else cout << "NO";
        cout << '\n';
    }

    return 0;
}