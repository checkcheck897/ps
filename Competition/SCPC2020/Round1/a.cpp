#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int j=0; j<t; j++){
        int n, k;
        cin>>n>>k;
        int a[n], b[n];
        for(int i=0; i<n; i++) cin>>a[i];
        for(int i=0; i<n; i++) cin>>b[i];
        cout<<"Case #"<<j+1<<"\n";
        sort(a, a+n);
        sort(b, b+n);
        int m = 0;
        for(int i=0; i<k; i++){
            m = max(m, a[i]+b[k-1-i]);
        }
        cout<<m;
        cout<<"\n";
    }
    return 0;
}