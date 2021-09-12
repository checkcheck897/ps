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
    ll n;
    cin >> n;
    ll a[n];
    for (int i=0; i<n; i++) cin >> a[i];
    ll psumo[n+1] = {0};
    ll psume[n+1] = {0};
    for (int i=0; i<n; i++) {
        psumo[i+1] = psumo[i] + (i%2==0?0:a[i]);
        psume[i+1] = psume[i] + (i%2==1?0:a[i]);
    }
    ll ans = 0;
    for (int i=0; i<n; i+=2) {
        ll tot = 0;
        ll tempmax1 = 0;
        ll tempmax2 = 0;
        for (int j=i+1; j<n; j+=2) {
            if (tot<0) break;
            ll numo = psumo[j]-psumo[i+1];
            ll nume = psume[j]-psume[i+1];
            if (i%2==0) {
                if (numo > nume + a[i]) continue;
                if (nume > numo + a[j]) continue;
                cout << i << " " << j << " " << " " << min(nume + a[i]-numo-tempmax1, numo + a[j]-nume-tempmax2) << endl;
                ans += min(nume + a[i]-numo-tempmax1, numo + a[j]-nume-tempmax2);
            }
            tempmax1 = max(tempmax1, a[j-1]-a[j]);
            tempmax2 = max(tempmax2, tot);
            tot += a[j-1]-a[j];
        }
    }
    cout << ans << '\n';
 
    return 0;
}