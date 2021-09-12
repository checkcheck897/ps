#include <bits/stdc++.h>

# pragma GCC optimize ("O3")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>

using namespace std;

ll mod = 998244353;
ll fac[(int)4e5+5];
ll faci[(int)4e5+5];

long long int power_(long long int b, long long int x){
	if(x ==1) return b;
	long long int ret = power_(b, x/2) %mod;
	ret = (ret * ret) %mod;
	if(x %2) ret = (ret * b) %mod;
	return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    fac[0] = 1;
    faci[0] = 1;
    fac[1] = 1;
    faci[1] = 1;
    for (int i=2; i<=4e5+2; i++) {
        fac[i] = (i * fac[i-1])%mod;
        faci[i] = power_(fac[i], mod-2);
    }

    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll a[n], b[n];
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        sort (a, a+n);

        if (a[n-1] > a[n-2]+1) {
            cout << "0\n";
            continue;
        }
        if (a[n-1] < a[n-2] + 1) {
            cout << fac[n] << "\n";
            continue;
        }
        int num = 0;
        for (int i=0; i<n; i++) {
            if (a[n-2] == a[i]) num++;
        }

        int num2 = n-num-1;

        ll ans = (fac[num]*fac[num2])%mod;
        ll nhr = (fac[num+num2+1] * faci[num2])%mod;
        nhr = (nhr * faci[num+1])%mod;
        ans = (ans * nhr)%mod;

        cout << (fac[n]-ans+mod)%mod << '\n';
    }

    return 0;
}