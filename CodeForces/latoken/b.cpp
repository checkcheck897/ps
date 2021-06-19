#include <bits/stdc++.h>

# pragma GCC optimize ("O3")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#define x first
#define y second
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>

using namespace std;
ll a[(int)5e5];
ll ispeak(int i, int n) {
    if (i==0) {
        if (a[0]>a[1]) return a[1];
    }
    else if (i==n-1) {
        if (a[n-1]>a[n-2]) return a[n-2];
    }
    else {
        if ((a[i]>a[i-1])&(a[i]>a[i+1])) return max(a[i-1], a[i+1]);
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        if (n==1) cout << a[0]+1;
        else {
            ll ans = 0;
            for (int j=0; j<10; j++) {
                for (int i=0; i<n; i++) {
                ll temp = ispeak(i, n);
                if (temp!=-1) {
                    ans += a[i]-temp;
                    a[i] = temp;
                }
            }
            for (int i=n-1; i>=0; i--) {
                ll temp = ispeak(i, n);
                if (temp!=-1) {
                    ans += a[i]-temp;
                    a[i] = temp;
                }
            }
            }
            ans += a[0]+a[n-1];
            for (int i=0; i<n-1; i++) ans += abs(a[i+1]-a[i]);
            cout << ans;
        }
        cout << '\n';
    }

    return 0;
}