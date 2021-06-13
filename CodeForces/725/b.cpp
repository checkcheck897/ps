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
        ll a[n];
        ll tot = 0;
        for (int i=0; i<n; i++) {
            cin >> a[i];
            tot += a[i];
        }
        ll ans = 0;
        if (tot %n!=0) ans = -1;
        else{
            sort(a, a+n);
            for (int i=n-1; i>=0; i--) {
                if (a[i] > tot/n) ans++;
            }
        }
        cout << ans;
        cout << '\n';
    }

    return 0;
}