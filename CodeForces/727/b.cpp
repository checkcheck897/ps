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
    ll n, t;
    cin >> n >> t;
    string s;
    cin >> s;
    ll num[n+1][30];
    for (int i=0; i<26; i++) num[0][i]=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<26; j++) num[i+1][j]=num[i][j];
        num[i+1][s[i]-'a']++;
    }
    while(t--) {
        ll l, r;
        cin >> l >> r;
        l--;
        ll ans =0;
        for (int i=0; i<26; i++) {
            ans += (i+1) * (num[r][i]-num[l][i]);
        }
        cout << ans;
        cout << '\n';
    }

    return 0;
}