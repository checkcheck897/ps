#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, count, p_2[31], pp_2[31];
    bool check[31];
    pp_2[0] = 1;
    for(int i=1; i<31; i++) pp_2[i] = pp_2[i-1]*2;
    for(int i=1; i<31; i++) pp_2[i] += i;
    bool odd;
    cin>>t;
    for(int k=0; k<t; k++){
        odd = true;
		cin>>n;
        cout<<"Case #"<<k+1<<": \n";
        for(int i=0; i<31; i++){
            if(pp_2[i]<=n && pp_2[i+1]>n) count = i+1;
        }
        check[0] = false;
        p_2[0] = 1;
        for(int i=1; i<31; i++){
            p_2[i] = p_2[i-1]*2;
            check[i] = false;
        }
        for(int i=count-1; i>=0; i--){
            if(pp_2[i]<=n){
                n-=p_2[i];
                check[i] = true;
            }
            else n-=1;

        }
        for(int i=1; i<=count; i++){
            if(check[i-1]){
                for(int j=1; j<=i; j++){
                    if(odd){
                        cout<<i<<" "<<j<<"\n";
                    }
                    else{
                        cout<<i<<" "<<i-j+1<<"\n";
                    }
                }
                odd = !(odd);
            }
            else{
                if(!odd){
                        cout<<i<<" "<<i<<"\n";
                    }
                    else{
                        cout<<i<<" "<<1<<"\n";
                    }
            }
            
        }
        for(int i=1; i<=n; i++){
            if(!odd) cout<<i+count<<" "<<i+count<<"\n";
            else cout<<i+count<<" "<<1<<"\n";
        }
    }
    return 0;
}