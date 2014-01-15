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


class DropCoins {
	public:
	int getMinimum(vector <string> board, int K) ;
};

int sum[30][30];

int DropCoins::getMinimum(vector <string> board, int K) {

	int n = board.size();
	int m = board[0].length();

	int all = 0;
	for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            sum[i+1][j+1] = sum[i][j+1] + sum[i+1][j] - sum[i][j];
            if (board[i][j]=='o') {
                all++;
                sum[i+1][j+1]++;
            }
        }
	}

	int ans = 1000000;
	for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            for (int ii=i; ii<n; ii++) {
                for (int jj=j; jj<m; jj++) {
                    int tot = i + (n-ii-1)  + min(i,(n-ii-1)) + j + (m-jj-1) + min(j, (m-jj-1));
                    if ((sum[ii+1][jj+1] - sum[i][jj+1] - sum[ii+1][j] + sum[i][j])==K) {
                        ans = min(ans, tot);
                    }
                }
            }
        }
	}

	if (ans==1000000) return -1;
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
		cout << "Testing DropCoins (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1385039985;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		DropCoins _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {".o.."
				                 ,"oooo"
				                 ,"..o."};
				int K = 3;
				_expected = 2;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string)), K); break;
			}
			case 1:
			{
				string board[] = {".....o"
				                 ,"......"
				                 ,"oooooo"
				                 ,"oooooo"
				                 ,"......"
				                 ,"o....."};
				int K = 12;
				_expected = 3;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string)), K); break;
			}
			case 2:
			{
				string board[] = {"...."
				                 ,".oo."
				                 ,".oo."
				                 ,"...."};
				int K = 3;
				_expected = -1;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string)), K); break;
			}
			case 3:
			{
				string board[] = {"......."
				                 ,"..ooo.."
				                 ,"ooooooo"
				                 ,".oo.oo."
				                 ,"oo...oo"};
				int K = 12;
				_expected = 4;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string)), K); break;
			}
			case 4:
			{
				string board[] = {"................."
				                 ,".ooooooo...oooo.."
				                 ,".ooooooo..oooooo."
				                 ,".oo.......oo..oo."
				                 ,".oo.......oo..oo."
				                 ,".ooooo.....oooo.."
				                 ,".ooooooo...oooo.."
				                 ,".....ooo..oo..oo."
				                 ,"......oo..oo..oo."
				                 ,".ooooooo..oooooo."
				                 ,".oooooo....oooo.."
				                 ,"................."};
				int K = 58;
				_expected = 6;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string)), K); break;
			}
			/*case 5:
			{
				string board[] = ;
				int K = ;
				_expected = ;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string)), K); break;
			}*/
			/*case 6:
			{
				string board[] = ;
				int K = ;
				_expected = ;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string)), K); break;
			}*/
			/*case 7:
			{
				string board[] = ;
				int K = ;
				_expected = ;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string)), K); break;
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
