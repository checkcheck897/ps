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
    
    int n;

    cin >> n;

    int a[n], b[n];
    vector<int> v, w;
    for (int i=0; i<n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
        if (i%2==0) v.push_back(a[i]);
    }

    sort (b, b+n);
    for (int i=0; i<n; i+=2)
    {
        w.push_back(b[i]);
    }

    sort(v.begin(), v.end());

    for (int i=0; i<v.size(); i++)
    {
        if (v[i]!=w[i])
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}