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

    int n, m, k;

    cin >> k >> n >> m;

    int cu[k+1];
    for (int i=1; i<=k; i++) cu[i+1] = i+1;
    int a[n-1], b[n-1], c[n-1];
    for (int i=0; i<n-1; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    int s[m], mm[m], t[m], aa[m], bb[m];
    int *ans[m];
    vector <pii> v;
    for (int i=0; i<m; i++)
    {
        cin >> s[i]>> mm[i] >> t[i] >> a[i] >> b[i];
        v.push_back({mm[i], i});
    }
    sort(v.begin(), v.end());

    int j = 0;
    while (v[j].x==0 && j<m)
    {
        ans[v[j].y] = &cu[s[v[j].y]];
        if(s[v[j].y] == a[j]) ans[v[j].y] = &cu[b[j]];
        else if (s[v[j].y] == b[j] && t[j] == 1) ans[v[j].y] = &cu[a[j]];
        j++;
    }
    for (int i=0; i<n-1; i++){
        swap(cu[b[i]], cu[c[i]]);
        while (v[j].y == i+1){
            ans[v[j].y] = &cu[s[v[j].y]];
            if(s[v[j].y] == a[j]) ans[v[j].y] = &cu[b[j]];
            else if (s[v[j].y] == b[j] && t[j] == 1) ans[v[j].y] = &cu[a[j]];
            j++;
        }
    }
    while(j<m){
        ans[v[j].y] = &cu[s[v[j].y]];
        if(s[v[j].y] == a[j]) ans[v[j].y] = &cu[b[j]];
        else if (s[v[j].y] == b[j] && t[j] == 1) ans[v[j].y] = &cu[a[j]];
        j++;
    }

    for (int i=0; i<m; i++)
    {
        cout << *ans[i] << "\n";
    }
    return 0;
}