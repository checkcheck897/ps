#include <bits/stdc++.h>

# pragma GCC optimize ("O3")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

#define x first
#define y second
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>

using namespace std;

bool v[5005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s;

    cin >> s;
    int n = s.size();
    int num0 = 0;
    int num1 =0;
    for (int i=0; i<n; i++)
    {
        if (s[i] == '0') num0++;
    }

    num1 = n - num0;
    int cnt1 =0;

    for (int i=0; i<n; i++)
    {
        if (s[i] == '1' && num1 != 2*cnt1)
        {
            v[i] = 1;
            cnt1++;
        }
    }
    int cnt0 = 0;
    for (int i=n-1; i>=0; i--)
    {
        if (s[i] == '0' && num0 != 2*cnt0)
        {
            v[i] = 1;
            cnt0++;
        }
    }

    for (int i=0; i<n; i++)
    {
        if (!v[i]) cout<<s[i];
    }
    return 0;
}