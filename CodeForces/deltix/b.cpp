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
        ll a[n];
        for (int i=0; i<n; i++) cin >> a[i];
        cout << 3*n << '\n';
        for (int i=0; i<n/2; i++) {
            int f = i*2+1; int g = i*2+2;
            cout << "1 " << f << ' ' << g; cout << '\n';
            cout << "2 " << f << ' ' << g; cout << '\n';
            cout << "1 " << f << ' ' << g; cout << '\n';
            cout << "2 " << f << ' ' << g; cout << '\n'; 
            cout << "1 " << f << ' ' << g; cout << '\n';
            cout << "2 " << f << ' ' << g; cout << '\n';
        }
    }

    return 0;
}