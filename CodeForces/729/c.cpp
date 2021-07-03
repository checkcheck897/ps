#include <bits/stdc++.h>

# pragma GCC optimize ("O3")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#define x first
#define y second
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>

using namespace std;

ll mod = 1e9+7;

ll gcd(ll a, ll b) {
    if (b==0) return a;
    return gcd(b, a%b);
}
ll lcm(ll a, ll b){
    return ((a/gcd(a,b))*b);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;

    while(t--) {
        ll n;
        cin >> n;
        ll tot = 2*n;
        ll res = 1;
        for (int i=2; i<=41; i++) {
            res = lcm(res, i);
            tot = (tot + n/res)%mod;
        }
        cout << tot;
        cout << '\n';
    }

    return 0;
}