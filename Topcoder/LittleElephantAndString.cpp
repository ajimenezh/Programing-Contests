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


class LittleElephantAndString {
	public:
	int getNumber(string A, string B) ;
};

int cnt[28];
int n;
string a,b;

int LittleElephantAndString::getNumber(string A, string B) {
    a = A;
    b = B;

    for (int i=0; i<A.length(); i++) cnt[A[i]-'A']++;
    for (int i=0; i<B.length(); i++) cnt[B[i]-'A']--;

    for (int i=0; i<26; i++) if (cnt[i]!=0) return -1;

    n = A.length();

    int i = n-1;
    int j = n-1;

    int t = 0;

    for (int k=n-1; k>=0; k--) {
        int i=0;
        int j=k;
        while (i<n && j<n) {
            if (a[i]==b[j]) {
                i++; j++;
            }
            else i++;
        }
        if (j==n) t = k;
    }

    cout<<t<<endl;

    t = n;
    i=n;
    for (int i=n-1; i>=0; i--) {
        if (A[i]==B[t-1]) {
            t--;
        }
    }

    return t;
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
		cout << "Testing LittleElephantAndString (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1384948821;
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
		LittleElephantAndString _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string A = "ABC";
				string B = "CBA";
				_expected = 2;
				_received = _obj.getNumber(A, B); break;
			}
			case 1:
			{
				string A = "A";
				string B = "B";
				_expected = -1;
				_received = _obj.getNumber(A, B); break;
			}
			case 2:
			{
				string A = "AAABBB";
				string B = "BBBAAA";
				_expected = 3;
				_received = _obj.getNumber(A, B); break;
			}
			case 3:
			{
				string A = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
				string B = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
				_expected = 25;
				_received = _obj.getNumber(A, B); break;
			}
			case 4:
			{
				string A = "A";
				string B = "A";
				_expected = 0;
				_received = _obj.getNumber(A, B); break;
			}
			case 5:
			{
				string A = "DCABA";
				string B = "DACBA";
				_expected = 2;
				_received = _obj.getNumber(A, B); break;
			}
			case 6:
			{
				string A = "AAATDCAAA";
				string B = "AAADTCAAA";
				_expected = 1;
				_received = _obj.getNumber(A, B); break;
			}
			/*case 7:
			{
				string A = ;
				string B = ;
				_expected = ;
				_received = _obj.getNumber(A, B); break;
			}*/
			/*case 8:
			{
				string A = ;
				string B = ;
				_expected = ;
				_received = _obj.getNumber(A, B); break;
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
