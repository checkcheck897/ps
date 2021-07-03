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
        ll a[2*n];
        ll odd = 0;
        for (int i=0; i<2*n; i++) {
            cin >> a[i];
            if (a[i]%2) odd++;
        }
        if (odd==n) cout << "Yes";
        else cout << "No";
        cout << '\n';
    }

    return 0;
}