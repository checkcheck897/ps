#include <bits/stdc++.h>

# pragma GCC optimize ("O3")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#define x first
#define y second
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>

using namespace std;

long long t[400001];
long long n;
long long query(long long l, long long r) {
    long long ans = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ans += t[l++];
        if (r & 1) ans += t[--r];
    }
    return ans;
}
void update(int pos, long long val) {
    t[pos + n] = val;
    for (pos += n; pos > 1; pos >>= 1) {
        t[pos >> 1] = t[pos] + t[pos ^ 1];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    ll a[n];
    ll dp[n+1] = {0};
    ll b[n];
    int cnt = 0;
    vector<pll> c;
    int cnt2=0;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        if (a[i]>=0) {
            dp[i+1] = dp[i] + a[i];
            cnt2++;
            if (a[i]==0) cnt++;
        }
        else {
            dp[i+1] = dp[i];
            c.push_back({-a[i], i});
        }
    }
    sort(c.begin(), c.end());
    if (dp[n]==0) {
        cout << cnt;
        return 0;
    }
    int l=0; int r=n+1;
    while(l+1<r) {
        int mid = (l+r)/2;
        for (int i=0; i<n; i++) b[i] = 0;
        for (int i=0; i<=2*n; i++) t[i] = 0;
        bool check2 = 1;
        int num = 0;
        for (int i=0; i<c.size(); i++) {
            if (num==mid-cnt2) {
                check2 = 0;
                break;
            }
            update(c[i].y, -c[i].x);
            if (dp[c[i].y] + query(0, c[i].y+1) >=0) {
                num++;
            } else {
                update(c[i].y, 0);
            }
        }
        if (check2 && num < mid-cnt2) {
            r = mid;
            continue;
        }
        for (int i=0; i<n; i++) b[i] = t[i+n];
        for (int i=0; i<n-1; i++) {
            b[i+1] += b[i];
        }
        bool check = 1;
        for (int i=0; i<n; i++) {
            if (dp[i+1]+b[i] < 0) check = 0;
        }
        if (check) l = mid;
        else r= mid;
    }
    cout << l;
    return 0;
}