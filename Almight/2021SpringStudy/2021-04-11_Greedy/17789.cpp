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
    ll p, v;

    cin >> p >> v;

    ll base[v];
    pair<pll, pll> ppoint[p];

    for (int i=0; i<p; i++) {
        ll a, b;
        cin >> a >> b;
        ppoint[i] = {{a+b, i}, {a, b}};
    }

    sort(ppoint, ppoint+p);

    for (int i=0; i<v; i++) cin >> base[i];

    sort(base, base+v);

    int j = 0;
    vector<ll> ans;

    for (int i=0; i<v; i++) {
        while (j<p && !(ppoint[j].y.x == base[i] || ppoint[j].y.y == base[i]))
            j++;
        if (j<p) {
            ans.push_back(ppoint[j].x.y + 1);
            j++;
        } else {
            cout << "impossible";
            return 0;
        }
    }

    for (ll i : ans) cout << i << '\n';

    return 0;
}