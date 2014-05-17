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


class ReverseDistance {
	public:
	string find(int difference) ;
};

int reverse(int a) {
    vector<int> v;
    int k = 1;
    while (a>0) {
        v.push_back(a%10);
        k *= 10;
        a /= 10;
    }
    k /= 10;
    int tot = 0;
    for (int i=0; i<v.size(); i++) {tot += v[i]*k; k /= 10;}
    return tot;
}

string ReverseDistance::find(int difference) {
    int d = difference;
	for (int i=1; i<=1000000; i++) {
        if (i-reverse(i)==d) {
            cout<<i<<endl;
            break;
        }
	}
	return "";
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
		cout << "Testing ReverseDistance (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393793515;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ReverseDistance _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int difference = 0;
				_expected = "20";
				_received = _obj.find(difference); break;
			}
			case 1:
			{
				int difference = 15;
				_expected = "NONE";
				_received = _obj.find(difference); break;
			}
			case 2:
			{
				int difference = 4275;
				_expected = "5080";
				_received = _obj.find(difference); break;
			}
			case 3:
			{
				int difference = 900;
				_expected = "101001";
				_received = _obj.find(difference); break;
			}
			case 4:
			{
				int difference = 1989;
				_expected = "100990";
				_received = _obj.find(difference); break;
			}
			case 5:
			{
				int difference = 857232;
				_expected = "860300";
				_received = _obj.find(difference); break;
			}
			case 6:
			{
				int difference = 45;
				_expected = "50";
				_received = _obj.find(difference); break;
			}
			/*case 7:
			{
				int difference = ;
				_expected = ;
				_received = _obj.find(difference); break;
			}*/
			/*case 8:
			{
				int difference = ;
				_expected = ;
				_received = _obj.find(difference); break;
			}*/
			/*case 9:
			{
				int difference = ;
				_expected = ;
				_received = _obj.find(difference); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

//END CUT HERE
