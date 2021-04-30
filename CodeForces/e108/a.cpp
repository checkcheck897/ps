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
        ll r, b, d;
        cin >> r >> b >> d;
        bool check = 1;
        if (r < b) {
            if (b - r*(d+1) >0) check = 0;
        } else {
            if (r - b*(d+1) >0) check = 0;
        }
        if (check) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}