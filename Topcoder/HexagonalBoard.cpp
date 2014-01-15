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


class HexagonalBoard {
	public:
	int minColors(vector <string> board) ;
};

int n;
int dx[] = {0,1,0,-1,1,-1};
int dy[] = {1,0,-1,0,-1,1};
int col[51][51];

int HexagonalBoard::minColors(vector <string> board) {
    int m = 0;
    n = board.size();
    bool some = 0;
    bool next = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            col[i][j] = -1;
        }
    }
    for (int i=0; i<board.size(); i++) {
        for (int j=0; j<board[0].length(); j++) if (board[i][j]=='X') {
            if (col[i][j]==-1) col[i][j] = 0;
            for (int k=0; k<6; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x<0 || x>=board.size()) continue;
                if (y<0 || y>=board[0].length()) continue;
                if (board[x][y]=='-') continue;

                if (col[x][y]==-1) col[x][y] = col[i][j]^1;
                else if (col[x][y]==col[i][j]) return 3;
            }
        }
    }
    m = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            m = max(m ,col[i][j]+1);
        }
    }

    return m;
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
		cout << "Testing HexagonalBoard (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1380988812;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		HexagonalBoard _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {"---",
				                  "---",
				                  "---"}
				                  ;
				_expected = 0;
				_received = _obj.minColors(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 1:
			{
				string board[] = {"-X--",
				                  "---X",
				                  "----",
				                  "-X--"};
				_expected = 1;
				_received = _obj.minColors(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 2:
			{
				string board[] = {"XXXX",
				                  "---X",
				                  "---X",
				                  "---X"};
				_expected = 2;
				_received = _obj.minColors(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 3:
			{
				string board[] = {"XX-XX--"
				                 ,"-XX-XXX"
				                 ,"X-XX--X"
				                 ,"X--X-X-"
				                 ,"XX-X-XX"
				                 ,"-X-XX-X"
				                 ,"-XX-XX-"};
				_expected = 3;
				_received = _obj.minColors(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			/*case 4:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.minColors(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.minColors(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.minColors(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
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
