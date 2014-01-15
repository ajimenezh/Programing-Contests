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


class Cut {
	public:
	int getMaximum(vector <int> eelLengths, int maxCuts) ;
};

int Cut::getMaximum(vector <int> eelLengths, int maxCuts) {
	vector<int> v1, v2;
	int ans = 0;
	int n = eelLengths.size();
	for (int i=0; i<n; i++) {
	    int t = eelLengths[i];
        if (t==10) ans++;
        else if (t%10==0) v1.push_back(t);
        else if (t>10) v2.push_back(t);
	}
    sort(v1.begin(),v1.end());
	int c = maxCuts;
	for (int i=0; i<v1.size(); i++) {
        int t = v1[i]/10 - 1;
        if (c>=t) {
            ans += t+1;
            c -= t;
        }
        else {
            ans += c;
            c = 0;
        }
	}

	for (int i=0; i<v2.size(); i++) {
        int t = v2[i]/10;
        if (c>=t) {
            ans += t;
            c -= t;
        }
        else {
            ans += c;
            c = 0;
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
		cout << "Testing Cut (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1384454920;
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
		Cut _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int eelLengths[] = {13, 20, 13};
				int maxCuts = 2;
				_expected = 3;
				_received = _obj.getMaximum(vector <int>(eelLengths, eelLengths+sizeof(eelLengths)/sizeof(int)), maxCuts); break;
			}
			case 1:
			{
				int eelLengths[] = {5, 5, 5, 5};
				int maxCuts = 2;
				_expected = 0;
				_received = _obj.getMaximum(vector <int>(eelLengths, eelLengths+sizeof(eelLengths)/sizeof(int)), maxCuts); break;
			}
			case 2:
			{
				int eelLengths[] = {34, 10, 48};
				int maxCuts = 4;
				_expected = 5;
				_received = _obj.getMaximum(vector <int>(eelLengths, eelLengths+sizeof(eelLengths)/sizeof(int)), maxCuts); break;
			}
			case 3:
			{
				int eelLengths[] = {30, 50, 30, 50};
				int maxCuts = 350;
				_expected = 16;
				_received = _obj.getMaximum(vector <int>(eelLengths, eelLengths+sizeof(eelLengths)/sizeof(int)), maxCuts); break;
			}
			case 4:
			{
				int eelLengths[] = {120,100,130,190,140,40};
				int maxCuts = 48;
				_expected = 53;
				_received = _obj.getMaximum(vector <int>(eelLengths, eelLengths+sizeof(eelLengths)/sizeof(int)), maxCuts); break;
			}
			/*case 5:
			{
				int eelLengths[] = ;
				int maxCuts = ;
				_expected = ;
				_received = _obj.getMaximum(vector <int>(eelLengths, eelLengths+sizeof(eelLengths)/sizeof(int)), maxCuts); break;
			}*/
			/*case 6:
			{
				int eelLengths[] = ;
				int maxCuts = ;
				_expected = ;
				_received = _obj.getMaximum(vector <int>(eelLengths, eelLengths+sizeof(eelLengths)/sizeof(int)), maxCuts); break;
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
