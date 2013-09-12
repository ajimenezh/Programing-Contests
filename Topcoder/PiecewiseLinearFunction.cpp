#line 2 "PiecewiseLinearFunction.cpp"

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

int n;
vector<int> y;
vector<long long> p;
int m;

class PiecewiseLinearFunction {
	public:
	int maximumSolutions(vector <int> Y) {
		n = Y.size(); 
		y = Y;
		for (int i=0; i<n-1; i++) if (y[i]==y[i+1]) return -1;
		for (int i=0; i<n; i++) {
			for (int j=i+1; j<n; j++) {
				p.push_back((long long)Y[j]+Y[i]);
			}
		}
		sort(p.begin(),p.end());
		m = n*(n-1)/2;
		int ans = 0;
		for (int i=0; i<m; i++) {
			int tmp = 0;
			for (int j=0; j<n-1; j++) {
				if ((long long)(2*y[j]-p[i])*(2*y[j+1]-p[i])<0) tmp++;
			}
			for (int j=0; j<n; j++) if (2*y[j]==p[i]) tmp++;
			ans = max(tmp,ans);
		}
		return ans;
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
		cout << "Testing PiecewiseLinearFunction (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1375451533;
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
		PiecewiseLinearFunction _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int Y[] = {3, 2};
				_expected = 1;
				_received = _obj.maximumSolutions(vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}
			case 1:
			{
				int Y[] = {4, 4};
				_expected = -1;
				_received = _obj.maximumSolutions(vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}
			case 2:
			{
				int Y[] = {1, 4, -1, 2};
				_expected = 3;
				_received = _obj.maximumSolutions(vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}
			case 3:
			{
				int Y[] = {2, 1, 2, 1, 3, 2, 3, 2};
				_expected = 5;
				_received = _obj.maximumSolutions(vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}
			case 4:
			{
				int Y[] = {125612666, -991004227, 0, 6, 88023, -1000000000, 1000000000, -1000000000, 1000000000};
				_expected = 6;
				_received = _obj.maximumSolutions(vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}
			/*case 5:
			{
				int Y[] = ;
				_expected = ;
				_received = _obj.maximumSolutions(vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int Y[] = ;
				_expected = ;
				_received = _obj.maximumSolutions(vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int Y[] = ;
				_expected = ;
				_received = _obj.maximumSolutions(vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
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
