#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[300001], a[300000];
set<ll> s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int z=0; z<t; z++){
        s.clear();
        int n; ll m;
        cin>>n>>m;
        for(int i=0; i<n; i++){
            cin>>a[i];
            dp[i+1] = dp[i]+a[i];
        }
        ll ans = 0;
        for(int i=0; i<n; i++){
            s.insert(dp[i]);
            set<ll>::iterator iter = s.upper_bound(dp[i+1]-m-1);
            if(iter!=s.end()){
                ll temp = *iter;
                ans = max(ans, dp[i+1]-temp);
                if(dp[i+1]-temp==m) break;
            }
        }
        cout<<"Case #"<<z+1<<endl;
        cout<<ans<<endl;
    }
    return 0;
}