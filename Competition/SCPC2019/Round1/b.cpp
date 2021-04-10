#include <cmath>
#include <iostream>

using namespace std;

double Answer;

const double pi = 3.1415926535897932384626433;

int main(int argc, char** argv)
{
	int T, test_case;
	int R,E;
	double S;
	int l, r, h, N;
	double temp;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
		cin >> R >> S >> E;
		cin >> N;
		for(int i=0; i<N; i++){
			cin >> l >> r >> h;
			if(h>=R){
				Answer += r-R-S;
				Answer += (h-R)*2;
				Answer += pi*R;
				S = r+R;
			}
			if(h<R){
				temp = sqrt(-h*h+2*R*h);
				Answer += r-temp-S;
				Answer += R*(2*asin(temp/R));
				S = r+temp;
			}
		}
		Answer += E-S;
		cout << "Case #" << test_case+1 << endl;
		cout<<fixed;
		cout.precision(9);
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}