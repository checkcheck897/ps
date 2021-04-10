#include <bits/stdc++.h>

# pragma GCC optimize ("O3")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    int test_case = t;
    while(t--) {
        int x, y;
        cin >> x >> y;
        string s;
        cin >> s;
        int ans = 0;

        if (s.length() == 1) {
            cout << "Case #" << test_case - t << ": " << 0 << '\n';
            continue;
        }

        for (int i=0; i<s.length()-1; i++) {
            if (s[i] == 'C' && s[i+1] == 'J') ans += x;
            if (s[i] == 'J' && s[i+1] == 'C') ans += y;
            if (s[i] == '?' && s[i+1] == '?') {
                s.erase(s.begin() + i);
                i--;
            }
        }

        for (int i=1; i<s.length()-1; i++) {
            if (s[i] != '?') continue;
            if (s[i-1] == s[i+1]) continue;
            if (s[i-1] == 'C' && s[i+1] == 'J') ans += x;
            if (s[i-1] == 'J' && s[i+1] == 'C') ans += y;
        }

        cout << "Case #" << test_case - t << ": " << ans << '\n';
    }

    return 0;
}