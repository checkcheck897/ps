#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int test_case;
    cin>>test_case;
    for(int z=1; z<=test_case; z++){
        int x,y;
        string m;
        cin>>x>>y;
        cin>>m;
        int len = m.length();
        int min_ = 1e9;
        for(int i=0; i<len; i++){
            if(m[i]=='N') y++;
            else if(m[i]=='S') y--;
            else if(m[i]=='E') x++;
            else if(m[i]=='W') x--;
            if(i+1>=max(x,-x)+max(y,-y)){
                min_ = min(min_, i+1);
            }
        }
        cout<<"CASE #"<<z<<": ";
        if(min_ == 1e9) cout<<"IMPOSSIBLE\n";
        else cout<<min_<<"\n";

    }
    return 0;
}
