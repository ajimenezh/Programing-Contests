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


class MergersDivOne {
	public:
	double findMaximum(vector <int> revenues) ;
};

double MergersDivOne::findMaximum(vector <int> revenues) {
	vector<int> v;
	priority_queue<double> q;
	for (int i=0; i<revenues.size(); i++) {
        q.push(-revenues[i]);
	}

	while (q.size()>1) {
        double p1 = q.top();
        q.pop();
        double p2 = q.top();
        q.pop();
        q.push((p1+p2)/2.0);
	}

	return -q.top();
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
		cout << "Testing MergersDivOne (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1384194578;
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
		MergersDivOne _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int revenues[] = {5, -7, 3};
				_expected = 1.5;
				_received = _obj.findMaximum(vector <int>(revenues, revenues+sizeof(revenues)/sizeof(int))); break;
			}
			case 1:
			{
				int revenues[] = {10, -17};
				_expected = -3.5;
				_received = _obj.findMaximum(vector <int>(revenues, revenues+sizeof(revenues)/sizeof(int))); break;
			}
			case 2:
			{
				int revenues[] = {12, 12, 12, 12, 12};
				_expected = 12.0;
				_received = _obj.findMaximum(vector <int>(revenues, revenues+sizeof(revenues)/sizeof(int))); break;
			}
			case 3:
			{
				int revenues[] = {0, 0, 0, 0, 0, 100};
				_expected = 50.0;
				_received = _obj.findMaximum(vector <int>(revenues, revenues+sizeof(revenues)/sizeof(int))); break;
			}
			case 4:
			{
				int revenues[] = {10, -10, 100, -100, 1000, -1000};
				_expected = 491.25;
				_received = _obj.findMaximum(vector <int>(revenues, revenues+sizeof(revenues)/sizeof(int))); break;
			}
			/*case 5:
			{
				int revenues[] = ;
				_expected = ;
				_received = _obj.findMaximum(vector <int>(revenues, revenues+sizeof(revenues)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int revenues[] = ;
				_expected = ;
				_received = _obj.findMaximum(vector <int>(revenues, revenues+sizeof(revenues)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int revenues[] = ;
				_expected = ;
				_received = _obj.findMaximum(vector <int>(revenues, revenues+sizeof(revenues)/sizeof(int))); break;
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
