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
    int test_case = t;
    while(t--) {
        int n;
        cin >> n;
        int l[n];
        for (int i=0; i<n; i++) {
            cin >> l[i];
        }

        int ans = 0;
        for (int i=0; i<n-1; i++) {
            for (int j=i; j<n; j++) {
                if (l[j] == i+1) {
                    ans += (j-i+1);
                    for (int k=0; k<(j-i+1)/2; k++) {
                        swap(l[i+k], l[j-k]);
                    }
                    break;
                }
            }
        }

        cout << "Case #" << test_case - t << ": " << ans << '\n';
    }

    return 0;
}