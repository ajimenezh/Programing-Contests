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


class PerforatedSheet {
	public:
	vector <double> getCenterOfMass(int sheetWidth, int sheetHeight, vector <int> x, vector <int> y, vector <int> width, vector <int> height) ;
};

vector <double> PerforatedSheet::getCenterOfMass(int sheetWidth, int sheetHeight, vector <int> x, vector <int> y, vector <int> width, vector <int> height) {
		
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
		cout << "Testing PerforatedSheet (400.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1379780017;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 400.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		PerforatedSheet _obj;
		vector <double> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int sheetWidth = 5;
				int sheetHeight = 10;
				int x[] = {};
				int y[] = {};
				int width[] = {};
				int height[] = {};
				double __expected[] = {2.5, 5.0 };
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.getCenterOfMass(sheetWidth, sheetHeight, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(height, height+sizeof(height)/sizeof(int))); break;
			}
			case 1:
			{
				int sheetWidth = 10;
				int sheetHeight = 5;
				int x[] = {0, 1};
				int y[] = {0, 0};
				int width[] = {1, 9};
				int height[] = {5, 1};
				double __expected[] = {5.5, 3.0 };
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.getCenterOfMass(sheetWidth, sheetHeight, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(height, height+sizeof(height)/sizeof(int))); break;
			}
			case 2:
			{
				int sheetWidth = 5;
				int sheetHeight = 5;
				int x[] = {1};
				int y[] = {1};
				int width[] = {1};
				int height[] = {1};
				double __expected[] = {2.5416666666666665, 2.5416666666666665 };
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.getCenterOfMass(sheetWidth, sheetHeight, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(height, height+sizeof(height)/sizeof(int))); break;
			}
			case 3:
			{
				int sheetWidth = 822741;
				int sheetHeight = 110524;
				int x[] = {335076, 665632, 210102, 714135, 229942, 149776, 675634, 502085, 393066, 115215,
				          80993, 272343, 434287, 593760, 589713, 485801, 395389, 755380, 417327, 477023};
				int y[] = {104509, 23182, 103471, 62180, 5040, 10186, 45286, 107985, 36936, 87885,
				          63846, 58794, 89480, 85195, 64703, 96341, 89224, 7727, 71438, 39128};
				int width[] = {24578, 20552, 3332, 254, 21489, 21158, 35061, 37453, 21881, 216,
				              32930, 31555, 5121, 36687, 6949, 3512, 8049, 30019, 37252, 8001};
				int height[] = {2240, 3152, 4625, 3508, 4206, 5262, 1750, 627, 3983, 3192,
				               3609, 3361, 1135, 2580, 4158, 1356, 583, 5408, 5521, 2742};
				double __expected[] = {411084.49564976187, 55331.97175632337 };
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.getCenterOfMass(sheetWidth, sheetHeight, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(height, height+sizeof(height)/sizeof(int))); break;
			}
			case 4:
			{
				int sheetWidth = 1234567;
				int sheetHeight = 314159;
				int x[] = {0};
				int y[] = {0};
				int width[] = {1234567};
				int height[] = {314159};
				double __expected[] = { };
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.getCenterOfMass(sheetWidth, sheetHeight, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(height, height+sizeof(height)/sizeof(int))); break;
			}
			case 5:
			{
				int sheetWidth = 2000000;
				int sheetHeight = 2000000;
				int x[] = {1, 0};
				int y[] = {0, 1};
				int width[] = {1999999, 1};
				int height[] = {2000000, 1999999};
				double __expected[] = {0.5, 0.5 };
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.getCenterOfMass(sheetWidth, sheetHeight, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(height, height+sizeof(height)/sizeof(int))); break;
			}
			/*case 6:
			{
				int sheetWidth = ;
				int sheetHeight = ;
				int x[] = ;
				int y[] = ;
				int width[] = ;
				int height[] = ;
				double __expected[] = ;
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.getCenterOfMass(sheetWidth, sheetHeight, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(height, height+sizeof(height)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int sheetWidth = ;
				int sheetHeight = ;
				int x[] = ;
				int y[] = ;
				int width[] = ;
				int height[] = ;
				double __expected[] = ;
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.getCenterOfMass(sheetWidth, sheetHeight, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(height, height+sizeof(height)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int sheetWidth = ;
				int sheetHeight = ;
				int x[] = ;
				int y[] = ;
				int width[] = ;
				int height[] = ;
				double __expected[] = ;
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.getCenterOfMass(sheetWidth, sheetHeight, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(height, height+sizeof(height)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		bool _passed = _expected.size() == _received.size();
		for (unsigned i = 0; i < _received.size(); i++)
			_passed = _passed && (abs(_expected[i]-_received[i]) < 1e-9 || (_received[i] > min(_expected[i]*(1.0-1e-9), _expected[i]*(1.0+1e-9)) && _received[i] < max(_expected[i]*(1.0-1e-9), _expected[i]*(1.0+1e-9))));
		if (_passed)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

//END CUT HERE
