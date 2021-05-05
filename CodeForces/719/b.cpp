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
    vector<int> v;
    int p[15] = {1};
    for (int i=1; i<15; i++) p[i] = p[i-1]*10;
    for (int i=1; i<10; i++) {
        int temp = 0;
        for (int j=0; j<9; j++) {
            temp += p[j]*i;
            v.push_back(temp);
        }
    }
    sort(v.begin(), v.end());
    while(t--) {
        ll n;
        cin >> n;
        cout << (lower_bound(v.begin(), v.end(), n+1) - v.begin()) << '\n';
    }

    return 0;
}