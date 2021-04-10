#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    fstream readf;
    readf.open("output.txt");
    for(int i=1; i<=t; i++){
        int n;
        cin>>n;
        string a, b;
        cin>>a>>b;
        readf<<"Case #"<<i<<":\n";
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                if(j==k) readf<<'Y';
                else{
                    if(j>k){
                        for(int x=k; x<j; x++){
                            if(a[x]!='Y' || b[x+1]!='Y'){
                                readf<<'N';
                                x=j;
                            }
                            if(x==j-1) readf<<'Y';
                        }
                    }
                    else{
                        for(int x=j; x<k; x++){
                            if(b[x]!='Y' || a[x+1]!='Y'){
                                readf<<'N';
                                x=k;
                            }
                            if(x==k-1) readf<<'Y';
                        }
                    }
                }
            }
            readf<<"\n";
        }
    }
    return 0;
}