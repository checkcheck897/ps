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
        ll n, m;
        cin >> n >> m;
        vector<ll> b[n];
        vector<pll> a;
        bool v[n][m];
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                int c;
                cin >> c;
                b[i].push_back(c);
            }
            sort(b[i].begin(), b[i].end());
            for (int j=0; j<m; j++) a.push_back({b[i][j], 105*i+j});
        }
        int j = 0;
        vector<ll> ans[n];
        sort(a.begin(), a.end());
        for (int i=0; i<n; i++) {
            for ( j; j<n*m; j++) {
                if (!v[a[j].y/105][a[j].y%105]) {
                    for (int k=0; k<n; k++) {
                        if (k==a[j].y/105) {
                            ans[k].push_back(a[j].first);
                            v[a[j].y/105][a[j].y%105] = 1;
                        }
                        else {
                            ans[k].push_back(b[k][m-1-i]);
                            v[k][m-1-i] = 1;
                        }
                    }
                    break;
                }
            }
        }

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) cout << ans[j][i] << ' '; 
            cout << '\n';
        }

    }

    return 0;
}