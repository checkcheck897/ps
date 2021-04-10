#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n;
    string s[50];
    cin>>t;
    for(int k=0; k<t; k++){
		cin>>n;
        string ans;
        cin>>s[0];
        ans = s[0];
        bool check = true;
        for(int i=1; i<n; i++){
            cin>>s[i];
            if(s[i].length() > ans.length()) ans = s[i];
        }
        for(int i=0; i<n; i++){
            if(ans.compare(ans.length()-s[i].length()+1, s[i].length()-1,s[i],1, s[i].length()-1)!=0) check = false;
        }
        if(check){
            cout<<"Case #"<<k+1<<": ";
            for(int i=1; i<ans.length(); i++) cout<<ans[i];
            cout<<"\n";
        }
        else cout<<"Case #"<<k+1<<": "<<"*"<<"\n";
    }
    return 0;
}