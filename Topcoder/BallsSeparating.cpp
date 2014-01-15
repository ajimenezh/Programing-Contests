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


class BallsSeparating {
	public:
	int minOperations(vector <int> red, vector <int> green, vector <int> blue) ;
};

int BallsSeparating::minOperations(vector <int> red, vector <int> green, vector <int> blue) {
	int g = 0, r = 0, b = 0;
	int n = red.size();

	red.push_back(0);
	blue.push_back(0);
	green.push_back(0);


	int best = 1000000000;
	for (int i=0; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            for (int k=j+1; k<=n; k++) {
                vector<int> v;
                v.push_back(i);
                v.push_back(j);
                v.push_back(k);
                for (r=0; r<3; r++) {
                    for (g=0; g<3; g++) {
                        for (b=0; b<3; b++) {
                            if (g==r || g==b || b==r) continue;

                            int cnt = 0;

                            cnt += red[v[g]] + red[v[b]];
                            cnt += green[v[r]] + green[v[b]];
                            cnt += blue[v[g]] + blue[v[r]];

                            for (int x=0; x<n; x++) if (x!=i && x!=j && x!=k) {
                                cnt += red[x] + green[x] + blue[x] - max(max(red[x],green[x]),blue[x]);
                            }

                            for (int x=0; x<n; x++) if (red[x]>0 && v[r]==n) cnt = 1000000000;
                            for (int x=0; x<n; x++) if (blue[x]>0 && v[b]==n) cnt = 1000000000;
                            for (int x=0; x<n; x++) if (green[x]>0 && v[g]==n) cnt = 1000000000;

                            best = min(best,cnt);

                        }
                    }
                }
            }
        }
	}

	if (best==1000000000) return -1;
	return best;

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
		cout << "Testing BallsSeparating (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1381773814;
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
		BallsSeparating _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int red[] = {1, 1, 1};
				int green[] = {1, 1, 1};
				int blue[] = {1, 1, 1};
				_expected = 6;
				_received = _obj.minOperations(vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(green, green+sizeof(green)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}
			case 1:
			{
				int red[] = {5};
				int green[] = {6};
				int blue[] = {8};
				_expected = -1;
				_received = _obj.minOperations(vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(green, green+sizeof(green)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}
			case 2:
			{
				int red[] = {4, 6, 5, 7};
				int green[] = {7, 4, 6, 3};
				int blue[] = {6, 5, 3, 8};
				_expected = 37;
				_received = _obj.minOperations(vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(green, green+sizeof(green)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}
			case 3:
			{
				int red[] = {7, 12, 9, 9, 7};
				int green[] = {7, 10, 8, 8, 9};
				int blue[] = {8, 9, 5, 6, 13};
				_expected = 77;
				_received = _obj.minOperations(vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(green, green+sizeof(green)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}
			case 4:
			{
				int red[] = {842398, 491273, 958925, 849859, 771363, 67803, 184892, 391907, 256150, 75799};
				int green[] = {268944, 342402, 894352, 228640, 903885, 908656, 414271, 292588, 852057, 889141};
				int blue[] = {662939, 340220, 600081, 390298, 376707, 372199, 435097, 40266, 145590, 505103};
				_expected = 7230607;
				_received = _obj.minOperations(vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(green, green+sizeof(green)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}
			/*case 5:
			{
				int red[] = ;
				int green[] = ;
				int blue[] = ;
				_expected = ;
				_received = _obj.minOperations(vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(green, green+sizeof(green)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int red[] = ;
				int green[] = ;
				int blue[] = ;
				_expected = ;
				_received = _obj.minOperations(vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(green, green+sizeof(green)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int red[] = ;
				int green[] = ;
				int blue[] = ;
				_expected = ;
				_received = _obj.minOperations(vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(green, green+sizeof(green)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
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
