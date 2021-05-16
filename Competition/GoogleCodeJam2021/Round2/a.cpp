#include <bits/stdc++.h>
# pragma GCC optimize ("O3")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#define x first
#define y second
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    int test_case = t;

    while(t--) {
        int n;
        cin >> n;

        for (int i=0; i<n-1; i++) {
            cout << "M " << i+1 << " " << n << endl;
            cout<<flush;
            int m;
            cin >> m;
            if (m!=i+1) {
                cout << "S " << m << " " << i+1 << endl;
                cout<<flush;
                int a;
                cin >> a; 
            }
        }
        
        cout << "D" << endl;
        cout<<flush;
    }

    return 0;
} 