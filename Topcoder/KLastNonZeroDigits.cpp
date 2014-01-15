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


class KLastNonZeroDigits {
	public:
	string getKDigits(int N, int K) ;
};

string KLastNonZeroDigits::getKDigits(int N, int K) {
    int f = 0;
    vector<int> v;
    for (int i=1; i<=N; i++) {
        int t = i;
        while (t%5==0) {
            t /= 5;
            f++;
        }
        v.push_back(t);
    }
    long long n = 1;
    for (int i=0; i<v.size(); i++) {
        int t = v[i];
        while (f>0 && t%2==0) {
            f--;
            t /= 2;
        }
        n = n*(long long)t;
    }
    string s;
    while (n>0 && s.length()<K) {
        s += char(n%10+'0');
        n /= 10;
    }
    reverse(s.begin(),s.end());
    return s;
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
		cout << "Testing KLastNonZeroDigits (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1389093988;
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
		KLastNonZeroDigits _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 10;
				int K = 3;
				_expected = "288";
				_received = _obj.getKDigits(N, K); break;
			}
			case 1:
			{
				int N = 6;
				int K = 1;
				_expected = "2";
				_received = _obj.getKDigits(N, K); break;
			}
			case 2:
			{
				int N = 6;
				int K = 3;
				_expected = "72";
				_received = _obj.getKDigits(N, K); break;
			}
			case 3:
			{
				int N = 7;
				int K = 2;
				_expected = "04";
				_received = _obj.getKDigits(N, K); break;
			}
			case 4:
			{
				int N = 20;
				int K = 9;
				_expected = "200817664";
				_received = _obj.getKDigits(N, K); break;
			}
			case 5:
			{
				int N = 1;
				int K = 1;
				_expected = "1";
				_received = _obj.getKDigits(N, K); break;
			}
			/*case 6:
			{
				int N = ;
				int K = ;
				_expected = ;
				_received = _obj.getKDigits(N, K); break;
			}*/
			/*case 7:
			{
				int N = ;
				int K = ;
				_expected = ;
				_received = _obj.getKDigits(N, K); break;
			}*/
			/*case 8:
			{
				int N = ;
				int K = ;
				_expected = ;
				_received = _obj.getKDigits(N, K); break;
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
