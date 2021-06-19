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
        ll k, n, a, b;
        cin >> k >> n >> a >> b;
        if (k - n*b<=0) {
            cout << "-1\n";
        } else {
            cout << min((k-n*b-1)/(a-b), min((k-1)/a, n)) << "\n";
        }
    }

    return 0;
}