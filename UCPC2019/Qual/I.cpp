#include<bits/stdc++.h>

using namespace std;
int v[6][3] = {{2,0,0}, {1,0,1}, {-1,0,1}, {-2,0,0}, {-1,0,-1}, {1, 0, -1}};
int pos[10000][3] = {{0,0,0}, {0,0,2}};
int n;
long long ans = 0;
bool meet(int p[], int nx){
    bool ret;
    for(int i=0; i<nx; i++){
        ret = true;
        for(int j=0; j<3; j++){
            if(p[j]!=pos[i][j]) ret = false;
        }
        if(ret == true) return true;
    }
    return false;
}
void dfs(int nx, int d){
    if(n==nx){
        for(int j=0; j<3; j++) pos[nx][j] = pos[nx-1][j] + v[(d+1)%6][j];
        if(meet(pos[nx], nx)) ans++;
        for(int j=0; j<3; j++) pos[nx][j] = pos[nx-1][j] + v[(d+5)%6][j];
        if(meet(pos[nx], nx)) ans++;
    }
    else{
        for(int j=0; j<3; j++) pos[nx][j] = pos[nx-1][j] + v[(d+1)%6][j];
        if(!meet(pos[nx], nx)){ dfs(nx+1, (d+1)%6);}
        for(int j=0; j<3; j++) pos[nx][j] = pos[nx-1][j] + v[(d+5)%6][j];
        if(!meet(pos[nx], nx)){ dfs(nx+1, (d+5)%6);}
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin>>n;
    n += 1;
    dfs(1, 0);
    cout<<ans/2;
	return 0;
}