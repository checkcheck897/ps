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
        sort(a, a+n, greater<>());
        ll ans = a[0];
        if (n==1) {
            cout << ans << '\n';
            continue;
        }
        if (n==2) {
            if (a[0]%a[1]) cout << a[0]+a[1] << '\n';
            else cout << a[0] << '\n';
            continue;
        }
        for (int i=0; i<n-2; i++) {
            if (i<n-3 &&a[i]==a[i+1]) continue;
            if (a[i]+a[i+1]+a[i+2] < ans) break;
            if (a[i]%a[n-1]) ans = max(ans, a[i]+a[n-1]);
            for (int j=i+1; j<n-1; j++) {
                if (j<n-2 && a[j]==a[j+1]) continue;
                if (a[i]+a[j]+a[j+1] < ans) break;
                if (a[i]%a[j]) ans = max(ans, a[i]+a[j]);
                else continue;
                for (int k=j+1; k<n; k++) {
                    if (k<n-1 &&a[k]==a[k+1]) continue;
                    if (a[i]+a[j]+a[k] < ans) break;
                    if (a[j]%a[k] && a[i]%a[k]) {
                        ans = a[i]+a[j]+a[k];
                        break;
                    }
                }
                break;
            }
        }
 
        cout << ans;
        cout << '\n';
    }
 
    return 0;
}