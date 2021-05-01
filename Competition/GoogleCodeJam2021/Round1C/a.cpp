#include <bits/stdc++.h>
# pragma GCC optimize ("O3")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#define x first
#define y second
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    int test_case = t;

    while(t--) {
        ll n, k;
        cin >> n >> k;

        ll p[n];
        for (int i=0; i<n; i++) cin >> p[i];

        sort (p, p+n);
        priority_queue<ll> num;
        priority_queue<ll> num2;
        num.push(p[0]-1);
        num.push(k-p[n-1]);
        num2.push(0);
        for (int i=1; i<n; i++) {
            ll temp = p[i]-p[i-1];
            num.push(temp/2);
            num2.push(temp-1);
        }
        ll a = num.top();
        num.pop();
        ll b = num.top();
        ll ans = max(a+b, num2.top());
        cout << fixed;
        cout.precision(9);
        cout << "Case #" << test_case - t << ": "  << (long double)ans/k << "\n";
    }
    return 0;
} 