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

#define eps 1.0e-8

class ConvexPolygons {
	public:
	double overlap(vector <string> polygon1, vector <string> polygon2) ;
};

double polarAngle(double xx, double yy) {
    if (fabs(xx) <= eps && fabs(yy) <= eps ) return -1.0;
    if (fabs(xx) <= eps ) return ( yy > eps ? 1.0 : 3.0 )*acos(0);
    double theta = atan(1.0*yy/xx);
    if (xx>eps) return (yy >= -eps ? theta : (4*acos(0) + theta));
    return (2*acos(0) + theta);
}

bool pointInsidePoly( pair<double,double> p, vector<pair<double,double> > pol) {
    double xx = p.first;
    double yy = p.second;
    int n = pol.size();
    double ang = 0.0;
    for (int i=n-1, j=0; j<n; i = j++) {
        double v[2], w[2];
        v[0] = pol[i].first - xx;
        v[1] = pol[i].second - yy;
        w[0] = pol[j].first - xx;
        w[1] = pol[j].second - yy;

        double va = polarAngle( v[0],v[1] );
        double wa = polarAngle( w[0],w[1] );
        double dx = wa - va;
        if (va<-0.5 || wa<-0.5 || fabs( fabs(dx) - 2*acos(0)) < eps) {
            ang += 2.0*acos(0);
            continue;
        }
        if (dx<-2*acos(0)) ang += dx + 4*acos(0);
        else if (dx>2*acos(0)) ang += dx - 4*acos(0);
        else ang += dx;
    }
    return (ang*ang>1.0);
}

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

double area(vector<pair<double,double> > pol) {
    double ans = 0;
    for (int i=0; i<pol.size(); i++) {
        int j = (i+1)%pol.size();
        ans += pol[i].first*pol[j].second - pol[i].second*pol[j].first;
    }
    return fabs(ans)/2.0;
}

double xi,yi; // Result of the line intersection
double ua, ub;
int parallel;
bool lineIntersect(pair<double,double> p1, pair<double,double> p2, pair<double,double> p3, pair<double,double> p4) {
    double x1 = p1.first;
    double y1 = p1.second;
    double x2 = p2.first;
    double y2 = p2.second;
    double x3 = p3.first;
    double y3 = p3.second;
    double x4 = p4.first;
    double y4 = p4.second;
    parallel = 0;
    if (fabs( (x2-x1)*(y4-y3) - (y2-y1)*(x4-x3) ) <= eps) {
        parallel = 1;
        return 0;
    }
    ua = ((x4-x3)*(y1-y3) - (y4-y3)*(x1-x3)) / ((y4-y3)*(x2-x1) - (x4-x3)*(y2-y1));
    ub = ((x2-x1)*(y1-y3) - (y1-y1)*(x1-x3)) / ((y4-y3)*(x2-x1) - (x4-x3)*(y2-y1));
    xi = x1 + ua*(x2-x1);
    yi = y1 + ua*(y2-y1);

    return ( (xi + eps >= fmin(x1,x2)) && (xi - eps <= fmax(x1,x2)) &&
             (yi + eps >= fmin(y1,y2)) && (yi - eps <= fmax(y1,y2)) &&
             (xi + eps >= fmin(x3,x4)) && (xi - eps <= fmax(x3,x4)) &&
             (yi + eps >= fmin(y3,y4)) && (yi - eps <= fmax(y3,y4))
            );
}

double ConvexPolygons::overlap(vector <string> polygon1, vector <string> polygon2) {
    vector<pair<double,double> > p[2];
    vector<pair<double,double> > pol;

    for (int i=0; i<polygon1.size(); i++) {
        int x,y;
        stringstream ss(polygon1[i]);
        string s;
        ss>>s;
        x = atoi(s.c_str());
        ss>>s;
        y = atoi(s.c_str());
        p[0].push_back(make_pair(x,y));
    }
    for (int i=0; i<polygon2.size(); i++) {
        int x,y;
        stringstream ss(polygon2[i]);
        string s;
        ss>>s;
        x = atoi(s.c_str());
        ss>>s;
        y = atoi(s.c_str());
        p[1].push_back(make_pair(x,y));
    }

    for (int i=0; i<2; i++) for (int j=0; j<p[i].size(); j++) {
        if (pointInsidePoly(p[i][j], p[(i+1)%2])) pol.push_back(p[i][j]);
    }

    for (int i=0; i<p[0].size(); i++) for (int j=0; j<p[1].size(); j++) {
        int k = (i+1)%p[0].size();
        int l = (j+1)%p[1].size();
        if (lineIntersect(p[0][i],p[0][k],p[1][j],p[1][l])) {
            pol.push_back(make_pair(xi,yi));
        }
    }

    return area(convexHull(pol));

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
		cout << "Testing ConvexPolygons (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1379968285;
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
		ConvexPolygons _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string polygon1[] = {"00 00","02 00","00 03"};
				string polygon2[] = {"1 1","3 1","3 3", "1 3"};
				_expected = 0.08333333333333326;
				_received = _obj.overlap(vector <string>(polygon1, polygon1+sizeof(polygon1)/sizeof(string)), vector <string>(polygon2, polygon2+sizeof(polygon2)/sizeof(string))); break;
			}
			case 1:
			{
				string polygon1[] = {"-1 -1","1 -1","1 1","-1 1"};
				string polygon2[] = {"-2 -2","0 -2","2 -2","2 0","2 2","0 2","-2 2","-2 0"};
				_expected = 4.0;
				_received = _obj.overlap(vector <string>(polygon1, polygon1+sizeof(polygon1)/sizeof(string)), vector <string>(polygon2, polygon2+sizeof(polygon2)/sizeof(string))); break;
			}
			case 2:
			{
				string polygon1[] = {"-1 -1","-2 -1","-1 -2"};
				string polygon2[] = {"1 1","2 1","1 2"};
				_expected = 0.0;
				_received = _obj.overlap(vector <string>(polygon1, polygon1+sizeof(polygon1)/sizeof(string)), vector <string>(polygon2, polygon2+sizeof(polygon2)/sizeof(string))); break;
			}
			case 3:
			{
				string polygon1[] = {"-2 0","-1 -2","1 -2","2 0","1 2","-1 2"};
				string polygon2[] = {"0 -3","1 -1","2 2","-1 0"};
				_expected = 5.233333333333333;
				_received = _obj.overlap(vector <string>(polygon1, polygon1+sizeof(polygon1)/sizeof(string)), vector <string>(polygon2, polygon2+sizeof(polygon2)/sizeof(string))); break;
			}
			/*case 4:
			{
				string polygon1[] = ;
				string polygon2[] = ;
				_expected = ;
				_received = _obj.overlap(vector <string>(polygon1, polygon1+sizeof(polygon1)/sizeof(string)), vector <string>(polygon2, polygon2+sizeof(polygon2)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string polygon1[] = ;
				string polygon2[] = ;
				_expected = ;
				_received = _obj.overlap(vector <string>(polygon1, polygon1+sizeof(polygon1)/sizeof(string)), vector <string>(polygon2, polygon2+sizeof(polygon2)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string polygon1[] = ;
				string polygon2[] = ;
				_expected = ;
				_received = _obj.overlap(vector <string>(polygon1, polygon1+sizeof(polygon1)/sizeof(string)), vector <string>(polygon2, polygon2+sizeof(polygon2)/sizeof(string))); break;
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
