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


class RepeatedPatterns {
	public:
	long long findZeroSegment(string P1, string P2, string zeroCount) ;
};

long long RepeatedPatterns::findZeroSegment(string P1, string P2, string _zeroCount) {
    long long zeroCount = atoll(_zeroCount.c_str());
	bool in1 = false;
	bool in2 = false;
	int n = P1.length();
	int m = P2.length();
	for (int i=0; i<n; i++) if (P1[i]=='1') in1 = true;
	for (int i=0; i<m; i++) if (P2[i]=='1') in2 = true;

	if (!in1 && !in2) return 0;

	long long ans = 1LL<<60;

	int last = -1;
	for (int i=0; i<n; i++) {
        if (P1[i]=='1') {
            int len = i - last - 1;
            if (len >= zeroCount) {
                ans = min(ans, (long long)last+1);
            }
            last = i;
        }
	}
	if (last!=n-1) {
        if (n - last - 1 >= zeroCount) {
            ans = min(ans, (long long)last+1);
        }
	}
	int prefix = 0;
	int i = 0;
	while (i<n && P1[i++]=='0') prefix++;
	i = n-1;
	int suffix = 0;
	while (i>=0 && P1[i--]=='0') suffix++;
	if (prefix==n && 1000000*n>=zeroCount) return 0;
	if (prefix+suffix>=zeroCount) return n-suffix;

	int prefix2 = 0;
	i = 0;
	while (i<m && P2[i++]=='0') prefix2++;
	i = m-1;
	int suffix2 = 0;
	while (i>=0 && P2[i--]=='0') suffix2++;

	if (prefix!=n && suffix2!=m) {
        if (prefix>=zeroCount) ans = min(ans, 0LL);
        if (suffix+prefix>=zeroCount) ans = min(ans, (long long)n-suffix);
        if (suffix+prefix2>=zeroCount) ans = min(ans, (long long)n*1000000-suffix);
        if (suffix2+prefix>=zeroCount) ans = min(ans, (long long)n*1000000+m-suffix2);
        if (suffix2+prefix2>=zeroCount) ans = min(ans, (long long)2*n*1000000+2*m-suffix2);
	}

	if (prefix>=zeroCount) ans = min(ans, 0LL);
    if (suffix+prefix>=zeroCount) ans = min(ans, (long long)n-suffix);
    if (suffix+prefix2>=zeroCount) ans = min(ans, (long long)n*1000000-suffix);
    if (suffix2+prefix>=zeroCount) ans = min(ans, (long long)n*1000000+m-suffix2);
    if (suffix2+prefix2>=zeroCount) ans = min(ans, (long long)2*n*1000000+2*m-suffix2);

	if (suffix==n && suffix2!=m) {
        if (n*1000000+prefix2>=zeroCount) ans = min(ans, 0LL);
        if (n*1000000+suffix2>=zeroCount) ans = min(ans, (long long)n*1000000+m-suffix2);
	}

	if (suffix+prefix2>=zeroCount) {
         ans = min(ans, (long long)1000000*n-suffix);
	}
	if (suffix+prefix>=zeroCount) {
         ans = min(ans, (long long)n-suffix);
	}
	if (suffix2==m) {
        if (suffix+prefix+suffix2>=zeroCount) ans = min(ans, (long long)1000000*n-suffix);
	}
	if (suffix2+prefix>=zeroCount) ans = min(ans, (long long)n*1000000+m-suffix2);
	if (suffix==n && suffix2==m) {
        ans = min(ans, (long long)0);
	}
	if (suffix2+prefix2>=zeroCount) {
        ans = min(ans, (long long)1000000*2*n + 2*m - suffix2);
	}
	if (suffix2==m) {
        zeroCount -= prefix + suffix;
        long long k = zeroCount/m;
        if (k*n<=(10000000000000000LL-zeroCount+suffix-(long long)k*(k-1)/2*m)/1000000)
            ans = min(ans, k*1000000*n-suffix + (long long)k*(k-1)/2*m);
	}
	if (ans==1LL<<60) return -1;
    return ans;
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
		cout << "Testing RepeatedPatterns (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1388406362;
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
		RepeatedPatterns _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string P1 = "111010100001010";
				string P2 = "010000001000";
				string zeroCount = "3";
				_expected = 7LL;
				_received = _obj.findZeroSegment(P1, P2, zeroCount); break;
			}
			case 1:
			{
				string P1 = "1101010010";
				string P2 = "0001000";
				string zeroCount = "3";
				_expected = 9999999LL;
				_received = _obj.findZeroSegment(P1, P2, zeroCount); break;
			}
			case 2:
			{
				string P1 = "1101010010";
				string P2 = "0001000";
				string zeroCount = "5";
				_expected = 20000011LL;
				_received = _obj.findZeroSegment(P1, P2, zeroCount); break;
			}
			case 3:
			{
				string P1 = "10101010";
				string P2 = "101010101010";
				string zeroCount = "9876543219876";
				_expected = -1LL;
				_received = _obj.findZeroSegment(P1, P2, zeroCount); break;
			}
			case 4:
			{
				string P1 = "11111111111111111111111111";
				string P2 = "0";
				string zeroCount = "9876543219876";
				_expected = -1LL;
				_received = _obj.findZeroSegment(P1, P2, zeroCount); break;
			}
			case 5:
			{
				string P1 = "1";
				string P2 = "0";
				string zeroCount = "87654321";
				_expected = 392929427215830LL;
				_received = _obj.findZeroSegment(P1, P2, zeroCount); break;
			}
			/*case 6:
			{
				string P1 = ;
				string P2 = ;
				string zeroCount = ;
				_expected = LL;
				_received = _obj.findZeroSegment(P1, P2, zeroCount); break;
			}*/
			/*case 7:
			{
				string P1 = ;
				string P2 = ;
				string zeroCount = ;
				_expected = LL;
				_received = _obj.findZeroSegment(P1, P2, zeroCount); break;
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
