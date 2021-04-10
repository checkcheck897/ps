#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long t, n, ansc, ansr, trace;;
    int m[100][100], hash[101], hash2[101];
    cin>>t;
    for(int k=0; k<t; k++){
		cin>>n;
        trace = 0;
        ansr = 0;
        ansc = 0;
        for(int i=0; i<n+1; i++) hash[i] = 0;
        for(int i=0; i<n+1; i++) hash2[i] = 0;
		for(int i=0; i<n; i++){
            for(int j=0; j<n; j++) cin>>m[i][j];
            trace += m[i][i];
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                hash2[m[i][j]]++;
                if(hash2[m[i][j]]>1){
                    ansc++;
                    break;
                }
            }
            for(int j=0; j<n+1; j++) hash2[j] = 0;
	    }
        for(int j=0; j<n; j++){
            for(int i=0; i<n; i++){
                hash[m[i][j]]++;
                if(hash[m[i][j]]>1){
                    ansr++;
                    break;
                }
            }
            for(int i=0; i<n+1; i++) hash[i] = 0;
	    }
        cout<<"Case #"<<k+1<<": "<<trace<<" "<<ansc<<" "<<ansr<<"\n";
    }
    return 0;
}