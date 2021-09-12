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
        ll n;
        cin >> n;
        string s;
        cin >> s;
        int num = 0;
        for (int i=0; i<n; i++) {
            if (s[i]=='2') num++;
        }
        if (num==1 || num==2) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        int a=0, b=0;
        for (int i=0; i<n; i++) {
            if (s[i]=='2') a++;
            for (int j=0; j<n; j++) {
                
                if (s[j]=='2') b++;
                if (i==j) cout << 'X';
                else if (s[i] == '1' && s[j]=='1') cout << '=';
                else if (s[i] == '1' && s[j]=='2') cout << '+';
                else if (s[i] == '2' && s[j]=='1') cout << '-';
                else if (s[i] == '2' && s[j]=='2') {
                    cout << ((a-b+100+(i>j))%2==1 ? '+':'-');
                }
                
            }
            b=0;
            cout << '\n';
        }
    }

    return 0;
}