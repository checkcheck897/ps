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
        bool a[n];
        for (int i=0; i<n; i++) cin >> a[i];
        if (a[0]==1) {
            cout << n+1 << " ";
            for (int i=0; i<n; i++) cout << i+1 << " ";
        } else if (a[n-1]==0) {
            for (int i=0; i<=n; i++) cout << i+1 << " ";
        } else {
            int check = 0;
            for (int i=0; i<n-1; i++) {
                if (a[i]==0 && a[i+1]==1) check = i+1;
            }
            if (check==0) cout << -1;
            else {
                for (int i=0; i<=n; i++) {
                    if (i < check) cout << i+1 << " ";
                    else if (i > check+1) cout << i << " ";
                    else {
                        if (i==check) cout << n+1 << " ";
                        else cout << check+1 << " ";
                    }
                }
            }
        }
        cout << '\n';
    }

    return 0;
}

// 0 : i > n+1
// 1 : n+1 > i
// a[0] == 1 or a[n-1]==0 easy
// a[0] == 0
// >> n+1로 갈때 >> 2로 갈수있어야댐 a[1] == 0
// >> 2로 갈때 >> a[n-1] ==0이거나 연속된 01이 있어야댐
// a[1] == 1