#include <bits/stdc++.h>

# pragma GCC optimize ("O3")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#define x first
#define y second
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>

using namespace std;
bool v[(int)1e5+5];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    vector<int> p;
    for (int i=2; i<1e5; i++) {
        if (v[i]) continue;
        p.push_back(i);
        for (int j=2*i; j<1e5; j+=i) v[j]=1;
    }
    while(t--) {
        ll a, b, k;
        cin >> a >> b >> k;
        ll na=0, nb=0;
        ll oa=a, ob=b;
        for (int i : p) {
            while (a%i==0) {
                a/=i;
                na++;
            } while (b%i==0) {
                b/=i;
                nb++;
            }
        }
        if (a!=1) na++;
        if (b!=1) nb++;
        if (k==1) {
            if ((oa%ob==0 || ob%oa==0) & oa!=ob) cout << "YES\n";
            else cout << "NO\n";
        }
        else {
            cout << (na+nb-k>=0?"YES":"NO")<< '\n';
        }
    }

    return 0;
}