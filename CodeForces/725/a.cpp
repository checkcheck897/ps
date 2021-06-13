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
        pll a[n];
        for (int i=0; i<n; i++) {
            ll b;
            cin >> b;
            a[i] = {b, i};
        }
        sort(a, a+n);
        ll c[2] = {a[0].y, a[n-1].y};
        sort(c, c+2);
        ll d[3] = {(n-c[1]+1) + (c[0]), c[1]+1, n-c[0]};
        sort(d, d+3);
        cout << d[0];
        cout << '\n';
    }

    return 0;
}