#include<bits/stdc++.h>

using namespace std;
long long pow10(int n){
    if(n==0) return 1;
    return 10*pow10(n-1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int test_case;
    cin>>test_case;
    for(int z=1; z<=test_case; z++){
        long long u;
        cin>>u;
        long long t;
        string m;
        long double v[26][10];
        string ans = "aaaaaaaaaa";
        for(int i=0; i<26; i++){
            for(int j=0; j<10; j++) v[i][j] = 0;
        }
        for(int y=0; y<10000; y++){
            cin>>t>>m;
            long long temp = t/pow10((int)m.size()-1);
            if(t>10){
                for(int i=0; i<10; i++) v[m[m.size()-1]-'a'][i] += 0.1;
                cout<<m.size()-1<<" "<<v[m[m.size()-1]-'a'][0];
            }
            cout<<endl;
            if(temp){
                if(temp>9) temp  = 9;
                for(int i=1; i<temp; i++){
                    v[m[0]-'a'][i] += ((long double)pow10((int)m.size()-1)/(long double)t);
                }
                v[m[0]-'a'][temp] +=((long double)(t%pow10((int)m.size()-1))/(long double)t);
            }
        }
        for(int i=0; i<26; i++){
            long double min_= 1e9;
            long double max_ = 0;
            int ax_, in_;
            for(int j=0; j<10; j++){
                cout<<v[i][j]<<" ";
                if(v[i][j]>max_){
                    max_ = v[i][j];
                    ax_ = j;
                }
                if(v[i][j]<min_){
                    min_ = v[i][j];
                    in_ = j;
                }
            }
            cout<<"\n";
            if(max_<10) continue;
            if(max_<1000) ans[0] += i;
            else ans[ax_] += i;
        }
        cout<<"CASE #"<<z<<": "<<ans<<"\n";
    }
    return 0;
}



