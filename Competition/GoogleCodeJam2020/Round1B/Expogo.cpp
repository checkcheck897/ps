#include<bits/stdc++.h>

using namespace std;
string dfs(long long a, long long b, string s, long long temp){
    if(a==0 && b==0) return s;
    string n="IMPOSSIBLE";
    if(temp>30) return n;
    if((max(a,-a)&(1LL<<temp))==(1LL<<temp) && (max(b,-b)&(1LL<<temp))!=(1LL<<temp)){
        if(-a==(1LL<<temp)){
            s.push_back('W');
        n=dfs(a+(1LL<<temp), b, s, temp+1);
        if(n!="IMPOSSIBLE") return n;
        s.pop_back();
        }
        s.push_back('E');
        n=dfs(a-(1LL<<temp), b, s, temp+1);
        if(n!="IMPOSSIBLE") return n;
        s.pop_back();
        s.push_back('W');
        n=dfs(a+(1LL<<temp), b, s, temp+1);
        if(n!="IMPOSSIBLE") return n;
        s.pop_back();
    }
    else if((max(a,-a)&(1LL<<temp))!=(1LL<<temp) && (max(b,-b)&(1LL<<temp))==(1LL<<temp)){
        if(b==(1LL<<temp)){
            s.push_back('N');
            n=dfs(a, b-(1LL<<temp), s, temp+1);
            if(n!="IMPOSSIBLE") return n;
            s.pop_back();
        }
        s.push_back('S');
        n=dfs(a, b+(1LL<<temp), s, temp+1);
        if(n!="IMPOSSIBLE") return n;
        s.pop_back();
        s.push_back('N');
        n=dfs(a, b-(1LL<<temp), s, temp+1);
        if(n!="IMPOSSIBLE") return n;
        s.pop_back();
    }
    s = "IMPOSSIBLE";
    return s;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long test, a, b;
    cin>>test;
    for(int x=0; x<test; x++){
        cin>>a>>b;
        string s;
        cout<<"Case #"<<x+1<<": "<<dfs(a, b, s, 0)<<"\n";
    }
    return 0;
}