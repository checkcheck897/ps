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
        ll n, k;
        cin >> n >> k;
        ll a[n];
        for (int i=0; i<n; i++) cin >> a[i];

        sort(a, a+n);

        ll mid = (a[0]+a[n-1]+1)/2;
        if (mid-a[0] > k) cout << -1;
        else cout << a[0] + k;
        cout << '\n';
    }

    return 0;
}