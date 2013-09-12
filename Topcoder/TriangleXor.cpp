#line 2 "TriangleXor.cpp"

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
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

#define fo(i,n) for(int i=0; i<(int)n; i++)
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

double a[70010];
double b[70010];
int w;

class TriangleXor {
	public:
	
	int solve1() {
		double area1 = 0.0;
		
		area1 = a[1] - (2.0*a[2] - a[3]);
		
		for (int i=3; i<=w; i+=2) {
			area1 += (double)i*(a[i] - (2.0*a[i+1] - a[i+2]));
		}
		
		double area2 = 0.0;
		
		area2 = b[1] - a[w];
		double pre = b[1] - a[w];
		for (int i=2; i<=w; i++) {
			if (i%2!=0) area2 += b[i] - a[w-i+1] - pre;
			pre = b[i] - a[w-i+1];
		}
		
		area2 *= 2;
		
		double area = area1 + area2 + (double)w/4.0;
		
		return (int)(area + 0.000000001);
	}
	
	int solve2() {
		double area1 = 0.0;
		
		for (int i=2; i<=w; i+=2) {
			area1 += (double)i*(a[i] - (2.0*a[i+1] - a[i+2]));
		}
		
		double area2 = 0.0;
		
		area2 = b[1] - a[w];
		double pre = b[1] - a[w];
		for (int i=2; i<=w; i++) {
			if (i%2!=0) area2 += b[i] - a[w-i+1] - pre;
			pre = b[i] - a[w-i+1];
		}
		
		area2 *= 2;
		
		double area = area1 + area2;
		
		return (int)(area + 0.000000001);
	}
	
	int theArea(int W) {
		
		w = W;
		
		for (int i=1; i<=W; i++) b[i] = (double)i*1*0.5;
		for (int i=1; i<=W; i++) a[w-i+1] = (double)i / (w+i)*0.5*i;
		
		if (W==1) return 0;
		if (W%2==0) return solve1();
		return solve2();
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
		cout << "Testing TriangleXor (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1375455073;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 550.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TriangleXor _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int W = 1;
				_expected = 0;
				_received = _obj.theArea(W); break;
			}
			case 1:
			{
				int W = 2;
				_expected = 1;
				_received = _obj.theArea(W); break;
			}
			case 2:
			{
				int W = 3;
				_expected = 1;
				_received = _obj.theArea(W); break;
			}
			case 3:
			{
				int W = 4;
				_expected = 2;
				_received = _obj.theArea(W); break;
			}
			case 4:
			{
				int W = 5;
				_expected = 2;
				_received = _obj.theArea(W); break;
			}
			case 5:
			{
				int W = 12345;
				_expected = 4629;
				_received = _obj.theArea(W); break;
			}
			/*case 6:
			{
				int W = ;
				_expected = ;
				_received = _obj.theArea(W); break;
			}*/
			/*case 7:
			{
				int W = ;
				_expected = ;
				_received = _obj.theArea(W); break;
			}*/
			/*case 8:
			{
				int W = ;
				_expected = ;
				_received = _obj.theArea(W); break;
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

// END CUT HERE
