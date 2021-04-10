#include <bits/stdc++.h>

# pragma GCC optimize ("O3")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

#define x first
#define y second
#define pii pair<int, int>
#define ll long long
#define lld long double
#define pll pair<ll, ll>

using namespace std;

ll r[105][3];
ll n, k;
lld square(lld a) { return a*a;}
lld ans = 1e15;

struct point{
    lld xx, yy, zz;
};

point cross(point a, point b)
{
    point ret;
    ret.xx = (a.yy*b.zz-a.zz*b.yy);
    ret.yy = (a.zz*b.xx-a.xx*b.zz);
    ret.zz = (a.xx*b.yy-a.yy*b.xx);
    return ret;
}

lld inner(point a, point b)
{
    lld ret = 0;
    ret += a.xx*b.xx;
    ret += a.yy*b.yy;
    ret += a.zz*b.zz;
    return ret;
}

lld cal(const vector<int> &up, const vector<int> &low)
{
    int u_s = up.size(), l_s = low.size();
    ll tot_u[3] = {0,0,0};
    ll tot_l[3] = {0,0,0};
    for (int i : up)
    {
        for (int j=0; j<3; j++) tot_u[j] += r[i][j];
    }
    for (int i : low)
    {
        for (int j=0; j<3; j++) tot_l[j] += r[i][j];
    }

    lld avg_u[3], avg_l[3];
    for (int i=0; i<3; i++)
    {
        avg_u[i] = (lld)tot_u[i]/u_s;
        avg_l[i] = (lld)tot_l[i]/l_s;
    }

    lld ret = 0;

    for (int i : up)
    {
        for (int j=0; j<3; j++) ret += square(avg_u[j]-r[i][j]);
    }
    for (int i : low)
    {
        for (int j=0; j<3; j++) ret += square(avg_l[j]-r[i][j]);
    }
    return ret;
}

lld solve(int ai, int aj, int ak)
{
    lld ret = 1e15;

    point a,b;
    a.xx = (r[ai][0]-r[aj][0]);
    a.yy = (r[ai][1]-r[aj][1]);
    a.zz = (r[ai][2]-r[aj][2]);
    b.xx = (r[aj][0]-r[ak][0]);
    b.yy = (r[aj][1]-r[ak][1]);
    b.zz = (r[aj][2]-r[ak][2]);

    point xx = cross(a, b);
    vector<int> upper;
    vector<int> lower;

    for (int i=0; i<n; i++)
    {
        if (i==ai || i==aj || i==ak) continue;
        point temp;
        temp.xx = r[i][0]-r[ai][0];
        temp.yy = r[i][1]-r[aj][1];
        temp.zz = r[i][2]-r[ak][2];
        if (inner(xx, temp) > 0) upper.push_back(i);
        else lower.push_back(i);
    }

    for (int i=0; i<8; i++)
    {
        if (i>=4) upper.push_back(ai);
        else lower.push_back(ai);
        if (i==2 || i==3 || i==6 || i==7) upper.push_back(aj);
        else lower.push_back(aj);
        if (i%2) upper.push_back(ak);
        else lower.push_back(ak);

        ret = min(cal(upper, lower), ret);

        if (i>=4) upper.pop_back();
        else lower.pop_back();
        if (i==2 || i==3 || i==6 || i==7) upper.pop_back();
        else lower.pop_back();
        if (i%2) upper.pop_back();
        else lower.pop_back();
    }

    return ret;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    for (int i=0; i<n; i++) cin >> r[i][0] >> r[i][1] >> r[i][2];

    cout<<fixed;
    cout.precision(6);

    if (k == 1)
    {
        ans = 0;
        ll tot[3] = {0,0,0};
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<3; j++) tot[j] += r[i][j];
        }
        lld avg[3] = {tot[0]/(lld)n, tot[1]/(lld)n, tot[2]/(lld)n};

        for (int i=0; i<n; i++)
        {
            for (int j=0; j<3; j++) ans += square(avg[j]-r[i][j]);
        }
        cout << ans;
    }
    else
    {
        if (n <=2)
        {
            ans = 0;
            cout << ans;
            return 0;
        }
        for (int i=0; i<n-2; i++)
        {
            for (int j=i+1; j<n-1; j++)
            {
                for (int k=j+1; k<n; k++) ans = min(ans, solve(i,j,k));
            }
        }
        cout << ans;
    }
    
    return 0;
}