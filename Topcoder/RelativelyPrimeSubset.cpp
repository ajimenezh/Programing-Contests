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


class RelativelyPrimeSubset {
	public:
	int findSize(vector <int> S) ;
};

bool prime(int i) {
    for (int j=2; j<i; j++) if (i%j==0) return 0;
    return 1;
}

int gcd(int a, int b) {
    if (a<b) return gcd(b,a);
    if (b==0) return a;
    return gcd(b,a%b);
}

int RelativelyPrimeSubset::findSize(vector <int> S) {
    int ans = 0;
	for (int i=0; i<S.size(); i++) {
        if (S[i]==1) {
            S[i] = 0;
            ans = 1;
            continue;
        }
        int n = S[i];
        for (int j=2; j<=n; j++) if (n%j==0) {
            while (n%j==0) {
                n /= j;
                S[i] /= j;
            }
            S[i] *= j;
        }
	}
	for (int i=0; i<S.size(); i++) if (S[i]!=0) {
        for (int j=0; j<S.size(); j++) if (i!=j) {
            if (S[j]!=0 && S[j]<=S[i] && S[i]%S[j]==0) {
                S[i] = 0;
                break;
            }
        } cout<<S[i]<<endl;
	}
	for (int i=2; i<=100; i++) if (prime(i)) {
        bool done = 0;
        for (int j=0; j<S.size(); j++) if (S[j]!=0 && S[j]%i==0) {
            for (int k=0; k<S.size(); k++) if (S[k]!=0 && j!=k && gcd(S[k],S[j])!=1) S[k] = 0;
            S[j] = 0;
            done = 1;
        }
        ans += done;
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
		cout << "Testing RelativelyPrimeSubset (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1383844990;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		RelativelyPrimeSubset _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int S[] = {2,3,7,11,4};
				_expected = 4;
				_received = _obj.findSize(vector <int>(S, S+sizeof(S)/sizeof(int))); break;
			}
			case 1:
			{
				int S[] = {4,8,12,16};
				_expected = 1;
				_received = _obj.findSize(vector <int>(S, S+sizeof(S)/sizeof(int))); break;
			}
			case 2:
			{
				int S[] = {100,17,81,82};
				_expected = 3;
				_received = _obj.findSize(vector <int>(S, S+sizeof(S)/sizeof(int))); break;
			}
			case 3:
			{
				int S[] = {2,3,4,5,6};
				_expected = 3;
				_received = _obj.findSize(vector <int>(S, S+sizeof(S)/sizeof(int))); break;
			}
			case 4:
			{
				int S[] = {6,10,21};
				_expected = 2;
				_received = _obj.findSize(vector <int>(S, S+sizeof(S)/sizeof(int))); break;
			}
			/*case 5:
			{
				int S[] = ;
				_expected = ;
				_received = _obj.findSize(vector <int>(S, S+sizeof(S)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int S[] = ;
				_expected = ;
				_received = _obj.findSize(vector <int>(S, S+sizeof(S)/sizeof(int))); break;
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
