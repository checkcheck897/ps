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

        int a=0, b=0;
        bool check = 0;
        for (int i=0; i<n; i++) {
            char t= s[i];
            if (t == 'T') {
                a++;
            } else {
                if (a > 0) {
                    a--;
                    b++;
                } else check = 1;
            }
        }
        if (a!=b) check = 1;
        a=0;
        b=0;
        for (int i=n-1; i>=0; i--) {
            char t= s[i];
            if (t == 'T') {
                a++;
            } else {
                if (a > 0) {
                    a--;
                    b++;
                } else check = 1;
            }
        }

        if (check || a!=b) cout << "NO\n";
        else cout << "YES\n"; 
    }

    return 0;
}