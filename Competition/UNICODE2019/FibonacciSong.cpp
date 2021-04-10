#include<bits/stdc++.h>
# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,m,q;
    cin>>q>>m;
    int fibo[m*(m+1)+7] = {1,1};
    for(int i=2; i<=m*(m+1)+6; i++){
        fibo[i] = (fibo[i-1]+fibo[i-2])%m;
    }
    int cycle;
    for(int j=2; j<=m*(m+1)+5; j++){
        if(fibo[j]==1 && fibo[j+1]==1){
            cycle = j;
            break;
        }
        if(j==m*(m+1)+5) return 0;
    }
    int f[cycle*4];
    long long j = 0;
    for(int i=0; i<cycle; i++){
        if(fibo[i]/100!=0){
            f[j] = fibo[i]/100;
            j++;
        }
        if(fibo[i]/10!=0){
            fibo[i] %=100;
            f[j] = fibo[i]/10;
            fibo[i] %= 10;
            j++;
        }
        f[j] = fibo[i];
        j++;
    }

    for(int i=0; i<q; i++){
        cin>>n;
        cout<<f[((n-1)%j+j)%j]<<"\n";
    }
    return 0;
}