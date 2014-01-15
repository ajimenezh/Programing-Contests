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


class ExpensiveTravel {
	public:
	int minTime(vector <string> m, int startRow, int startCol, int endRow, int endCol) ;
};

int gcd(int a, int b) {
    if (b>a) return  gcd(b,a);
    if (b==0) return  a;
    return gcd(b,a%b);
}

struct frac{
    int x,y;
    frac(int _x,int _y) {
        x = _x; y = _y;
        int g = gcd(x,y);
        x /= g;
        y /= g;
    }
    frac() {
        x = 0; y = 1;
    }
    bool operator <(frac b) {
        return x*b.y < y*b.x;
    }
};

frac sum(frac a, frac b) {
    frac c = frac(a.x*b.y + b.x*a.y, a.y*b.y);
    return c;
}

frac dist[55][55];
priority_queue<pair<double, int> > q;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int ExpensiveTravel::minTime(vector <string> a, int startRow, int startCol, int endRow, int endCol) {
    int n = a.size();
    int m = a[0].length();
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            dist[i][j] = frac(1000000,1);
        }
    }
    startRow--; startCol--;
    endRow--; endCol--;
    dist[startRow][startCol] = frac(99,100);
    q.push(make_pair(0, m*startRow + startCol));

    while (q.size()>0) {
        int p = q.top().second;
        q.pop();
        int x = p/m;
        int y = p%m; //cout<<x<<" "<<y<<" "<<dist[x][y].x<<"/"<<dist[x][y].y<<endl;
        frac d = dist[x][y];

        int t1 = d.x / d.y;

        for (int k=0; k<4; k++) {
            int xx = x+dx[k];
            int yy = y+dy[k];
            if (xx<0 || xx>=n) continue;
            if (yy<0 || yy>=m) continue;
            if (a[xx][yy]=='1') continue;

            frac tmp = sum(d, frac(1,a[xx][yy]-'0'));

            //cout<<xx<<" "<<yy<<" "<<tmp.x<<"/"<<tmp.y<<" "<<a[xx][yy]<<endl;

            int t2 = tmp.x/tmp.y;

            if (t1==t2 && d.x%d.y!=0) {
                if (tmp < dist[xx][yy]) {
                    dist[xx][yy] = tmp;
                    q.push(make_pair((double)tmp.x/tmp.y, xx*m+yy));
                }
            }
            else {
                tmp = frac(d.x/d.y, 1);
                if (d.x%d.y!=0) tmp = sum(tmp, frac(1,1));
                //cout<<tmp.x<<"/"<<tmp.y<<endl;
                tmp = sum(tmp, frac(1,a[xx][yy]-'0'));
                tmp = sum(tmp, frac(1,a[x][y]-'0'));
                if (tmp < dist[xx][yy]) {
                    dist[xx][yy] = tmp;
                    q.push(make_pair((double)tmp.x/tmp.y, xx*m+yy));
                }
            }
        }
    }

    int res = 0;
    if (dist[endRow][endCol].x%dist[endRow][endCol].y==0) res = dist[endRow][endCol].x/dist[endRow][endCol].y;
    else res = dist[endRow][endCol].x/dist[endRow][endCol].y + 1;

    if (res>1000000-10) return -1;
    return res-1;
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
		cout << "Testing ExpensiveTravel (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1388521499;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 550.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ExpensiveTravel _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string m[] = {"22334"};
				int startRow = 1;
				int startCol = 1;
				int endRow = 1;
				int endCol = 5;
				_expected = 3;
				_received = _obj.minTime(vector <string>(m, m+sizeof(m)/sizeof(string)), startRow, startCol, endRow, endCol); break;
			}
			case 1:
			{
				string m[] = {"55",
				              "52",
				              "55"};
				int startRow = 1;
				int startCol = 2;
				int endRow = 3;
				int endCol = 2;
				_expected = 1;
				_received = _obj.minTime(vector <string>(m, m+sizeof(m)/sizeof(string)), startRow, startCol, endRow, endCol); break;
			}
			case 2:
			{
				string m[] = {"251",
				              "212",
				              "122"};
				int startRow = 1;
				int startCol = 1;
				int endRow = 3;
				int endCol = 3;
				_expected = -1;
				_received = _obj.minTime(vector <string>(m, m+sizeof(m)/sizeof(string)), startRow, startCol, endRow, endCol); break;
			}
			case 3:
			{
				string m[] = {"452232",
				              "287979",
				              "219872",
				              "928234",
				              "767676"};
				int startRow = 1;
				int startCol = 6;
				int endRow = 3;
				int endCol = 1;
				_expected = 3;
				_received = _obj.minTime(vector <string>(m, m+sizeof(m)/sizeof(string)), startRow, startCol, endRow, endCol); break;
			}
			case 4:
			{
				string m[] = {"11"};
				int startRow = 1;
				int startCol = 1;
				int endRow = 1;
				int endCol = 2;
				_expected = -1;
				_received = _obj.minTime(vector <string>(m, m+sizeof(m)/sizeof(string)), startRow, startCol, endRow, endCol); break;
			}
			case 5:
			{
				string m[] = {"123456789987654321"};
				int startRow = 1;
				int startCol = 2;
				int endRow = 1;
				int endCol = 16;
				_expected = 5;
				_received = _obj.minTime(vector <string>(m, m+sizeof(m)/sizeof(string)), startRow, startCol, endRow, endCol); break;
			}
			/*case 6:
			{
				string m[] = ;
				int startRow = ;
				int startCol = ;
				int endRow = ;
				int endCol = ;
				_expected = ;
				_received = _obj.minTime(vector <string>(m, m+sizeof(m)/sizeof(string)), startRow, startCol, endRow, endCol); break;
			}*/
			/*case 7:
			{
				string m[] = ;
				int startRow = ;
				int startCol = ;
				int endRow = ;
				int endCol = ;
				_expected = ;
				_received = _obj.minTime(vector <string>(m, m+sizeof(m)/sizeof(string)), startRow, startCol, endRow, endCol); break;
			}*/
			/*case 8:
			{
				string m[] = ;
				int startRow = ;
				int startCol = ;
				int endRow = ;
				int endCol = ;
				_expected = ;
				_received = _obj.minTime(vector <string>(m, m+sizeof(m)/sizeof(string)), startRow, startCol, endRow, endCol); break;
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
