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
    int l = 10;
    ll ans[10];
    for (int i=0; i<9; i++) ans[i] = 0;
    while (l/10 < n) {
        for (int i=0; i<n; i++) ans[i] += (n/l)*(l/10);
        for (int i=0; i<=(n%l)/(l/10); i++) {
        }
        l *= 10;
    }

    return 0;
}

// 12, 2
// 1, 22
// 1,