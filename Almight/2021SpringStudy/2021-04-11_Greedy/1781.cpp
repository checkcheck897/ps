#include<bits/stdc++.h>
using namespace std;

bool comp(const pair<int, int>&a, const pair<int, int>&b){
	return a.second>b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	int n, d, p;
	priority_queue <int> pq;
	pair<int, int> pa[200000];
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>p>>d;
		pa[i] = {d, p};
	}
	sort(pa, pa+n, comp);
	int ans  = 0;
	int j=0;
	for(int i=n; i>0; i--){
		while(i == pa[j].second) pq.push(pa[j++].first);
		if(pq.empty()==false){
			ans += pq.top();
			pq.pop();
		}
	}
	cout<<ans;
    return 0;
}