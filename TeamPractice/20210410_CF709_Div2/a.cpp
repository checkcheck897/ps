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
        ll a[n];
        for (int i=0; i<n; i++) cin >> a[i];
        for (int i=0; i<n-1; i++) {
            if (a[i]!=a[i+1]) break;
            if(i==n-2) {
                n=1;
            }
        }
        if (n==1) {
            cout << "0\n";
            continue;
        }
        ll s=a[0],c=-1,d=-1;
        bool check = 0;
        for (int i=0; i<n-1; i++) {
            if (a[i]==a[i+1]) {
                check = 1;
                break;
            }
            else if (a[i] < a[i+1]) {
                if(c==-1) c= a[i+1]-a[i];
                else if(c!=a[i+1]-a[i]) {
                    check = 1;
                    break;
                }
            } else {
                if(d==-1) d= a[i]-a[i+1];
                else if(d!=a[i]-a[i+1]) {
                    check = 1;
                    break;
                }
            }
        }
        if (check) {
            cout << "-1\n";
            continue;
        }
        if(d==-1) cout<<"0";
        else if(c==-1) cout <<"0";
        else if((c+d) <= s) cout << "-1";
        else if((c+d)==0) cout << "0";
        else {
            bool check2=0;
            ll xx=a[0]-c;
            for (int i=0; i<n; i++) {
                xx += c;
                xx %= (c+d);
                if (xx!=a[i]) check2 = 1;
            }
            if (check2) cout << "-1";
            else cout << c+d << " " << c;
        }
 
        cout << '\n';
    }
 
    return 0;
}
