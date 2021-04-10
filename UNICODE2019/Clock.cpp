#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
 	int t; double h,m, s;
 	double a,b,c; double ang[3];
 	cin >> t;
 	for(int i=0; i<t; i++){
 		cin >> h>> m>> s;
 		a = 30*h+0.5*m+s/120;
 		b = 6*m+s/10;
 		c = 6*s;
 		ang[0]= min(max(a-b,b-a),360-max(a-b,b-a));
 		ang[1]= min(max(c-b,b-c),360-max(c-b,b-c));
 		ang[2]= min(max(a-c,c-a),360-max(a-c,c-a));
 		sort(ang, ang+3);
 		cout<<setprecision(10);
 		cout<<ang[0]<<"\n";
	 }
    return 0;
}