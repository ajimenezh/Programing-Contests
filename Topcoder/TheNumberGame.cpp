#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <stdio.h>

using namespace std;

#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)


class TheNumberGame {
	public:
	string determineOutcome(int A, int B) ;
};

string a,b;



string TheNumberGame::determineOutcome(int A, int B) {

	while (A>0) {
        a = char(A%10+'0') + a;
        A /= 10;
	}
	while (B>0) {
        b = char(B%10+'0') + b;
        B /= 10;
	}

	if (b.length()>a.length()) return "Manao loses";
	if (b.length()<a.length()-1) return "Manao loses";

	if (a.length()==b.length()) {
        if (a==b) return "Manao wins";
        reverse(a.begin(),a.end());
        if (a==b) return "Manao wins";
        return "Manao loses";
	}

	string a1 = a.substr(0,a.length()-1);
	if (a1==b) return "Manao wins";
	reverse(a1.begin(),a1.end());
	if (a1==b) return "Manao wins";
	a1 = a.substr(1,a.length()-1);
	if (a1==b) return "Manao wins";
	reverse(a1.begin(),a1.end());
	if (a1==b) return "Manao wins";

	return "Manao loses";
};

//BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1)
	{
		cout << "Testing TheNumberGame (275.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1381262288;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 275.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TheNumberGame _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A = 45;
				int B = 4;
				_expected = "Manao wins";
				_received = _obj.determineOutcome(A, B); break;
			}
			case 1:
			{
				int A = 45;
				int B = 5;
				_expected = "Manao wins";
				_received = _obj.determineOutcome(A, B); break;
			}
			case 2:
			{
				int A = 99;
				int B = 123;
				_expected = "Manao loses";
				_received = _obj.determineOutcome(A, B); break;
			}
			case 3:
			{
				int A = 2356236;
				int B = 5666;
				_expected = "Manao loses";
				_received = _obj.determineOutcome(A, B); break;
			}
			/*case 4:
			{
				int A = ;
				int B = ;
				_expected = ;
				_received = _obj.determineOutcome(A, B); break;
			}*/
			/*case 5:
			{
				int A = ;
				int B = ;
				_expected = ;
				_received = _obj.determineOutcome(A, B); break;
			}*/
			/*case 6:
			{
				int A = ;
				int B = ;
				_expected = ;
				_received = _obj.determineOutcome(A, B); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

//END CUT HERE
