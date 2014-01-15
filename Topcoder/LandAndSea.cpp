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


class LandAndSea {
	public:
	vector <int> howManyIslands(vector <string> seaMap) ;
};

string s[56];
int t[56][56];
int n,m;
int dx[] = {1,0,-1,0,1,1,-1,-1};
int dy[] = {0,1,0,-1,-1,1,-1,1};
vector<vector<int> > v;
bool vis[56][56];
vector<int> e[2755];
int tot[2755];
bool done[2755];
int ans[2755];

void dfs(int x, int y, int c) {
    t[x][y] = c;
    for (int k=0; k<8; k++) {
        int xx = x+dx[k];
        int yy = y+dy[k];
        if (xx<0 || xx>=n) continue;
        if (yy<0 || yy>=m) continue;
        if (s[xx][yy]=='.') continue;
        if (t[xx][yy]!=-1) continue;
        dfs(xx,yy,c);
    }
    return;
}

void dfs2(int x,int y, int px, int py) {
    vis[x][y] = 1;
    for (int k=0; k<4; k++) {
        int xx = x+dx[k];
        int yy = y+dy[k];
        if (xx<0 || xx>=n) continue;
        if (yy<0 || yy>=m) continue;
        if (vis[xx][yy]) continue;
        if (s[xx][yy]=='.' || t[xx][yy]==-1) {
            dfs2(xx,yy,px,py);
        }
        else {
            if (t[xx][yy]==t[px][py]) continue;
            else v[t[px][py]][t[xx][yy]] = 1;
        }
    }
}

int calc(int p) {
    if (done[p]) return tot[p];
    if (e[p].size()==0) return 1;
    int tmp = 0;
    for (int i=0; i<e[p].size(); i++) {
        tmp = max(tmp, calc(e[p][i])+1);
    }
    tot[p] = tmp;
    done[p] = 1;
    return tmp;
}

