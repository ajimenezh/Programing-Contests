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


class EllysRivers {
	public:
	double getMin(int length, int walk, vector <int> width, vector <int> speed) ;
};

double dp[2][100010];

double EllysRivers::getMin(int length, int walk, vector <int> width, vector <int> speed) {
    int l = length;
    int w = walk;

    int n = width.size();

    for (int i=0; i<=l; i++) dp[0][i] = 1.0*(l-i) / w;

    reverse(width.begin(),width.end());
    reverse(speed.begin(),speed.end());

    for (int i=0; i<n; i++) {
        int now = 1 - i%2;
        int pos = l;
        for (int j=l; j>=0; j--) {
            dp[now][j] = dp[1-now][pos] + sqrt(width[i]*width[i] + (pos-j)*(pos-j)) / speed[i];
            while (pos>j) {
                double next = dp[1-now][pos-1] + sqrt(width[i]*width[i] + (pos-j-1)*(pos-j-1)) / speed[i];
                if (next>dp[now][j]) break;
                dp[now][j] = next; pos--;
            }
        }
    }

    return dp[n%2][0];

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
		cout << "Testing EllysRivers (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1384028714;
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
		EllysRivers _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int length = 10;
				int walk = 3;
				int width[] = {5, 2, 3};
				int speed[] = {5, 2, 7};
				_expected = 3.231651964071508;
				_received = _obj.getMin(length, walk, vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(speed, speed+sizeof(speed)/sizeof(int))); break;
			}
			case 1:
			{
				int length = 10000;
				int walk = 211;
				int width[] = {911};
				int speed[] = {207};
				_expected = 48.24623664712219;
				_received = _obj.getMin(length, walk, vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(speed, speed+sizeof(speed)/sizeof(int))); break;
			}
			case 2:
			{
				int length = 1337;
				int walk = 2;
				int width[] = {100, 200, 300, 400};
				int speed[] = {11, 12, 13, 14};
				_expected = 128.57830549575695;
				_received = _obj.getMin(length, walk, vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(speed, speed+sizeof(speed)/sizeof(int))); break;
			}
			case 3:
			{
				int length = 77;
				int walk = 119;
				int width[] = {11, 12, 13, 14};
				int speed[] = {100, 200, 300, 400};
				_expected = 0.3842077071089629;
				_received = _obj.getMin(length, walk, vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(speed, speed+sizeof(speed)/sizeof(int))); break;
			}
			case 4:
			{
				int length = 7134;
				int walk = 1525;
				int width[] = {11567, 19763, 11026, 10444, 24588, 22263, 17709, 11181, 15292, 28895, 15039, 18744, 19985, 13795, 26697, 18812, 25655, 13620, 28926, 12393};
				int speed[] = {1620, 1477, 2837, 2590, 1692, 2270, 1655, 1078, 2683, 1475, 1383, 1153, 1862, 1770, 1671, 2318, 2197, 1768, 1979, 1057};
				_expected = 214.6509731258811;
				_received = _obj.getMin(length, walk, vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(speed, speed+sizeof(speed)/sizeof(int))); break;
			}
			/*case 5:
			{
				int length = ;
				int walk = ;
				int width[] = ;
				int speed[] = ;
				_expected = ;
				_received = _obj.getMin(length, walk, vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(speed, speed+sizeof(speed)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int length = ;
				int walk = ;
				int width[] = ;
				int speed[] = ;
				_expected = ;
				_received = _obj.getMin(length, walk, vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(speed, speed+sizeof(speed)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int length = ;
				int walk = ;
				int width[] = ;
				int speed[] = ;
				_expected = ;
				_received = _obj.getMin(length, walk, vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(speed, speed+sizeof(speed)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

//END CUT HERE
