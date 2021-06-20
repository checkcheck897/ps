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
    pll a[n];
    ll free = 0;
    for (int i=0; i<n; i++) {
        ll k, m;
        cin >> k >> m;
        a[i] = {m, k};
        free+=k;
    }
    sort(a, a+n);

    ll c = 0;
    ll disc = 0;
    ll now = 0;
    for (int i=0; i<n; i++) {
        if (free==0) break;
        if (a[i].x - now < free) {
            ll num1 = max(a[i].x - now, (ll)0);
            free -= num1;
            c += num1;
            now += num1;
            ll num = a[i].y;
            num = min(free, num);
            free -= num;
            disc += num;
            now += num; 
        } else break;
    }
    cout << 2*c + disc + 2*free;
    return 0;
}