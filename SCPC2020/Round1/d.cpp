#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int z=0; z<t; z++){
        int n, k, m;
        cin>>n>>k>>m;
        string s;
        cin>>s;
        if(n>1000) return 0;
        int max_=0;
        for(int i=0; i<=n; i++){
            char temp;
            if(i!=n){
                temp = s[i];
                s[i] = '1';
            }
            int a[n-k+1];
            for(int i=0; i<=n-k; i++){
                string x = s.substr(i,k);
                a[i] =atoi(x.c_str());
            }
            sort(a, a+n-k+1);
            int ma = 0;
            int j = 0;
            for(int i=0; i<n-k; i++){
                while(j<n-k && a[j+1]-a[i]<=m) j++;
                ma = max(ma, j-i+1);
            }
            max_ = max(max_, ma);
            if(i!=n){
                s[i] = temp;
            }
        }
        cout<<"Case #"<<z+1<<"\n";
        cout<<max_;
        cout<<"\n";
    }
    return 0;
}