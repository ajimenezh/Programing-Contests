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


class AkariDaisukiDiv1 {
	public:
	int countF(string Waai, string Akari, string Daisuki, string S, string F, int k) ;
};

int AkariDaisukiDiv1::countF(string Waai, string Akari, string Daisuki, string S, string F, int k) {
		
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
		cout << "Testing AkariDaisukiDiv1 (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1384081466;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 550.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		AkariDaisukiDiv1 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string Waai = "a";
				string Akari = "b";
				string Daisuki = "c";
				string S = "x";
				string F = "axb";
				int k = 2;
				_expected = 2;
				_received = _obj.countF(Waai, Akari, Daisuki, S, F, k); break;
			}
			case 1:
			{
				string Waai = "a";
				string Akari = "b";
				string Daisuki = "c";
				string S = "x";
				string F = "abcdefghij";
				int k = 1;
				_expected = 0;
				_received = _obj.countF(Waai, Akari, Daisuki, S, F, k); break;
			}
			case 2:
			{
				string Waai = "a";
				string Akari = "a";
				string Daisuki = "a";
				string S = "b";
				string F = "aba";
				int k = 2;
				_expected = 4;
				_received = _obj.countF(Waai, Akari, Daisuki, S, F, k); break;
			}
			case 3:
			{
				string Waai = "a";
				string Akari = "b";
				string Daisuki = "c";
				string S = "d";
				string F = "baadbdcbadbdccccbaaaadbdcbadbdccbaadbdcba";
				int k = 58;
				_expected = 191690599;
				_received = _obj.countF(Waai, Akari, Daisuki, S, F, k); break;
			}
			case 4:
			{
				string Waai = "a";
				string Akari = "x";
				string Daisuki = "y";
				string S = "b";
				string F = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
				int k = 49;
				_expected = 1;
				_received = _obj.countF(Waai, Akari, Daisuki, S, F, k); break;
			}
			case 5:
			{
				string Waai = "waai";
				string Akari = "akari";
				string Daisuki = "daisuki";
				string S = "usushio";
				string F = "id";
				int k = 10000000;
				_expected = 127859200;
				_received = _obj.countF(Waai, Akari, Daisuki, S, F, k); break;
			}
			case 6:
			{
				string Waai = "vfsebgjfyfgerkqlr";
				string Akari = "ezbiwls";
				string Daisuki = "kjerx";
				string S = "jbmjvaawoxycfndukrjfg";
				string F = "bgjfyfgerkqlrvfsebgjfyfgerkqlrvfsebgjfyfgerkqlrvfs";
				int k = 1575724;
				_expected = 483599313;
				_received = _obj.countF(Waai, Akari, Daisuki, S, F, k); break;
			}
			/*case 7:
			{
				string Waai = ;
				string Akari = ;
				string Daisuki = ;
				string S = ;
				string F = ;
				int k = ;
				_expected = ;
				_received = _obj.countF(Waai, Akari, Daisuki, S, F, k); break;
			}*/
			/*case 8:
			{
				string Waai = ;
				string Akari = ;
				string Daisuki = ;
				string S = ;
				string F = ;
				int k = ;
				_expected = ;
				_received = _obj.countF(Waai, Akari, Daisuki, S, F, k); break;
			}*/
			/*case 9:
			{
				string Waai = ;
				string Akari = ;
				string Daisuki = ;
				string S = ;
				string F = ;
				int k = ;
				_expected = ;
				_received = _obj.countF(Waai, Akari, Daisuki, S, F, k); break;
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
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

//END CUT HERE
