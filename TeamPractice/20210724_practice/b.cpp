#include <bits/stdc++.h>

# pragma GCC optimize ("O3")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#define x first
#define y second
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll n;
    cin >> n;

    n = n%100;
    if (n==0 || n ==10 || n==30 || n==60) cout<< "0";
    else if (n <= 10) cout << "1";
    else if (n <= 30) {
        if (n <=15 || n>=25) cout << "1";
        else cout << "2";
    }
    else if (n <= 60) {
        if (n<=35 || n>=55) cout << "1";
        else if (n<=40 || n>=50) cout << "2";
        else cout << "3";
    } 
    else {
        if (n<=65 || n>=95) cout << "1";
        else if (n<=70 || n>=90) cout << "2";
        else if (n<=75 || n>=85) cout << "3";
        else cout << "4";
    }
    return 0;
}