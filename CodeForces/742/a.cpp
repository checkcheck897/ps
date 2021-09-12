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
        string s;
        cin >> s;
        for (int i=0; i<n; i++) {
            if (s[i] == 'L') cout << "L";
            else if (s[i] == 'R') cout << "R";
            else if (s[i] == 'U') cout << "D";
            else cout << "U";
        }
        cout << '\n';
    }

    return 0;
}