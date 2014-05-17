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


class MoneyGame {
	public:
	int play(vector <int> lennysCoins, vector <int> fredsCoins, vector <int> values) ;
};

int dp[11][11][11][11][11][11];
bool vis[11][11][11][11][11][11];
bool done[11][11][11][11][11][11];
vector<int> v;
int tot[3];

int solve(int a1,int a2,int b1,int b2,int c1,int c2) { //cout<<"hola "<<a1<<" "<<a2<<" "<<b1<<" "<<b2<<" "<<c1<<" "<<c2<<endl;
    if (a1==0 && b1==0 && c1==0) return -a2*v[0] - b2*v[1] - c2*v[2];
    if (vis[a1][a2][b1][b2][c1][c2]) return 1000000000;
    if (done[a1][a2][b1][b2][c1][c2]) return dp[a1][a2][b1][b2][c1][c2];

    int tmp = -1000000000;

    vis[a1][a2][b1][b2][c1][c2] = 1;

    if (a1!=0) {
        tmp = max(tmp, -solve(a2,a1-1,b2,b1,c2,c1));
    }
    if (b1!=0) {
        for (int i=0; i<=tot[0]-a1-a2; i++) {
            if (i*v[0]>=v[1]) break;
            tmp = max(tmp, -solve(a2,a1+i,b2,b1-1,c2,c1));
        }
    }
    if (c1!=0) {
        for (int i=0; i<=tot[0]-a1-a2; i++) {
            if (i*v[0]>=v[2]) break;
            for (int j=0; j<=tot[1]-b1-b2; j++) {
                if (i*v[0]+j*v[1]>=v[2]) break;
                tmp = max(tmp, -solve(a2,a1+i,b2,b1+j,c2,c1-1));
            }
        }
    }

    done[a1][a2][b1][b2][c1][c2] = 1;

    dp[a1][a2][b1][b2][c1][c2] = tmp;

    vis[a1][a2][b1][b2][c1][c2] = 0;

    //cout<<a1<<" "<<a2<<" "<<b1<<" "<<b2<<" "<<c1<<" "<<c2<<" "<<tmp<<endl;

    return tmp;

}

int MoneyGame::play(vector <int> lennysCoins, vector <int> fredsCoins, vector <int> values) {
    for (int i=0; i<3; i++) {
        for (int j=i+1; j<3; j++) {
            if (values[i]>values[j]) {
                swap(values[i],values[j]);
                swap(lennysCoins[i], lennysCoins[j]);
                swap(fredsCoins[i], fredsCoins[j]);
            }
        }
    }
    v = values;
    for (int i=0; i<3; i++) tot[i] = lennysCoins[i] + fredsCoins[i];

    int ans = solve(lennysCoins[0], fredsCoins[0], lennysCoins[1], fredsCoins[1], lennysCoins[2], fredsCoins[2]);

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
		cout << "Testing MoneyGame (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1390826992;
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
		MoneyGame _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int lennysCoins[] = {0,1,1};
				int fredsCoins[] = {0,1,1};
				int values[] = {20,10,2};
				_expected = -2;
				_received = _obj.play(vector <int>(lennysCoins, lennysCoins+sizeof(lennysCoins)/sizeof(int)), vector <int>(fredsCoins, fredsCoins+sizeof(fredsCoins)/sizeof(int)), vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}
			case 1:
			{
				int lennysCoins[] = {0,1,2};
				int fredsCoins[] = {0,1,1};
				int values[] = {20,10,2};
				_expected = 2;
				_received = _obj.play(vector <int>(lennysCoins, lennysCoins+sizeof(lennysCoins)/sizeof(int)), vector <int>(fredsCoins, fredsCoins+sizeof(fredsCoins)/sizeof(int)), vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}
			case 2:
			{
				int lennysCoins[] = {1,1,0};
				int fredsCoins[] = {0,0,1};
				int values[] = {1,5,10};
				_expected = 0;
				_received = _obj.play(vector <int>(lennysCoins, lennysCoins+sizeof(lennysCoins)/sizeof(int)), vector <int>(fredsCoins, fredsCoins+sizeof(fredsCoins)/sizeof(int)), vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}
			case 3:
			{
				int lennysCoins[] = {4,4,3};
				int fredsCoins[] = {4,3,4};
				int values[] = {100,753,100};
				_expected = 600;
				_received = _obj.play(vector <int>(lennysCoins, lennysCoins+sizeof(lennysCoins)/sizeof(int)), vector <int>(fredsCoins, fredsCoins+sizeof(fredsCoins)/sizeof(int)), vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}
			case 4:
			{
				int lennysCoins[] = {5,5,5};
				int fredsCoins[] = {5,5,5};
				int values[] = {1,10,100};
				_expected = -19;
				_received = _obj.play(vector <int>(lennysCoins, lennysCoins+sizeof(lennysCoins)/sizeof(int)), vector <int>(fredsCoins, fredsCoins+sizeof(fredsCoins)/sizeof(int)), vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}
			case 5:
			{
				int lennysCoins[] = {3,2,1};
				int fredsCoins[] = {0,0,0};
				int values[] = {6,8,14};
				_expected = 42;
				_received = _obj.play(vector <int>(lennysCoins, lennysCoins+sizeof(lennysCoins)/sizeof(int)), vector <int>(fredsCoins, fredsCoins+sizeof(fredsCoins)/sizeof(int)), vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}
			/*case 6:
			{
				int lennysCoins[] = ;
				int fredsCoins[] = ;
				int values[] = ;
				_expected = ;
				_received = _obj.play(vector <int>(lennysCoins, lennysCoins+sizeof(lennysCoins)/sizeof(int)), vector <int>(fredsCoins, fredsCoins+sizeof(fredsCoins)/sizeof(int)), vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int lennysCoins[] = ;
				int fredsCoins[] = ;
				int values[] = ;
				_expected = ;
				_received = _obj.play(vector <int>(lennysCoins, lennysCoins+sizeof(lennysCoins)/sizeof(int)), vector <int>(fredsCoins, fredsCoins+sizeof(fredsCoins)/sizeof(int)), vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int lennysCoins[] = ;
				int fredsCoins[] = ;
				int values[] = ;
				_expected = ;
				_received = _obj.play(vector <int>(lennysCoins, lennysCoins+sizeof(lennysCoins)/sizeof(int)), vector <int>(fredsCoins, fredsCoins+sizeof(fredsCoins)/sizeof(int)), vector <int>(values, values+sizeof(values)/sizeof(int))); break;
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
