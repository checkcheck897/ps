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
    ll a[15];
    a[0] = 2050;
    for (int i=1; i<15; i++) {
        a[i] = a[i-1]*10;
    }
    while(t--) {
        ll n;
        cin >> n;
        int ans = 0;
        for (int i=14; i>=0; i--) {
            while(n >= a[i]) {
                n -= a[i];
                ans++;
            }
        }
        cout << (n==0?ans:-1);

        cout << '\n';
    }

    return 0;
}