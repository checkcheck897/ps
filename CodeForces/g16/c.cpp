#include <bits/stdc++.h>

# pragma GCC optimize ("O3")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#define x first
#define y second
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>

using namespace std;

ll get(ll a, ll b) {
    if (b==0) return 0;
    if (a==0) return 1;
    return 2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        string s1, s2;
        cin >> s1 >> s2;
        ll dp[n+1];
        for (int i=0; i<=n; i++) dp[i] = 0;
        for (int i=0; i<n; i++) {
            int n1=0, n2=0;
            n1 += (s1[i]=='1') + (s2[i]=='1');
            n2 += (s1[i]=='0') + (s2[i]=='0');
            dp[i+1] = dp[i] + get(n1, n2);
            if (i!=0) {
                n1 += (s1[i-1]=='1') + (s2[i-1]=='1');
                n2 += (s1[i-1]=='0') + (s2[i-1]=='0');
                dp[i+1] = max(dp[i-1] + get(n1, n2), dp[i+1]);
            }
        }
        cout << dp[n] << '\n';
    }

    return 0;
}