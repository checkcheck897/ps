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
        for (int i=0; i<n; i++) {
            for (int j=0; j<2*n; j++) {
                if (j <= 2*i) {
                    if (j%2==0) cout << '(';
                    else cout << ')';
                } else {
                    if (j -2*i < n-i) cout << '(';
                    else cout << ')';
                }
            }
            cout << '\n';
        }
    }

    return 0;
}