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


class MayTheBestPetWin {
	public:
	int calc(vector <int> A, vector <int> B) ;
};

int n;
int suma, sumb;
bool vis[2][1000002];
int best;
vector<int> a,b;

void dfs(int i, int s) {
    if (i>=n) {
        int tmp = abs(s);
        tmp = max(tmp, s - suma + sumb);
        best = min(best,tmp);
        return;
    }
    if (vis[i][s+500000]) return;

    dfs(i+1, s+a[i]);
    dfs(i+1, s-b[i]);

    vis[i][s+500000] = 1;
    return;
}

int MayTheBestPetWin::calc(vector <int> A, vector <int> B) {
    n = A.size();
    a = A; b = B;
    for (int i=0; i<n; i++) suma += a[i];
    for (int i=0; i<n; i++) sumb += b[i];

    vis[0][500001] = 1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<1000002; j++)  vis[1-i%2][j] = 0;
        for (int j=0; j<1000002; j++) if (vis[i%2][j]) {
            if (a[i]+j<1000002) vis[1-i%2][j+a[i]] = 1;
            if (-b[i]+j>=0) vis[1-i%2][-b[i]+j] = 1;
        }
    }

    best = 10000000;
    for (int j=0; j<1000002; j++) if (vis[n%2][j]) {
        int tmp = abs(j-500001);
        tmp = max(tmp, j-500001-suma+sumb);
        best = min(best,tmp);
    }

    return best;
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
		cout << "Testing MayTheBestPetWin (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1380991745;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 450.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		MayTheBestPetWin _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A[] = {3,4,4,7};
				int B[] = {3,4,4,7};
				_expected = 2;
				_received = _obj.calc(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}
			case 1:
			{
				int A[] = {1,3,5,4,5};
				int B[] = {2,5,6,8,7};
				_expected = 5;
				_received = _obj.calc(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}
			case 2:
			{
				int A[] = {2907,949,1674,6092,8608,5186,2630,970,1050,2415,1923,2697,5571,6941,8065,4710,716,756,5185,1341,993,5092,248,1895,4223,1783,3844,3531,2431,1755,2837,4015,1895,4223,1783,3844,3531,2431,1755,2837,4015,1895,4223,1783,3844,3531,2431,1755,2837,4015};
				int B[] = {7296,6954,4407,9724,8645,8065,9323,8433,1352,9618,6487,7309,9297,8999,9960,5653,4721,7623,6017,7320,3513,6642,6359,3145,7233,5077,6457,3605,2911,4679,5381,6574,3145,7233,5077,6457,3605,2911,4679,5381,6574,3145,7233,5077,6457,3605,2911,4679,5381,6574};
				_expected = 52873;
				_received = _obj.calc(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}
			/*case 3:
			{
				int A[] = ;
				int B[] = ;
				_expected = ;
				_received = _obj.calc(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}*/
			/*case 4:
			{
				int A[] = ;
				int B[] = ;
				_expected = ;
				_received = _obj.calc(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int A[] = ;
				int B[] = ;
				_expected = ;
				_received = _obj.calc(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
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
