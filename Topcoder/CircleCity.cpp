
#line 3 "CircleCity.cpp"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

typedef long long LL;
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)

class CircleCity {
	public:
	int findMin(vector <int> dist, int k) {

        long long sum = 0;
		for (int i=0; i<dist.size(); i++) sum += dist[i];

		if (k == 0) {
            int d = 0;

            int cur = 0;
            int inv = sum;

            for (int i=0; i<dist.size(); i++) {
                for (int j=i+1; j<dist.size(); j++) {

                    cur += dist[i];
                    inv -= dist[i];

                    d = max(d, min(cur, inv));

                }
            }

            return inv;
		}

		long long lo = 0;
		long long hi = sum;

		while (lo < hi) {

            long long mi = (lo+hi)>>1;

            bool check = true;

            int need = k+1;

            for (int j=0; j<dist.size(); j++) {

                int cur = 0;
                int inv = sum;
                int tmp = 1;

                for (int i=0; i<dist.size()-1; i++) {

                    int d = cur + dist[(i+j)%dist.size()];

                    if (tmp == 1) {
                        inv -= dist[(i+j)%dist.size()];
                        d = min(d, inv);
                    }

                    if (d > mi) {
                        tmp++;
                        cur = 0;
                    }
                    else {
                        cur += dist[(i+j)%dist.size()];
                    }

                }

                need = min(need, tmp);
            }

            check = need <= k;

            //cout<<mi<<" "<<need<<endl;

            if (check) {
                hi = mi;
            }
            else {
                lo = mi+1;
            }

		}

		return lo;

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
		cout << "Testing CircleCity (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1507932211;
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
		CircleCity _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int dist[] = {3,5,4};
				int k = 2;
				_expected = 3;
				_received = _obj.findMin(vector <int>(dist, dist+sizeof(dist)/sizeof(int)), k); break;
			}
			case 1:
			{
				int dist[] = {3,5,4};
				int k = 3;
				_expected = 0;
				_received = _obj.findMin(vector <int>(dist, dist+sizeof(dist)/sizeof(int)), k); break;
			}
			case 2:
			{
				int dist[] = {1,2,3,4,5,6,5,4,3,2,1};
				int k = 5;
				_expected = 5;
				_received = _obj.findMin(vector <int>(dist, dist+sizeof(dist)/sizeof(int)), k); break;
			}
			case 3:
			{
				int dist[] = {1, 100, 1,1,1, 100, 1, 100, 1,1,1, 100, 1};
				int k = 4;
				_expected = 3;
				_received = _obj.findMin(vector <int>(dist, dist+sizeof(dist)/sizeof(int)), k); break;
			}
			case 4:
			{
				int dist[] = {3,1,4,1,5,9,2,6,5,3,5,8,9,7};
				int k = 6;
				_expected = 8;
				_received = _obj.findMin(vector <int>(dist, dist+sizeof(dist)/sizeof(int)), k); break;
			}
			case 5:
			{
				int dist[] = {
				             1000000,1000000,1000000,1000000,1000000,1000000,
				             1000000,1000000,1000000,1000000,1000000,1000000,
				             1000000,1000000,1000000,1000000,1000000,1000000,
				             1000000,1000000,1000000,1000000,1000000,1000000,
				             1000000,1000000,1000000,1000000,1000000,1000000,
				             1000000,1000000,1000000,1000000,1000000,1000000,
				             1000000,1000000,1000000,1000000,1000000,1000000,
				             1000000,1000000,1000000,1000000,1000000,1000000,
				             1000000,1000000,1000000,1000000,1000000,1000000,
				             1000000,1000000,1000000,1000000,1000000,1000000,
				             1000000,1000000,1000000,1000000,1000000,1000000
				             };
				int k = 7;
				_expected = 9000000;
				_received = _obj.findMin(vector <int>(dist, dist+sizeof(dist)/sizeof(int)), k); break;
			}
			/*case 6:
			{
				int dist[] = ;
				int k = ;
				_expected = ;
				_received = _obj.findMin(vector <int>(dist, dist+sizeof(dist)/sizeof(int)), k); break;
			}*/
			/*case 7:
			{
				int dist[] = ;
				int k = ;
				_expected = ;
				_received = _obj.findMin(vector <int>(dist, dist+sizeof(dist)/sizeof(int)), k); break;
			}*/
			/*case 8:
			{
				int dist[] = ;
				int k = ;
				_expected = ;
				_received = _obj.findMin(vector <int>(dist, dist+sizeof(dist)/sizeof(int)), k); break;
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
