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


class CellRemoval {
	public:
	int cellsLeft(vector <int> parent, int deletedCell) ;
};

vector<int> e[55];
int root;

int dfs(int p, int kill) {
    if (p==kill) return 0;
    if (e[p].size()==0) return 1;
    int t = 0;
    for (int i=0; i<e[p].size(); i++) {
        t += dfs(e[p][i], kill);
    }
    return t;
}

int CellRemoval::cellsLeft(vector <int> parent, int deletedCell) {
	for (int i=0; i<parent.size(); i++) {
        int k = parent[i];
        if (k==-1) root = i;
        else {
            e[k].push_back(i);
        }
	}
	return dfs(root, deletedCell);
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
		cout << "Testing CellRemoval (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397047849;
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
		CellRemoval _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int parent[] = {-1,0,0,1,1};
				int deletedCell = 2;
				_expected = 2;
				_received = _obj.cellsLeft(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), deletedCell); break;
			}
			case 1:
			{
				int parent[] = {-1,0,0,1,1};
				int deletedCell = 1;
				_expected = 1;
				_received = _obj.cellsLeft(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), deletedCell); break;
			}
			case 2:
			{
				int parent[] = {-1,0,0,1,1};
				int deletedCell = 0;
				_expected = 0;
				_received = _obj.cellsLeft(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), deletedCell); break;
			}
			case 3:
			{
				int parent[] = {-1,0,0,2,2,4,4,6,6};
				int deletedCell = 4;
				_expected = 2;
				_received = _obj.cellsLeft(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), deletedCell); break;
			}
			case 4:
			{
				int parent[] = {26,2,32,36,40,19,43,24,30,13,21,14,24,21,19,4,30,10,44,12,7,32,17,43,
				                35,18,7,36,10,16,5,38,35,4,13,-1,16,26,1,12,2,5,18,40,1,17,38,44,14};
				int deletedCell = 24;
				_expected = 14;
				_received = _obj.cellsLeft(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), deletedCell); break;
			}
			/*case 5:
			{
				int parent[] = ;
				int deletedCell = ;
				_expected = ;
				_received = _obj.cellsLeft(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), deletedCell); break;
			}*/
			/*case 6:
			{
				int parent[] = ;
				int deletedCell = ;
				_expected = ;
				_received = _obj.cellsLeft(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), deletedCell); break;
			}*/
			/*case 7:
			{
				int parent[] = ;
				int deletedCell = ;
				_expected = ;
				_received = _obj.cellsLeft(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), deletedCell); break;
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
