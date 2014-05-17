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


class WebsiteRank {
	public:
	long long countVotes(vector <string> votes, string website) ;
};

map<string, int> id;
int n;
int cnt;
vector<int> v[2510];
int a;
int graph[2510][2510];
long long sum[2510];

void dfs(int i, int k) {
    graph[k][i] = 1;
    for (int j=0; j<v[i].size(); j++) if (graph[k][v[i][j]]==0) dfs(v[i][j], k);
    return;
}

long long solve(int p) {
    if (sum[p]>=0) return sum[p];

    long long tmp = 1;
    for (int i=0; i<v[p].size(); i++) if (graph[p][v[p][i]]) tmp += solve(v[p][i]);

    sum[p] = tmp;
    return tmp;
}

void insert(string s) {
    if (id.find(s)!=id.end()) return;
    id[s] = cnt++;
}

long long WebsiteRank::countVotes(vector <string> votes, string website) {
    n = votes.size();
	for (int i=0; i<n; i++) {
        stringstream ss(votes[i]);
        string s;
        ss>>s;
        insert(s);
        int k = id[s];
        while (ss>>s) {
            insert(s);
            int c = id[s];
            v[k].push_back(c);
        }
	}
    a = id[website];
    n = cnt;
    for (int i=0; i<n; i++) dfs(i,i);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) if (graph[i][j]==graph[j][i]) {
            graph[i][j] = graph[j][i] = 0;
        }
    }
    for (int i=0; i<n; i++) sum[i] = -1;

	return solve(a);
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
		cout << "Testing WebsiteRank (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393667417;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		WebsiteRank _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string votes[] = {"C A B"};
				string website = "C";
				_expected = 3LL;
				_received = _obj.countVotes(vector <string>(votes, votes+sizeof(votes)/sizeof(string)), website); break;
			}
			case 1:
			{
				string votes[] = {"A B C D", "B C D", "C D"};
				string website = "A";
				_expected = 8LL;
				_received = _obj.countVotes(vector <string>(votes, votes+sizeof(votes)/sizeof(string)), website); break;
			}
			case 2:
			{
				string votes[] = {"A"};
				string website = "A";
				_expected = 1LL;
				_received = _obj.countVotes(vector <string>(votes, votes+sizeof(votes)/sizeof(string)), website); break;
			}
			case 3:
			{
				string votes[] = {"A B", "B A"};
				string website = "A";
				_expected = 1LL;
				_received = _obj.countVotes(vector <string>(votes, votes+sizeof(votes)/sizeof(string)), website); break;
			}
			case 4:
			{
				string votes[] = {"A B C D E F", "B A", "C B", "D B"};
				string website = "A";
				_expected = 3LL;
				_received = _obj.countVotes(vector <string>(votes, votes+sizeof(votes)/sizeof(string)), website); break;
			}
			case 5:
			{
				string votes[] = {"MYSITE OTHERSITE ANOTHERSITE THIRDSITE"};
				string website = "MYSITE";
				_expected = 4LL;
				_received = _obj.countVotes(vector <string>(votes, votes+sizeof(votes)/sizeof(string)), website); break;
			}
			/*case 6:
			{
				string votes[] = ;
				string website = ;
				_expected = LL;
				_received = _obj.countVotes(vector <string>(votes, votes+sizeof(votes)/sizeof(string)), website); break;
			}*/
			/*case 7:
			{
				string votes[] = ;
				string website = ;
				_expected = LL;
				_received = _obj.countVotes(vector <string>(votes, votes+sizeof(votes)/sizeof(string)), website); break;
			}*/
			/*case 8:
			{
				string votes[] = ;
				string website = ;
				_expected = LL;
				_received = _obj.countVotes(vector <string>(votes, votes+sizeof(votes)/sizeof(string)), website); break;
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
