#include <bits/stdc++.h>

# pragma GCC optimize ("O3")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#define x first
#define y second
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>

using namespace std;


bool v[10005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    for (int i=1; i<=100; i++) v[i*i] = 1;
    
    while(t--) {
        int n, k;
        cin >> n >> k;

        int a[n];
        for (int i=0; i<n; i++) cin >> a[i];
        int i=0;
        while(k--) {
            while(a[i]==0) i++;
            if(i>=n-1) break;
            a[i]--;
            a[n-1]++;
        }
        for (int i=0; i<n; i++) cout << a[i] << ' ';

        cout << '\n';
    }

    return 0;
}