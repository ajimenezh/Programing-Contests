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


class MailArchiving {
	public:
	int minSelections(vector <string> destFolders) ;
};

int dp[51][51];
map<string,int> id;
int cnt;
int v[51];
int n;

int solve(int a, int b) {
    if (a==b) return 1;
    if (a>b) return 0;
    if (dp[a][b]>=0) return dp[a][b];

    int tmp = 1000000;

    for (int i=a+1; i<=b; i++) if (v[i]==v[a]) tmp = min(tmp, solve(a+1,i-1)+solve(i,b));

    tmp = min(tmp, 1+solve(a+1,b));
    tmp = min(tmp, 1+solve(a,b-1));

    dp[a][b] = tmp;

    return tmp;
}

int MailArchiving::minSelections(vector <string> destFolders) {
	n = destFolders.size();
	for (int i=0; i<n; i++) {
        if (id.find(destFolders[i])==id.end()) {
            id[destFolders[i]] = cnt++;
        }
	}

	for (int i=0; i<n; i++) v[i] = id[destFolders[i]];

	for (int i=0; i<n; i++) for (int j = 0; j<n; j++) dp[i][j] = -1;

    int ans = solve(0,n-1);

	return  ans;
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
		cout << "Testing MailArchiving (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1379796405;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 900.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		MailArchiving _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string destFolders[] = {"Deleted messages","Saved messages","Deleted messages"};
				_expected = 2;
				_received = _obj.minSelections(vector <string>(destFolders, destFolders+sizeof(destFolders)/sizeof(string))); break;
			}
			case 1:
			{
				string destFolders[] = {"Folder A","Folder B","Folder C","Folder D","Folder E","Folder F"};
				_expected = 6;
				_received = _obj.minSelections(vector <string>(destFolders, destFolders+sizeof(destFolders)/sizeof(string))); break;
			}
			case 2:
			{
				string destFolders[] = {"FOLDER","folder"};
				_expected = 2;
				_received = _obj.minSelections(vector <string>(destFolders, destFolders+sizeof(destFolders)/sizeof(string))); break;
			}
			case 3:
			{
				string destFolders[] = {"a","b","a","c","a","a","b","a","c","d","a"};
				_expected = 6;
				_received = _obj.minSelections(vector <string>(destFolders, destFolders+sizeof(destFolders)/sizeof(string))); break;
			}
			case 4:
			{
				string destFolders[] = {"a","b","b","c","d","e","d","e","d","e",
				                        "c","c","a","a","a","f","g","g","f","a",
				                        "h","h","i","j","i","j","a","a","k","k",
				                        "l","m","k","l","m","a","o","o","p","a"};
				_expected = 20;
				_received = _obj.minSelections(vector <string>(destFolders, destFolders+sizeof(destFolders)/sizeof(string))); break;
			}
			/*case 5:
			{
				string destFolders[] = ;
				_expected = ;
				_received = _obj.minSelections(vector <string>(destFolders, destFolders+sizeof(destFolders)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string destFolders[] = ;
				_expected = ;
				_received = _obj.minSelections(vector <string>(destFolders, destFolders+sizeof(destFolders)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string destFolders[] = ;
				_expected = ;
				_received = _obj.minSelections(vector <string>(destFolders, destFolders+sizeof(destFolders)/sizeof(string))); break;
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
