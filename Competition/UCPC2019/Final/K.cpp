#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int a[n];
    int l = 1e9;
    int r = 0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        l = min(a[i], l);
        r = max(a[i], r);
    }
    while(l+1<r){
        int mid = (l+r)/2;
        ll tot = 0;
        int b, num1=0, num2=1;
        for(int i=0; i<n; i++){
            b = (a[i]+mid-1)/mid;
            if(b==1) num1++;
            else num2 += (b-2);
        }
        if(num1>=num2) r = mid;
        else l = mid;
    }
    cout<<r;
    return 0;
}