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

        vector<ll> a(n);
        for (int i=0; i<n; i++) cin>>a[i];

        int ans = 3;
        if (!(a[0]==n && a[n-1]==1)) ans--;
        if (a[0]==1 || a[n-1]==n) ans--;
        for (int i=0; i<n; i++) {
            if (a[i]!=i+1) break;
            if (i==n-1) ans--;
        }
        cout << ans << '\n';
    }

    return 0;
}