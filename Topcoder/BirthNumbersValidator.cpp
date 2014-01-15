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


class BirthNumbersValidator {
	public:
	vector <string> validate(vector <string> test) ;
};

int len[] = {31,28,31,30,31,30,31,31,30,31,30,31};

vector <string> BirthNumbersValidator::validate(vector <string> test) {
    int n = test.size();
    vector<string> v;
    for (int i=0; i<n; i++) {
        long long a = atoll(test[i].c_str());
        bool good = 1;
        if (a%11!=0) good = 0;
        int b = atoi(test[i].substr(2,2).c_str());
        if (b>12 && b<51) good = 0;
        if (b>62) good = 0;
        if (good) {
            if (b>12) b -= 50;
            int c = atoi(test[i].substr(4,2).c_str());
            if (b!= 2 && c>len[b-1]) good = 0;
            if (b==2) {
                int d = atoi(test[i].substr(0,2).c_str());
                if (d%4!=0) {
                    if (c>28) good = 0;
                }
                else {
                    if (c>29) good = 0;
                }
            }
            if (c==0) good = 0;
        }
        if (good) v.push_back("YES");
        else v.push_back("NO");
    }
    return v;
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
		cout << "Testing BirthNumbersValidator (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1388405496;
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
		BirthNumbersValidator _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string test[] = {"8104121234"};
				string __expected[] = {"YES" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.validate(vector <string>(test, test+sizeof(test)/sizeof(string))); break;
			}
			case 1:
			{
				string test[] = {"8154121239"};
				string __expected[] = {"YES" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.validate(vector <string>(test, test+sizeof(test)/sizeof(string))); break;
			}
			case 2:
			{
				string test[] = {"8134120005"};
				string __expected[] = {"NO" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.validate(vector <string>(test, test+sizeof(test)/sizeof(string))); break;
			}
			case 3:
			{
				string test[] = {"8102310007","8104121235"};
				string __expected[] = {"NO", "NO" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.validate(vector <string>(test, test+sizeof(test)/sizeof(string))); break;
			}
			case 4:
			{
				string test[] = {"0411131237"};
				string __expected[] = {"YES" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.validate(vector <string>(test, test+sizeof(test)/sizeof(string))); break;
			}
			case 5:
			{
				string test[] = {"0402281242", "0502281237"};;
				string __expected[] = {"YES", "NO" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.validate(vector <string>(test, test+sizeof(test)/sizeof(string))); break;
			}
			/*case 6:
			{
				string test[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.validate(vector <string>(test, test+sizeof(test)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string test[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.validate(vector <string>(test, test+sizeof(test)/sizeof(string))); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _expected[i] << "\"";
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _received[i] << "\"";
			}
			cout << " }" << endl;
		}
	}
}

//END CUT HERE
