#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
# pragma GCC optimize ("O3")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#define x first
#define y second
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << "150\n";
    for (int i=0; i<150; i++) {
        cout << "1 300\n";
        for (int j=0; j<300; j++) {
            cout << j+1 << " ";
        }
    }
    return 0;
}