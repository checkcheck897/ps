#include <bits/stdc++.h>

# pragma GCC optimize ("O3")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#define x first
#define y second
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>

using namespace std;

int a[2000], n;

int gcd_(int xx, int yy) {
    if (xx < yy) swap(xx, yy);
    if (yy ==0) return xx;
    return gcd_(yy, xx%yy);
}

bool dp[250000];

void solve() {
    int tot = 0;
    int odd = -1;
    dp[0] = 1;
    for (int i=0; i<n; i++) {
        if(a[i]%2) odd = i+1;
        tot += a[i];
        for (int j=2000*i; j>=0; j--) dp[j+a[i]] = (dp[j] | dp[j+a[i]]);
    }
    if (tot%2) cout << "0";
    else if (!dp[tot/2]) cout << "0";
    else {
        cout << "1\n" << odd;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    int g = a[0];
    for (int i=0; i<n; i++) {
        cin >> a[i];
        g= gcd_(g, a[i]);
    }
    for (int i=0; i<n; i++) a[i]/=g;

    solve();

    return 0;
}