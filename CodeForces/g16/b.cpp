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
        string s;
        int n0=0, n1=0;
        cin >> s;
        for (char c : s) {
            if (c=='1') n1++;
            else n0++;
        }
        if (n1==0) cout << 1;
        else if (n0==0) cout << 0;
        else {
            int cnt = 0;
            bool check1 = 0;
            bool check2 = 0;
            int on1 = n1;
            for (int i=0; i<n0+on1; i++) {
                if (s[i]=='1' && check1 == 0) n1--;
                if (s[i]=='0') check1 = 1;
                if (s[n0+on1-i]=='1' && check2 == 0) n1--;
                if (s[n0+on1-i]=='0') check2 = 1;
            }
            if (n1==0) cout << 1;
            else cout << 2;
        }
        cout << '\n';
    }

    return 0;
}