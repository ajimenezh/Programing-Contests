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


class Aircraft {
	public:
	string nearMiss(vector <int> p1, vector <int> v1, vector <int> p2, vector <int> v2, int R) ;
};

int dist2(vector<int> p1, vector<int> p2) {
    int d = 0;
    for (int i=0; i<3; i++) {
        int c = p1[i] - p2[i];
        d += c*c;
    }
    return d;
}

vector<double> propagate(vector <int> p, vector <int> v, double t) {
    vector<double> q = vector<double>(3,0.0);

    for (int i=0; i<3; i++) q[i] = p[i] + (double)v[i]*t;

    return q;
}

double dist(vector<double> p1, vector<double> p2) {
    double d = 0;
    for (int i=0; i<3; i++) {
        double c = p1[i] - p2[i];
        d += c*c;
    }
    return sqrt(d);
}

string Aircraft::nearMiss(vector <int> p1, vector <int> v1, vector <int> p2, vector <int> v2, int R) {
    if (v1==v2) {
        if (dist2(p1,p2)>R*R) return "NO";
        else return "YES";
    }
    else {
        double lo = -1000000.0;
        double hi = 1000000.0;
        for (int i=0; i<100; i++) {
            double l = (2*lo + hi)/3;
            double r = (2*hi + lo)/3;

            vector<double> pl1 = propagate(p1, v1, l);
            vector<double> pl2 = propagate(p2, v2, l);
            vector<double> pr1 = propagate(p1, v1, r);
            vector<double> pr2 = propagate(p2, v2, r);

            double dl = dist(pl1,pl2);
            double dr = dist(pr1,pr2);

            //cout<<lo<<" "<<hi<<" "<<dl<<" "<<dr<<endl;

            if (dl < dr) {
                hi = r;
            }
            else {
                lo = l;
            }

        }

        vector<double> pl1 = propagate(p1, v1, lo);
        vector<double> pl2 = propagate(p2, v2, lo);

        double dl = dist(pl1,pl2);

        if (R-dl>-1.0e-6 && lo>-1.0e-6) return "YES";
        return "NO";
    }
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
		cout << "Testing Aircraft (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1391173531;
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
		Aircraft _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int p1[] = {15,50,5};
				int v1[] = {25,1,0};
				int p2[] = {161,102,9};
				int v2[] = {-10,-10,-1};
				int R = 10;
				_expected = "YES";
				_received = _obj.nearMiss(vector <int>(p1, p1+sizeof(p1)/sizeof(int)), vector <int>(v1, v1+sizeof(v1)/sizeof(int)), vector <int>(p2, p2+sizeof(p2)/sizeof(int)), vector <int>(v2, v2+sizeof(v2)/sizeof(int)), R); break;
			}
			case 1:
			{
				int p1[] = {0,0,0};
				int v1[] = {2,2,0};
				int p2[] = {9,0,5};
				int v2[] = {-2,2,0};
				int R = 5;
				_expected = "YES";
				_received = _obj.nearMiss(vector <int>(p1, p1+sizeof(p1)/sizeof(int)), vector <int>(v1, v1+sizeof(v1)/sizeof(int)), vector <int>(p2, p2+sizeof(p2)/sizeof(int)), vector <int>(v2, v2+sizeof(v2)/sizeof(int)), R); break;
			}
			case 2:
			{
				int p1[] = {0,0,0};
				int v1[] = {-2,2,0};
				int p2[] = {9,0,5};
				int v2[] = {2,2,0};
				int R = 5;
				_expected = "NO";
				_received = _obj.nearMiss(vector <int>(p1, p1+sizeof(p1)/sizeof(int)), vector <int>(v1, v1+sizeof(v1)/sizeof(int)), vector <int>(p2, p2+sizeof(p2)/sizeof(int)), vector <int>(v2, v2+sizeof(v2)/sizeof(int)), R); break;
			}
			case 3:
			{
				int p1[] = {-2838,-7940,-2936};
				int v1[] = {1,1,-2};
				int p2[] = {532,3850,9590};
				int v2[] = {1,0,-3};
				int R = 3410;
				_expected = "YES";
				_received = _obj.nearMiss(vector <int>(p1, p1+sizeof(p1)/sizeof(int)), vector <int>(v1, v1+sizeof(v1)/sizeof(int)), vector <int>(p2, p2+sizeof(p2)/sizeof(int)), vector <int>(v2, v2+sizeof(v2)/sizeof(int)), R); break;
			}
			case 4:
			{
				int p1[] = {-8509,9560,345};
				int v1[] = {-89,-33,62};
				int p2[] = {-5185,-1417,2846};
				int v2[] = {-58,24,26};
				int R = 8344;
				_expected = "YES";
				_received = _obj.nearMiss(vector <int>(p1, p1+sizeof(p1)/sizeof(int)), vector <int>(v1, v1+sizeof(v1)/sizeof(int)), vector <int>(p2, p2+sizeof(p2)/sizeof(int)), vector <int>(v2, v2+sizeof(v2)/sizeof(int)), R); break;
			}
			case 5:
			{
				int p1[] = {-7163,-371,-2459};
				int v1[] = {-59,-41,-14};
				int p2[] = {-2398,-426,-5487};
				int v2[] = {-43,27,67};
				int R = 5410;
				_expected = "NO";
				_received = _obj.nearMiss(vector <int>(p1, p1+sizeof(p1)/sizeof(int)), vector <int>(v1, v1+sizeof(v1)/sizeof(int)), vector <int>(p2, p2+sizeof(p2)/sizeof(int)), vector <int>(v2, v2+sizeof(v2)/sizeof(int)), R); break;
			}
			case 6:
			{
				int p1[] = {1774,-4491,7810};
				int v1[] = {-12,19,-24};
				int p2[] = {2322,3793,9897};
				int v2[] = {-12,19,-24};
				int R = 10000;
				_expected = "YES";
				_received = _obj.nearMiss(vector <int>(p1, p1+sizeof(p1)/sizeof(int)), vector <int>(v1, v1+sizeof(v1)/sizeof(int)), vector <int>(p2, p2+sizeof(p2)/sizeof(int)), vector <int>(v2, v2+sizeof(v2)/sizeof(int)), R); break;
			}
			case 7:
			{
				int p1[] = {3731,8537,5661};
				int v1[] = {-70,71,32};
				int p2[] = {8701,-1886,-5115};
				int v2[] = {28,-13,7};
				int R = 9766;
				_expected = "NO";
				_received = _obj.nearMiss(vector <int>(p1, p1+sizeof(p1)/sizeof(int)), vector <int>(v1, v1+sizeof(v1)/sizeof(int)), vector <int>(p2, p2+sizeof(p2)/sizeof(int)), vector <int>(v2, v2+sizeof(v2)/sizeof(int)), R); break;
			}
			/*case 8:
			{
				int p1[] = ;
				int v1[] = ;
				int p2[] = ;
				int v2[] = ;
				int R = ;
				_expected = ;
				_received = _obj.nearMiss(vector <int>(p1, p1+sizeof(p1)/sizeof(int)), vector <int>(v1, v1+sizeof(v1)/sizeof(int)), vector <int>(p2, p2+sizeof(p2)/sizeof(int)), vector <int>(v2, v2+sizeof(v2)/sizeof(int)), R); break;
			}*/
			/*case 9:
			{
				int p1[] = ;
				int v1[] = ;
				int p2[] = ;
				int v2[] = ;
				int R = ;
				_expected = ;
				_received = _obj.nearMiss(vector <int>(p1, p1+sizeof(p1)/sizeof(int)), vector <int>(v1, v1+sizeof(v1)/sizeof(int)), vector <int>(p2, p2+sizeof(p2)/sizeof(int)), vector <int>(v2, v2+sizeof(v2)/sizeof(int)), R); break;
			}*/
			/*case 10:
			{
				int p1[] = ;
				int v1[] = ;
				int p2[] = ;
				int v2[] = ;
				int R = ;
				_expected = ;
				_received = _obj.nearMiss(vector <int>(p1, p1+sizeof(p1)/sizeof(int)), vector <int>(v1, v1+sizeof(v1)/sizeof(int)), vector <int>(p2, p2+sizeof(p2)/sizeof(int)), vector <int>(v2, v2+sizeof(v2)/sizeof(int)), R); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

//END CUT HERE
