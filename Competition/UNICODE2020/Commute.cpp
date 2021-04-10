#include <bits/stdc++.h>

# pragma GCC optimize ("O3")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

#define x first
#define y second
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>

using namespace std;

int n, m, a, b;
ll dist[1005];
vector <pll> adj[1005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> a >> b;

    for (int i=0; i<1005; i++)
    {
        dist[i] = 1e15;
    }

    for (int i=0; i<m; i++)
    {
        ll xx, yy, zz;
        cin >> xx >> yy >> zz;
        adj[xx].push_back({yy,zz});
        adj[yy].push_back({xx,zz});
    }

    int k;
    cin >> k;


        priority_queue<pll> pq;
        pq.push({0,a});
        dist[a] = 0;
        while (!pq.empty())
        {
            ll h = pq.top().y;
            pq.pop();
            for (pll tt : adj[h])
            {
                ll i = tt.x;
                ll di = tt.y;
                
                if (di+dist[h] < dist[i])
                {
                    dist[i] = di+dist[h];
                    pq.push({-di, i});
                }
            }
        }

    
    cout << dist[b];

    return 0;
}