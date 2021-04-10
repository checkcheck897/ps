#include<bits/stdc++.h>

using namespace std;
int leaf =0;
vector<int> adj[200000];
bool visited[200000];
int dfs(int here){
	int ans = 0;
	visited[here] = true;
	for(int i=0; i<adj[here].size(); ++i){
		int there = adj[here][i];
		if(!visited[there]){
			ans += dfs(there);
		}
		if(adj[here].size()==1) ans +=1;
	}
	return ans;
}

int main() {
    ios::sync_with_stdio(false);
    int n;
 	cin >>n;
 	int a,b;
 	for(int i=0; i<n-1; i++){
 		cin>>a>>b;
 		adj[a].push_back(b);
 		adj[b].push_back(a);
 	}
 	cout<< (1+dfs(0))/2;
	return 0;
}