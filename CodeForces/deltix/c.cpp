#include <bits/stdc++.h>

# pragma GCC optimize ("O3")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#define x first
#define y second
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>

using namespace std;
int v[1005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        int a[n];
        for (int i=0; i<n; i++) {
            v[i] = 0;
            cin >> a[i];
        }
        v[0] = 1;
        int d = 0;
        for (int i=1; i<n; i++) {
            if (a[i] == 1) {
                d++;
                v[d]++;
            }
        }
        cout << '\n';
    }

    return 0;
}