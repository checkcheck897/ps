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

        ll b[n+2];
        for (int i=0; i<n+2; i++) cin >> b[i];

        sort(b, b+n+2);

        ll psum[n+3];
        psum[0] = 0;
        for (int i=0; i<n+2; i++) psum[i+1] = psum[i] + b[i];


        ll diff = psum[n+1] - b[n+1];
        ll idx= lower_bound(b, b+n+2, diff) - b;
        if (diff == b[idx] && idx < n+1) {
            for (int i=0; i<n+1; i++) {
                if(idx==i) continue;
                cout << b[i] << ' ';
            }
            cout << "\n";
            continue;
        }

        if (psum[n] == b[n]) {
            for (int i=0; i<n; i++) cout << b[i] << ' ';
            cout << '\n';
            continue;
        }

        cout << "-1";
        cout << '\n';
    }

    return 0;
}