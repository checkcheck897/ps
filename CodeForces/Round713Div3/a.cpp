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
        pii a[n];
        for (int i=0; i<n; i++) {
            int temp;
            cin >> temp;
            a[i] = {temp, i};
        }
        sort (a, a+n);
        int ans =0;
        if(a[0].x == a[1].x) {
            ans = a[n-1].y;
        } else {
            ans = a[0].y;
        }
        cout << ans + 1 << '\n';
    }

    return 0;
}