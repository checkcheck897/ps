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
        int n;
        cin >> n;
        int ans = 100;
        if (n%4==0) ans/=4;
        else if (n%2==0) ans/=2;
        if (n%25==0) ans/=25;
        else if (n%5==0) ans/=5;
        cout << ans<< '\n';
    }

    return 0;
}