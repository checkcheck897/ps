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
        ll l, r;
        cin >> l >> r;
        ll ans = 0;
        while (r!=0) {
            ans += r-l;
            r/=10;
            l/=10;
        }
        cout << ans<< '\n';
    }

    return 0;
}