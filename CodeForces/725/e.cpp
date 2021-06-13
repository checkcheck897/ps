#include <bits/stdc++.h>

# pragma GCC optimize ("O3")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
# define ll long long
using namespace std;
ll x, y, a, b;
ll solve(ll z){
    if(z<0) return 0;
    if (x-a*z<0 || y-b*z<0) return 0;
    return min((x-a*z)/b, (y-b*z)/a)+z;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        cin >> x >> y >> a >> b;
        ll x1 = a==b?min(x/a,b/y):(b*y-a*x)/(b*b-a*a);
        ll x2 = x1+1;
        ll x3 = x/a;
        ll x4 = y/b;
        ll x5= x/b;
        ll x6= y/a;
        ll a1 = max(solve(x1), solve(x2));
        ll a2 = max(solve(x3), solve(x4));
        for (int i=-1000; i<1000; i++) {
            a1 = max (a1, solve(x1+i));
            a1 = max (a1, solve(x3+i));
            a1 = max (a1, solve(x4+i));
            a1 = max (a1, solve(x5+i));
            a1 = max (a1, solve(x6+i));
        }
        for (int i=0; i<1000; i++) {
            a1 = max(a1, solve(i));
        }
        for (int i=0; i<1000; i++) {
            a1 = max(a1, solve(min(x/a, y/b)-i));
        }
        cout << max(a1, a2) << '\n';
    }

    return 0;
}