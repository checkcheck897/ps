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
        ll n, l, r, s;
        cin >> n >> l >> r>> s;

        ll len = r-l+1;
        ll mi = 0;
        ll ma = 0;
        vector<int> v;
        for (int i=1; i<=len; i++) {
            mi += i;
            ma += (i+n-len);
            v.push_back(i);
        }

        if (s<mi || s>ma) {
            cout << "-1\n";
            continue;
        }

        for (int i=len-1; i>=0; i--) {
            for (int j=0; j<(n-len); j++) {
                if (s== mi) break;
                v[i]++;
                s--;
            }
        }

        bool visit[n];
        for (int i=0; i<n; i++) visit[i] = 0;
        for (int i=0; i<len; i++) visit[v[i]-1] = 1;
        vector<int> ans;
        int k = 0;
        for (int i=0; i<n; i++) {
            if (i >= l-1 && i < r) {
                for (int j=0; j<len; j++) {
                    ans.push_back(v[j]);
                    i++;
                }
                i--;
            } else {
                while(visit[k]) k++;
                ans.push_back(k+1);
                visit[k] = 1;
            }
        }
        for (int i=0; i<n; i++) cout << ans[i] << " ";
        cout << '\n';
    }

    return 0;
}