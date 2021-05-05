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
        string s;
        cin >> s;
        vector<int> v;
        for (int i=0; i<n; i++) {
            if (s[i]=='*') v.push_back(i);
        }
        if (v.empty()) cout << '0';
        else {
            ll ans = 0;
            int m = v.size();
            for (int i=0; i<m; i++) {
                ans += abs(v[i]-v[m/2]-i+m/2);
            }
            cout << ans;
        }
        cout << '\n';
    }

    return 0;
}