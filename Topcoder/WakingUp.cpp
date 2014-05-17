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


class WakingUp {
	public:
	int maxSleepiness(vector <int> period, vector <int> start, vector <int> volume, int D) ;
};

vector<pair<int,int> > v;

int WakingUp::maxSleepiness(vector <int> period, vector <int> start, vector <int> volume, int D) {
	int lo = -15000;
	int hi = 15000;

	if (period.size()==0) return -1;

    for (int i=0; i<period.size(); i++) {
        for (int j=0; j<15000; j++) v.push_back(make_pair(start[i] + j*period[i], volume[i]));
    }
    sort(v.begin(), v.end());

    while (lo<hi) {
        int mi = (lo+hi+1)>>1;

        bool awake = 0;

        int i = 0;
        int last = 0;

        long long s = mi;

        for (int i=0; i<v.size(); i++) {
            if (i!=0 && v[i].first!=v[i-1].first) {
                if (s<=0) {
                    awake = 1;
                    break;
                }
            }
            if (v[i].first!=last) {
                s += D*(v[i].first-last);
                last = v[i].first;
            }
            s -= v[i].second;
        }

        if (s<=0) awake = 1;

        if (!awake) {
            hi = mi-1;
        }
        else lo = mi;
    }

    if (lo==15000) return -1;
    return lo;
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
		cout << "Testing WakingUp (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397142007;
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
		WakingUp _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int period[] = {2, 3};
				int start[] = {1, 2};
				int volume[] = {3, 4};
				int D = 3;
				_expected = 2;
				_received = _obj.maxSleepiness(vector <int>(period, period+sizeof(period)/sizeof(int)), vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(volume, volume+sizeof(volume)/sizeof(int)), D); break;
			}
			case 1:
			{
				int period[] = {1};
				int start[] = {1};
				int volume[] = {17};
				int D = 17;
				_expected = 0;
				_received = _obj.maxSleepiness(vector <int>(period, period+sizeof(period)/sizeof(int)), vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(volume, volume+sizeof(volume)/sizeof(int)), D); break;
			}
			case 2:
			{
				int period[] = {10};
				int start[] = {1};
				int volume[] = {1};
				int D = 100;
				_expected = -1;
				_received = _obj.maxSleepiness(vector <int>(period, period+sizeof(period)/sizeof(int)), vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(volume, volume+sizeof(volume)/sizeof(int)), D); break;
			}
			case 3:
			{
				int period[] = {9, 2, 5, 5, 7};
				int start[] = {6, 1, 4, 1, 6};
				int volume[] = {71, 66, 7, 34, 6};
				int D = 50;
				_expected = 78;
				_received = _obj.maxSleepiness(vector <int>(period, period+sizeof(period)/sizeof(int)), vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(volume, volume+sizeof(volume)/sizeof(int)), D); break;
			}
			case 4:
			{
				int period[] = {5, 6, 5, 3, 8, 3, 4};
				int start[] = {1, 1, 3, 2, 6, 3, 3};
				int volume[] = {42, 85, 10, 86, 21, 78, 38};
				int D = 88;
				_expected = -1;
				_received = _obj.maxSleepiness(vector <int>(period, period+sizeof(period)/sizeof(int)), vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(volume, volume+sizeof(volume)/sizeof(int)), D); break;
			}
			/*case 5:
			{
				int period[] = ;
				int start[] = ;
				int volume[] = ;
				int D = ;
				_expected = ;
				_received = _obj.maxSleepiness(vector <int>(period, period+sizeof(period)/sizeof(int)), vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(volume, volume+sizeof(volume)/sizeof(int)), D); break;
			}*/
			/*case 6:
			{
				int period[] = ;
				int start[] = ;
				int volume[] = ;
				int D = ;
				_expected = ;
				_received = _obj.maxSleepiness(vector <int>(period, period+sizeof(period)/sizeof(int)), vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(volume, volume+sizeof(volume)/sizeof(int)), D); break;
			}*/
			/*case 7:
			{
				int period[] = ;
				int start[] = ;
				int volume[] = ;
				int D = ;
				_expected = ;
				_received = _obj.maxSleepiness(vector <int>(period, period+sizeof(period)/sizeof(int)), vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(volume, volume+sizeof(volume)/sizeof(int)), D); break;
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
