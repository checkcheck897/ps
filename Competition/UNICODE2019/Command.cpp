#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
 	string a;
 	string s;
	int t;
	cin >> t;
	for(int i=0; i<t; i++){
		cin >> a;
		if(a.length()==7){
			if(a.at(0)!=a.at(2)){
				s="";
				s.push_back(a.at(0));
				s.push_back(a.at(0));
				s.push_back(a.at(2));
				s.push_back(a.at(2));
				s.push_back(a.at(0));
				s.push_back(a.at(2));
				s.push_back(a.at(2));
				if(s==a){
					cout<< 1<<endl;
					continue;
				}
			}
		}
		cout << 0<<endl;
	}
    return 0;
}