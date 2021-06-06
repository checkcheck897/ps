#include <bits/stdc++.h>

# pragma GCC optimize ("O3")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#define x first
#define y second
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>

bool v[1005][1005];

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        ll n, m;
        cin >> n >> m;
        string s; cin >> s;
        for (int i=0; i<n; i++) {
            v[0][i] = s[i]=='1';
            for(int j=1; j<=min(n+1, m); j++) {
                v[j][i] = 0;
            }
        }
        
        for (int i=0; i<min(n+1, m); i++) {
            for (int j=1; j<n-1; j++) {
                if (v[i][j-1] != v[i][j+1]) v[(i+1)][j] = 1;
                else v[(i+1)][j] = v[i][j];
            }
            if (v[i][1] == 1) v[(i+1)][0] = 1;
            else v[(i+1)][0] = v[i][0];
            if (v[i][n-2] == 1) v[(i+1)][n-1] = 1;
            else v[(i+1)][n-1] = v[i][n-1];
        }
        for (int i=0; i<n; i++) cout << v[(min(n+1, m))][i];

        cout << '\n';
    }

    return 0;
}