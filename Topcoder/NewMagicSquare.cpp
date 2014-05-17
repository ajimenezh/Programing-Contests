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


class NewMagicSquare {
	public:
	vector <string> completeTheSquare(vector <string> square) ;
};

const int maxnode=1000+5;
const int maxedge=6000+5;
const int INF=1000000000;

int n,src,dest,nedge;
int head[maxnode],point[maxedge],next[maxedge],flow[maxedge],capa[maxedge];
int dist[maxnode],q[maxnode],work[maxnode];

void init(int _n, int _src, int _dest) {
    n = _n;
    src = _src;
    dest = _dest;
    for (int i=0; i<n; i++) head[i] = -1;
    nedge = 0;
}

void add_edge(int u, int v, int c1, int c2) {
    point[nedge] = v; capa[nedge]=c1; flow[nedge] = 0; next[nedge]=head[u]; head[u] = (nedge++);
    point[nedge] = u; capa[nedge]=c2; flow[nedge] = 0; next[nedge]=head[v]; head[v] = (nedge++);
}

bool bfs() {
    for (int i=0; i<n; i++) dist[i] = -1;
    dist[src] = 0;
    int fn = 0;
    q[fn++]=src;
    int in=0;
    while (fn!=in)
    {
        for (int k=q[in], i=head[k]; i>=0; i=next[i])
        {
            if (flow[i]<capa[i] && dist[point[i]]<0)
            {
                dist[point[i]] = dist[k]+1;
                q[fn++] = point[i];
            }
        }
        in++;
    }
    return dist[dest]>=0;
}

int dfs(int x, int f) {
    if (!f) return 0;
    if (x == dest) return f;

    int res = 0;
    for (int i = work[x]; i>=0; i = next[i])
    {
        int v = point[i],temp;

        if (flow[i] < capa[i] && dist[v] == (dist[x] + 1))
        {
            temp=dfs(v,min(f,capa[i]-flow[i]));
            if (temp>0)
            {
                flow[i] += temp;
                flow[i^1] -= temp;
                res += temp;
                f -= temp;
                if (f==0) break;
            }
        }
    }
    return res;
}

int dinic() {
    int f = 0;
    while (bfs())
    {
        for (int i = 0; i<n; i++) work[i] = head[i];

        f += dfs(src,INF);
    }
    return f;
}

int a[5][5];
int b[5][5];
bool vis[25];

bool check() {
    for (int i=0; i<25; i++) vis[i] = 0;
    for (int i=0; i<5; i++) for (int j=0; j<5; j++) if (b[i][j]!=-1) {
        if (vis[b[i][j]]) return false;
        vis[b[i][j]] = true;
    }
    for (int i=0; i<5; i++) for (int j=0; j<5; j++) for (int k=j+1; k<5; k++) if (b[i][j]!=-1 && b[i][k]!=-1 && b[i][j]>b[i][k]) return false;

    init(52,50,51);

    int tmp = 0;
    for (int i=0; i<5; i++) for (int j=0; j<5; j++) {
        if (b[i][j]!=-1) continue;
        tmp++;
        int lo = -1;
        int hi = 25;
        for (int k=0; k<j; k++) if (b[i][k]!=-1) lo = max(lo, b[i][k]);
        for (int k=4; k>j; k--) if (b[i][k]!=-1) hi = min(hi, b[i][k]);
        for (int k=lo+1; k<hi; k++) add_edge(i*5+j, 25+k, 1, 0);
        add_edge(50, i*5+j, 1, 0);
    }
    for (int i=0; i<25; i++) if (!vis[i]) add_edge(25+i, 51, 1, 0);

    if (dinic()==tmp) return true;
    return false;
}

vector <string> NewMagicSquare::completeTheSquare(vector <string> square) {
    for (int i=0; i<5; i++) for (int j=0;j<5; j++) {
        if (square[i][3*j]=='?') a[i][j] = -1;
        else a[i][j] = (square[i][3*j]-'0')*10 + (square[i][3*j+1]-'0') - 1;
    }
    for (int i=0; i<5; i++) for (int j=0; j<5; j++) {
        if (a[i][j]!=-1) continue;
        for (int ii=0; ii<5; ii++) for (int jj=0; jj<5; jj++) b[ii][jj] = a[ii][jj];
        int k;
        for (k=0; k<25; k++) {
            b[i][j] = k;
            if (check()) break;
        }
        if (k==25) return vector<string>();
        a[i][j] = b[i][j];
    }

    vector<string> ans;

    for (int i=0; i<5; i++) {
        string s;
        for (int j=0; j<5; j++) {
            s += char((a[i][j]+1)/10 + '0');
            s += char((a[i][j]+1)%10 + '0');
            if (j!=4) s += ' ';
        }
        ans.push_back(s);
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
		cout << "Testing NewMagicSquare (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393529552;
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
		NewMagicSquare _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string square[] = {"?? ?? ?? ?? ??",
				                   "?? ?? ?? ?? ??",
				                   "?? ?? ?? ?? ??",
				                   "?? ?? ?? ?? ??",
				                   "?? ?? ?? ?? ??"};
				string __expected[] = {"01 02 03 04 05", "06 07 08 09 10", "11 12 13 14 15", "16 17 18 19 20", "21 22 23 24 25" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.completeTheSquare(vector <string>(square, square+sizeof(square)/sizeof(string))); break;
			}
			case 1:
			{
				string square[] = {"?? ?? 20 ?? ??",
				                   "?? ?? ?? ?? ??",
				                   "?? ?? ?? 05 ??",
				                   "?? ?? ?? ?? ??",
				                   "?? ?? ?? ?? ??"};
				string __expected[] = {"01 06 20 21 22", "07 08 09 10 11", "02 03 04 05 12", "13 14 15 16 17", "18 19 23 24 25" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.completeTheSquare(vector <string>(square, square+sizeof(square)/sizeof(string))); break;
			}
			case 2:
			{
				string square[] = {"?? ?? ?? ?? ??",
				                   "?? ?? ?? ?? 24",
				                   "?? ?? ?? ?? ??",
				                   "?? ?? ?? ?? ??",
				                   "21 ?? ?? ?? ??"};
				string __expected[] = { };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.completeTheSquare(vector <string>(square, square+sizeof(square)/sizeof(string))); break;
			}
			case 3:
			{
				string square[] = {"?? ?? 15 ?? ??",
				                   "02 ?? ?? ?? ??",
				                   "?? ?? ?? 07 ??",
				                   "?? ?? 16 ?? ??",
				                   "?? ?? ?? ?? 21"};
				string __expected[] = {"01 03 15 17 18", "02 08 09 10 22", "04 05 06 07 23", "11 12 16 24 25", "13 14 19 20 21" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.completeTheSquare(vector <string>(square, square+sizeof(square)/sizeof(string))); break;
			}
			/*case 4:
			{
				string square[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.completeTheSquare(vector <string>(square, square+sizeof(square)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string square[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.completeTheSquare(vector <string>(square, square+sizeof(square)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string square[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.completeTheSquare(vector <string>(square, square+sizeof(square)/sizeof(string))); break;
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
				cout << " \"" << _expected[i] << "\"";
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _received[i] << "\"";
			}
			cout << " }" << endl;
		}
	}
}

//END CUT HERE
