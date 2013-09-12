#line 2 "EnclosingTriangleColorful.cpp"

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
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

#define fo(i,n) for(int i=0; i<(int)n; i++)
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

class EnclosingTriangleColorful {
	public:
	int n;
	int p[300*4];
	vector<int> x,y;
	bool good[300*4][300*4];
	int px[300*4], py[300*4];
	
	int cross(int x1, int y1, int x2, int y2) {
		return x1*y2 - y1*x2;
	}
	
	int getNumber(int m, vector <int> _x, vector <int> _y) {
		x = _x;
		y = _y;
		n = x.size();
		m--;
		for (int i=0; i<m; i++) {
			px[i] = i+1;
			py[i] = 0;
		}
		for (int i=m; i<2*m; i++) {
			px[i] = m+1;
			py[i] = i+1-m;
		}
		for (int i=2*m; i<3*m; i++) {
			px[i] = i+1-2*m;
			py[i] = m+1;
		}
		for (int i=3*m; i<4*m; i++) {
			px[i] = 0;
			py[i] = i+1-3*m;
		}
		
		for (int i=0; i<4*m; i++) {
			for (int j=0; j<4*m; j++) {
				if (i/m != j/m) {
					int ma = -1000000;
					for (int k=0; k<n; k++) {
						int c = cross(px[j]-px[i],py[j]-py[i],x[k]-px[i],y[k]-py[i]);
						ma = max(ma,c);
					}
					if (i==6 && j==3) cout<<ma<<endl;
					if (ma<=0) {
						good[i][j] = 1;
					}
				}
			}
		}
		
		int ans = 0;
		for (int i=0; i<m; i++) {
			for (int j=m; j<2*m; j++) {
				for (int k=2*m; k<4*m; k++) {
					if (good[i][j] && good[j][k] && good[k][i]) ans++;
					if (good[i][k] && good[k][j] && good[j][i]) ans++;
				}
			}
			for (int j=2*m; j<3*m; j++) {
				for (int k=3*m; k<4*m; k++) {
					if (good[i][j] && good[j][k] && good[k][i]) ans++;
					if (good[i][k] && good[k][j] && good[j][i]) ans++;
				}
			}  
		}
		for (int i=m; i<2*m; i++) {
			for (int j=2*m; j<3*m; j++) {
				for (int k=3*m; k<4*m; k++) {
					if (good[i][j] && good[j][k] && good[k][i]) ans++;
					if (good[i][k] && good[k][j] && good[j][i]) ans++;
				}
			}  
		}
		
		return ans;
	}
};

// BEGIN CUT HERE
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
		cout << "Testing EnclosingTriangleColorful (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1375375270;
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
		EnclosingTriangleColorful _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int m = 4;
				int x[] = { 1, 2, 3 };
				int y[] = { 1, 3, 2 };
				_expected = 8;
				_received = _obj.getNumber(m, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 1:
			{
				int m = 7;
				int x[] = { 1, 1, 6, 6 };
				int y[] = { 1, 6, 1, 6 };
				_expected = 0;
				_received = _obj.getNumber(m, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 2:
			{
				int m = 4;
				int x[] = { 2 };
				int y[] = { 2 };
				_expected = 72;
				_received = _obj.getNumber(m, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 3:
			{
				int m = 10;
				int x[] = { 2, 6, 7, 6 };
				int y[] = { 7, 7, 9, 3 };
				_expected = 52;
				_received = _obj.getNumber(m, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 4:
			{
				int m = 15;
				int x[] = { 7, 6, 5, 4, 3 };
				int y[] = { 1, 4, 7, 10, 13 };
				_expected = 150;
				_received = _obj.getNumber(m, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 5:
			{
				int m = 300;
				int x[] = { 117, 183, 181, 118, 132, 128, 184, 150, 168, 121, 
				            179, 132, 168, 182, 119, 117, 180, 120, 175, 177, 
				            116, 175, 128, 163, 181, 178, 123, 118, 172, 143, 
				            163, 157, 179, 122, 121, 119, 157, 122, 150, 180, 
				            137, 177, 125, 123, 172, 125, 137, 143, 120, 178 };
				int y[] = { 157, 157, 132, 163, 181, 180, 150, 116, 181, 125, 
				            125, 119, 119, 163, 132, 143, 172, 172, 179, 178, 
				            150, 121, 120, 118, 168, 123, 178, 137, 120, 117, 
				            182, 117, 175, 177, 175, 168, 183, 123, 184, 128, 
				            118, 122, 179, 122, 180, 121, 182, 183, 128, 177 };
				_expected = 21690886;
				_received = _obj.getNumber(m, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			/*case 6:
			{
				int m = ;
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.getNumber(m, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int m = ;
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.getNumber(m, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int m = ;
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.getNumber(m, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
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

// END CUT HERE
