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


class HatRack {
	public:
	long long countWays(vector <int> knob1, vector <int> knob2) ;
};

vector<int> e[55];
int n;
int last[55];
bool vis[55];

bool dfs(int u, int v, int h, int k) {
    if (h>k) return false;
    if (h<k-1 && e[u].size()<3 && v!=-1) return false;
    if (e[u].size()>3 || (v==-1 && e[u].size()>2)) return false;
    bool flag = 1;
    for (int i=0; i<e[u].size(); i++) if (e[u][i]!=v) {
        flag &= dfs(e[u][i],u,h+1,k);
    }
    return flag;
}

bool check(int a, int k) {
    if (!dfs(a,-1,1,k)) return 0;
    return 1;
}

int make(int u, int v, int h, int k) {
    if (h == k) last[u] = 1;
    for (int i=0; i<e[u].size(); i++) if (e[u][i]!=v) {
        last[u] += make(e[u][i], u, h+1, k);
    }
    return last[u];
}

long long solve(int u, int v, int k) {
    if (e[u].size()==1) return 1;
    long long tmp = 0;
    long long t1 = -1, t2 = -1;
    int s1 = -1, s2 = -1;
    for (int i=0; i<e[u].size(); i++) if (e[u][i]!=v) {
        if (s1==-1) {
            s1 = last[e[u][i]];
            t1 = solve(e[u][i], u, k-1);
        }
        else {
            s2 = last[e[u][i]];
            t2 = solve(e[u][i], u, k-1);
        }
    }
    //cout<<u+1<<" "<<s1<<" "<<s2<<" "<<t1<<" "<<t2<<" "<<k<<endl;
    if (s2==-1) {
        return t1;
    }
    else {
        if (s1==(1<<k) && s2==(1<<k)) {
            return 2*t1*t2;
        }
        else {
            if (s1<s2) {
                swap(s1,s2);
                swap(t1,t2);
            }
            if (s1==(1<<k) || s2==0) {
                return t1*t2;
            }
            else return 0;
        }
    }
}

long long HatRack::countWays(vector <int> knob1, vector <int> knob2) {
	n = knob1.size();
	for (int i=0; i<n; i++) {
        e[knob1[i]-1].push_back(knob2[i]-1);
        e[knob2[i]-1].push_back(knob1[i]-1);
	}
	n++;

    int k = 0;
    while ((1<<k)<=n) k++;

	long long ans = 0;
	for (int i=0; i<n; i++) {
        if (!check(i, k)) continue;
        for (int j=0; j<n; j++) last[j] = 0;
        make(i,-1, 1, k);
        ans += solve(i,-1,k-2);
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
		cout << "Testing HatRack (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1383238935;
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
		HatRack _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int knob1[] = {1};
				int knob2[] = {2};
				_expected = 2LL;
				_received = _obj.countWays(vector <int>(knob1, knob1+sizeof(knob1)/sizeof(int)), vector <int>(knob2, knob2+sizeof(knob2)/sizeof(int))); break;
			}
			case 1:
			{
				int knob1[] = {1,1};
				int knob2[] = {2,3};
				_expected = 2LL;
				_received = _obj.countWays(vector <int>(knob1, knob1+sizeof(knob1)/sizeof(int)), vector <int>(knob2, knob2+sizeof(knob2)/sizeof(int))); break;
			}
			case 2:
			{
				int knob1[] = {1,1,1,1};
				int knob2[] = {2,3,4,5};
				_expected = 0LL;
				_received = _obj.countWays(vector <int>(knob1, knob1+sizeof(knob1)/sizeof(int)), vector <int>(knob2, knob2+sizeof(knob2)/sizeof(int))); break;
			}
			case 3:
			{
				int knob1[] = {6,6,6,4,1};
				int knob2[] = {1,2,4,5,3};
				_expected = 0LL;
				_received = _obj.countWays(vector <int>(knob1, knob1+sizeof(knob1)/sizeof(int)), vector <int>(knob2, knob2+sizeof(knob2)/sizeof(int))); break;
			}
			case 4:
			{
				int knob1[] = {1,1,2,2,11,11,8,8,3,3,4,4,5};
				int knob2[] = {2,3,11,8,12,13,9,10,4,5,7,6,14};
				_expected = 16LL;
				_received = _obj.countWays(vector <int>(knob1, knob1+sizeof(knob1)/sizeof(int)), vector <int>(knob2, knob2+sizeof(knob2)/sizeof(int))); break;
			}
			case 5:
			{
				int knob1[] = {1,2,3,4,5,6,7,8,9};
				int knob2[] = {2,3,4,5,6,7,8,9,10};
				_expected = 0LL;
				_received = _obj.countWays(vector <int>(knob1, knob1+sizeof(knob1)/sizeof(int)), vector <int>(knob2, knob2+sizeof(knob2)/sizeof(int))); break;
			}
			case 6:
			{
				int knob1[] = {2,1,3};
				int knob2[] = {4,4,2};
				_expected = 2LL;
				_received = _obj.countWays(vector <int>(knob1, knob1+sizeof(knob1)/sizeof(int)), vector <int>(knob2, knob2+sizeof(knob2)/sizeof(int))); break;
			}
			/*case 7:
			{
				int knob1[] = ;
				int knob2[] = ;
				_expected = LL;
				_received = _obj.countWays(vector <int>(knob1, knob1+sizeof(knob1)/sizeof(int)), vector <int>(knob2, knob2+sizeof(knob2)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int knob1[] = ;
				int knob2[] = ;
				_expected = LL;
				_received = _obj.countWays(vector <int>(knob1, knob1+sizeof(knob1)/sizeof(int)), vector <int>(knob2, knob2+sizeof(knob2)/sizeof(int))); break;
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
