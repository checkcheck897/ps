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
    ll n;
    cin >> n;

    ll a[n];
    for (int i=0; i<n; i++) cin >> a[i];
    sort (a, a+n);
    ll ans = 1e18;
    for (int i=0; i<n; i++) {
        ll temp = 0;
        ll prev = i-1;
        ll next = i+1;
        ll nowmin = a[i];
        ll nowmax = a[i];
        while(prev != -1 || next != n) {
            if (prev == -1) {
                temp += nowmax-nowmin;
                nowmax = a[next];
                next++;
                continue;
            }
            if (next == n) {
                temp += nowmax-nowmin;
                nowmin = a[prev];
                prev--;
                continue;
            }

            if ((nowmin-a[prev])*(n-next) < (a[next]-nowmax)*(prev+1)) {
                temp += nowmax-nowmin;
                nowmin = a[prev];
                prev--;
            } else {
                temp += nowmax-nowmin;
                nowmax = a[next];
                next++;;
            }
        }
        temp += nowmax - nowmin;
        ans = min(ans, temp);
    }

    cout << ans << '\n';
    return 0;
}       