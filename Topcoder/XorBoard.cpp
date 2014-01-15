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


class XorBoard {
	public:
	int count(int H, int W, int Rcount, int Ccount, int S) ;
};

const long long mod = 555555555;
int C[3510][3510];

int XorBoard::count(int H, int W, int Rcount, int Ccount, int S) {
	for (int i=0; i<=3500; i++) {
        C[i][0] = 1;
        C[i][i] = 1;
        for (int j=1; j<i; j++) C[i][j] = ((long long)C[i-1][j-1]+C[i-1][j])%mod;
	}

	long long ans = 0;
	for (int x=0; x<=H; x++) {
        if (x<=Rcount && (Rcount-x)%2==0) {
            for (int y=0; y<=W; y++) {
                if (y<=Ccount && (Ccount-y)%2==0) {
                    if (x*(W-y)+y*(H-x)==S) {
                        long long tmp = ((long long)C[H][x]*C[H+(Rcount-x)/2-1][H-1])%mod;
                        tmp = (tmp*C[W][y])%mod;
                        tmp = (tmp*C[W+(Ccount-y)/2-1][W-1])%mod;
                        ans = (ans + tmp)%mod;
                    }
                }
            }
        }
	}
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
		cout << "Testing XorBoard (555.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1383342830;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 555.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		XorBoard _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int H = 2;
				int W = 2;
				int Rcount = 2;
				int Ccount = 2;
				int S = 4;
				_expected = 4;
				_received = _obj.count(H, W, Rcount, Ccount, S); break;
			}
			case 1:
			{
				int H = 2;
				int W = 2;
				int Rcount = 0;
				int Ccount = 0;
				int S = 1;
				_expected = 0;
				_received = _obj.count(H, W, Rcount, Ccount, S); break;
			}
			case 2:
			{
				int H = 10;
				int W = 20;
				int Rcount = 50;
				int Ccount = 40;
				int S = 200;
				_expected = 333759825;
				_received = _obj.count(H, W, Rcount, Ccount, S); break;
			}
			case 3:
			{
				int H = 1200;
				int W = 1000;
				int Rcount = 800;
				int Ccount = 600;
				int S = 4000;
				_expected = 96859710;
				_received = _obj.count(H, W, Rcount, Ccount, S); break;
			}
			case 4:
			{
				int H = 555;
				int W = 555;
				int Rcount = 555;
				int Ccount = 555;
				int S = 5550;
				_expected = 549361755;
				_received = _obj.count(H, W, Rcount, Ccount, S); break;
			}
			/*case 5:
			{
				int H = ;
				int W = ;
				int Rcount = ;
				int Ccount = ;
				int S = ;
				_expected = ;
				_received = _obj.count(H, W, Rcount, Ccount, S); break;
			}*/
			/*case 6:
			{
				int H = ;
				int W = ;
				int Rcount = ;
				int Ccount = ;
				int S = ;
				_expected = ;
				_received = _obj.count(H, W, Rcount, Ccount, S); break;
			}*/
			/*case 7:
			{
				int H = ;
				int W = ;
				int Rcount = ;
				int Ccount = ;
				int S = ;
				_expected = ;
				_received = _obj.count(H, W, Rcount, Ccount, S); break;
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
