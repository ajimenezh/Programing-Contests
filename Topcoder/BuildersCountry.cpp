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


class BuildersCountry {
	public:
	long long minCost(vector <int> before, vector <int> after, vector <int> houseCost, vector <string> g, int roadCost) ;
};

long long BuildersCountry::minCost(vector <int> before, vector <int> after, vector <int> houseCost, vector <string> g, int roadCost) {
		
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
		cout << "Testing BuildersCountry (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396962521;
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
		BuildersCountry _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int before[] = {2, 1, 3, 5};
				int after[] = {2, 1, 3, 5};
				int houseCost[] = {4, 5, 3, 2};
				string g[] = {"NNNN", "NNNN", "NNNN", "NNNN"};
				int roadCost = 1000;
				_expected = 13000LL;
				_received = _obj.minCost(vector <int>(before, before+sizeof(before)/sizeof(int)), vector <int>(after, after+sizeof(after)/sizeof(int)), vector <int>(houseCost, houseCost+sizeof(houseCost)/sizeof(int)), vector <string>(g, g+sizeof(g)/sizeof(string)), roadCost); break;
			}
			case 1:
			{
				int before[] = {1, 1, 1, 1};
				int after[] = {1, 3, 1, 2};
				int houseCost[] = {8, 5, 3, 2};
				string g[] = {"NYNN", "YNYN", "NYNY", "NNYN"};
				int roadCost = 100000;
				_expected = 39LL;
				_received = _obj.minCost(vector <int>(before, before+sizeof(before)/sizeof(int)), vector <int>(after, after+sizeof(after)/sizeof(int)), vector <int>(houseCost, houseCost+sizeof(houseCost)/sizeof(int)), vector <string>(g, g+sizeof(g)/sizeof(string)), roadCost); break;
			}
			case 2:
			{
				int before[] = {9, 11};
				int after[] = {10, 11};
				int houseCost[] = {5, 1};
				string g[] = {"NN", "NN"};
				int roadCost = 15;
				_expected = 400LL;
				_received = _obj.minCost(vector <int>(before, before+sizeof(before)/sizeof(int)), vector <int>(after, after+sizeof(after)/sizeof(int)), vector <int>(houseCost, houseCost+sizeof(houseCost)/sizeof(int)), vector <string>(g, g+sizeof(g)/sizeof(string)), roadCost); break;
			}
			case 3:
			{
				int before[] = {1};
				int after[] = {1000};
				int houseCost[] = {2};
				string g[] = {"N"};
				int roadCost = 888;
				_expected = 999000LL;
				_received = _obj.minCost(vector <int>(before, before+sizeof(before)/sizeof(int)), vector <int>(after, after+sizeof(after)/sizeof(int)), vector <int>(houseCost, houseCost+sizeof(houseCost)/sizeof(int)), vector <string>(g, g+sizeof(g)/sizeof(string)), roadCost); break;
			}
			case 4:
			{
				int before[] = {99, 23, 44, 55, 32};
				int after[] = {99, 23, 44, 55, 32};
				int houseCost[] = {39, 32, 11, 23, 89};
				string g[] = {"NYNNN", "YNNNY", "NNNYY", "NNYNY", "NYYYN"};
				int roadCost = 54;
				_expected = 0LL;
				_received = _obj.minCost(vector <int>(before, before+sizeof(before)/sizeof(int)), vector <int>(after, after+sizeof(after)/sizeof(int)), vector <int>(houseCost, houseCost+sizeof(houseCost)/sizeof(int)), vector <string>(g, g+sizeof(g)/sizeof(string)), roadCost); break;
			}
			/*case 5:
			{
				int before[] = ;
				int after[] = ;
				int houseCost[] = ;
				string g[] = ;
				int roadCost = ;
				_expected = LL;
				_received = _obj.minCost(vector <int>(before, before+sizeof(before)/sizeof(int)), vector <int>(after, after+sizeof(after)/sizeof(int)), vector <int>(houseCost, houseCost+sizeof(houseCost)/sizeof(int)), vector <string>(g, g+sizeof(g)/sizeof(string)), roadCost); break;
			}*/
			/*case 6:
			{
				int before[] = ;
				int after[] = ;
				int houseCost[] = ;
				string g[] = ;
				int roadCost = ;
				_expected = LL;
				_received = _obj.minCost(vector <int>(before, before+sizeof(before)/sizeof(int)), vector <int>(after, after+sizeof(after)/sizeof(int)), vector <int>(houseCost, houseCost+sizeof(houseCost)/sizeof(int)), vector <string>(g, g+sizeof(g)/sizeof(string)), roadCost); break;
			}*/
			/*case 7:
			{
				int before[] = ;
				int after[] = ;
				int houseCost[] = ;
				string g[] = ;
				int roadCost = ;
				_expected = LL;
				_received = _obj.minCost(vector <int>(before, before+sizeof(before)/sizeof(int)), vector <int>(after, after+sizeof(after)/sizeof(int)), vector <int>(houseCost, houseCost+sizeof(houseCost)/sizeof(int)), vector <string>(g, g+sizeof(g)/sizeof(string)), roadCost); break;
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
