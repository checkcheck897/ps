#include<bits/stdc++.h>

using namespace std;
bool visited[1000];
vector<int> adj[1000];
bool odd[1000];
int k;
void dfs(int cur, bool c){
    if(visited[cur]) return;
    odd[cur] = c;
    visited[cur] = true;
    for(auto i : adj[cur]){
        if(visited[i]) continue;
        dfs(i, !c);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int test, n, a[1000], b[1000], t[1440];
    bool imp;
    cin>>test;
    for(k=0; k<test; k++){
        imp = false;
        cin>>n;
        for(int i=0; i<1000; i++){
            visited[i] = 0;
            odd[i] = 0;
        }
        for(int i=0; i<1440; i++){
            t[i] = 0;
        }
        for(int i=0; i<n; i++){
            adj[i].clear();
            cin>>a[i]>>b[i];
            for(int j=a[i]; j<b[i]; j++) t[j]++;
        }
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(!((a[j]>=b[i])||(b[j]<=a[i]))){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for(int i=0; i<n; i++){
            if(visited[i]) continue;
            dfs(i, true);
        }
        for(int i=0; i<1440; i++){
            if(t[i]>2) imp = true;
        }
        cout<<"Case #"<<k+1<<": ";

        if(imp){cout<<"IMPOSSIBLE\n";}
        else{
            for(int i=0; i<n; i++){
                if(odd[i]==false) cout<<"J";
                else cout<<"C";
            }
            cout<<"\n";
        }
    }
    return 0;
}