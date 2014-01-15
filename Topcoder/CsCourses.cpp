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


class CsCourses {
	public:
	vector <int> getOrder(vector <int> theoreticalValue, vector <int> practicalValue, vector <int> expire, int skillBound) ;
};

int n;
int m;
int dist[55][55][55];
int next[55][55][55][2][2];
vector<int> vt, vp, ve;
priority_queue<pair<int,int> > q;
int ans;

int solve(int i, int t, int p) {
    if (t>=m && p>=m) {
        if (dist[i][t][p]<100) {
            dist[i][t][p] = 0;
            return 0;
        }
        return 100000;
    }
    int tmp = 1000000;
    if (next[i][t][p][1][0]) {
        tmp = min(tmp, solve(i+1,t+1,p));
    }
    if (next[i][t][p][0][1]) {
        tmp = min(tmp, solve(i+1,t,p+1));
    }
    if (next[i][t][p][1][1]) {
        tmp = min(tmp, solve(i+1,t+1,p+1));
    }
    dist[i][t][p] = tmp + 1;
    return tmp + 1;
}

vector <int> CsCourses::getOrder(vector <int> theoreticalValue, vector <int> practicalValue, vector <int> expire, int skillBound) {
    int n = theoreticalValue.size();
    vt = theoreticalValue;
    vp = practicalValue;
    ve = expire;
    m = skillBound;
    for (int i=0; i<51; i++) {
        for (int t=0; t<51; t++) {
            for (int p = 0; p<51; p++) dist[i][t][p] = 1000000;
        }
    }
    dist[0][0][0] = 0;
    q.push(make_pair(0,0));
    ans = -1;
    while (q.size()>0) {
        int h = q.top().second;
        int i = (h/55)/55;
        int t = (h/55)%55;
        int p = h%55;
        q.pop();

        if (t>=m && p>=m) {
            if (ans==-1) {
                ans = dist[i][t][p];
            }
        }
        if (ans!=-1 && ans<dist[i][t][p]) {
            continue;
        }
        for (int j=0; j<n; j++) {
            if (ve[j]>i) {
                if (t>=vt[j]-1 && p>=vp[j]-1) {
                    if (vt[j]>t || vp[j]>p) {
                        if (dist[i+1][max(t,vt[j])][max(p,vp[j])]>=dist[i][t][p]+1) {
                            if (t>=m && p>=m) {
                                if (ans==-1) {
                                    ans = dist[i][t][p]+1;
                                }
                                else if (ans<dist[i][t][p]+1) {
                                    continue;
                                }
                            }
                            if (dist[i+1][max(t,vt[j])][max(p,vp[j])]==dist[i][t][p]+1) {
                                int t1 = 0, p1 = 0;
                                if (vt[j]>t) t1 = 1;
                                if (vp[j]>p) p1 = 1;
                                if (!next[i][t][p][t1][p1] || next[i][t][p][t1][p1]>j+1) {
                                    next[i][t][p][t1][p1] = j+1;
                                }
                            }
                            else {
                                dist[i+1][max(t,vt[j])][max(p,vp[j])] = dist[i][t][p]+1;
                                int t1 = 0, p1 = 0;
                                if (vt[j]>t) t1 = 1;
                                if (vp[j]>p) p1 = 1;
                                if (!next[i][t][p][t1][p1] || next[i][t][p][t1][p1]>j+1) {
                                    next[i][t][p][t1][p1] = j+1;
                                }
                                q.push(make_pair(dist[i][t][p]+1, (i+1)*55*55 + max(t,vt[j])*55 + max(p,vp[j])));
                            }
                        }
                    }
                }
            }
        }
    }

    solve(0,0,0);
    //cout<<dist[0][0][0]<<endl;
    vector<int> res;
    if (dist[0][0][0]>100) return res;
    int i = 0, t = 0, p = 0;
    int tot = dist[0][0][0];
    while (t<m || p<m) {
        vector<int> tmp;
        if (dist[i+1][t+1][p]<tot) tmp.push_back(next[i][t][p][1][0]);
        if (dist[i+1][t+1][p+1]<tot) tmp.push_back(next[i][t][p][1][1]);
        if (dist[i+1][t][p+1]<tot) tmp.push_back(next[i][t][p][0][1]);
        sort(tmp.begin(), tmp.end());
        //cout<<i<<" "<<t<<" "<<p<<endl;
        //for (int k=0; k<tmp.size(); k++) cout<<tmp[k]<<" "; cout<<endl;
        //cout<<dist[i+1][t+1][p]<<" "<<dist[i+1][t+1][p+1]<<" "<<dist[i+1][t][p+1]<<endl;
        if (tmp.size()==0) break;
        if (dist[i+1][t+1][p]<tot && next[i][t][p][1][0]==tmp[0]) {
            res.push_back(next[i][t][p][1][0]-1);
            i++;
            t++;
        }
        else if (dist[i+1][t+1][p+1]<tot && next[i][t][p][1][1]==tmp[0]) {
            res.push_back(next[i][t][p][1][1]-1);
            i++;
            t++;
            p++;
        }
        else if (dist[i+1][t][p+1]<tot && next[i][t][p][0][1]==tmp[0]) {
            res.push_back(next[i][t][p][0][1]-1);
            i++;
            p++;
        }
        tot--;
    }
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
		cout << "Testing CsCourses (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1389009614;
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
		CsCourses _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int theoreticalValue[] = {1};
				int practicalValue[] = {1};
				int expire[] = {1};
				int skillBound = 1;
				int __expected[] = {0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getOrder(vector <int>(theoreticalValue, theoreticalValue+sizeof(theoreticalValue)/sizeof(int)), vector <int>(practicalValue, practicalValue+sizeof(practicalValue)/sizeof(int)), vector <int>(expire, expire+sizeof(expire)/sizeof(int)), skillBound); break;
			}
			case 1:
			{
				int theoreticalValue[] = {1, 2, 1};
				int practicalValue[] = {2, 1, 1};
				int expire[] = {5, 5, 5};
				int skillBound = 2;
				int __expected[] = {2, 0, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getOrder(vector <int>(theoreticalValue, theoreticalValue+sizeof(theoreticalValue)/sizeof(int)), vector <int>(practicalValue, practicalValue+sizeof(practicalValue)/sizeof(int)), vector <int>(expire, expire+sizeof(expire)/sizeof(int)), skillBound); break;
			}
			case 2:
			{
				int theoreticalValue[] = {1, 2, 1};
				int practicalValue[] = {2, 1, 1};
				int expire[] = {1, 1, 1};
				int skillBound = 2;
				int __expected[] = { };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getOrder(vector <int>(theoreticalValue, theoreticalValue+sizeof(theoreticalValue)/sizeof(int)), vector <int>(practicalValue, practicalValue+sizeof(practicalValue)/sizeof(int)), vector <int>(expire, expire+sizeof(expire)/sizeof(int)), skillBound); break;
			}
			case 3:
			{
				int theoreticalValue[] = {1, 2, 1};
				int practicalValue[] = {2, 1, 1};
				int expire[] = {3, 2, 1};
				int skillBound = 2;
				int __expected[] = {2, 1, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getOrder(vector <int>(theoreticalValue, theoreticalValue+sizeof(theoreticalValue)/sizeof(int)), vector <int>(practicalValue, practicalValue+sizeof(practicalValue)/sizeof(int)), vector <int>(expire, expire+sizeof(expire)/sizeof(int)), skillBound); break;
			}
			case 4:
			{
				int theoreticalValue[] = {1, 2, 3, 4, 5, 6, 7};
				int practicalValue[] = {1, 2, 3, 4, 5, 6, 7};
				int expire[] = {1, 2, 3, 4, 5, 6, 7};
				int skillBound = 7;
				int __expected[] = {0, 1, 2, 3, 4, 5, 6 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getOrder(vector <int>(theoreticalValue, theoreticalValue+sizeof(theoreticalValue)/sizeof(int)), vector <int>(practicalValue, practicalValue+sizeof(practicalValue)/sizeof(int)), vector <int>(expire, expire+sizeof(expire)/sizeof(int)), skillBound); break;
			}
			case 5:
			{
				int theoreticalValue[] = {0, 1, 2, 2, 1};
				int practicalValue[] = {0, 0, 1, 2, 1};
				int expire[] = {9, 9, 9, 9, 9};
				int skillBound = 2;
				int __expected[] = {4, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getOrder(vector <int>(theoreticalValue, theoreticalValue+sizeof(theoreticalValue)/sizeof(int)), vector <int>(practicalValue, practicalValue+sizeof(practicalValue)/sizeof(int)), vector <int>(expire, expire+sizeof(expire)/sizeof(int)), skillBound); break;
			}
			/*case 6:
			{
				int theoreticalValue[] = ;
				int practicalValue[] = ;
				int expire[] = ;
				int skillBound = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getOrder(vector <int>(theoreticalValue, theoreticalValue+sizeof(theoreticalValue)/sizeof(int)), vector <int>(practicalValue, practicalValue+sizeof(practicalValue)/sizeof(int)), vector <int>(expire, expire+sizeof(expire)/sizeof(int)), skillBound); break;
			}*/
			/*case 7:
			{
				int theoreticalValue[] = ;
				int practicalValue[] = ;
				int expire[] = ;
				int skillBound = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getOrder(vector <int>(theoreticalValue, theoreticalValue+sizeof(theoreticalValue)/sizeof(int)), vector <int>(practicalValue, practicalValue+sizeof(practicalValue)/sizeof(int)), vector <int>(expire, expire+sizeof(expire)/sizeof(int)), skillBound); break;
			}*/
			/*case 8:
			{
				int theoreticalValue[] = ;
				int practicalValue[] = ;
				int expire[] = ;
				int skillBound = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getOrder(vector <int>(theoreticalValue, theoreticalValue+sizeof(theoreticalValue)/sizeof(int)), vector <int>(practicalValue, practicalValue+sizeof(practicalValue)/sizeof(int)), vector <int>(expire, expire+sizeof(expire)/sizeof(int)), skillBound); break;
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
