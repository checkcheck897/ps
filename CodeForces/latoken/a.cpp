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
        ll n, m;
        cin >> n >> m;
        string s[n];
        bool check = 0;
        bool check2=0;
        for (int i=0; i<n; i++) cin >> s[i];
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if ((i+j)%2) {
                    if (s[i][j]=='W') {
                        
                        check2=1;
                        break;
                    }
                } else if (s[i][j] =='R'){
                     
                     check2=1;
                     break;
                }
                if (i==n-1 && j==m-1) {
                    check = 1;
                    cout << "YES\n";
                    for (int i=0; i<n; i++) {
                        for (int j=0; j<m; j++) {
                            cout << ((i+j)%2==1?"R":"W");
                        }
                        cout << '\n';
                    }
                }
            }
            if(check2) break;
        }
        check2=0;
        if (check) continue;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if ((i+j)%2) {
                    if (s[i][j]=='R') {
                        check2=1;
                        break;
                        
                    }
                } else if (s[i][j] =='W'){
                     check2=1;
                     break;
                    
                }
                if (i==n-1 && j==m-1) {
                    check = 1;
                    cout << "YES\n";
                    for (int i=0; i<n; i++) {
                        for (int j=0; j<m; j++) {
                            cout << ((i+j)%2==1?"W":"R");
                        }
                        cout << '\n';
                    }
                }
            }
            if(check2) break;
        }
        if (!check) cout <<"NO\n";
    }

    return 0;
}