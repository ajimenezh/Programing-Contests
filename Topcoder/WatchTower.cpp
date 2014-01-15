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


class WatchTower {
	public:
	double minHeight(vector <int> positions, vector <int> heights) ;
};

double WatchTower::minHeight(vector <int> positions, vector <int> heights) {
    int n = positions.size();

    double ans = 1.0e12;
    for (int i=0; i<n; i++) {
        double h = 0.0;
        for (int j=0; j<n-1; j++) {
            double m = (double)(heights[j+1]-heights[j]) / (positions[j+1]-positions[j]);
            double y = heights[j] + m*(positions[i] - positions[j]);
            h = max(h, max(y - heights[i],0.0));
        }
        ans = min(ans, h);
    }

    vector<pair<double,double> > points;
    for (int i=0; i<n-1; i++) {
        double m1 = (double)(heights[i+1]-heights[i]) / (positions[i+1]-positions[i]);
        for (int j=i+1; j<n-1; j++) {
            double m2 = (double)(heights[j+1]-heights[j]) / (positions[j+1]-positions[j]);
            if (abs(m2-m1)>1.0e-8) {
                double x = (double)(heights[i]-heights[j]+m2*positions[j] - m1*positions[i]) / (m2-m1);
                for (int k=0; k<n-1; k++) {
                    if (x>=positions[k] && x<=positions[k+1]) {
                        double m = (double)(heights[k+1]-heights[k]) / (positions[k+1]-positions[k]);
                        double y = heights[k] + m*(x - positions[k]);
                        points.push_back(make_pair(x,y));
                        break;
                    }
                }
            }
        }
    }

    for (int i=0; i<points.size(); i++) {
        double h = 0.0;
        for (int j=0; j<n-1; j++) {
            double m = (double)(heights[j+1]-heights[j]) / (positions[j+1]-positions[j]);
            double y = heights[j] + m*(points[i].first - positions[j]);
            h = max(h, max(y - points[i].second,0.0));
        }
        ans = min(ans, h);
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
		cout << "Testing WatchTower (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1379794986;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		WatchTower _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int positions[] = { 1,2,4,5,6,7 };
				int heights[] = { 1,2,2,4,2,1 };
				_expected = 1.0;
				_received = _obj.minHeight(vector <int>(positions, positions+sizeof(positions)/sizeof(int)), vector <int>(heights, heights+sizeof(heights)/sizeof(int))); break;
			}
			case 1:
			{
				int positions[] = { 10,20,49,59 };
				int heights[] = { 0,10,10,0 };
				_expected = 14.5;
				_received = _obj.minHeight(vector <int>(positions, positions+sizeof(positions)/sizeof(int)), vector <int>(heights, heights+sizeof(heights)/sizeof(int))); break;
			}
			case 2:
			{
				int positions[] = { 0,2,4,6,8,10 };
				int heights[] = { 0,1,3,6,10,11 };
				_expected = 0.0;
				_received = _obj.minHeight(vector <int>(positions, positions+sizeof(positions)/sizeof(int)), vector <int>(heights, heights+sizeof(heights)/sizeof(int))); break;
			}
			/*case 3:
			{
				int positions[] = ;
				int heights[] = ;
				_expected = ;
				_received = _obj.minHeight(vector <int>(positions, positions+sizeof(positions)/sizeof(int)), vector <int>(heights, heights+sizeof(heights)/sizeof(int))); break;
			}*/
			/*case 4:
			{
				int positions[] = ;
				int heights[] = ;
				_expected = ;
				_received = _obj.minHeight(vector <int>(positions, positions+sizeof(positions)/sizeof(int)), vector <int>(heights, heights+sizeof(heights)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int positions[] = ;
				int heights[] = ;
				_expected = ;
				_received = _obj.minHeight(vector <int>(positions, positions+sizeof(positions)/sizeof(int)), vector <int>(heights, heights+sizeof(heights)/sizeof(int))); break;
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
