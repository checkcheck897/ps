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
    char co[5] = {'A', 'E', 'I', 'O', 'U'};
    int tc = t;
    while(t--) {
        string s;
        cin >> s;
        int n = s.length();
        int numCo = 0;
        int num[5];
        int numtot[26];
        int numExcept[26];
        for (int i=0; i<5; i++) num[i] = 0;
        for (int i=0; i<26; i++){
            numtot[i] = 0;
            numExcept[i] = 0;
        }
        for (int i=0; i<n; i++) {
            numtot[s[i]-'A']++;
            for (int j=0; j<5; j++) {
                if (s[i]==co[j]) {
                    numCo++;
                    num[j]++;
                    break;
                }
                if (j==4) numExcept[s[i]-'A']++;
            }
        }
        sort(num , num+5);
        sort(numtot, numtot+26);
        sort(numExcept, numExcept+26);
        int ans = 1e8;
        if (numtot[25]==n) {
            cout << "Case #"<< tc-t <<": 0\n";
            continue;
        }
        if (numCo==0) ans = n;
        if (n==numCo) ans = n;
        ans = min(ans, n-numCo + 2*(numCo-num[4]));
        ans = min(ans, numCo + 2*(n-numCo-numExcept[25]));
        cout << "Case #"<< tc-t <<": " << ans << "\n";
    }

    return 0;
}