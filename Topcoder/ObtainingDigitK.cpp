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


class ObtainingDigitK {
	public:
	int minNumberToAdd(string originalNumber, int k) ;
};

bool check(string s, int k) {
    for (int i=0; i<s.length(); i++) if (s[i]==char('0'+k)) return true;
    return false;
}

string sum(string s) {
    int j = s.length()-1;
    int r = 1;
    while (j>=0 && r==1) {
        if (s[j]!='9') {
            s[j] = char(s[j]+1);
            r = 0;
        }
        else {
            s[j] = '0';
        }
        j--;
    }
    if (r) s = '1' + s;
    return s;
}

int ObtainingDigitK::minNumberToAdd(string originalNumber, int k) {
	int tot = 0;
	string n = originalNumber;
	while (!check(n, k)) {
        n = sum(n);
        tot++;
	}
	return tot;
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
		cout << "Testing ObtainingDigitK (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1394133571;
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
		ObtainingDigitK _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string originalNumber = "153";
				int k = 7;
				_expected = 4;
				_received = _obj.minNumberToAdd(originalNumber, k); break;
			}
			case 1:
			{
				string originalNumber = "158";
				int k = 7;
				_expected = 9;
				_received = _obj.minNumberToAdd(originalNumber, k); break;
			}
			case 2:
			{
				string originalNumber = "7853192";
				int k = 2;
				_expected = 0;
				_received = _obj.minNumberToAdd(originalNumber, k); break;
			}
			case 3:
			{
				string originalNumber = "99999999999999999999999999999999999999999999999";
				int k = 0;
				_expected = 1;
				_received = _obj.minNumberToAdd(originalNumber, k); break;
			}
			/*case 4:
			{
				string originalNumber = ;
				int k = ;
				_expected = ;
				_received = _obj.minNumberToAdd(originalNumber, k); break;
			}*/
			/*case 5:
			{
				string originalNumber = ;
				int k = ;
				_expected = ;
				_received = _obj.minNumberToAdd(originalNumber, k); break;
			}*/
			/*case 6:
			{
				string originalNumber = ;
				int k = ;
				_expected = ;
				_received = _obj.minNumberToAdd(originalNumber, k); break;
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
