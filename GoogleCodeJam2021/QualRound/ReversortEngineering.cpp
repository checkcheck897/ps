#include <bits/stdc++.h>

# pragma GCC optimize ("O3")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#define x first
#define y second
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>

using namespace std;

ll check[8][1005];

pll solve(vector<int> v) {
    int ans = 0;

    ll p = 0;
    ll l = 1;
    for (int i=0; i<v.size(); i++) {
        p += l * v[i];
        l *= 10;
    }

    for (int i=0; i<v.size()-1; i++) {
        for (int j=i; j<v.size(); j++) {
            if (v[j] == i+1) {
                ans += (j-i+1);
                for (int k=0; k<(j-i+1)/2; k++) {
                    swap(v[i+k], v[j-k]);
                }
                break;
            }
        }
    }
    return {ans, p};
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    int test_case = t;

    for (int i=2; i<8; i++) {
        for (int j=0; j<=1000; j++) check[i][j] = -1;
        vector<int> v;
        for (int j=1; j<=i; j++) v.push_back(j);
        do {
            pll ret = solve(v);
            check[i][ret.x] = ret.y;
        }
        while(next_permutation(v.begin(), v.begin()+i));
    }

    while(t--) {
        int n, c;
        cin >> n >> c;
        if (n > 7 || check[n][c] == - 1) cout << "Case #" << test_case - t << ": IMPOSSIBLE" << '\n';
        else {
                ll ans = check[n][c];
                cout << "Case #" << test_case - t << ": ";
                vector<int> v;
                while (ans) {
                    v.push_back(ans%10);
                    ans /= 10;
                }

                for (auto i : v) cout << i << ' ';
                cout << '\n';
        }
    }

    return 0;
}