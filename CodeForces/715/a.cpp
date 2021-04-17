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
        int a[n];
        vector<int> o, e;
        for (int i=0; i<n; i++) {
            cin >> a[i];
            if(a[i]%2) o.push_back(a[i]);
            else e.push_back(a[i]);
        }


        for (int i : o) cout << i << ' ';

        for (int i : e) cout << i << ' ';

        cout << '\n';
    }

    return 0;
}