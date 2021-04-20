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
    
    ll n, d;
    cin >> n;

    vector<pll> h(n);

    for (int i=0; i<n; i++) {
        ll a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        h[i] = {b, a};
    }
    cin >> d;

    sort(h.begin(), h.end());

    for (int i=0; i<n; i++) {
        ll a=h[i].x, b=h[i].y;
        h[i] = {b, a};
    }

    priority_queue<ll, vector<ll>, greater<ll>> q;

    int ans = 0;
    for (pll i : h) {
        q.push(i.x);
        while (!q.empty() & q.top() < i.y - d) q.pop();
        if (ans < q.size()) ans = q.size();
    }

    cout << ans;
    return 0;
}