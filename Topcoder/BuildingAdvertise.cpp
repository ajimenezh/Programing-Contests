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


class BuildingAdvertise {
	public:
	long long getMaxArea(vector <int> h, int n) ;
};

int v[100010];
int v2[100010];
map<int,int> id;
map<int,int> inv;
int mi[100010];
int ma[100010];
int m;
int n;
int l[100010];
int r[100010];

void update(int x, int val, int w) {
    if (w==1) for (int y=x; y<=m; y+=y&-y) mi[y] = min(mi[y], val);
    if (w==2) for (int y=x; y<=m; y+=y&-y) ma[y] = max(ma[y], val);
}

int getmin(int x) {
    int res = n;
    for (;x>=1; x-=x&-x) res = min(mi[x], res);
    return res;
}

int getmax(int x) {
    int res = -1;
    for (;x>=1; x-=x&-x) res = max(ma[x], res);
    return res;
}

long long BuildingAdvertise::getMaxArea(vector <int> h, int _n) {
	int j = 0;
	int mm = h.size();
	n = _n;
	for (int i=0; i<n; i++) {
        v[i] = h[j];
        int s = (j+1)%mm;
        h[j] = ((h[j]^h[s])+13)%835454957;
        j = s;
	}
	for (int i=0; i<n; i++) v2[i] = v[i];
	sort(v2,v2+n);
	int k = 1;
	for (int i=0; i<n; i++) if (i==0 || v2[i]!=v2[i-1]) {
        inv[k] = v2[i];
        id[v2[i]] = k++;
	}
	for (int i=0; i<n; i++) v[i] = id[v[i]];
	m = k;
	for (int i=0; i<n; i++) {
        mi[i] = n;
        ma[i] = -1;
	}
	for (int i=0; i<n; i++) {
        l[i] = getmax(v[i]-1);
        update(v[i],i,2);
	}
	for (int i=n-1; i>=0; i--) {
        r[i] = getmin(v[i]-1);
        update(v[i],i,1);
	}

	long long ans = 0;
	for (int i=0; i<n; i++) {
        int k2 = r[i];
        int k1 = l[i];
        //cout<<k1<<" "<<k2<<" "<<v[i]<<endl;
        if (k1!=-1 && k2!=n) ans = max(ans, (long long)(k2-k1-1)*inv[v[i]]);
        else if (k1==-1 && k2!=n) ans = max(ans, (long long)(k2)*inv[v[i]]);
        else if (k1!=-1 && k2==n)  ans = max(ans, (long long)(k2-k1-1)*inv[v[i]]);
        else ans = max(ans, (long long)(n)*inv[v[i]]);
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
		cout << "Testing BuildingAdvertise (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1388750141;
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
		BuildingAdvertise _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int h[] = {3,6,5,6,2,4};
				int n = 6;
				_expected = 15LL;
				_received = _obj.getMaxArea(vector <int>(h, h+sizeof(h)/sizeof(int)), n); break;
			}
			case 1:
			{
				int h[] = {5,0,7,0,2,6,2};
				int n = 7;
				_expected = 7LL;
				_received = _obj.getMaxArea(vector <int>(h, h+sizeof(h)/sizeof(int)), n); break;
			}
			case 2:
			{
				int h[] = {1048589,2097165};
				int n = 100000;
				_expected = 104858900000LL;
				_received = _obj.getMaxArea(vector <int>(h, h+sizeof(h)/sizeof(int)), n); break;
			}
			case 3:
			{
				int h[] = {1,7,2,5,3,1};
				int n = 6;
				_expected = 8LL;
				_received = _obj.getMaxArea(vector <int>(h, h+sizeof(h)/sizeof(int)), n); break;
			}
			/*case 4:
			{
				int h[] = ;
				int n = ;
				_expected = LL;
				_received = _obj.getMaxArea(vector <int>(h, h+sizeof(h)/sizeof(int)), n); break;
			}*/
			/*case 5:
			{
				int h[] = ;
				int n = ;
				_expected = LL;
				_received = _obj.getMaxArea(vector <int>(h, h+sizeof(h)/sizeof(int)), n); break;
			}*/
			/*case 6:
			{
				int h[] = ;
				int n = ;
				_expected = LL;
				_received = _obj.getMaxArea(vector <int>(h, h+sizeof(h)/sizeof(int)), n); break;
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
