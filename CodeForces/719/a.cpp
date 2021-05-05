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
        bool check = 0;
        for (int i=0; i<n; i++) {
            bool temp = 0;
            for (int j=i+1; j<n; j++) {
                if (s[i]!=s[j]) temp=1;
                if (temp && s[i]==s[j]) check = 1;
            }
        }
        if (check) cout << "NO";
        else cout << "YES";
        cout << '\n';
    }

    return 0;
}