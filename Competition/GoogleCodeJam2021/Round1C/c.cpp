#include <bits/stdc++.h>
# pragma GCC optimize ("O3")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#define x first
#define y second
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>

using namespace std;

bool v[(1<<15)];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    int test_case = t;

    while(t--) {

        string s, e;
        cin >> s >> e;
        ll a=0, b=0;
        for (int i=0; i<s.length(); i++) {
            if (s[s.length()-1-i]=='1') a += (1 << i);
        }
        for (int i=0; i<e.length(); i++) {
            if (e[e.length()-1-i]=='1') b += (1 << i);
        }
        for (int i=0; i<(1<<15); i++) v[i] = 0;

        queue<pll> q;
        q.push({a, 0});
        int depth = -1;
        while (!q.empty()) {
            ll s = q.front().x;
            ll d = q.front().y;
            v[s] = 1;
            q.pop();
            if (s==b){
                depth = d;
                break;
            }
            if (d > 10000) break;
            if (s < (1<<14) && !v[2*s]) q.push({2*s, d+1});
            for (int i=1; i<16; i++) {
                if ((1<<i) > s) {
                    if(!v[(1<<i)-s-1]) q.push({(1<<(i)) -s-1, d+1});
                    break;
                }
            }
        }

        if(depth==-1) cout << "Case #" << test_case - t << ": " << "IMPOSSIBLE" << '\n';
        else cout << "Case #" << test_case - t << ": " << depth << '\n';
    }
    return 0;
} 