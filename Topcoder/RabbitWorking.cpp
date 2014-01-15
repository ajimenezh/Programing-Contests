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


class RabbitWorking {
	public:
	double getMaximum(vector <string> profit) ;
};

double RabbitWorking::getMaximum(vector <string> profit) {
		
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
		cout << "Testing RabbitWorking (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1384080733;
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
		RabbitWorking _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string profit[] = { "071", 
				                    "702", 
				                    "120" };
				_expected = 0.017676767676767676;
				_received = _obj.getMaximum(vector <string>(profit, profit+sizeof(profit)/sizeof(string))); break;
			}
			case 1:
			{
				string profit[] = { "061", 
				                    "602", 
				                    "120" };
				_expected = 0.015228426395939087;
				_received = _obj.getMaximum(vector <string>(profit, profit+sizeof(profit)/sizeof(string))); break;
			}
			case 2:
			{
				string profit[] = { "0" };
				_expected = 0.0;
				_received = _obj.getMaximum(vector <string>(profit, profit+sizeof(profit)/sizeof(string))); break;
			}
			case 3:
			{
				string profit[] = { "013040", 
				                    "100010", 
				                    "300060", 
				                    "000008", 
				                    "416000", 
				                    "000800" };
				_expected = 0.021996615905245348;
				_received = _obj.getMaximum(vector <string>(profit, profit+sizeof(profit)/sizeof(string))); break;
			}
			case 4:
			{
				string profit[] = { "06390061", 
				                    "60960062", 
				                    "39090270", 
				                    "96900262", 
				                    "00000212", 
				                    "00222026", 
				                    "66761201", 
				                    "12022610" };
				_expected = 0.06871794871794872;
				_received = _obj.getMaximum(vector <string>(profit, profit+sizeof(profit)/sizeof(string))); break;
			}
			/*case 5:
			{
				string profit[] = ;
				_expected = ;
				_received = _obj.getMaximum(vector <string>(profit, profit+sizeof(profit)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string profit[] = ;
				_expected = ;
				_received = _obj.getMaximum(vector <string>(profit, profit+sizeof(profit)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string profit[] = ;
				_expected = ;
				_received = _obj.getMaximum(vector <string>(profit, profit+sizeof(profit)/sizeof(string))); break;
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
