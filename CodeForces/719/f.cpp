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
    
    ll n, a, k;
    cin >> n >> a;
    set<pll> s;
    while(a--) {
        ll l=0, r=n;
        cin >> k;
        while (l+1<r) {
            ll mid = (l+r)/2;
            cout << "? 1 " << mid << '\n';
            cout.flush();
            ll v;
            cin >> v;
            s.insert({mid, v});
            if (v > mid -k) l = mid;
            else r = mid;
        }
        cout << "! " << l+1 << '\n';
        cout.flush();
    }

    return 0;
}