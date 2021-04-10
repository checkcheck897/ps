#include<bits/stdc++.h>

using namespace std;
unordered_map<string, vector<string>> m;
unordered_map<string, bool> v;
vector<string> ans;
void dfs(string here){
    v[here] = true;
    for(auto i : m[here]){
        if(!v[i]){
            ans.push_back(i);
            dfs(i);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    string a, b, is;
    for(int i=0; i<n; i++){
        cin>>a>>is>>b;  
        m[a].push_back(b);
        v[a] = false;
        v[b] = false;
    }
    dfs("Baba");
    sort(ans.begin(), ans.end());
    for(auto i : ans) cout<<i<<"\n";
    return 0;
}