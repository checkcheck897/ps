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
        ll a, b;
        cin >> a >> b;
        if ((a-b)%2==0) {
            if (a==0 && b==0) cout << "0";
            else if (a==b) cout << "1";
            else cout << "2";
        } else cout << -1;
        cout << '\n';
    }

    return 0;
}