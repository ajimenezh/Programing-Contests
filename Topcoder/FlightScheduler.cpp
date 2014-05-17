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


class FlightScheduler {
	public:
	double minimizeFuel(int distance, int K, int emptyMass, int takeoffFuel) ;
};

double FlightScheduler::minimizeFuel(int distance, int K, int emptyMass, int takeoffFuel) {
    double res = 1.0e18;

    int lo = 0;
    int hi = 1000000000;

    for (int i=0; i<100; i++) {
        int l = (2*lo + hi)/3;
        int r = (2*hi + lo)/3;

        double x = (double)distance/(l+1);
        double totl = exp(x/K)*emptyMass + takeoffFuel - emptyMass;
        totl *= (l+1);

        x = (double)distance/(r+1);
        double totr = exp(x/K)*emptyMass + takeoffFuel - emptyMass;
        totr *= (r+1);

        if (totl<totr) {
            hi = r;
        }
        else {
            lo = l;
        }
    }

    for (int i=lo; i<=hi; i++) {
        double x = (double)distance/(i+1);
        double tot = exp(x/K)*emptyMass + takeoffFuel - emptyMass;
        tot *= (i+1);
        res = min(res, tot);
    }

    return res;
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
		cout << "Testing FlightScheduler (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1391174492;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 450.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		FlightScheduler _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int distance = 40000;
				int K = 100000;
				int emptyMass = 150000;
				int takeoffFuel = 5000;
				_expected = 76420.82744805096;
				_received = _obj.minimizeFuel(distance, K, emptyMass, takeoffFuel); break;
			}
			case 1:
			{
				int distance = 40000;
				int K = 55000;
				int emptyMass = 150000;
				int takeoffFuel = 5000;
				_expected = 138450.61724934017;
				_received = _obj.minimizeFuel(distance, K, emptyMass, takeoffFuel); break;
			}
			case 2:
			{
				int distance = 1000;
				int K = 500;
				int emptyMass = 1000;
				int takeoffFuel = 50;
				_expected = 2664.9853821314487;
				_received = _obj.minimizeFuel(distance, K, emptyMass, takeoffFuel); break;
			}
			case 3:
			{
				int distance = 10000;
				int K = 100;
				int emptyMass = 200;
				int takeoffFuel = 5;
				_expected = 24635.869665316768;
				_received = _obj.minimizeFuel(distance, K, emptyMass, takeoffFuel); break;
			}
			case 4:
			{
				int distance = 140000;
				int K = 4;
				int emptyMass = 10000;
				int takeoffFuel = 10;
				_expected = 3.6576871282155204E8;
				_received = _obj.minimizeFuel(distance, K, emptyMass, takeoffFuel); break;
			}
			/*case 5:
			{
				int distance = ;
				int K = ;
				int emptyMass = ;
				int takeoffFuel = ;
				_expected = ;
				_received = _obj.minimizeFuel(distance, K, emptyMass, takeoffFuel); break;
			}*/
			/*case 6:
			{
				int distance = ;
				int K = ;
				int emptyMass = ;
				int takeoffFuel = ;
				_expected = ;
				_received = _obj.minimizeFuel(distance, K, emptyMass, takeoffFuel); break;
			}*/
			/*case 7:
			{
				int distance = ;
				int K = ;
				int emptyMass = ;
				int takeoffFuel = ;
				_expected = ;
				_received = _obj.minimizeFuel(distance, K, emptyMass, takeoffFuel); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

//END CUT HERE
