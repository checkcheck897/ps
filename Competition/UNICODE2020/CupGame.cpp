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
    ll h[n], t[n];
    for (int i=0; i<n; i++) cin >> h[i];

    for (int i=0; i<n-1; i++) cin >> t[i];
    sort(h, h+n);
    priority_queue<pll> pq;
    ll time = 0;
    int ans[n];

    for (int i=0; i<n; i++) ans[i] = h[n-1]; 
    for (int i=0; i<n; i++)
    {
        while (!pq.empty())
        {
            if (pq.top().x + time > h[i])
            {
                ans[pq.top().y] = h[i-1];
                pq.pop();
            }
            else break;
        }
        pq.push({-time, i});
        if(i!=n) time += t[i];
    }

    for (int i=0; i<n; i++) cout << ans[i] << " ";
    return 0;
}