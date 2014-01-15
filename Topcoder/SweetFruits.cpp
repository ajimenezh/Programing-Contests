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


class SweetFruits {
	public:
	int countTrees(vector <int> sweetness, int maxSweetness) ;
};

int SweetFruits::countTrees(vector <int> sweetness, int maxSweetness) {
		
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
		cout << "Testing SweetFruits (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1383495872;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		SweetFruits _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int sweetness[] = {1, 2, -1, 3};
				int maxSweetness = 3;
				_expected = 3;
				_received = _obj.countTrees(vector <int>(sweetness, sweetness+sizeof(sweetness)/sizeof(int)), maxSweetness); break;
			}
			case 1:
			{
				int sweetness[] = {1, 2, -1, 3};
				int maxSweetness = 5;
				_expected = 7;
				_received = _obj.countTrees(vector <int>(sweetness, sweetness+sizeof(sweetness)/sizeof(int)), maxSweetness); break;
			}
			case 2:
			{
				int sweetness[] = {-1, -1, 2, 5, 5};
				int maxSweetness = 6;
				_expected = 20;
				_received = _obj.countTrees(vector <int>(sweetness, sweetness+sizeof(sweetness)/sizeof(int)), maxSweetness); break;
			}
			case 3:
			{
				int sweetness[] = {2, 6, 8, 4, 1, 10, -1, -1, -1, -1};
				int maxSweetness = 15;
				_expected = 17024000;
				_received = _obj.countTrees(vector <int>(sweetness, sweetness+sizeof(sweetness)/sizeof(int)), maxSweetness); break;
			}
			case 4:
			{
				int sweetness[] = {1078451, -1, 21580110, 8284711, -1, 4202301, 3427559, 8261270, -1, 16176713,
				                  22915672, 24495540, 19236, 5477666, 12280316, 3305896, 17917887, 564911, 22190488, 21843923,
				                  23389728, 14641920, 9590140, 12909561, 20405638, 100184, 23336457, 12780498, 18859535, 23180993,
				                  10278898, 5753075, 21250919, 17563422, 10934412, 22557980, 24895749, 7593671, 10834579, 5606562};
				int maxSweetness = 245243285;
				_expected = 47225123;
				_received = _obj.countTrees(vector <int>(sweetness, sweetness+sizeof(sweetness)/sizeof(int)), maxSweetness); break;
			}
			/*case 5:
			{
				int sweetness[] = ;
				int maxSweetness = ;
				_expected = ;
				_received = _obj.countTrees(vector <int>(sweetness, sweetness+sizeof(sweetness)/sizeof(int)), maxSweetness); break;
			}*/
			/*case 6:
			{
				int sweetness[] = ;
				int maxSweetness = ;
				_expected = ;
				_received = _obj.countTrees(vector <int>(sweetness, sweetness+sizeof(sweetness)/sizeof(int)), maxSweetness); break;
			}*/
			/*case 7:
			{
				int sweetness[] = ;
				int maxSweetness = ;
				_expected = ;
				_received = _obj.countTrees(vector <int>(sweetness, sweetness+sizeof(sweetness)/sizeof(int)), maxSweetness); break;
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
