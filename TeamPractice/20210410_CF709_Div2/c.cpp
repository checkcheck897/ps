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
        pll k[n];
        for (int i=0; i<n; i++) k[i] = {0,i};
        vector<int> v[n];
        vector<int> tt[n];
        for (int i=0; i<m; i++) {
            int a;
            cin >> a;
            for (int j=0; j<a; j++) {
                int b;
                cin >> b;
                k[b-1].first++;
                v[b-1].push_back(i);
                if(a==1) tt[b-1].push_back(i);
            } 
        }
        sort(k, k+n);
        int visit[m];
        for (int i=0; i<m; i++) visit[i] = 0;
        int numm[n];
        int mm = 0;
        for (int i=0; i<n; i++) numm[i] = 0;
        for (int kk=0; kk<n; kk++){
            int jj = k[kk].second;
            for(auto vx : tt[jj]) {
                visit[vx] = jj+1;
                numm[kk]++;
            }
            mm = max(numm[kk], mm);
        }
        
        if (mm >(m+1)/2) {
            cout << "NO\n";
            continue;
        }
        for (int i=0; i<n; i++) {
            int num = 0;
            if(i==n-1) num += numm[i];
            int j = k[i].second;
            for (auto vx : v[j]) {
                if (visit[vx]==0 && num<(m+1)/2) {
                    visit[vx]=j+1;
                    num++;
                }
            }
        }
        bool check = 0;
        for (int i=0; i<m; i++) {
            if(!visit[i]) continue;
            if (i==m-1) {
                check = 1;
            }
        }
        if(check){
            cout <<"YES\n";
            for (int i=0; i<m; i++) cout << visit[i] << " ";
            cout << "\n";
        }
        else cout << "NO\n";
 
    }
 
    return 0;
}