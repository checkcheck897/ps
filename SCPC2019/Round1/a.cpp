#include <iostream>
#include <stdio.h>
using namespace std;

int Answer;

int dp[1000001];


int main(int argc, char** argv)
{
	int T, test_case;
	int n1, n2;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	// freopen("input.txt", "r", stdin);

	cin >> T;
	dp[0] = 0;
	dp[1] = 0;
	for(int i=2; i<1000001; i++){
		if(i%2==0) dp[i] = dp[i/2] +1;
		if(i%2==1) dp[i] = dp[(i+1)/2] +2;
	}
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
		cin>>n1>>n2;
		for(int i=n1; i<n2+1; i++){
			Answer += dp[i];
		}
		printf("Case #%d\n%d\n", test_case+1, Answer);
	}

	return 0;//Your program should return 0 on normal termination.
}