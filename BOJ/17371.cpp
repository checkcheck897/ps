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
    pll t[n];
    for (int i=0; i<n; i++) {
        ll a, b;
        cin >> a >> b;
        t[i] = {a, b};
    }
    ll m = 1e18;
    int ans = 0;
    for (int i=0; i<n; i++) {
        ll temp = 0;
        for (int j=0; j<n; j++) {
            if (i==j) continue;
            temp = max(temp, (t[i].x-t[j].x)*(t[i].x-t[j].x) + (t[i].y-t[j].y)*(t[i].y-t[j].y));
        }
        if (temp < m) {
            m = temp;
            ans = i;
        }
    }    
    cout << t[ans].x << " " << t[ans].y;
    return 0;
}