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
        ll n, m, k;
        cin >> n >> m >> k;
        ll mi=0, ma=0;
        mi = min(n-1+n*(m-1), m-1+m*(n-1));
        ma = max(n-1+n*(m-1), m-1+m*(n-1));
        if (k>=mi && k <=ma) cout <<"YES";
        else cout << "NO";

        cout << '\n';
    }

    return 0;
}