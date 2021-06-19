#include <bits/stdc++.h>

# pragma GCC optimize ("O3")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#define x first
#define y second
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>

using namespace std;

ll getvalue(ll a) {
    ll ret = 0;
    while (a!=0) {
        ret += a%10;
        a /= 10;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll n;
    cin >> n;

    while (getvalue(n)%4!=0) n++;
    cout << n;
    cout << '\n'; 

    return 0;
}