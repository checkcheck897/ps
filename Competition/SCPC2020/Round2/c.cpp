#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define pll pair<ll, ll>
using namespace __gnu_pbds;

ll dp[200001], a[200000];
tree<pll, null_type,less<pll>, rb_tree_tag,tree_order_statistics_node_update> s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    setbuf(stdout, NULL);
    int t;
    cin>>t;
    for(int z=0; z<t; z++){
        s.clear();
        int n, k, q;
        cin>>n>>k>>q;
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        if(n>20000) return 0;
        dp[0] = 0;
        for(int i=0; i<k; i++) dp[0] += a[i];
        s.insert({dp[0], 0});
        for(int i=1; i<=n-k; i++){
            dp[i] = dp[i-1]-a[i-1]+a[i-1+k];
            s.insert({dp[i], i});
        }
        cout<<"Case #"<<z+1<<endl;
        cout<< (*s.find_by_order((n-k+1)/2)).first<<" ";
        for(int i=0; i<q; i++){
            int id, diff;
            cin>>id>>diff;
            id--;
            int temp = diff;
            temp = diff - a[id];
            a[id] = diff;
            diff = temp;
            for(int i=max(0, id-k+1); i<min(id+1, n-k+1); i++){
                s.erase({dp[i], i});
                dp[i] += diff;
                s.insert({dp[i], i});
            }
            cout<<(*s.find_by_order((n-k+1)/2)).first<<" ";
        }
        cout<<endl;
    }
    return 0;
}