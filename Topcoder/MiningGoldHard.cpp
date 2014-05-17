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


class MiningGoldHard {
	public:
	int GetMaximumGold(int N, int M, vector <int> event_i, vector <int> event_j, vector <int> event_di, vector <int> event_dj) ;
};

int MiningGoldHard::GetMaximumGold(int N, int M, vector <int> event_i, vector <int> event_j, vector <int> event_di, vector <int> event_dj) {
		
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
		cout << "Testing MiningGoldHard (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393526573;
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
		MiningGoldHard _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 3;
				int M = 3;
				int event_i[] = {1};
				int event_j[] = {1};
				int event_di[] = {};
				int event_dj[] = {};
				_expected = 6;
				_received = _obj.GetMaximumGold(N, M, vector <int>(event_i, event_i+sizeof(event_i)/sizeof(int)), vector <int>(event_j, event_j+sizeof(event_j)/sizeof(int)), vector <int>(event_di, event_di+sizeof(event_di)/sizeof(int)), vector <int>(event_dj, event_dj+sizeof(event_dj)/sizeof(int))); break;
			}
			case 1:
			{
				int N = 3;
				int M = 3;
				int event_i[] = {0, 2};
				int event_j[] = {0, 2};
				int event_di[] = {1};
				int event_dj[] = {1};
				_expected = 10;
				_received = _obj.GetMaximumGold(N, M, vector <int>(event_i, event_i+sizeof(event_i)/sizeof(int)), vector <int>(event_j, event_j+sizeof(event_j)/sizeof(int)), vector <int>(event_di, event_di+sizeof(event_di)/sizeof(int)), vector <int>(event_dj, event_dj+sizeof(event_dj)/sizeof(int))); break;
			}
			case 2:
			{
				int N = 4;
				int M = 2;
				int event_i[] = {1, 4, 4};
				int event_j[] = {1, 2, 0};
				int event_di[] = {1, 1};
				int event_dj[] = {1, 1};
				_expected = 15;
				_received = _obj.GetMaximumGold(N, M, vector <int>(event_i, event_i+sizeof(event_i)/sizeof(int)), vector <int>(event_j, event_j+sizeof(event_j)/sizeof(int)), vector <int>(event_di, event_di+sizeof(event_di)/sizeof(int)), vector <int>(event_dj, event_dj+sizeof(event_dj)/sizeof(int))); break;
			}
			case 3:
			{
				int N = 6;
				int M = 6;
				int event_i[] = {0, 2, 1, 5, 6, 4};
				int event_j[] = {4, 3, 1, 6, 2, 0};
				int event_di[] = {2, 3, 1, 5, 6};
				int event_dj[] = {2, 4, 0, 5, 1};
				_expected = 63;
				_received = _obj.GetMaximumGold(N, M, vector <int>(event_i, event_i+sizeof(event_i)/sizeof(int)), vector <int>(event_j, event_j+sizeof(event_j)/sizeof(int)), vector <int>(event_di, event_di+sizeof(event_di)/sizeof(int)), vector <int>(event_dj, event_dj+sizeof(event_dj)/sizeof(int))); break;
			}
			case 4:
			{
				int N = 72;
				int M = 90;
				int event_i[] = {9, 9, 42, 64, 37, 4, 67, 65, 20, 18, 25, 45, 19, 57, 34, 29, 20, 43, 17, 46, 61, 1, 18, 53, 54, 23, 9, 69, 57, 44, 34, 50, 37, 4, 26, 1, 8, 4, 66};
				int event_j[] = {37, 47, 48, 69, 56, 22, 40, 52, 43, 46, 64, 24, 48, 54, 54, 56, 32, 77, 50, 8, 7, 90, 55, 34, 40, 89, 57, 44, 21, 59, 89, 21, 69, 46, 0, 89, 31, 3, 50};
				int event_di[] = {56, 5, 21, 5, 22, 5, 45, 4, 44, 20, 68, 63, 37, 14, 43, 31, 70, 28, 51, 38, 20, 59, 72, 66, 16, 20, 39, 72, 11, 71, 21, 51, 60, 42, 40, 10, 32, 70};
				int event_dj[] = {77, 73, 42, 80, 43, 24, 81, 68, 40, 86, 1, 76, 43, 10, 43, 53, 40, 26, 18, 70, 60, 68, 29, 17, 66, 2, 87, 71, 90, 33, 11, 76, 69, 17, 65, 21, 4, 19};
				_expected = 5810;
				_received = _obj.GetMaximumGold(N, M, vector <int>(event_i, event_i+sizeof(event_i)/sizeof(int)), vector <int>(event_j, event_j+sizeof(event_j)/sizeof(int)), vector <int>(event_di, event_di+sizeof(event_di)/sizeof(int)), vector <int>(event_dj, event_dj+sizeof(event_dj)/sizeof(int))); break;
			}
			/*case 5:
			{
				int N = ;
				int M = ;
				int event_i[] = ;
				int event_j[] = ;
				int event_di[] = ;
				int event_dj[] = ;
				_expected = ;
				_received = _obj.GetMaximumGold(N, M, vector <int>(event_i, event_i+sizeof(event_i)/sizeof(int)), vector <int>(event_j, event_j+sizeof(event_j)/sizeof(int)), vector <int>(event_di, event_di+sizeof(event_di)/sizeof(int)), vector <int>(event_dj, event_dj+sizeof(event_dj)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int N = ;
				int M = ;
				int event_i[] = ;
				int event_j[] = ;
				int event_di[] = ;
				int event_dj[] = ;
				_expected = ;
				_received = _obj.GetMaximumGold(N, M, vector <int>(event_i, event_i+sizeof(event_i)/sizeof(int)), vector <int>(event_j, event_j+sizeof(event_j)/sizeof(int)), vector <int>(event_di, event_di+sizeof(event_di)/sizeof(int)), vector <int>(event_dj, event_dj+sizeof(event_dj)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int N = ;
				int M = ;
				int event_i[] = ;
				int event_j[] = ;
				int event_di[] = ;
				int event_dj[] = ;
				_expected = ;
				_received = _obj.GetMaximumGold(N, M, vector <int>(event_i, event_i+sizeof(event_i)/sizeof(int)), vector <int>(event_j, event_j+sizeof(event_j)/sizeof(int)), vector <int>(event_di, event_di+sizeof(event_di)/sizeof(int)), vector <int>(event_dj, event_dj+sizeof(event_dj)/sizeof(int))); break;
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
