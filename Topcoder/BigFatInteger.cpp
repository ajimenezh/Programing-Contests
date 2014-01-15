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


class BigFatInteger {
	public:
	int minOperations(int A, int B) ;
};

int f(vector<int> v) {
    int k = 0;
    int res = 0;
    for (int i=0; i<v.size(); i++) if (v[i]!=0) {
        if (v[i]%2==0) {
            v[i] /= 2;
            k++;
        }
        else {
            if (v[i]==1) {
                v[i]=0;
                res++;
            }
            else {
                v[i] = v[i]/2 + 1;
                k++;
            }
        }
    }
    if (k==0) return res;
    return res + f(v) + 1;
}

int BigFatInteger::minOperations(int A, int B) {
    int ans = 0;
    vector<int> v;
    for (int i=2; i*i<=A; i++) if (A%i==0) {
        int c = 0;
        while (A>0 && A%i==0) {
            c++;
            A /= i;
        }
        v.push_back(c*B);
    }
    if (A!=1) v.push_back(B);
    ans = f(v);
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
		cout << "Testing BigFatInteger (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1386922694;
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
		BigFatInteger _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A = 6;
				int B = 1;
				_expected = 2;
				_received = _obj.minOperations(A, B); break;
			}
			case 1:
			{
				int A = 162;
				int B = 1;
				_expected = 4;
				_received = _obj.minOperations(A, B); break;
			}
			case 2:
			{
				int A = 999983;
				int B = 9;
				_expected = 5;
				_received = _obj.minOperations(A, B); break;
			}
			case 3:
			{
				int A = 360;
				int B = 8;
				_expected = 8;
				_received = _obj.minOperations(A, B); break;
			}
			/*case 4:
			{
				int A = ;
				int B = ;
				_expected = ;
				_received = _obj.minOperations(A, B); break;
			}*/
			/*case 5:
			{
				int A = ;
				int B = ;
				_expected = ;
				_received = _obj.minOperations(A, B); break;
			}*/
			/*case 6:
			{
				int A = ;
				int B = ;
				_expected = ;
				_received = _obj.minOperations(A, B); break;
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
