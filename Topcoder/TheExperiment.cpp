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


class TheExperiment {
	public:
	int countPlacements(vector <string> intensity, int M, int L, int A, int B) ;
};

int TheExperiment::countPlacements(vector <string> intensity, int M, int L, int A, int B) {
		
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
		cout << "Testing TheExperiment (576.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1381084217;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 576.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TheExperiment _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string intensity[] = {"341156"};
				int M = 3;
				int L = 3;
				int A = 6;
				int B = 10;
				_expected = 2;
				_received = _obj.countPlacements(vector <string>(intensity, intensity+sizeof(intensity)/sizeof(string)), M, L, A, B); break;
			}
			case 1:
			{
				string intensity[] = {"999112999"};
				int M = 2;
				int L = 4;
				int A = 21;
				int B = 30;
				_expected = 2;
				_received = _obj.countPlacements(vector <string>(intensity, intensity+sizeof(intensity)/sizeof(string)), M, L, A, B); break;
			}
			case 2:
			{
				string intensity[] = {"111"};
				int M = 2;
				int L = 2;
				int A = 2;
				int B = 3;
				_expected = 0;
				_received = _obj.countPlacements(vector <string>(intensity, intensity+sizeof(intensity)/sizeof(string)), M, L, A, B); break;
			}
			case 3:
			{
				string intensity[] = {"59059", "110", "1132230231"};
				int M = 1;
				int L = 5;
				int A = 10;
				int B = 20;
				_expected = 6;
				_received = _obj.countPlacements(vector <string>(intensity, intensity+sizeof(intensity)/sizeof(string)), M, L, A, B); break;
			}
			case 4:
			{
				string intensity[] = {"111111111111111111111111", "111111111111111111111111111", "11111111111111111111111"};
				int M = 12;
				int L = 8;
				int A = 4;
				int B = 2700;
				_expected = 418629948;
				_received = _obj.countPlacements(vector <string>(intensity, intensity+sizeof(intensity)/sizeof(string)), M, L, A, B); break;
			}
			/*case 5:
			{
				string intensity[] = ;
				int M = ;
				int L = ;
				int A = ;
				int B = ;
				_expected = ;
				_received = _obj.countPlacements(vector <string>(intensity, intensity+sizeof(intensity)/sizeof(string)), M, L, A, B); break;
			}*/
			/*case 6:
			{
				string intensity[] = ;
				int M = ;
				int L = ;
				int A = ;
				int B = ;
				_expected = ;
				_received = _obj.countPlacements(vector <string>(intensity, intensity+sizeof(intensity)/sizeof(string)), M, L, A, B); break;
			}*/
			/*case 7:
			{
				string intensity[] = ;
				int M = ;
				int L = ;
				int A = ;
				int B = ;
				_expected = ;
				_received = _obj.countPlacements(vector <string>(intensity, intensity+sizeof(intensity)/sizeof(string)), M, L, A, B); break;
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
