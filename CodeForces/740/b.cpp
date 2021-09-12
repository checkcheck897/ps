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
        for (int i=0; i<n; i++) cin >> a[i];

        int od=0, ev=0;
        for (int i=0; i<n; i++) {
            if (a[i]%2) od++;
            else ev++;
        }

        if (od > ev+1 || ev > od+1) cout << -1;
        else {
            if (od > ev) {
                int j = 0;
                int ans = 0;
                for (int i=0; i<n; i++) {
                    if (a[i]%2) {
                        ans += abs(i-j);
                        j+=2;
                    }
                }
                cout << ans;
            } else if (ev > od) {
                int j=1;
                int ans = 0;
                for (int i=0; i<n; i++) {
                    if (a[i]%2) {
                        ans += abs(i-j);
                        j+= 2;
                    }
                }
                cout << ans;
            } else {
                int j1 = 0, j2=1;
                int ans1 = 0, ans2=0;
                for (int i=0; i<n; i++) {
                    if (a[i]%2) {
                        ans1 += abs(i-j1);
                        j1+=2;
                        ans2 += abs(i-j2);
                        j2+=2;
                    }
                }
                cout << min(ans1, ans2);
            }
        }
        cout << '\n';
    }

    return 0;
}