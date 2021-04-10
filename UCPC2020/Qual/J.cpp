#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<int> k[m];
    bool d[n], d2[n], d3[n];
    for(int i=0; i<m; i++){
        int num;
        cin>>num;
        for(int j=0; j<num; j++){
            int p;
            cin>>p;
            k[i].push_back(p-1);
        }
    }
    for(int i=0; i<n; i++) cin>>d[i];
    for(int i=0; i<n; i++) d2[i] = d[i];
    for(int i=m-1; i>=0; i--){
        bool check = true;
        for(auto j: k[i]) check &= d[j];
        if(check==true) continue;
        else{
            for(auto j: k[i]) d[j] = false;
        }
    }
    for(int i=0; i<n; i++) d3[i] = d[i];
    for(int i=0; i<m; i++){
        for(auto j : k[i]){
            if(d3[j]==true){
                for(auto t : k[i]) d3[t] = true;
                break;
            }
        }
    }
    for(int i=0; i<n; i++){
        if(d2[i]!=d3[i]){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES\n";
    for(int i=0; i<n; i++) cout<<d[i]<<" ";
    return 0;
}