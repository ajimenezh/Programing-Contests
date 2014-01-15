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


class P8XMatrixRecovery {
	public:
	vector <string> solve(vector <string> rows, vector <string> columns) ;
};


const int VM=1010;
const int EM=200010;
const int INF=0x3f3f3f3f;

struct Edge{
    int to,nxt;
    int cap;
}edge[EM<<1];

int N,F,D,cnt,head[VM],src,des;
int dep[VM];

void init(int _n, int _src, int _dest) {
    N = _n;
    src = _src;
    des = _dest;
    for (int i=0; i<N; i++) head[i] = -1;
    cnt = 0;
}

void addedge(int cu,int cv,int cw){
    edge[cnt].to=cv;    edge[cnt].cap=cw;   edge[cnt].nxt=head[cu];
    head[cu]=cnt++;
    edge[cnt].to=cu;    edge[cnt].cap=0;    edge[cnt].nxt=head[cv];
    head[cv]=cnt++;
}

int BFS(){
    queue<int> q;
    while(!q.empty())
        q.pop();
    memset(dep,-1,sizeof(dep));
    dep[src]=0;
    q.push(src);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=head[u];i!=-1;i=edge[i].nxt){
            int v=edge[i].to;
            if(edge[i].cap>0 && dep[v]==-1){
                dep[v]=dep[u]+1;
                q.push(v);
            }
        }
    }
    return dep[des]!=-1;
}

int DFS(int u,int minx){
    if(u==des)
        return minx;
    int tmp;
    for(int i=head[u];i!=-1;i=edge[i].nxt){
        int v=edge[i].to;
        if(edge[i].cap>0 && dep[v]==dep[u]+1 && (tmp=DFS(v,min(minx,edge[i].cap)))){
            edge[i].cap-=tmp;
            edge[i^1].cap+=tmp;
            return tmp;
        }
    }
    dep[u]=-1;
    return 0;
}

int Dinic(){
    int ans=0,tmp;
    while(BFS()){
        while(1){
            tmp=DFS(src,INF);
            if(tmp==0)
                break;
            ans+=tmp;
        }
    }
    return ans;
}


bool can(vector<string> a, vector<string> b) {
    int n = a[0].length();
    int m = b.size();
    init(n+n+2,n+n,n+n+1);

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            bool bad = 0;
            for (int k=0; k<a.size(); k++) {
                if (a[k][i]!='?' && b[j][k]!='?' && a[k][i]!=b[j][k]) bad = 1;
            }
            if (!bad) addedge(i,n+j,1);
        }
    }

    for (int i=0; i<n; i++) addedge(src,i,1);
    for (int j=0; j<m; j++) addedge(n+j,des,1);

    if (Dinic()==n) return true;
    return false;
}

vector <string> P8XMatrixRecovery::solve(vector <string> rows, vector <string> columns) {
	vector<string> a = rows;
	vector<string> b = columns;

	for (int i=0; i<a.size(); i++) {
        for (int j=0; j<a[0].size(); j++) {
            if (a[i][j]=='?') {
                a[i][j] = '0';
                if (!can(a,b)) a[i][j] = '1';
            }
        }
	}

	return a;
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
		cout << "Testing P8XMatrixRecovery (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1384513534;
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
		P8XMatrixRecovery _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string rows[] = {"10?"
				                ,"?11"};
				string columns[] = {"01"
				                   ,"10"
				                   ,"1?"};
				string __expected[] = {"101", "011" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.solve(vector <string>(rows, rows+sizeof(rows)/sizeof(string)), vector <string>(columns, columns+sizeof(columns)/sizeof(string))); break;
			}
			case 1:
			{
				string rows[] = {"0"
				                ,"?"
				                ,"1"};
				string columns[] = {"0?1"};
				string __expected[] = {"0", "0", "1" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.solve(vector <string>(rows, rows+sizeof(rows)/sizeof(string)), vector <string>(columns, columns+sizeof(columns)/sizeof(string))); break;
			}
			case 2:
			{
				string rows[] = {"10"
				                ,"01"};
				string columns[] = {"10"
				                   ,"01"};
				string __expected[] = {"10", "01" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.solve(vector <string>(rows, rows+sizeof(rows)/sizeof(string)), vector <string>(columns, columns+sizeof(columns)/sizeof(string))); break;
			}
			case 3:
			{
				string rows[] = {"??0"
				                ,"11?"
				                ,"?01"
				                ,"1?1"};
				string columns[] = {"1???"
				                   ,"?111"
				                   ,"0?1?"};
				string __expected[] = {"010", "110", "101", "101" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.solve(vector <string>(rows, rows+sizeof(rows)/sizeof(string)), vector <string>(columns, columns+sizeof(columns)/sizeof(string))); break;
			}
			/*case 4:
			{
				string rows[] = ;
				string columns[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.solve(vector <string>(rows, rows+sizeof(rows)/sizeof(string)), vector <string>(columns, columns+sizeof(columns)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string rows[] = ;
				string columns[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.solve(vector <string>(rows, rows+sizeof(rows)/sizeof(string)), vector <string>(columns, columns+sizeof(columns)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string rows[] = ;
				string columns[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.solve(vector <string>(rows, rows+sizeof(rows)/sizeof(string)), vector <string>(columns, columns+sizeof(columns)/sizeof(string))); break;
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
