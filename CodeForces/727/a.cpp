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
        ll n, xx, t;
        cin >> n >> xx >> t;
        if (t < xx) cout << 0;
        else if (n > t/xx) cout << (t/xx)*(t/xx-1)/2 + (t/xx)*(n-t/xx);
        else cout << n*(n-1)/2;
        cout << '\n';
    }
    
    return 0;
}