vector <int> LandAndSea::howManyIslands(vector <string> seaMap) {
    for (int i=2; i<seaMap.size()+2; i++) s[i] = seaMap[i-2];
    for (int i=2; i<seaMap.size()+2; i++) s[i] = "x." + s[i] + ".x";
    m = s[2].length();
    string tmp;
    for (int i=1; i<m-1; i++) tmp += ".";
    tmp = "x" + tmp + "x";
    s[1] = s[seaMap.size()+2] = tmp;
    n = seaMap.size()+4;
    tmp = "";
    for (int i=0; i<m; i++) tmp += "x";
    s[0] = s[n-1] = tmp;
    int cnt = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            t[i][j] = -1;
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) if (s[i][j]=='x' && t[i][j]==-1) dfs(i,j,cnt++);
    }

    v = vector<vector<int> > (cnt, vector<int> (cnt,0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) if (t[i][j]>0) {
            for (int ii=0; ii<n; ii++) {
                for (int jj=0; jj<m; jj++) {
                    vis[ii][jj] = 0;
                }
            }
            dfs2(i,j,i,j);
        }
    }
    for (int i=1; i<cnt; i++) {
        int k = 0;
        int p = 1;
        if (v[i][0]) ;
        else {
            for (int j=1; j<cnt; j++) if (v[i][j]) {
                k++;
                p = j;
                if (k>1) break;
            }
            e[p].push_back(i);
        }
    }

    int last = 0;
    for (int i=1; i<cnt; i++) {
        tot[i] = calc(i);
        last = max(last, tot[i]);
        ans[tot[i]]++;
    }

    vector<int> res;
    for (int i=1; i<=last; i++) res.push_back(ans[i]);

    return res;
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
		cout << "Testing LandAndSea (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1389094312;
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
		LandAndSea _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string seaMap[] = {"x"};
				int __expected[] = {1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.howManyIslands(vector <string>(seaMap, seaMap+sizeof(seaMap)/sizeof(string))); break;
			}
			case 1:
			{
				string seaMap[] = {
				                  "xxxxx",
				                  "x...x",
				                  "x.x.x",
				                  "x...x",
				                  "xxxxx"
				                  };
				int __expected[] = {1, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.howManyIslands(vector <string>(seaMap, seaMap+sizeof(seaMap)/sizeof(string))); break;
			}
			case 2:
			{
				string seaMap[] = {
				                  "xxxxx",
				                  "x...x",
				                  "x.x.x",
				                  "x...x",
				                  "xxxxx",
				                  "xxxxx",
				                  "x...x",
				                  "x.x.x",
				                  "x...x",
				                  "xxxxx"
				                  };
				int __expected[] = {2, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.howManyIslands(vector <string>(seaMap, seaMap+sizeof(seaMap)/sizeof(string))); break;
			}
			case 3:
			{
				string seaMap[] = {
				                  "..",
				                  ".."
				                  };
				int __expected[] = { };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.howManyIslands(vector <string>(seaMap, seaMap+sizeof(seaMap)/sizeof(string))); break;
			}
			case 4:
			{
				string seaMap[] = {
				                  "..................................................",
				                  ".......xxxx........xxxx........xxxx........xxxx...",
				                  "..xxx.x...x...xxx.x...x...xxx.x...x...xxx.x...x...",
				                  "..x..x..x.x...x..x..x.x...x..x..x.x...x..x..x.x...",
				                  "..x.x.x...x...x.x.x...x...x.x.x...x...x.x.x...x...",
				                  "..xx...xxx....xx...xxx....xx...xxx....xx...xxx....",
				                  "..................................................",
				                  ".......xxxx........xxxx........xxxx........xxxx...",
				                  "..xxx.x...x...xxx.x...x...xxx.x...x...xxx.x...x...",
				                  "..x..x..x.x...x..x..x.x...x..x..x.x...x..x..x.x...",
				                  "..x.x.x...x...x.x.x...x...x.x.x...x...x.x.x...x...",
				                  "..xx...xxx....xx...xxx....xx...xxx....xx...xxx....",
				                  "..................................................",
				                  ".......xxxx........xxxx........xxxx........xxxx...",
				                  "..xxx.x...x...xxx.x...x...xxx.x...x...xxx.x...x...",
				                  "..x..x..x.x...x..x..x.x...x..x..x.x...x..x..x.x...",
				                  "..x.x.x...x...x.x.x...x...x.x.x...x...x.x.x...x...",
				                  "..xx...xxx....xx...xxx....xx...xxx....xx...xxx....",
				                  "..................................................",
				                  ".......xxxx........xxxx........xxxx........xxxx...",
				                  "..xxx.x...x...xxx.x...x...xxx.x...x...xxx.x...x...",
				                  "..x..x..x.x...x..x..x.x...x..x..x.x...x..x..x.x...",
				                  "..x.x.x...x...x.x.x...x...x.x.x...x...x.x.x...x...",
				                  "..xx...xxx....xx...xxx....xx...xxx....xx...xxx....",
				                  "..................................................",
				                  ".......xxxx........xxxx........xxxx........xxxx...",
				                  "..xxx.x...x...xxx.x...x...xxx.x...x...xxx.x...x...",
				                  "..x..x..x.x...x..x..x.x...x..x..x.x...x..x..x.x...",
				                  "..x.x.x...x...x.x.x...x...x.x.x...x...x.x.x...x...",
				                  "..xx...xxx....xx...xxx....xx...xxx....xx...xxx....",
				                  "..................................................",
				                  ".......xxxx........xxxx........xxxx........xxxx...",
				                  "..xxx.x...x...xxx.x...x...xxx.x...x...xxx.x...x...",
				                  "..x..x..x.x...x..x..x.x...x..x..x.x...x..x..x.x...",
				                  "..x.x.x...x...x.x.x...x...x.x.x...x...x.x.x...x...",
				                  "..xx...xxx....xx...xxx....xx...xxx....xx...xxx....",
				                  "..................................................",
				                  ".......xxxx........xxxx........xxxx........xxxx...",
				                  "..xxx.x...x...xxx.x...x...xxx.x...x...xxx.x...x...",
				                  "..x..x..x.x...x..x..x.x...x..x..x.x...x..x..x.x...",
				                  "..x.x.x...x...x.x.x...x...x.x.x...x...x.x.x...x...",
				                  "..xx...xxx....xx...xxx....xx...xxx....xx...xxx....",
				                  "..................................................",
				                  ".......xxxx........xxxx........xxxx........xxxx...",
				                  "..xxx.x...x...xxx.x...x...xxx.x...x...xxx.x...x...",
				                  "..x..x..x.x...x..x..x.x...x..x..x.x...x..x..x.x...",
				                  "..x.x.x...x...x.x.x...x...x.x.x...x...x.x.x...x...",
				                  "..xx...xxx....xx...xxx....xx...xxx....xx...xxx....",
				                  "..................................................",
				                  ".................................................."
				                  };
				int __expected[] = {1, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.howManyIslands(vector <string>(seaMap, seaMap+sizeof(seaMap)/sizeof(string))); break;
			}
			/*case 5:
			{
				string seaMap[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.howManyIslands(vector <string>(seaMap, seaMap+sizeof(seaMap)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string seaMap[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.howManyIslands(vector <string>(seaMap, seaMap+sizeof(seaMap)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string seaMap[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.howManyIslands(vector <string>(seaMap, seaMap+sizeof(seaMap)/sizeof(string))); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

//END CUT HERE
