#include <bits/stdc++.h>

# pragma GCC optimize ("O3")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#define x first
#define y second
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>

using namespace std;
const ll maxn = 2e5+5;
ll n, a[maxn], b[maxn], ka[maxn], kb[maxn];
vector<pll> adj[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> a[i] >> ka[i] >> b[i] >> kb[i];
        adj[i].push_back({a[i], ka[i]});
        adj[i].push_back({b[i], kb[i]});
    }

    
    
    return 0;
}