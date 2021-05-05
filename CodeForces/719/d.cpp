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
        for (int i=0; i<n; i++) {
            cin >> a[i];
            a[i] -= i;
        }
        sort(a, a+n);
        ll cnt = 0;
        ll ans = 0;
        for (int i=0; i<n-1; i++) {
            if (a[i]==a[i+1]) cnt++;
            else {
                ans +=cnt * (cnt+1)/2;
                cnt = 0;
            }
        }
        ans +=cnt * (cnt+1)/2;
        cout << ans;
    
        cout << '\n';
    }

    return 0;
}