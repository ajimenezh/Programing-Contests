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


class CasketOfStar {
	public:
	int maxEnergy(vector <int> weight) ;
};

vector<int> v;
int n;
int dp[55][55];

int solve(int a, int b) {
    if (b-a+1==3) return v[a]*v[b];
    if (b-a+1<3) return 0;
    if (dp[a][b]>=0) return dp[a][b];

    int tmp = 0;

    for (int i=a+1; i<b; i++) {
        tmp = max(v[a]*v[b] + solve(a,i) + solve(i,b), tmp);
    }

    dp[a][b] = tmp;

    return tmp;
}

int CasketOfStar::maxEnergy(vector <int> weight) {
	v = weight;

	n = v.size();

	for (int i=0; i<n; i++) for (int j=0; j<n; j++) dp[i][j] = -1;

	int res = solve(0,n-1);

	return res;
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
		cout << "Testing CasketOfStar (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1384356630;
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
		CasketOfStar _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int weight[] = {1,2,3,4};
				_expected = 12;
				_received = _obj.maxEnergy(vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}
			case 1:
			{
				int weight[] = {100,2,1,3,100};
				_expected = 10400;
				_received = _obj.maxEnergy(vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}
			case 2:
			{
				int weight[] = {2,2,7,6,90,5,9};
				_expected = 1818;
				_received = _obj.maxEnergy(vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}
			case 3:
			{
				int weight[] = {477,744,474,777,447,747,777,474};
				_expected = 2937051;
				_received = _obj.maxEnergy(vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}
			case 4:
			{
				int weight[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
				_expected = 13;
				_received = _obj.maxEnergy(vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}
			case 5:
			{
				int weight[] = {12,5,2};
				_expected = 24;
				_received = _obj.maxEnergy(vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}
			/*case 6:
			{
				int weight[] = ;
				_expected = ;
				_received = _obj.maxEnergy(vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int weight[] = ;
				_expected = ;
				_received = _obj.maxEnergy(vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
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
