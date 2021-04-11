#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int s, t;
    vector<pair<double, int>> v;
    for(int i=0; i<n; i++){
        cin>>t>>s;
        v.push_back({(double)t/s, i+1});
    }
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++) cout<<v[i].second<<" ";
    return 0;
}