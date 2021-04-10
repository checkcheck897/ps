#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long t, len;
    int a[101];
    string s;
    cin>>t;
    for(int i=0; i<t; i++){
		cin>>s;
		len = s.length();
        a[0] = s[0]-'0';
        for(int j=1; j<len; j++){
            a[j] = s[j]-s[j-1];
        }
        a[len] = -s[len-1]+'0';
        cout<<"Case #"<<i+1<<": ";
        for(int j=0; j<len; j++){
            for(int k=0; k<a[j]; k++) cout<<"(";
            cout<<s[j];
            for(int k=0; k<(-1)*a[j+1]; k++) cout<<")";
        }
        cout<<"\n";
	}
    return 0;
}