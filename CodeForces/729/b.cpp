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
        ll n, a, b;
        cin >> n >> a >> b;
        ll k = 1;
        bool check = 0;
        if (k%b == n%b) check = 1;
        while (a != 1 && k <= n) {
            if (k%b == n%b) check = 1;
            k *= a;
        }
        if (check) cout << "Yes";
        else cout << "No";
        cout << '\n';
    }

    return 0;
}