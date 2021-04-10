/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <cmath>
using namespace std;
int sum[10001];
int Answer;
int jump(int num){
	int j=0;
	if(num == 1) return 1;
	if(num == 0) return 0;
	while(sum[j]<=num) j++;
	num -= sum[j-1];
	return j-1+jump(num);
}

int main(int argc, char** argv)
{
	int T, test_case; int x,y;
	for(int i=1; i<10001; i++) sum[i] = i*(i+1)/2;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
		cin>>x>>y;
		if(y>1000000) return 0;
		for(int i=x; i<y+1; i++){
			Answer = max(Answer, jump(i));
		}
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}