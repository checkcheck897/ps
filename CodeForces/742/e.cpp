#include <bits/stdc++.h>

# pragma GCC optimize ("O3")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#define x first
#define y second
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>

using namespace std;

int k, nx, ny;
int fl[128][128];

void solve(int lox, int loy, int hix, int hiy) {
    bool isleft, islower;
    if ( (lox + hix)/2 > nx ) isleft = 1;
    if ( (loy + hiy)/2 > ny ) islower = 1;

    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> k >> nx >> ny;
    nx--;
    ny--;
    k = (1<<k);
    cout << k;
    solve(0, 0, k, k);

    return 0;
}