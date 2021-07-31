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
        ll n, m;
        cin >> n >> m;
        pll seg[n]; ll w[n];
        for (int i=0; i<n; i++) {
            ll a, b;
            cin >> a >> b >> w[i];
            seg[i] = {a, b};
        }

        ll l = 1, r = m+1;
        while (l+1<r) {
            
        }
        cout << '\n';
    }

    return 0;
}