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


class DrawingMarbles {
	public:
	double sameColor(vector <int> colors, int n) ;
};

double DrawingMarbles::sameColor(vector <int> colors, int n) {
	double p = 0.0;
	int tot = 0;
	for (int i=0; i<colors.size(); i++) tot += colors[i];
	for (int i=0; i<colors.size(); i++) {
        double tmp = 1.0;
        if (colors[i]>=n) {
            for (int j=0; j<n; j++) tmp = tmp*(colors[i]-j)/(tot-j);
            p += tmp;
        }
	}
	return p;
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
		cout << "Testing DrawingMarbles (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1394279064;
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
		DrawingMarbles _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int colors[] = { 13 };
				int n = 8;
				_expected = 1.0;
				_received = _obj.sameColor(vector <int>(colors, colors+sizeof(colors)/sizeof(int)), n); break;
			}
			case 1:
			{
				int colors[] = { 5, 7 };
				int n = 1;
				_expected = 1.0;
				_received = _obj.sameColor(vector <int>(colors, colors+sizeof(colors)/sizeof(int)), n); break;
			}
			case 2:
			{
				int colors[] = { 5, 6, 7 };
				int n = 2;
				_expected = 0.3006535947712418;
				_received = _obj.sameColor(vector <int>(colors, colors+sizeof(colors)/sizeof(int)), n); break;
			}
			case 3:
			{
				int colors[] = { 12, 2, 34, 13, 17 };
				int n = 4;
				_expected = 0.035028830818304504;
				_received = _obj.sameColor(vector <int>(colors, colors+sizeof(colors)/sizeof(int)), n); break;
			}
			/*case 4:
			{
				int colors[] = ;
				int n = ;
				_expected = ;
				_received = _obj.sameColor(vector <int>(colors, colors+sizeof(colors)/sizeof(int)), n); break;
			}*/
			/*case 5:
			{
				int colors[] = ;
				int n = ;
				_expected = ;
				_received = _obj.sameColor(vector <int>(colors, colors+sizeof(colors)/sizeof(int)), n); break;
			}*/
			/*case 6:
			{
				int colors[] = ;
				int n = ;
				_expected = ;
				_received = _obj.sameColor(vector <int>(colors, colors+sizeof(colors)/sizeof(int)), n); break;
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
