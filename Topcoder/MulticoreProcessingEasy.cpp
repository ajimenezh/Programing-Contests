
#line 3 "MulticoreProcessingEasy.cpp"
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

class MulticoreProcessingEasy {
	public:
	int fastestTime(int jobLength, int corePenalty, vector <int> speed, vector <int> cores) {

		int best = 1000000000;

		for (int i=0; i<cores.size(); i++) {

            for (int j=1; j<=cores[i]; j++) {

                int tmp = ((jobLength-1) / j) / speed[i] + 1 + corePenalty*(j-1);

                best = min(best, tmp);

            }

		}

		return best;

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
		cout << "Testing MulticoreProcessingEasy (700.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1507814955;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 700.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		MulticoreProcessingEasy _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int jobLength = 2000;
				int corePenalty = 5;
				int speed[] = {40,20};
				int cores[] = {2,4};
				_expected = 30;
				_received = _obj.fastestTime(jobLength, corePenalty, vector <int>(speed, speed+sizeof(speed)/sizeof(int)), vector <int>(cores, cores+sizeof(cores)/sizeof(int))); break;
			}
			case 1:
			{
				int jobLength = 2000;
				int corePenalty = 5;
				int speed[] = {10,20};
				int cores[] = {2,4};
				_expected = 40;
				_received = _obj.fastestTime(jobLength, corePenalty, vector <int>(speed, speed+sizeof(speed)/sizeof(int)), vector <int>(cores, cores+sizeof(cores)/sizeof(int))); break;
			}
			case 2:
			{
				int jobLength = 1000;
				int corePenalty = 0;
				int speed[] = {10};
				int cores[] = {3};
				_expected = 34;
				_received = _obj.fastestTime(jobLength, corePenalty, vector <int>(speed, speed+sizeof(speed)/sizeof(int)), vector <int>(cores, cores+sizeof(cores)/sizeof(int))); break;
			}
			case 3:
			{
				int jobLength = 10000;
				int corePenalty = 5;
				int speed[] = {39,37,44};
				int cores[] = {8,16,6};
				_expected = 63;
				_received = _obj.fastestTime(jobLength, corePenalty, vector <int>(speed, speed+sizeof(speed)/sizeof(int)), vector <int>(cores, cores+sizeof(cores)/sizeof(int))); break;
			}
			/*case 4:
			{
				int jobLength = ;
				int corePenalty = ;
				int speed[] = ;
				int cores[] = ;
				_expected = ;
				_received = _obj.fastestTime(jobLength, corePenalty, vector <int>(speed, speed+sizeof(speed)/sizeof(int)), vector <int>(cores, cores+sizeof(cores)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int jobLength = ;
				int corePenalty = ;
				int speed[] = ;
				int cores[] = ;
				_expected = ;
				_received = _obj.fastestTime(jobLength, corePenalty, vector <int>(speed, speed+sizeof(speed)/sizeof(int)), vector <int>(cores, cores+sizeof(cores)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int jobLength = ;
				int corePenalty = ;
				int speed[] = ;
				int cores[] = ;
				_expected = ;
				_received = _obj.fastestTime(jobLength, corePenalty, vector <int>(speed, speed+sizeof(speed)/sizeof(int)), vector <int>(cores, cores+sizeof(cores)/sizeof(int))); break;
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

// END CUT HERE
