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
        
        int n, q;
        cin >> n >> q;
        string s[n+1];
        int score[n+1];
        for (int i=0; i<n; i++) {
            cin >> s[i] >> score[i];
        }

        if (n==1) cout << "Case #" << test_case - t << ": " << s[0] << " " << score[0] << "/1" << '\n';
        else {
            int dif =0, com = 0;
            for (int i=0; i<q; i++) {
                if (s[0][i] != s[1][i]) {
                    dif++;
                    if (score[0] >= score[1]) s[2][i] = s[0][i];
                    else s[2][i] = s[1][i];
                }
                else com++;
            }
            score[2] = (dif + abs(score[1]-score[0]))/2;
            int comscore = score[0]>score[1] ? score[0]-score[2] : score[1]-score[2];
            if (comscore >= com - comscore) {
                cout << "Case #" << test_case - t << ": ";
                for (int i=0; i<q; i++) {
                    if (s[0][i] != s[1][i]) cout << s[2][i];
                    else cout << s[0][i];
                }
                cout << " " << comscore + score[2] << "/1" << '\n';
            } else {
                cout << "Case #" << test_case - t << ": ";
                for (int i=0; i<q; i++) {
                    if (s[0][i] != s[1][i]) cout << s[2][i];
                    else if(s[0][i] == 'T') cout << 'F';
                    else cout << 'T';
                }
                cout << " " << com - comscore + score[2] << "/1" << '\n';
            }
        }
    }
    return 0;
}