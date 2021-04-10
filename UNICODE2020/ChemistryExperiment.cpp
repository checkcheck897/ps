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
    int n, k;

    cin >> n >> k;

    priority_queue<pii> a;

    for (int i=0; i<k; i++)
    {
        int t;
        cin >> t;
        a.push({t, i+1});
    }
    if ((n+1)/2 < a.top().x) cout << "-1";
    else
    {
        for (int i=0; i<n/2; i++)
        {
            pii xx = a.top();
            a.pop();
            pii yy = a.top();
            a.pop();

            cout << xx.y << " " << yy.y << " ";
            xx.x -= 1;
            yy.x -= 1;
            if (xx.x !=0) a.push(xx);
            if (yy.x !=0) a.push(yy);
        }
        if (!a.empty()) cout << a.top().y;
    }
     

    return 0;
}