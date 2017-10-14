
#line 3 "DFSCountEasy.cpp"
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

class DFSCountEasy {
	public:
	long long count(vector <string> G) {
		
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
		cout << "Testing DFSCountEasy (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1508021388;
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
		DFSCountEasy _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string G[] = {"NYY",
				              "YNY",
				              "YYN"};
				_expected = 6LL;
				_received = _obj.count(vector <string>(G, G+sizeof(G)/sizeof(string))); break;
			}
			case 1:
			{
				string G[] = {"NYNN",
				              "YNYN",
				              "NYNY",
				              "NNYN"};
				_expected = 6LL;
				_received = _obj.count(vector <string>(G, G+sizeof(G)/sizeof(string))); break;
			}
			case 2:
			{
				string G[] = {"NYYY",
				              "YNYY",
				              "YYNN",
				              "YYNN"};
				_expected = 16LL;
				_received = _obj.count(vector <string>(G, G+sizeof(G)/sizeof(string))); break;
			}
			case 3:
			{
				string G[] = {"NYYYYYYYYYYYY",
				              "YNYYYYYYYYYYY",
				              "YYNYYYYYYYYYY",
				              "YYYNYYYYYYYYY",
				              "YYYYNYYYYYYYY",
				              "YYYYYNYYYYYYY",
				              "YYYYYYNYYYYYY",
				              "YYYYYYYNYYYYY",
				              "YYYYYYYYNYYYY",
				              "YYYYYYYYYNYYY",
				              "YYYYYYYYYYNYY",
				              "YYYYYYYYYYYNY",
				              "YYYYYYYYYYYYN"};
				_expected = 6227020800LL;
				_received = _obj.count(vector <string>(G, G+sizeof(G)/sizeof(string))); break;
			}
			case 4:
			{
				string G[] = {"N"};
				_expected = 1LL;
				_received = _obj.count(vector <string>(G, G+sizeof(G)/sizeof(string))); break;
			}
			/*case 5:
			{
				string G[] = ;
				_expected = LL;
				_received = _obj.count(vector <string>(G, G+sizeof(G)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string G[] = ;
				_expected = LL;
				_received = _obj.count(vector <string>(G, G+sizeof(G)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string G[] = ;
				_expected = LL;
				_received = _obj.count(vector <string>(G, G+sizeof(G)/sizeof(string))); break;
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
