
#line 3 "LexmaxReplace.cpp"
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

class LexmaxReplace {
	public:
	string get(string s, string t) {

		sort(t.begin(), t.end());
		reverse(t.begin(), t.end());

		int i = 0;
		for (int j=0; j<t.size(); j++) {

            while (i < s.size() && s[i]>=t[j]) i++;

            if (i < s.size() && s[i]<t[j]) {
                s[i] = t[j];
                i++;
            }

		}

		return s;
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
		cout << "Testing LexmaxReplace (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1507933610;
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
		LexmaxReplace _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s = "abb";
				string t = "c";
				_expected = "cbb";
				_received = _obj.get(s, t); break;
			}
			case 1:
			{
				string s = "z";
				string t = "f";
				_expected = "z";
				_received = _obj.get(s, t); break;
			}
			case 2:
			{
				string s = "fedcba";
				string t = "ee";
				_expected = "feeeba";
				_received = _obj.get(s, t); break;
			}
			case 3:
			{
				string s = "top";
				string t = "coder";
				_expected = "trp";
				_received = _obj.get(s, t); break;
			}
			case 4:
			{
				string s = "xldyzmsrrwzwaofkcxwehgvtrsximxgdqrhjthkgfucrjdvwlr";
				string t = "xfpidmmilhdfzypbguentqcojivertdhshstkcysydgcwuwhlk";
				_expected = "zyyyzyxwwwzwvuuttxwtssvtssxrqxppqrontmmllukrkjvwlr";
				_received = _obj.get(s, t); break;
			}
			/*case 5:
			{
				string s = ;
				string t = ;
				_expected = ;
				_received = _obj.get(s, t); break;
			}*/
			/*case 6:
			{
				string s = ;
				string t = ;
				_expected = ;
				_received = _obj.get(s, t); break;
			}*/
			/*case 7:
			{
				string s = ;
				string t = ;
				_expected = ;
				_received = _obj.get(s, t); break;
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

// END CUT HERE
