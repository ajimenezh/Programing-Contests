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
#define y1 Y1
#define y2 Y2

class Shadow {
	public:
	double area(vector <int> tree, vector <int> light) ;
};

#define eps 1.0e-8

bool leftTurn(double x1, double y1, double x2, double y2, double x3, double y3) {
    return (x2-x1)*(y3-y1) - (y2-y1)*(x3-x1) > eps;
}

vector< pair<double,double> > convexHull(vector<pair<double,double> > pol) {
    sort(pol.begin(),pol.end());
    pol.erase(unique(pol.begin(),pol.end()),pol.end());

    vector<pair<double,pair<double,double> > > p;
    vector<pair<double,double> > ans;

    int tn = pol.size();

    double midx = 0.0, midy = 0.0;
    for (int i=0; i<tn; i++) midx += pol[i].first;
    for (int i=0; i<tn; i++) midy += pol[i].second;
    midx /= (double)tn;
    midy /= (double)tn;

    for (int i=0; i<tn; i++) p.push_back(make_pair(atan2((double)pol[i].second - midy, (double)pol[i].first - midx), make_pair(pol[i].first,pol[i].second)));

    sort(p.begin(),p.end());
    reverse(p.begin(),p.end());

    for (int i=0; i<tn; i++) {
        ans.push_back(make_pair(p[i].second.first,p[i].second.second));
        while (ans.size()>2) {
            int bz = ans.size();
            if (leftTurn(ans[bz-1].first,ans[bz-1].second, ans[bz-2].first, ans[bz-2].second, ans[bz-3].first, ans[bz-3].second)) break;
            swap(ans[bz-1],ans[bz-2]);
            ans.pop_back();
        }
    }
    int pd = 0;
    while (ans.size()-pd>2) {
        int bz = ans.size();
        if (!leftTurn(ans[pd].first,ans[pd].second, ans[bz-1].first, ans[bz-1].second, ans[bz-2].first, ans[bz-2].second)) {
            ans.pop_back();
            continue;
        }
        bz = ans.size();
        if (!leftTurn(ans[pd+1].first,ans[pd+1].second, ans[pd].first, ans[pd].second, ans[bz-1].first, ans[bz-1].second)) {
            pd++;
            continue;
        }
        break;
    }
    vector<pair<double,double> > trans;
    for (int i=pd; i<ans.size(); i++) trans.push_back(ans[i]);
    return trans;
}

double areaPol(vector<pair<double,double> > pol) {
    double ans = 0;
    for (int i=0; i<pol.size(); i++) {
        int j = (i+1)%pol.size();
        ans += pol[i].first*pol[j].second - pol[i].second*pol[j].first;
    }
    return fabs(ans)/2.0;
}

int x1,x2,y1,y2,z1,z2;
int h;
int xp, yp, zp;

struct point{
    int x,y,z;
    point();
    point(int x, int y, int z) : x(x), y(y), z(z){};
};

double Shadow::area(vector <int> tree, vector <int> light) {
	x1 = tree[0];
	y1 = tree[1];
	z1 = tree[2];
	x2 = tree[3];
	y2 = tree[4];
	z2 = tree[5];
	h = max(y1,y2);
    xp = light[0];
    yp = light[1];
    zp = light[2];

    if (yp<=h) {
        if (x1==x2 && y1==y2 && z1==z2) return 0.0;
        if (x1==x2 && y1==y2) return 0.0;
        if (x1==x2 && z1==z2) return 0.0;
        if (y1==y2 && z1==z2) return 0.0;
        if (x1==x2 && xp==x1) return 0.0;
        if (z1==z2 && zp==z1) return 0.0;
        if (y1==y2 && yp==y1) return 0.0;
        if (yp<=min(y1,y2) && min(y1,y2)!=0) return 0.0;
        return -1.0;
    }
    else {
        vector<point> pol;
        for (int i=0; i<2; i++) {
            for (int j=0; j<2; j++) {
                for (int k=0; k<2; k++) {
                    pol.push_back(point(tree[3*i],tree[3*j+1],tree[3*k+2]));
                }
            }
        }
        vector<pair<double,double> > shadow;
        for (int i=0; i<pol.size(); i++) {
            point v = point(pol[i].x-xp, pol[i].y-yp, pol[i].z-zp);

            double t = -1.0*yp / v.y;
            shadow.push_back(make_pair(xp + t*v.x, zp + t*v.z));
        }
        shadow = convexHull(shadow);
        return areaPol(shadow);
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
		cout << "Testing Shadow (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1388665752;
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
		Shadow _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int tree[] = {1,1,1, 10,1,1};
				int light[] = {5,5,5};
				_expected = 0.0;
				_received = _obj.area(vector <int>(tree, tree+sizeof(tree)/sizeof(int)), vector <int>(light, light+sizeof(light)/sizeof(int))); break;
			}
			case 1:
			{
				int tree[] = {1,3,1, 10,1,1};
				int light[] = {2,2,2};
				_expected = -1.0;
				_received = _obj.area(vector <int>(tree, tree+sizeof(tree)/sizeof(int)), vector <int>(light, light+sizeof(light)/sizeof(int))); break;
			}
			case 2:
			{
				int tree[] = {1,1,1, 2,2,2};
				int light[] = {3,3,3};
				_expected = 15.75;
				_received = _obj.area(vector <int>(tree, tree+sizeof(tree)/sizeof(int)), vector <int>(light, light+sizeof(light)/sizeof(int))); break;
			}
			case 3:
			{
				int tree[] =  {1,1,1, 3,3,3} ;
				int light[] = {2,2,2};
				_expected = -1.0;
				_received = _obj.area(vector <int>(tree, tree+sizeof(tree)/sizeof(int)), vector <int>(light, light+sizeof(light)/sizeof(int))); break;
			}
			/*case 4:
			{
				int tree[] = ;
				int light[] = ;
				_expected = ;
				_received = _obj.area(vector <int>(tree, tree+sizeof(tree)/sizeof(int)), vector <int>(light, light+sizeof(light)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int tree[] = ;
				int light[] = ;
				_expected = ;
				_received = _obj.area(vector <int>(tree, tree+sizeof(tree)/sizeof(int)), vector <int>(light, light+sizeof(light)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int tree[] = ;
				int light[] = ;
				_expected = ;
				_received = _obj.area(vector <int>(tree, tree+sizeof(tree)/sizeof(int)), vector <int>(light, light+sizeof(light)/sizeof(int))); break;
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
