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

    int a[n];
    int ans = 0;
    vector<int> b;
    vector<int> w;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        if (a[i]) b.push_back(i);
        else w.push_back(i);
    }
    bool v[w.size()];
    for (int i=0; i<w.size(); i++) v[i] = 0;
    priority_queue<int> pq;
    for (int k= 0; k<b.size(); k++) {
        int l = -1;
        int r = n+1;
        for (int j=0; j<w.size(); j++) {
            if (v[j]) continue;
            if (w[j] < b[k]) l = j;
            if (w[j] > b[k] && r==n+1) r = j;
        }

        int tt;
        if (l==-1) {
            tt = r;
        }
        else if (r==n+1) {
            tt = l;
        }
        else {
            if (b[k]-w[l] <= w[r]- b[k]) tt=l;
            else tt = r;
        }
        if (k==0 || tt==l) {
            v[tt] = 1;
            pq.push(tt);
            ans += abs(w[tt]-b[k]);
            continue;
        }
        int temp = -1;
        for (int j=pq.top()-1; j>=0; j--) {
            if (v[j]) continue;
            pq.push(j);
            temp = j;
            break;
        }
        if (temp==-1) {
            v[tt] = 1;
            pq.push(tt);
            ans += abs(w[tt]-b[k]);
            continue;
        }
        int ans2 = 0;
        vector<int> m;
        int q = 0;
        while (!pq.empty()) {
            m.push_back(pq.top());
            pq.pop();
            ans2 += abs(m[q]-b[q]);
            q++;
        }
        if (ans2 < ans + abs(w[tt]-b[k])) {
            ans = ans2;
            for (int i=0; i<q; i++) pq.push(m[i]);
            v[temp] = 1;
        } else {
            ans += abs(w[tt]-b[k]);
            v[tt] = 1;
            pq.push(tt);
            for (int i=0; i<q; i++) {
                if (m[i]!=temp) pq.push(m[i]);
            }
        }
    }
    cout << ans;

    return 0;
}