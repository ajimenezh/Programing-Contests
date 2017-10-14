
#line 3 "ConstructLCS.cpp"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

typedef long long LL;
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)

class ConstructLCS {
	public:
	string construct(int ab, int bc, int ca) {
		
	}
};

// BEGIN CUT HERE
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
		cout << "Testing ConstructLCS (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1507988275;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ConstructLCS _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int ab = 3;
				int bc = 4;
				int ca = 2;
				_expected = "101 1010101 1111";
				_received = _obj.construct(ab, bc, ca); break;
			}
			case 1:
			{
				int ab = 7;
				int bc = 4;
				int ca = 4;
				_expected = "10101010 1010101 1011";
				_received = _obj.construct(ab, bc, ca); break;
			}
			case 2:
			{
				int ab = 8;
				int bc = 7;
				int ca = 8;
				_expected = "110101001011 010101101 10101010";
				_received = _obj.construct(ab, bc, ca); break;
			}
			case 3:
			{
				int ab = 8;
				int bc = 6;
				int ca = 7;
				_expected = "110101010 10101010 1111010";
				_received = _obj.construct(ab, bc, ca); break;
			}
			case 4:
			{
				int ab = 15;
				int bc = 17;
				int ca = 19;
				_expected = "000100101101111011000 11110111010011101010 100100001010101001010101000011111";
				_received = _obj.construct(ab, bc, ca); break;
			}
			case 5:
			{
				int ab = 50;
				int bc = 50;
				int ca = 50;
				_expected = "11111111111111111111111111111111111111111111111111 11111111111111111111111111111111111111111111111111 11111111111111111111111111111111111111111111111111";
				_received = _obj.construct(ab, bc, ca); break;
			}
			/*case 6:
			{
				int ab = ;
				int bc = ;
				int ca = ;
				_expected = ;
				_received = _obj.construct(ab, bc, ca); break;
			}*/
			/*case 7:
			{
				int ab = ;
				int bc = ;
				int ca = ;
				_expected = ;
				_received = _obj.construct(ab, bc, ca); break;
			}*/
			/*case 8:
			{
				int ab = ;
				int bc = ;
				int ca = ;
				_expected = ;
				_received = _obj.construct(ab, bc, ca); break;
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

// END CUT HERE