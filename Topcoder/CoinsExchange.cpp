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


class CoinsExchange {
	public:
	int countExchanges(int G1, int S1, int B1, int G2, int S2, int B2) ;
};

int CoinsExchange::countExchanges(int _G1, int _S1, int _B1, int _G2, int _S2, int _B2) {
    int G1 = _G1;
    int G2 = _G2;
    int S1 = _S1;
    int S2 = _S2;
    int B1 = _B1;
    int B2 = _B2;

    if (G2<G1) {
        S1 += 9*(G1-G2);
        G1 = G2;
    }
    if (B2<B1) {
        S1 += (B1-B2)/11;
        B1 = B2;
    }
    if (G2>G1) {
        int tmp = S1-S2;
        if (tmp<0) return -1;
        if ((G2-G1)*11>tmp) return -1;
        S1 -= (G2-G1)*11;
    }
    if (B2>B1) {
        int tmp = S1-S2;
        if (tmp<0) return -1;
        if ((B2-B1)>tmp*9) return -1;
        S1 -= (B2-B1-1)/9+1;
    }
    if (S1<S2) return -1;

    G1 = _G1;
    G2 = _G2;
    S1 = _S1;
    S2 = _S2;
    B1 = _B1;
    B2 = _B2;

    int res = 0;

    if (B1<B2) {
        int tmp = B2-B1;
        res += (tmp-1)/9 + 1;
        S1 -= (tmp-1)/9 + 1;
        B1 += ((tmp-1)/9 + 1)*9;
    }
    if (S1<S2) {
        int tmp = S2-S1;
        res += (tmp-1)/9 + 1;
        G1 -= (tmp-1)/9 + 1;
        S1 += ((tmp-1)/9 + 1)*9;
    }
    if (G1<G2) {
        int tmp = G2-G1;
        res += tmp;
        S1 -= (tmp)*11;
        G1 += tmp;
    }
    if (S1<S2) {
        int tmp = S2-S1;
        res += tmp;
        G1 -= (tmp)*11;
        S1 += tmp;
    }

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
		cout << "Testing CoinsExchange (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393527355;
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
		CoinsExchange _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int G1 = 1;
				int S1 = 0;
				int B1 = 0;
				int G2 = 0;
				int S2 = 0;
				int B2 = 81;
				_expected = 10;
				_received = _obj.countExchanges(G1, S1, B1, G2, S2, B2); break;
			}
			case 1:
			{
				int G1 = 1;
				int S1 = 100;
				int B1 = 12;
				int G2 = 5;
				int S2 = 53;
				int B2 = 33;
				_expected = 7;
				_received = _obj.countExchanges(G1, S1, B1, G2, S2, B2); break;
			}
			case 2:
			{
				int G1 = 1;
				int S1 = 100;
				int B1 = 12;
				int G2 = 5;
				int S2 = 63;
				int B2 = 33;
				_expected = -1;
				_received = _obj.countExchanges(G1, S1, B1, G2, S2, B2); break;
			}
			case 3:
			{
				int G1 = 5;
				int S1 = 10;
				int B1 = 12;
				int G2 = 3;
				int S2 = 7;
				int B2 = 9;
				_expected = 0;
				_received = _obj.countExchanges(G1, S1, B1, G2, S2, B2); break;
			}
			/*case 4:
			{
				int G1 = ;
				int S1 = ;
				int B1 = ;
				int G2 = ;
				int S2 = ;
				int B2 = ;
				_expected = ;
				_received = _obj.countExchanges(G1, S1, B1, G2, S2, B2); break;
			}*/
			/*case 5:
			{
				int G1 = ;
				int S1 = ;
				int B1 = ;
				int G2 = ;
				int S2 = ;
				int B2 = ;
				_expected = ;
				_received = _obj.countExchanges(G1, S1, B1, G2, S2, B2); break;
			}*/
			/*case 6:
			{
				int G1 = ;
				int S1 = ;
				int B1 = ;
				int G2 = ;
				int S2 = ;
				int B2 = ;
				_expected = ;
				_received = _obj.countExchanges(G1, S1, B1, G2, S2, B2); break;
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
