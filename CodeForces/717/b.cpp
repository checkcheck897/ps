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
        ll tot[n+1] ={0};
        for (int i=0; i<n; i++) {
            cin >> a[i];
            tot[i+1] = tot[i]^ a[i];
        }
        if (tot[n]==0) cout << "YES";
        else {
            bool check = 0;
            for (int i=1; i<n; i++) {
                for (int j=i; j<n-1; j++) {
                    if (tot[i] == (tot[j+1]^tot[i]) && (tot[j+1]^tot[i]) == (tot[j+1]^tot[n])) check = 1;
                }
            }
            if (check) cout << "YES";
            else cout << "NO";
        }

        cout << '\n';
    }

    return 0;
}