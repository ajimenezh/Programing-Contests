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


class PointyWizardHats {
	public:
	int getNumHats(vector <int> topHeight, vector <int> topRadius, vector <int> bottomHeight, vector <int> bottomRadius) ;
};

int PointyWizardHats::getNumHats(vector <int> topHeight, vector <int> topRadius, vector <int> bottomHeight, vector <int> bottomRadius) {
		
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
		cout << "Testing PointyWizardHats (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1383506001;
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
		PointyWizardHats _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int topHeight[] = {30};
				int topRadius[] = {3};
				int bottomHeight[] = {3};
				int bottomRadius[] = {30};
				_expected = 1;
				_received = _obj.getNumHats(vector <int>(topHeight, topHeight+sizeof(topHeight)/sizeof(int)), vector <int>(topRadius, topRadius+sizeof(topRadius)/sizeof(int)), vector <int>(bottomHeight, bottomHeight+sizeof(bottomHeight)/sizeof(int)), vector <int>(bottomRadius, bottomRadius+sizeof(bottomRadius)/sizeof(int))); break;
			}
			case 1:
			{
				int topHeight[] = {4,4};
				int topRadius[] = {4,3};
				int bottomHeight[] = {5,12};
				int bottomRadius[] = {5,4};
				_expected = 1;
				_received = _obj.getNumHats(vector <int>(topHeight, topHeight+sizeof(topHeight)/sizeof(int)), vector <int>(topRadius, topRadius+sizeof(topRadius)/sizeof(int)), vector <int>(bottomHeight, bottomHeight+sizeof(bottomHeight)/sizeof(int)), vector <int>(bottomRadius, bottomRadius+sizeof(bottomRadius)/sizeof(int))); break;
			}
			case 2:
			{
				int topHeight[] = {3};
				int topRadius[] = {3};
				int bottomHeight[] = {1,1};
				int bottomRadius[] = {2,4};
				_expected = 1;
				_received = _obj.getNumHats(vector <int>(topHeight, topHeight+sizeof(topHeight)/sizeof(int)), vector <int>(topRadius, topRadius+sizeof(topRadius)/sizeof(int)), vector <int>(bottomHeight, bottomHeight+sizeof(bottomHeight)/sizeof(int)), vector <int>(bottomRadius, bottomRadius+sizeof(bottomRadius)/sizeof(int))); break;
			}
			case 3:
			{
				int topHeight[] = {10,10};
				int topRadius[] = {2,5};
				int bottomHeight[] = {2,9};
				int bottomRadius[] = {3,6};
				_expected = 2;
				_received = _obj.getNumHats(vector <int>(topHeight, topHeight+sizeof(topHeight)/sizeof(int)), vector <int>(topRadius, topRadius+sizeof(topRadius)/sizeof(int)), vector <int>(bottomHeight, bottomHeight+sizeof(bottomHeight)/sizeof(int)), vector <int>(bottomRadius, bottomRadius+sizeof(bottomRadius)/sizeof(int))); break;
			}
			case 4:
			{
				int topHeight[] = {3,4,5};
				int topRadius[] = {5,4,3};
				int bottomHeight[] = {3,4,5};
				int bottomRadius[] = {3,8,5};
				_expected = 2;
				_received = _obj.getNumHats(vector <int>(topHeight, topHeight+sizeof(topHeight)/sizeof(int)), vector <int>(topRadius, topRadius+sizeof(topRadius)/sizeof(int)), vector <int>(bottomHeight, bottomHeight+sizeof(bottomHeight)/sizeof(int)), vector <int>(bottomRadius, bottomRadius+sizeof(bottomRadius)/sizeof(int))); break;
			}
			case 5:
			{
				int topHeight[] = {1,2,3,4,5};
				int topRadius[] = {2,3,4,5,6};
				int bottomHeight[] = {2,3,4,5,6};
				int bottomRadius[] = {1,2,3,4,5};
				_expected = 0;
				_received = _obj.getNumHats(vector <int>(topHeight, topHeight+sizeof(topHeight)/sizeof(int)), vector <int>(topRadius, topRadius+sizeof(topRadius)/sizeof(int)), vector <int>(bottomHeight, bottomHeight+sizeof(bottomHeight)/sizeof(int)), vector <int>(bottomRadius, bottomRadius+sizeof(bottomRadius)/sizeof(int))); break;
			}
			case 6:
			{
				int topHeight[] = {123,214,232,323,342,343};
				int topRadius[] = {123,123,232,123,323,434};
				int bottomHeight[] = {545,322,123,545,777,999};
				int bottomRadius[] = {323,443,123,656,767,888};
				_expected = 5;
				_received = _obj.getNumHats(vector <int>(topHeight, topHeight+sizeof(topHeight)/sizeof(int)), vector <int>(topRadius, topRadius+sizeof(topRadius)/sizeof(int)), vector <int>(bottomHeight, bottomHeight+sizeof(bottomHeight)/sizeof(int)), vector <int>(bottomRadius, bottomRadius+sizeof(bottomRadius)/sizeof(int))); break;
			}
			case 7:
			{
				int topHeight[] = {999,999,999,10000,10000,10000};
				int topRadius[] = {10000,10000,10000,1,2,3};
				int bottomHeight[] = {2324,2323,234,5454,323,232};
				int bottomRadius[] = {1,2,3222,434,5454,23};
				_expected = 3;
				_received = _obj.getNumHats(vector <int>(topHeight, topHeight+sizeof(topHeight)/sizeof(int)), vector <int>(topRadius, topRadius+sizeof(topRadius)/sizeof(int)), vector <int>(bottomHeight, bottomHeight+sizeof(bottomHeight)/sizeof(int)), vector <int>(bottomRadius, bottomRadius+sizeof(bottomRadius)/sizeof(int))); break;
			}
			/*case 8:
			{
				int topHeight[] = ;
				int topRadius[] = ;
				int bottomHeight[] = ;
				int bottomRadius[] = ;
				_expected = ;
				_received = _obj.getNumHats(vector <int>(topHeight, topHeight+sizeof(topHeight)/sizeof(int)), vector <int>(topRadius, topRadius+sizeof(topRadius)/sizeof(int)), vector <int>(bottomHeight, bottomHeight+sizeof(bottomHeight)/sizeof(int)), vector <int>(bottomRadius, bottomRadius+sizeof(bottomRadius)/sizeof(int))); break;
			}*/
			/*case 9:
			{
				int topHeight[] = ;
				int topRadius[] = ;
				int bottomHeight[] = ;
				int bottomRadius[] = ;
				_expected = ;
				_received = _obj.getNumHats(vector <int>(topHeight, topHeight+sizeof(topHeight)/sizeof(int)), vector <int>(topRadius, topRadius+sizeof(topRadius)/sizeof(int)), vector <int>(bottomHeight, bottomHeight+sizeof(bottomHeight)/sizeof(int)), vector <int>(bottomRadius, bottomRadius+sizeof(bottomRadius)/sizeof(int))); break;
			}*/
			/*case 10:
			{
				int topHeight[] = ;
				int topRadius[] = ;
				int bottomHeight[] = ;
				int bottomRadius[] = ;
				_expected = ;
				_received = _obj.getNumHats(vector <int>(topHeight, topHeight+sizeof(topHeight)/sizeof(int)), vector <int>(topRadius, topRadius+sizeof(topRadius)/sizeof(int)), vector <int>(bottomHeight, bottomHeight+sizeof(bottomHeight)/sizeof(int)), vector <int>(bottomRadius, bottomRadius+sizeof(bottomRadius)/sizeof(int))); break;
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
