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
        bool check = 0;
        for (int i=0; i<n; i++) {
            if (check) break;
            int a=0, b=0;
            for (int j=i; j<n; j++) {
                if (check) break;
                if (s[j]=='a') a++;
                else b++;
                if (a==b) {
                    cout << i+1 << " " << j+1 << "\n";
                    check = 1;
                }
            }
        }
        if (!check) cout << "-1 -1\n";
    }

    return 0;
}