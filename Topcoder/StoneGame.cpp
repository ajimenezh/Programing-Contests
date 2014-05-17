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


class StoneGame {
	public:
	int getScore(vector <int> treasure, vector <int> stones) ;
};

int StoneGame::getScore(vector <int> treasure, vector <int> stones) {
    int p = 0;
    while (true) {
        bool done = 0;
        int last = -1;
        for (int i=0; i<treasure.size(); i++) {
            if (stones[i]==1) {
                if (last!=-1) {
                    if (treasure[last]<treasure[i]) {
                        stones[last]++;
                        stones[i]--;
                        p -= treasure[last];
                        p += treasure[i];
                        last = i;
                    }
                }
                else {
                    stones[i]--;
                    p += treasure[i];
                    done = 1;
                    last = i;
                    done = 1;
                }
            }
        }
        if (!done) {
            for (int i=0; i<treasure.size(); i++) {
                if (stones[i]>2) {
                    stones[i]--;
                    done = 1;
                    break;
                }
            }
        }
        if (!done) {
            for (int i=0; i<treasure.size(); i++) {
                if (stones[i]==2) {
                    stones[i]--;
                    done = 1;
                    break;
                }
            }
        }
        if (!done) break;

        done = 0;
        last = -1;
        for (int i=0; i<treasure.size(); i++) {
            if (stones[i]==1) {
                if (last!=-1) {
                    if (treasure[last]<treasure[i]) {
                        stones[last]++;
                        stones[i]--;
                        last = i;
                    }
                }
                else {
                   stones[i]--;
                    done = 1;
                    last = i;
                    done = 1;
                }
            }
        }
        if (!done) {
            for (int i=0; i<treasure.size(); i++) {
                if (stones[i]>2) {
                    stones[i]--;
                    done = 1;
                    break;
                }
            }
        }
        if (!done) {
            for (int i=0; i<treasure.size(); i++) {
                if (stones[i]==2) {
                    stones[i]--;
                    done = 1;
                    break;
                }
            }
        }
        if (!done) break;
        if (!done) break;
    }

    return p;
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
		cout << "Testing StoneGame (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1391000642;
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
		StoneGame _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int treasure[] = {3,2};
				int stones[] = {1,2};
				_expected = 5;
				_received = _obj.getScore(vector <int>(treasure, treasure+sizeof(treasure)/sizeof(int)), vector <int>(stones, stones+sizeof(stones)/sizeof(int))); break;
			}
			case 1:
			{
				int treasure[] = {5,4,3,2,1};
				int stones[] = {1,1,1,1,1};
				_expected = 9;
				_received = _obj.getScore(vector <int>(treasure, treasure+sizeof(treasure)/sizeof(int)), vector <int>(stones, stones+sizeof(stones)/sizeof(int))); break;
			}
			case 2:
			{
				int treasure[] = {5,5};
				int stones[] = {2,2};
				_expected = 0;
				_received = _obj.getScore(vector <int>(treasure, treasure+sizeof(treasure)/sizeof(int)), vector <int>(stones, stones+sizeof(stones)/sizeof(int))); break;
			}
			case 3:
			{
				int treasure[] = {1};
				int stones[] = {10};
				_expected = 0;
				_received = _obj.getScore(vector <int>(treasure, treasure+sizeof(treasure)/sizeof(int)), vector <int>(stones, stones+sizeof(stones)/sizeof(int))); break;
			}
			/*case 4:
			{
				int treasure[] = ;
				int stones[] = ;
				_expected = ;
				_received = _obj.getScore(vector <int>(treasure, treasure+sizeof(treasure)/sizeof(int)), vector <int>(stones, stones+sizeof(stones)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int treasure[] = ;
				int stones[] = ;
				_expected = ;
				_received = _obj.getScore(vector <int>(treasure, treasure+sizeof(treasure)/sizeof(int)), vector <int>(stones, stones+sizeof(stones)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int treasure[] = ;
				int stones[] = ;
				_expected = ;
				_received = _obj.getScore(vector <int>(treasure, treasure+sizeof(treasure)/sizeof(int)), vector <int>(stones, stones+sizeof(stones)/sizeof(int))); break;
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
