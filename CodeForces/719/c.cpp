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
        if (n==1) cout << "1\n";
        else if (n==2) cout << "-1\n";
        else {
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    if (2*(n*i+j)+1 <=n*n) cout << 2*(n*i+j)+1 << ' ';
                    else cout << (2*(n*i+j))%(n*n) + 2 -n%2<< ' ';
                }
                cout << '\n';
            }
        }
    }

    return 0;
}