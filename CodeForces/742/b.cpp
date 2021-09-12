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
    vector<int> v;
    for (int i=0; i<256; i++) {
        int oi = i;
        int m = 100;
        int tot = 0;
        while (oi!=0) {
            if (oi%2) tot += m;
            m *= 10;
            oi /= 2;
        }
        v.push_back(tot);
    }
    while(t--) {
        ll n;
        cin >> n;
        ll ans = 0;
        for (int i : v) {
            if (i > n) continue;
            ll temp = 1;
            int oi = n-i;  
            i /= 10;
            cout << i << " i \n";
            while (oi!=0 || i!=0) {
                int toi = i%10;
                int ti = oi%10;
                int re = 10*toi + ti;
                temp += min(re+1, 19-re);
                oi /= 10; i/= 10;
            }
            ans += temp;
            cout << temp << "temp \n";
        }
        cout << ans << '\n';
    }

    return 0;
}