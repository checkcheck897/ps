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
        ll a[2];
        cin >> a[0] >> a[1];
        string s;
        cin >> s;
        int n = s.length();
        if (a[0]%2) {
            if (!n%2 || s[n/2] == '1') {
                cout << "-1\n";
                continue;
            }
            s[n/2] = '0';
            a[0]--;
        } 
        if (a[1]%2) {
            if (!n%2 || s[n/2] == '0') {
                cout << "-1\n";
                continue;
            }
            s[n/2] = '1';
            a[1]--;
        }

        bool check = 0;
        for (int i=0; i<n/2; i++) {
            if (s[i] + s[n-1-i] == '1' + '0') {
                check = 1;
                break;
            }

            if (s[i] == '?' && s[n-1-i] != '?') {
                a[s[n-1-i]-'0'] -= 2;
                s[i] = s[n-1-i];
            } else if (s[i] != '?' && s[n-1-i] == '?') {
                a[s[i]-'0'] -= 2;
                s[n-1-i] = s[i];
            } else if (s[i] == s[n-1-i] && s[i] != '?') {
                a[s[i]-'0'] -= 2;
            }
        }
        if (a[0]<0 || a[1]<0) check = 1;
        if (check) cout << "-1";
        else {
            for (int i=0; i<n/2; i++) {
                if (s[i] == '?') {
                    if (a[0] >0) {
                        s[i] = '0';
                        s[n-1-i] = '0';
                        a[0] -= 2;
                    } else if (a[1] >0) {
                        s[i] = '1';
                        s[n-1-i] = '1';
                        a[1] -= 2;
                    }
                }
            }
            cout << s;
        }
        
        cout << '\n';
    }

    return 0;
}