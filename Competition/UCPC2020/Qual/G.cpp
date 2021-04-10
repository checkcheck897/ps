#include<bits/stdc++.h>

using namespace std;

int n, t[200001], v[200001];
vector<int> adj[200001];
vector<int> adjt[200001];
bool visit[200001] = {0};
queue<int> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        while(a!=0){
            adj[i+1].push_back(a);
            if(a!=i+1) adj[a].push_back(i+1);
            cin>>a;
        }
    }
    int m;
    cin>>m;
    for(int i=1; i<=n; i++){
        t[i] = -1;
        v[i] = 0;
    }
    for(int i=0; i<m; i++){
        int b;
        cin>>b;
        q.push(b);
        t[b] = 0;
    }
    while(!q.empty()){
        int here = q.front();
        visit[here] = true;
        q.pop();
        if(t[here]==-1){
            sort(adjt[here].begin(), adjt[here].end());
            t[here] = adjt[here][(adj[here].size()-1)/2];
        }
        for(auto next : adj[here]){
            adjt[next].push_back(t[here]+1);
            v[next]++;
            if(2*v[next]==adj[next].size()-adj[next].size()%2 && t[next]==-1
                && !visit[next]) q.push(next);
        }
    }
    for(int i=1; i<=n; i++){
        cout<<t[i]<<" ";
    }
    return 0;
}
