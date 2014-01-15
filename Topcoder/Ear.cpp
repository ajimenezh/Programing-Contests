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


class Ear {
	public:
	long long getCount(vector <string> redX, vector <string> blueX, vector <string> blueY) ;
};

int v[10010];
int red[310];
int bluex[310];
int bluey[310];
int nr, nbx, nby;

void update(int x) {
    for (;x<=10000; x+=x&-x) v[x]++;
}
int get(int x) {
    int sum = 0;
    for(;x>=1; x-=x&-x) sum += v[x];
    return sum;
}

int vect(int i, int j, int k) {
    int ux = bluex[j] - red[i];
    int vx = bluex[k] - red[i];
    int uy = bluey[j];
    int vy = bluey[k];

    return ux*vy - uy*vx;
}

long long Ear::getCount(vector <string> redX, vector <string> blueX, vector <string> blueY) {
	string sred, sbluex, sbluey;
	for (int i=0; i<redX.size(); i++) sred += redX[i];
	for (int i=0; i<blueX.size(); i++) sbluex += blueX[i];
	for (int i=0; i<blueY.size(); i++) sbluey += blueY[i];
	stringstream ssred(sred), ssbluex(sbluex), ssbluey(sbluey);

	while (ssred>>sred) {
        red[nr++] = atoi(sred.c_str());
	}
	while (ssbluex>>sbluex) {
        bluex[nbx++] = atoi(sbluex.c_str());
	}
	while (ssbluey>>sbluey) {
        bluey[nby++] = atoi(sbluey.c_str());
	}

	sort(red, red + nr);
	for (int i=0; i<nr; i++) update(red[i]);

	long long ans = 0;
	for (int i=0; i<nbx; i++) {
        for (int j=0; j<nbx; j++) if (i!=j && bluey[i]>bluey[j]) {
            long long left = 0;
            for (int k=0; k<nr; k++) {
                if (red[k]>=bluex[i] || vect(k,i,j)>=0) break;
                left += get(bluex[j]-1) - get(red[k]);
            }
            long long right = 0;
            for (int k=nr-1; k>=0; k--) {
                if (red[k]<=bluex[i] || vect(k,i,j)<=0) break;
                right += get(red[k]-1) - get(bluex[j]);
            }
            ans += right*left;
        }
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
		cout << "Testing Ear (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1383304378;
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
		Ear _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string redX[] = {"3 2 8 7"};
				string blueX[] = {"5 4"};
				string blueY[] = {"2 4"};
				_expected = 1LL;
				_received = _obj.getCount(vector <string>(redX, redX+sizeof(redX)/sizeof(string)), vector <string>(blueX, blueX+sizeof(blueX)/sizeof(string)), vector <string>(blueY, blueY+sizeof(blueY)/sizeof(string))); break;
			}
			case 1:
			{
				string redX[] = {"3 2 8 7"};
				string blueX[] = {"2 8"};
				string blueY[] = {"3 4"};
				_expected = 0LL;
				_received = _obj.getCount(vector <string>(redX, redX+sizeof(redX)/sizeof(string)), vector <string>(blueX, blueX+sizeof(blueX)/sizeof(string)), vector <string>(blueY, blueY+sizeof(blueY)/sizeof(string))); break;
			}
			case 2:
			{
				string redX[] = {"1 2 6 9"};
				string blueX[] = {"3 6 8 5"};
				string blueY[] = {"1 5 4 3"};
				_expected = 4LL;
				_received = _obj.getCount(vector <string>(redX, redX+sizeof(redX)/sizeof(string)), vector <string>(blueX, blueX+sizeof(blueX)/sizeof(string)), vector <string>(blueY, blueY+sizeof(blueY)/sizeof(string))); break;
			}
			case 3:
			{
				string redX[] = {"10000"};
				string blueX[] = {"10000 9999"};
				string blueY[] = {"10000 9999"};
				_expected = 0LL;
				_received = _obj.getCount(vector <string>(redX, redX+sizeof(redX)/sizeof(string)), vector <string>(blueX, blueX+sizeof(blueX)/sizeof(string)), vector <string>(blueY, blueY+sizeof(blueY)/sizeof(string))); break;
			}
			case 4:
			{
				string redX[] = {"100 2", "00", " 39", "9", " 800 900 9", "99"};
				string blueX[] = {"15", "0 250 ", "349"};
				string blueY[] = {"2 3 1"};
				_expected = 12LL;
				_received = _obj.getCount(vector <string>(redX, redX+sizeof(redX)/sizeof(string)), vector <string>(blueX, blueX+sizeof(blueX)/sizeof(string)), vector <string>(blueY, blueY+sizeof(blueY)/sizeof(string))); break;
			}
			case 5:
			{
				string redX[] = {"1", " ", "2", " ", "3", " ", "4 5 6", " 7 8 9"};
				string blueX[] = {"4", " ", "5", " ", "6", " 7 ", "8"};
				string blueY[] = {"1", " 2 ", "3 4", " 5"};
				_expected = 204LL;
				_received = _obj.getCount(vector <string>(redX, redX+sizeof(redX)/sizeof(string)), vector <string>(blueX, blueX+sizeof(blueX)/sizeof(string)), vector <string>(blueY, blueY+sizeof(blueY)/sizeof(string))); break;
			}
			/*case 6:
			{
				string redX[] = ;
				string blueX[] = ;
				string blueY[] = ;
				_expected = LL;
				_received = _obj.getCount(vector <string>(redX, redX+sizeof(redX)/sizeof(string)), vector <string>(blueX, blueX+sizeof(blueX)/sizeof(string)), vector <string>(blueY, blueY+sizeof(blueY)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string redX[] = ;
				string blueX[] = ;
				string blueY[] = ;
				_expected = LL;
				_received = _obj.getCount(vector <string>(redX, redX+sizeof(redX)/sizeof(string)), vector <string>(blueX, blueX+sizeof(blueX)/sizeof(string)), vector <string>(blueY, blueY+sizeof(blueY)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string redX[] = ;
				string blueX[] = ;
				string blueY[] = ;
				_expected = LL;
				_received = _obj.getCount(vector <string>(redX, redX+sizeof(redX)/sizeof(string)), vector <string>(blueX, blueX+sizeof(blueX)/sizeof(string)), vector <string>(blueY, blueY+sizeof(blueY)/sizeof(string))); break;
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
