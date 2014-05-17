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


class EmoticonsDiv1 {
	public:
	int printSmiles(int smiles) ;
};

int dp[1010][1010];
bool vis[1010][1010];
int tot;

int solve(int p, int q) {
    if (p<=0) return 1000000;
    if (p>=tot) return p-tot;
    if (p<q/2) return 1000000;
    if (dp[p][q]>=0) return dp[p][q];
    if (vis[p][q]) return 100000;

    vis[p][q] = 1;

    int tmp = 100000;
    tmp = min(tmp, solve(p, p) + 1);
    tmp = min(tmp, solve(p-1, q) + 1);
    tmp = min(tmp, solve(p+q, q) + 1);

    dp[p][q] = tmp;

    return tmp;
}

int EmoticonsDiv1::printSmiles(int smiles) {
    tot = smiles;
    for (int i=0; i<=tot; i++) for (int j=0; j<=tot; j++) dp[i][j] = -1;
    return solve(1,1) + 1;
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
		cout << "Testing EmoticonsDiv1 (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1395321531;
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
		EmoticonsDiv1 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int smiles = 2;
				_expected = 2;
				_received = _obj.printSmiles(smiles); break;
			}
			case 1:
			{
				int smiles = 4;
				_expected = 4;
				_received = _obj.printSmiles(smiles); break;
			}
			case 2:
			{
				int smiles = 6;
				_expected = 5;
				_received = _obj.printSmiles(smiles); break;
			}
			case 3:
			{
				int smiles = 18;
				_expected = 8;
				_received = _obj.printSmiles(smiles); break;
			}
			case 4:
			{
				int smiles = 11;
				_expected = 8;
				_received = _obj.printSmiles(smiles); break;
			}
			case 5:
			{
				int smiles = 1000;
				_expected = 800;
				_received = _obj.printSmiles(smiles); break;
			}
			case 6:
			{
				int smiles = 800;
				_expected = 80;
				_received = _obj.printSmiles(smiles); break;
			}
			/*case 7:
			{
				int smiles = ;
				_expected = ;
				_received = _obj.printSmiles(smiles); break;
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
