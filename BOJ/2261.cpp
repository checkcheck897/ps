#include <bits/stdc++.h>

# pragma GCC optimize ("O3")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#define x first
#define y second
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>

using namespace std;

int dist(pii a, pii b) {
    return (a.x-b.x) * (a.x-b.x) + (a.y-b.y) * (a.y-b.y);
}
pii h[(int)1e5+5];

int solve(int l, int r) {
    if (r-l <= 1) return dist(h[l], h[r]);
    if (r-l == 2) return min(dist(h[l], h[r]), min(dist(h[l], h[l+1]), dist(h[r], h[r-1])));
    int ret = min(solve(l, (l+r)/2), solve((l+r)/2, r));
    int mid = (h[(l+r-1)/2].x + h[(l+r+1)/2].x)/2;

    vector<pii> v;

    for (int i=l; i<=r; i++) {
        if ((h[i].x-mid)*(h[i].x-mid) < ret) v.push_back({h[i].y, h[i].x});
    }
    sort(v.begin(), v.end());
    int vs = v.size();
    for (int i=0; i+1<vs; i++) {
        for (int j=i+1; j<vs; j++) {
            if (dist({0, v[i].x}, {0, v[j].x}) < ret) {
                ret = min(ret, dist(v[i], v[j]));
            } else break;
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        h[i] = {a, b};
    }

    sort (h, h+n);
    cout << solve(0, n-1);

    return 0;
}