#include <bits/stdc++.h>
# pragma GCC optimize ("O3")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#define x first
#define y second
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    int test_case = t;
    vector<ll> ans;
    for (ll i=1; i<1e4; i++) {
        string temp = "";
        for (int j=0; j<6; j++) {
            temp += to_string((i+j));
            if (stoll(temp) > 1e10) break;
            if (j>=1) {
                ans.push_back(stoll(temp));
            }
        }
    }

    sort(ans.begin(), ans.end());
    while(t--) {
        ll n;
        cin >> n;
        cout << "Case #" << test_case - t << ": " << *lower_bound(ans.begin(), ans.end(), n+1) << '\n';
    }
    return 0;
} 