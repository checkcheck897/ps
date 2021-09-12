#include <bits/stdc++.h>

# pragma GCC optimize ("O3")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#define x first
#define y second
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>

using namespace std;

char rev(char a) {
    if (a == 'B') return 'R';
    else return 'B';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        string ans = "";
        for (int i=0; i<n; i++) ans += '?';
        for (int i=0; i<n; i++) {
            int l = i-1;
            int r = i+1;
            if (s[i] == '?') continue;
            ans[i] = s[i];
            while (l>=0 && s[l]=='?') {
                ans[l] = ((i-l)%2==1) ? rev(s[i]) : s[i];
                l--;
            }
            while (r<n && s[r]=='?') {
                ans[r] = ((r-i)%2==1) ? rev(s[i]) : s[i];
                r++;
            }
        }

        for (int i=0; i<n; i++) {
            if (ans[i] == '?') ans[i] = (i%2==1) ? 'B' : 'R';
        }

        cout << ans;
        cout << '\n';
    }

    return 0;
}