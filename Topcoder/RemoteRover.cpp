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


class RemoteRover {
	public:
	double optimalTravel(vector <int> width, vector <int> speed, int offset) ;
};

double RemoteRover::optimalTravel(vector <int> width, vector <int> speed, int offset) {
		double t = 0.0;

		int sum = 0;
		int n = speed.size();
		for (int i=0; i<n; i++) sum += speed[i];

		for (int i=0; i<n; i++) {
            double x = (double)offset*speed[i]/sum;
            t += sqrt(x*x + width[i]*width[i])/speed[i];
		}
		return t;
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
		cout << "Testing RemoteRover (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1379780186;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 900.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		RemoteRover _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int width[] = {100, 300, 200};
				int speed[] = {100, 50, 75};
				int offset = 1000;
				_expected = 17.042083785318038;
				_received = _obj.optimalTravel(vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(speed, speed+sizeof(speed)/sizeof(int)), offset); break;
			}
			case 1:
			{
				int width[] = {1155, 6184, 2783, 7540, 8156};
				int speed[] = {570, 810, 875, 172, 642};
				int offset = 0;
				_expected = 69.38271426584203;
				_received = _obj.optimalTravel(vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(speed, speed+sizeof(speed)/sizeof(int)), offset); break;
			}
			case 2:
			{
				int width[] = {5000};
				int speed[] = {50};
				int offset = 10000;
				_expected = 223.60679774997894;
				_received = _obj.optimalTravel(vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(speed, speed+sizeof(speed)/sizeof(int)), offset); break;
			}
			case 3:
			{
				int width[] = {9033, 8232, 8842, 6518, 2358, 1115, 941, 928, 220, 8460};
				int speed[] = {50, 50, 50, 50, 50, 50, 50, 50, 50, 50};
				int offset = 10000;
				_expected = 954.1368054948935;
				_received = _obj.optimalTravel(vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(speed, speed+sizeof(speed)/sizeof(int)), offset); break;
			}
			case 4:
			{
				int width[] = {9236, 7065, 2283, 506, 6432, 9812, 3133, 1397, 7052, 3729,
				              2556, 9954, 1367, 6440, 5141, 3091, 2879, 1346, 7080, 1036,
				              7503, 7775, 433, 7579, 6520, 2287, 1971, 3879, 1725, 8200,
				              1830, 2774, 3850, 7509, 8531, 7493, 1511, 9399, 9679, 2124,
				              791, 3432};
				int speed[] = {956, 799, 481, 194, 993, 444, 571, 986, 815, 910,
				              98, 847, 650, 487, 419, 434, 410, 812, 374, 751,
				              307, 134, 134, 955, 758, 73, 932, 360, 135, 588,
				              218, 936, 674, 494, 157, 556, 881, 292, 851, 890,
				              886, 912};
				int offset = 9756;
				_expected = 501.6129192127166;
				_received = _obj.optimalTravel(vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(speed, speed+sizeof(speed)/sizeof(int)), offset); break;
			}
			/*case 5:
			{
				int width[] = ;
				int speed[] = ;
				int offset = ;
				_expected = ;
				_received = _obj.optimalTravel(vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(speed, speed+sizeof(speed)/sizeof(int)), offset); break;
			}*/
			/*case 6:
			{
				int width[] = ;
				int speed[] = ;
				int offset = ;
				_expected = ;
				_received = _obj.optimalTravel(vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(speed, speed+sizeof(speed)/sizeof(int)), offset); break;
			}*/
			/*case 7:
			{
				int width[] = ;
				int speed[] = ;
				int offset = ;
				_expected = ;
				_received = _obj.optimalTravel(vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(speed, speed+sizeof(speed)/sizeof(int)), offset); break;
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
