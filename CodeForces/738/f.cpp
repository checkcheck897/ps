#include <bits/stdc++.h>

# pragma GCC optimize ("O3")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#define x first
#define y second
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>

using namespace std;
bool isp[100005];
vector<int> t;
vector<int> f;
ll n, mx;
vector<pii> seg;
ll mod = 998244353;
ll dp[55][100505];
ll psum[100505];

ll solve(int div) {
    int smx = mx/div;
    vector<int> count;
    int on = n;
    for (int i=0; i<n; i++) {
        int sl = (seg[i].first-1)/div + 1;
        int sr = (seg[i].second)/div;
        if (sl > sr) return 0;
        smx -= sl;
        if (sr-sl!=0) {
            count.push_back(sr-sl);
        } else on--;
    }
    if (smx<0) return 0;
    if (on==0) return 1;
    for (int i=0; i<on+1; i++) {
        for (int j=0; j<smx+1; j++) dp[i][j] = 0;
    }
    dp[0][0] = 1;
    ll ret = 0;
    for (int i=0; i<on; i++) {
        psum[0] = 0;
        for (int j=0; j<=smx; j++){
            psum[j+1] = (psum[j] + dp[i][j])%mod;
        } 
        for (int j=0; j<=smx; j++) {
            dp[i+1][j] = (psum[j+1]-psum[max(0,j-count[i])])%mod;
            if (i+1==on) ret = (ret+dp[i+1][j])%mod;
        }
    }
    return ret%mod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<ll> p;
    cin >> n >> mx;

    for (int i=2; i<=mx; i++) {
        if (isp[i]) continue;
        p.push_back(i);
        for (int j=2*i; j<=mx; j+=i) isp[j] = 1;
    }
    int l = p.size();
    
    for (int i=0; i<l; i++) {
        if (p[i]*n > mx) break;
        t.push_back(p[i]);
        for (int j=i+1; j<l; j++) {
            if (p[i]*p[j]*n > mx) break;
            f.push_back(p[i]*p[j]);
            for (int k=j+1; k<l; k++) {
                if (p[i]*p[j]*p[k]*n > mx) break;
                t.push_back(p[i]*p[j]*p[k]);
                for (int aa=k+1; aa<l; aa++) {
                    if (p[i]*p[j]*p[k]*p[aa]*n > mx) break;
                    f.push_back(p[i]*p[j]*p[k]*p[aa]);
                    for (int bb=aa+1; bb<l; bb++) {
                        if (p[i]*p[j]*p[k]*p[aa]*p[bb]*n > mx) break;
                        t.push_back(p[i]*p[j]*p[k]*p[aa]*p[bb]);
                        for (int cc=bb+1; cc<l; cc++) {
                            if (p[i]*p[j]*p[k]*p[aa]*p[bb]*p[cc]*n > mx) break;
                            f.push_back(p[i]*p[j]*p[k]*p[aa]*p[bb]*p[cc]);
                        }
                    }
                }
            }
        }
    }

    for (int i=0; i<n; i++) {
        int aa=1, bb=1e5;
        cin >> aa >> bb;
        seg.push_back({aa, bb});
    }
    ll ret = solve(1);
    for (int i : t) {
        ret -= solve(i);
        ret %= mod;
    }
    for (int i : f) {
        ret += solve(i);
        ret %= mod;
    }
    cout << (ret%mod+mod)%mod << endl;

    return 0;
}

// li-1 , ri의 몫이 다를때
// 9552개의 소수