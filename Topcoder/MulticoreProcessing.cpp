
#line 3 "MulticoreProcessing.cpp"
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

class MulticoreProcessing {
	public:
	long long fastestTime(long long jobLength, int corePenalty, vector <int> speed, vector <int> cores) {
        long long best = 1LL<<61;

		for (int i=0; i<cores.size(); i++) {

            int lo = 1;
            int hi = cores[i];

            while (lo + 2 < hi) {

                long long lt = (2*lo+hi)/3;
                long long ht = (lo+2*hi)/3;

                long long fl = ((jobLength-1) / (lt*speed[i])) + 1 + (long long) corePenalty*(lt-1);
                long long fh = ((jobLength-1) / (ht*speed[i])) + 1 + (long long) corePenalty*(ht-1);

                if (fl <= fh) {
                    hi = ht;
                }
                else {
                    lo = lt;
                }

            }

            for (long long j=lo; j<=hi; j++) {

                long long tmp = ((jobLength-1) / (j*speed[i])) + 1 + (long long) corePenalty*(j-1);

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
		cout << "Testing MulticoreProcessing (350.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1507815506;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 350.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		MulticoreProcessing _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long jobLength = 10000000000LL;
				int corePenalty = 1;
				int speed[] = {1};
				int cores[] = {1000000000};
				_expected = 199999LL;
				_received = _obj.fastestTime(jobLength, corePenalty, vector <int>(speed, speed+sizeof(speed)/sizeof(int)), vector <int>(cores, cores+sizeof(cores)/sizeof(int))); break;
			}
			case 1:
			{
				long long jobLength = 2000LL;
				int corePenalty = 5;
				int speed[] = {10,20};
				int cores[] = {2,4};
				_expected = 40LL;
				_received = _obj.fastestTime(jobLength, corePenalty, vector <int>(speed, speed+sizeof(speed)/sizeof(int)), vector <int>(cores, cores+sizeof(cores)/sizeof(int))); break;
			}
			case 2:
			{
				long long jobLength = 1000LL;
				int corePenalty = 0;
				int speed[] = {10};
				int cores[] = {3};
				_expected = 34LL;
				_received = _obj.fastestTime(jobLength, corePenalty, vector <int>(speed, speed+sizeof(speed)/sizeof(int)), vector <int>(cores, cores+sizeof(cores)/sizeof(int))); break;
			}
			case 3:
			{
				long long jobLength = 10000LL;
				int corePenalty = 5;
				int speed[] = {39,37,44};
				int cores[] = {8,16,6};
				_expected = 63LL;
				_received = _obj.fastestTime(jobLength, corePenalty, vector <int>(speed, speed+sizeof(speed)/sizeof(int)), vector <int>(cores, cores+sizeof(cores)/sizeof(int))); break;
			}
			/*case 4:
			{
				long long jobLength = LL;
				int corePenalty = ;
				int speed[] = ;
				int cores[] = ;
				_expected = LL;
				_received = _obj.fastestTime(jobLength, corePenalty, vector <int>(speed, speed+sizeof(speed)/sizeof(int)), vector <int>(cores, cores+sizeof(cores)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				long long jobLength = LL;
				int corePenalty = ;
				int speed[] = ;
				int cores[] = ;
				_expected = LL;
				_received = _obj.fastestTime(jobLength, corePenalty, vector <int>(speed, speed+sizeof(speed)/sizeof(int)), vector <int>(cores, cores+sizeof(cores)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				long long jobLength = LL;
				int corePenalty = ;
				int speed[] = ;
				int cores[] = ;
				_expected = LL;
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
