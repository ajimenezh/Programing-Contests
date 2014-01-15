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


class KeyDungeonDiv1 {
	public:
	int maxKeys(vector <int> doorR, vector <int> doorG, vector <int> roomR, vector <int> roomG, vector <int> roomW, vector <int> keys) ;
};

bool dp[1<<12][135];

int KeyDungeonDiv1::maxKeys(vector <int> doorR, vector <int> doorG, vector <int> roomR, vector <int> roomG, vector <int> roomW, vector <int> keys) {
	int n = doorR.size();
	for (int i=0; i<=keys[2]; i++) dp[0][i] = 1;
	int best = 0;
	for (int i=0; i<(1<<n); i++) for (int j=0; j<=130; j++) if (dp[i][j]) {
        int r = keys[0] + j, g = keys[1] - j + keys[2];
        for (int j=0; j<n; j++) if ((1<<j)&i) {
            r += -doorR[j] + roomR[j];
            g += -doorG[j] + roomG[j] + roomW[j];
        }
        best = max(best, r+g);
        for (int t=0; t<n; t++) if (((1<<t)&i)==0) {
            if (r>=doorR[t] && g>=doorG[t]) {
                for (int k=0; k<=roomW[t]; k++) {
                    dp[i|(1<<t)][j+k] = 1;
                }
            }
        }
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
		cout << "Testing KeyDungeonDiv1 (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1381073216;
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
		KeyDungeonDiv1 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int doorR[] = {1, 2, 3};
				int doorG[] = {0, 4, 9};
				int roomR[] = {0, 0, 10};
				int roomG[] = {0, 8, 9};
				int roomW[] = {1, 0, 8};
				int keys[] = {3, 1, 2};
				_expected = 8;
				_received = _obj.maxKeys(vector <int>(doorR, doorR+sizeof(doorR)/sizeof(int)), vector <int>(doorG, doorG+sizeof(doorG)/sizeof(int)), vector <int>(roomR, roomR+sizeof(roomR)/sizeof(int)), vector <int>(roomG, roomG+sizeof(roomG)/sizeof(int)), vector <int>(roomW, roomW+sizeof(roomW)/sizeof(int)), vector <int>(keys, keys+sizeof(keys)/sizeof(int))); break;
			}
			case 1:
			{
				int doorR[] = {1, 1, 1, 2};
				int doorG[] = {0, 2, 3, 1};
				int roomR[] = {2, 1, 0, 4};
				int roomG[] = {1, 3, 3, 1};
				int roomW[] = {1, 0, 2, 1};
				int keys[] = {0, 4, 0};
				_expected = 4;
				_received = _obj.maxKeys(vector <int>(doorR, doorR+sizeof(doorR)/sizeof(int)), vector <int>(doorG, doorG+sizeof(doorG)/sizeof(int)), vector <int>(roomR, roomR+sizeof(roomR)/sizeof(int)), vector <int>(roomG, roomG+sizeof(roomG)/sizeof(int)), vector <int>(roomW, roomW+sizeof(roomW)/sizeof(int)), vector <int>(keys, keys+sizeof(keys)/sizeof(int))); break;
			}
			case 2:
			{
				int doorR[] = {2, 0, 4};
				int doorG[] = {3, 0, 4};
				int roomR[] = {0, 0, 9};
				int roomG[] = {0, 0, 9};
				int roomW[] = {8, 5, 9};
				int keys[] = {0, 0, 0};
				_expected = 27;
				_received = _obj.maxKeys(vector <int>(doorR, doorR+sizeof(doorR)/sizeof(int)), vector <int>(doorG, doorG+sizeof(doorG)/sizeof(int)), vector <int>(roomR, roomR+sizeof(roomR)/sizeof(int)), vector <int>(roomG, roomG+sizeof(roomG)/sizeof(int)), vector <int>(roomW, roomW+sizeof(roomW)/sizeof(int)), vector <int>(keys, keys+sizeof(keys)/sizeof(int))); break;
			}
			case 3:
			{
				int doorR[] = {5, 3, 0, 0};
				int doorG[] = {0, 1, 2, 1};
				int roomR[] = {0, 9, 2, 4};
				int roomG[] = {2, 9, 2, 0};
				int roomW[] = {0, 9, 1, 1};
				int keys[] = {1, 1, 0};
				_expected = 32;
				_received = _obj.maxKeys(vector <int>(doorR, doorR+sizeof(doorR)/sizeof(int)), vector <int>(doorG, doorG+sizeof(doorG)/sizeof(int)), vector <int>(roomR, roomR+sizeof(roomR)/sizeof(int)), vector <int>(roomG, roomG+sizeof(roomG)/sizeof(int)), vector <int>(roomW, roomW+sizeof(roomW)/sizeof(int)), vector <int>(keys, keys+sizeof(keys)/sizeof(int))); break;
			}
			case 4:
			{
				int doorR[] = {9,5,10,8,4,3,0,8,4,1,3,9};
				int doorG[] = {9,10,0,8,9,4,3,8,1,8,10,4};
				int roomR[] = {1,2,0,2,3,3,5,3,1,3,0,5};
				int roomG[] = {5,2,5,0,5,2,3,4,0,0,5,2};
				int roomW[] = {1,5,1,2,0,4,4,0,3,3,1,3};
				int keys[] = {5,0,1};
				_expected = 16;
				_received = _obj.maxKeys(vector <int>(doorR, doorR+sizeof(doorR)/sizeof(int)), vector <int>(doorG, doorG+sizeof(doorG)/sizeof(int)), vector <int>(roomR, roomR+sizeof(roomR)/sizeof(int)), vector <int>(roomG, roomG+sizeof(roomG)/sizeof(int)), vector <int>(roomW, roomW+sizeof(roomW)/sizeof(int)), vector <int>(keys, keys+sizeof(keys)/sizeof(int))); break;
			}
			/*case 5:
			{
				int doorR[] = ;
				int doorG[] = ;
				int roomR[] = ;
				int roomG[] = ;
				int roomW[] = ;
				int keys[] = ;
				_expected = ;
				_received = _obj.maxKeys(vector <int>(doorR, doorR+sizeof(doorR)/sizeof(int)), vector <int>(doorG, doorG+sizeof(doorG)/sizeof(int)), vector <int>(roomR, roomR+sizeof(roomR)/sizeof(int)), vector <int>(roomG, roomG+sizeof(roomG)/sizeof(int)), vector <int>(roomW, roomW+sizeof(roomW)/sizeof(int)), vector <int>(keys, keys+sizeof(keys)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int doorR[] = ;
				int doorG[] = ;
				int roomR[] = ;
				int roomG[] = ;
				int roomW[] = ;
				int keys[] = ;
				_expected = ;
				_received = _obj.maxKeys(vector <int>(doorR, doorR+sizeof(doorR)/sizeof(int)), vector <int>(doorG, doorG+sizeof(doorG)/sizeof(int)), vector <int>(roomR, roomR+sizeof(roomR)/sizeof(int)), vector <int>(roomG, roomG+sizeof(roomG)/sizeof(int)), vector <int>(roomW, roomW+sizeof(roomW)/sizeof(int)), vector <int>(keys, keys+sizeof(keys)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int doorR[] = ;
				int doorG[] = ;
				int roomR[] = ;
				int roomG[] = ;
				int roomW[] = ;
				int keys[] = ;
				_expected = ;
				_received = _obj.maxKeys(vector <int>(doorR, doorR+sizeof(doorR)/sizeof(int)), vector <int>(doorG, doorG+sizeof(doorG)/sizeof(int)), vector <int>(roomR, roomR+sizeof(roomR)/sizeof(int)), vector <int>(roomG, roomG+sizeof(roomG)/sizeof(int)), vector <int>(roomW, roomW+sizeof(roomW)/sizeof(int)), vector <int>(keys, keys+sizeof(keys)/sizeof(int))); break;
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
