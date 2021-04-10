#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll a[200000], b[200000], psum[200005], c[200005], d[200005];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int z=0; z<t; z++){
        long long ans = 0;
        int n;
        cin>>n;
        for(int i=0; i<n; i++) cin>>a[i];
        for(int i=0; i<n; i++) cin>>b[i];
        sort(a, a+n);
        sort(b, b+n);
        psum[0] = 0;
        ll m = 0;
        for(int i=0; i<n; i++){
            psum[i+1] = psum[i] + max(a[i]-b[i], b[i]-a[i]);
            m = max(m, max(a[i]-b[i], b[i]-a[i]));
        }
        ans = psum[n] - m;
        pair<ll, ll> ma = {0,0};
        for(int i=0; i<n-1; i++){
            c[i+1] = c[i] + max(a[i+1]-b[i], b[i]-a[i+1]) - max(a[i]-b[i], b[i]-a[i]);
            ans = min(ans, psum[n]+c[i+1]-ma.first-max(a[i+1]-b[i+1], b[i+1]-a[i+1]));
            if(ma.first < c[i+1]){
                ma.first = c[i+1];
                ma.second = i+1;
            }
        }
        ma = {0,0};
        for(int i=0; i<n-1; i++){
            d[i+1] = d[i] + max(a[i]-b[i+1], b[i+1]-a[i]) - max(a[i]-b[i], b[i]-a[i]);
            ans = min(ans, psum[n]+d[i+1]-ma.first-max(a[i+1]-b[i+1], b[i+1]-a[i+1]));
            if(ma.first < d[i+1]){
                ma.first = d[i+1];
                ma.second = i+1;
            }
        }
        cout<<"Case #"<<z+1<<endl;
        cout<<ans<<endl;
    }
    return 0;
}