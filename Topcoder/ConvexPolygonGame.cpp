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


class ConvexPolygonGame {
	public:
	string winner(vector <int> X, vector <int> Y) ;
};

int p[12] = {2,3,5,7,11};

int gcd(int a, int b) {
    if (b>a) return gcd(b,a);
    if (b==0) return a;
    return gcd(b,a%b);
}

long long vect(int x1, int y1, int x2, int y2, int x3, int y3) {
    int ux = x2-x1;
    int uy = y2-y1;
    int vx = x3-x1;
    int vy = y3-y1;

    return (long long)ux*vy - (long long)uy*vx;
}

string ConvexPolygonGame::winner(vector <int> X, vector <int> Y) {
    int n = X.size();

    set<pair<int,int> > all;
    set<int> xs,ys;

    for (int i=0; i<n; i++) {
        int j = (i+1)%n;
        int k = gcd(abs(X[i]-X[j]),abs(Y[i]-Y[j]));
        if (k==1) continue;
        int t1 = X[i]-X[j];
        t1 /= k;
        int t2 = Y[i]-Y[j];
        t2 /= k;
        for (int i=1; i<min(k,3); i++) {
            all.insert(make_pair(X[i]+t1,Y[i]+t2));
        }
    }

    if (all.size()==3) return "Masha";

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            bool inside = 1;

            int x = X[i];
            int y = Y[j];

            for (int k=0; k<n; k++) if (x==X[k] && y==Y[k]) inside = 0;

            if (all.find(make_pair(x,y))!=all.end()) inside = 0;

            for (int k=0; k<n; k++) {
                if (vect(x,y,X[k],Y[k],X[(k+1)%n],Y[(k+1)%n])<=0) inside = 0;
            }

            if (inside) all.insert(make_pair(x,y));
        }
    }

    if (all.size()==3) return "Masha";

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<5; k++) {
                if ((X[i]+X[j])%p[k]==0) xs.insert((X[i]+X[j])/p[k]);
                if ((Y[i]+Y[j])%p[k]==0) ys.insert((Y[i]+Y[j])/p[k]);
            }
            if (xs.size()>100 || ys.size()>100) break;
        }
        if (xs.size()>100 || ys.size()>100) break;
    }

    rep(itx,xs) {
        rep(ity,ys) {
            bool inside = 1;

            int x = *itx;
            int y = *ity;

            for (int k=0; k<n; k++) if (x==X[k] && y==Y[k]) inside = 0;

            if (all.find(make_pair(x,y))!=all.end()) inside = 0;

            for (int k=0; k<n; k++) {
                if (vect(x,y,X[k],Y[k],X[(k+1)%n],Y[(k+1)%n])<=0) inside = 0;
            }

            if (inside) all.insert(make_pair(x,y));
        }
    }

    vector<pair<int,int> > v;
    rep(it,all) if (v.size()<200) v.push_back(*it);

    n = v.size();

    for (int i=0; i<n; i++) for (int j=i+1; j<n; j++) for (int k=j+1; k<n; k++) {
        if (vect(v[i].first,v[i].second,v[j].first,v[j].second, v[k].first,v[k].second)!=0) {
            return "Masha";
        }
    }

    return "Petya";
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
		cout << "Testing ConvexPolygonGame (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1384951757;
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
		ConvexPolygonGame _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int X[] = {0, 1, 0};
				int Y[] = {0, 0, 1};
				_expected = "Petya";
				_received = _obj.winner(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}
			case 1:
			{
				int X[] = {0, 4, 2};
				int Y[] = {0, 0, 2};
				_expected = "Masha";
				_received = _obj.winner(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}
			case 2:
			{
				int X[] = {0, 100, 100, 0};
				int Y[] = {0, 0, 100, 100};
				_expected = "Masha";
				_received = _obj.winner(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}
			case 3:
			{
				int X[] = {0, 50, 100, 50};
				int Y[] = {0, -1, 0, 1};
				_expected = "Petya";
				_received = _obj.winner(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}
			case 4:
			{
				int X[] = {-100000, 100000, 100000, -100000};
				int Y[] = {-1, -1, 1, 1};
				_expected = "Masha";
				_received = _obj.winner(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}
			/*case 5:
			{
				int X[] = ;
				int Y[] = ;
				_expected = ;
				_received = _obj.winner(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int X[] = ;
				int Y[] = ;
				_expected = ;
				_received = _obj.winner(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int X[] = ;
				int Y[] = ;
				_expected = ;
				_received = _obj.winner(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
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
