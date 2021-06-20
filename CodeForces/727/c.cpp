#include <bits/stdc++.h>

# pragma GCC optimize ("O3")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, k, x;
    cin >> n >> k >> x;
    ll a[n];
    for (int i=0; i<n; i++) cin >> a[i];

    sort(a, a+n);
    vector<ll> v;
    if (n==1) {
        cout << '1';
        return 0;
    }
    for (int i=0; i<n-1; i++) {
        if (a[i+1]-a[i] > x) {
            v.push_back((a[i+1]-a[i]-1)/x);
        }  
    }
    if (v.size()==0) {
        cout << '1';
        return 0;
    }
    sort(v.begin(), v.end());
    int ans = 1;
    for (ll i : v) {
        if (i > k) {
            ans++;
        } else {
            k -= i;
        }
    }

    cout << ans;

    return 0;
}