#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class CheckerFreeness {
public:
	string isFree(vector <string>, vector <string>, vector <string>, vector <string>);
};

typedef long long LL;

const double EPS = 1E-9 ;

struct pt{
	LL x,y;
	
	pt(LL _x=-1, LL _y=-1) {
		x = _x;
		y = _y;
	}
};

struct seg{
	pt p, q;
	int id;

	double get_y(double x) {
		if ( abs(p.x - q.x) < EPS )  return p.y ;
		return 1.0*p.y + 1.0*(q.y - p.y)*(x-p.x)/(1.0*q.x - 1.0*p.x);
	}
};

vector<seg> v_Seg;
int cnt;
int n;
void add(pt a, pt b)
{
	seg s;
	s.p = a;
	s.q = b;
	s.id = cnt++;
	v_Seg.push_back(s);
}
	

bool intersect1d(LL l1, LL r1, LL l2, LL r2) {
	if (l1 > r1)  return intersect1d(r1,l1,l2,r2);
	if (l2 > r2)  return intersect1d(l1,r1,r2,l2);
	return max(l1, l2) <= min(r1, r2) + EPS ;
}

int vec_sgn(pt a, pt b, pt c ) {
	long long s = (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
	return abs(s) < 0 ? 0 : s>0 ? +1 : -1 ;
}

bool intersect(seg a, seg b) {
	return intersect1d(a.p.x, a.q.x, b.p.x, b.q.x)
		&& intersect1d(a.p.y, a.q.y, b.p.y, b.q.y)
		&& vec_sgn(a.p, a.q, b.p)*vec_sgn( a.p, a.q, b.q) <= 0
		&& vec_sgn(b.p, b.q, a.p)*vec_sgn(b.p, b.q, a.q) <= 0 ;
}


bool operator < ( seg a, seg b ) {
	double x = max(min(a.p.x, a.q.x), min(b.p.x, b.q.x));
	return a.get_y(x) < b.get_y(x) - EPS;
}

struct event{
	double x;
	int tp, id;

	event (double _x=0, int _tp=0, int _id=0) {
		x = _x; tp = _tp; id = _id;
	}

	bool operator < (const event & e) const {
		if ( abs(x - e.x) > EPS)  return x < e.x;
		return tp > e.tp;
	}
} ;

set<seg> s;
vector<set<seg>::iterator > where;

set<seg>::iterator prev(set<seg>::iterator it) {
	return it == s.begin() ? s.end() : --it;
}

inline set<seg>::iterator next(set<seg>::iterator it) {
	return ++it;
}

bool diff(int a, int b)
{
	if (a<n && b>=n) return true;
	if (a>=n && b<n) return true;
	return false;
}

pair <int,int> solve(const vector<seg> & a) {
	int n = (int) a.size();
	vector<event> e;
	for (int i = 0; i < n; ++i) {
		e.push_back(event(min(a[i].p.x, a[i].q.x), + 1, i));
		e.push_back(event(max(a[i].p.x, a[i].q.x), - 1, i));
	}
	sort(e.begin(), e.end());

	s.clear();
	where.resize(a.size());
	for (size_t i = 0; i < e.size(); ++i ) {
		int id = e[i].id;
		if ( e[i].tp == +1 ) {
			set<seg>::iterator
				nxt = s.lower_bound(a[id]),
				prv = prev(nxt);
			if (nxt!= s.end() && intersect(*nxt, a[id]) && diff(nxt->id,id))
				return make_pair(nxt->id,id);
			if (prv != s.end() && intersect(*prv, a[id]) && diff(nxt->id,id))
				return make_pair(prv->id, id);
			where[id] = s.insert(nxt, a[id]);
		}
		else {
			set<seg>::iterator
				nxt = next(where[id]),
				prv = prev(where[id]);
			if ( nxt != s.end() && prv != s.end() && intersect(*nxt, *prv) && diff(nxt->id,id))
				return make_pair(prv->id, nxt->id);
			s.erase(where[id]);
		}
	}

	return make_pair(-1,-1);
}

string wX, wY, bX, bY;
vector<LL> pwX,pwY,pbX,pbY;

string CheckerFreeness::isFree(vector <string> whiteX, vector <string> whiteY, vector <string> blackX, vector <string> blackY) {
	cnt = 0;
	
	for (int i=0; i<whiteX.size(); i++) wX += whiteX[i];
	for (int i=0; i<whiteY.size(); i++) wY += whiteY[i];
	for (int i=0; i<blackX.size(); i++) bX += blackX[i];
	for (int i=0; i<blackY.size(); i++) bY += blackY[i];
	
	string s;
	
	stringstream ss(wX);
	while (ss>>s) pwX.push_back(atoll(s.c_str()));
	stringstream ss2(wY);
	while (ss2>>s) pwY.push_back(atoll(s.c_str()));
	stringstream ss3(bX);
	while (ss3>>s) pbX.push_back(atoll(s.c_str()));
	stringstream ss4(bY);
	while (ss4>>s) pbY.push_back(atoll(s.c_str()));
	
	//for (int i=0; i<pwX.size(); i++) printf("%.4f ",pwX[i]); cout<<endl;
	for (int i=0; i<pwY.size(); i++) cout<<pwY[i]<<" "; cout<<endl;
	for (int i=0; i<pbX.size(); i++) cout<<pbX[i]<<" "; cout<<endl;
	for (int i=0; i<pbY.size(); i++) cout<<pbY[i]<<" "; cout<<endl;
	
	
	for (int i=0; i<pwX.size(); i++) for (int j=i+1; j<pwX.size(); j++) add(pt(pwX[i],pwY[i]),pt(pwX[j],pwY[j]));
	n = cnt;
	for (int i=0; i<pbX.size(); i++) for (int j=i+1; j<pbX.size(); j++) add(pt(pbX[i],pbY[i]),pt(pbX[j],pbY[j]));
	
	
	pair<int,int> pq = solve(v_Seg);
	
	if (pq.first==-1) return "YES";
	return "NO";
	
}


//Powered by [KawigiEdit] 2.0!
