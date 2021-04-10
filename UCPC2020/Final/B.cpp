#include<bits/stdc++.h>
# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,m,k;
    cin>>n>>m>>k;
    string s[26];
    for(long long i=0; i<k; i++) cin>>s[i];
    string a;
    cin>>a;
    long long l = m-1;
    long long r = m-1;
    long long ans= 0;
    for(long long i=n-1; i>=0; i--){
        while(l>=1 && s[a[i]-'A'][l-1]=='R') l--;
        if(i!=n-1) while(r>=1 && s[a[i]-'A'][r]=='R') r--;
        if(r==0 && s[a[i]-'A'][r]=='R' && m!=1) break;
        ans += max((long long)0,r-l+1);
    }
    cout<<ans;
    return 0;
}