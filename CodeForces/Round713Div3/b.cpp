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
        string s[n];
        for (int i=0; i<n; i++) cin >> s[i];
        vector<pii> v;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (s[i][j] == '*') v.push_back({i,j});
            }
        }

        if (v[0].x == v[1].x) {
            s[(v[0].x+1)%n][v[0].y] = '*';
            s[(v[0].x+1)%n][v[1].y] = '*';
        } else if (v[0].y == v[1].y) {
            s[v[0].x][(v[0].y+1)%n] = '*';
            s[v[1].x][(v[0].y+1)%n] = '*';
        } else {
            s[min(v[0].x, v[1].x)][min(v[0].y, v[1].y)] = '*';
            s[max(v[0].x, v[1].x)][max(v[0].y, v[1].y)] = '*';
            s[min(v[0].x, v[1].x)][max(v[0].y, v[1].y)] = '*';
            s[max(v[0].x, v[1].x)][min(v[0].y, v[1].y)] = '*';
        }

        for (int i=0; i<n; i++) cout << s[i] << '\n';
    }

    return 0;
}