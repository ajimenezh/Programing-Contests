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


class KingdomReorganization {
	public:
	int getCost(vector <string> kingdom, vector <string> build, vector <string> destroy) ;
};

int KingdomReorganization::getCost(vector <string> kingdom, vector <string> build, vector <string> destroy) {
		
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
		cout << "Testing KingdomReorganization (950.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1384449180;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 950.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		KingdomReorganization _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string kingdom[] = {"000","000","000"};
				string build[] = {"ABD","BAC","DCA"};
				string destroy[] = {"ABD","BAC","DCA"};
				_expected = 3;
				_received = _obj.getCost(vector <string>(kingdom, kingdom+sizeof(kingdom)/sizeof(string)), vector <string>(build, build+sizeof(build)/sizeof(string)), vector <string>(destroy, destroy+sizeof(destroy)/sizeof(string))); break;
			}
			case 1:
			{
				string kingdom[] = {"011","101","110"};
				string build[] = {"ABD","BAC","DCA"};
				string destroy[] = {"ABD","BAC","DCA"};
				_expected = 1;
				_received = _obj.getCost(vector <string>(kingdom, kingdom+sizeof(kingdom)/sizeof(string)), vector <string>(build, build+sizeof(build)/sizeof(string)), vector <string>(destroy, destroy+sizeof(destroy)/sizeof(string))); break;
			}
			case 2:
			{
				string kingdom[] = {"011000","101000","110000","000011","000101","000110"};
				string build[] = {"ABDFFF","BACFFF","DCAFFF","FFFABD","FFFBAC","FFFDCA"};
				string destroy[] = {"ABDFFF","BACFFF","DCAFFF","FFFABD","FFFBAC","FFFDCA"};
				_expected = 7;
				_received = _obj.getCost(vector <string>(kingdom, kingdom+sizeof(kingdom)/sizeof(string)), vector <string>(build, build+sizeof(build)/sizeof(string)), vector <string>(destroy, destroy+sizeof(destroy)/sizeof(string))); break;
			}
			case 3:
			{
				string kingdom[] = {"0"};
				string build[] = {"A"};
				string destroy[] = {"A"};
				_expected = 0;
				_received = _obj.getCost(vector <string>(kingdom, kingdom+sizeof(kingdom)/sizeof(string)), vector <string>(build, build+sizeof(build)/sizeof(string)), vector <string>(destroy, destroy+sizeof(destroy)/sizeof(string))); break;
			}
			case 4:
			{
				string kingdom[] = {"0001","0001","0001","1110"};
				string build[] = {"AfOj","fAcC","OcAP","jCPA"};
				string destroy[] = {"AWFH","WAxU","FxAV","HUVA"};
				_expected = 0;
				_received = _obj.getCost(vector <string>(kingdom, kingdom+sizeof(kingdom)/sizeof(string)), vector <string>(build, build+sizeof(build)/sizeof(string)), vector <string>(destroy, destroy+sizeof(destroy)/sizeof(string))); break;
			}
			case 5:
			{
				string kingdom[] = {"0000000000","0000000011","0001010000","0010010000","0000001000","0011000000","0000100000","0000000011","0100000101","0100000110"};
				string build[] = {"AhPEqkSFMM","hAfKPtsDad","PfAyGQkaqN","EKyAeLpRpm","qPGeASfNwo","ktQLSAnCAK","SskpfnAdJS","FDaRNCdAZz","MaqpwAJZAn","MdNmoKSznA"};
				string destroy[] = {"AgTqWWxEYH","gAXPgjzIRA","TXAleTmWvT","qPlAQkwxRO","WgeQAqgbJJ","WjTkqAiTzl","xzmwgiAuHb","EIWxbTuAwk","YRvRJzHwAn","HATOJlbknA"};
				_expected = 65;
				_received = _obj.getCost(vector <string>(kingdom, kingdom+sizeof(kingdom)/sizeof(string)), vector <string>(build, build+sizeof(build)/sizeof(string)), vector <string>(destroy, destroy+sizeof(destroy)/sizeof(string))); break;
			}
			/*case 6:
			{
				string kingdom[] = ;
				string build[] = ;
				string destroy[] = ;
				_expected = ;
				_received = _obj.getCost(vector <string>(kingdom, kingdom+sizeof(kingdom)/sizeof(string)), vector <string>(build, build+sizeof(build)/sizeof(string)), vector <string>(destroy, destroy+sizeof(destroy)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string kingdom[] = ;
				string build[] = ;
				string destroy[] = ;
				_expected = ;
				_received = _obj.getCost(vector <string>(kingdom, kingdom+sizeof(kingdom)/sizeof(string)), vector <string>(build, build+sizeof(build)/sizeof(string)), vector <string>(destroy, destroy+sizeof(destroy)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string kingdom[] = ;
				string build[] = ;
				string destroy[] = ;
				_expected = ;
				_received = _obj.getCost(vector <string>(kingdom, kingdom+sizeof(kingdom)/sizeof(string)), vector <string>(build, build+sizeof(build)/sizeof(string)), vector <string>(destroy, destroy+sizeof(destroy)/sizeof(string))); break;
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
