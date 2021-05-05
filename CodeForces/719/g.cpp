#include <bits/stdc++.h>

# pragma GCC optimize ("O3")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

using namespace std;
#define xx first
#define yy second
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};


bool v[(int)2e3+5][(int)2e3+5];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, m, w;
    cin >> n >> m >> w;
    ll a[n][m];

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) cin >> a[i][j];
    }

    vector<ll> p1;
    vector<ll> p2;

    for (int aa=0; aa<2; aa++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) v[i][j] = 0;
        }
        queue<pair<pll, ll>> q;
        q.push({{aa==0 ? 0 : n-1, aa==0 ? 0 : m-1}, 0});
        while(!q.empty()) {
            ll hx = q.front().xx.xx;
            ll hy = q.front().xx.yy;
            ll d = q.front().yy;
            q.pop();
            v[hx][hy] = 1;
            if (aa==0) {
                if (a[hx][hy]) {
                    p1.push_back(d + a[hx][hy]);
                }
            }
            else {
                if (a[hx][hy]) {
                    p2.push_back(d + a[hx][hy]);
                }
            }
            for (int i=0; i<4; i++) {
                int tx = hx + dx[i];
                int ty = hy + dy[i];
                if (tx<0 || tx >=n) continue;
                if (ty<0 || ty >=m) continue;
                if (v[tx][ty] || a[tx][ty]==-1) continue;
                q.push({{tx, ty}, d+1});
            }
        }
        if (aa==0 && v[n-1][m-1]) {
            cout << (n-1)+(m-1);
            return 0;
        }
    }

    if (p1.empty() || p2.empty()) cout << "-1";
    else {
        sort(p1.begin(), p1.end());
        sort(p2.begin(), p2.end());
        cout << p1[0] + p2[0];
    }

    return 0;
}