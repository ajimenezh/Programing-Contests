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

class FavouriteDigits {
	public:
	long long findNext(long long N, int digit1, int count1, int digit2, int count2) ;
};

long long f[18];
int v[18];
int d1, d2, count1, count2;
long long dp[20][16][16][2];
int l;

long long solve(int i, int  c1, int c2, bool t) {
    if (i==l) {
        if (c1==0 && c2==0) return 0;
        else return -1;
    }
    if (dp[i][c1][c2][t]>0) return dp[i][c1][c2][t];

    long long tmp = -1;

    if (t) {
        for (int j=0; j<10; j++) {
            if (j==d1) {
                long long res = solve(i+1,max(c1-1,0),c2,1);
                if (res!=-1) {
                    res += f[i]*d1;
                    if (tmp==-1) tmp = res;
                    else tmp = min(tmp, res);
                }
            }
            else if (j==d2) {
                long long res = solve(i+1,c1,max(c2-1,0),1);
                if (res!=-1) {
                    res += f[i]*d1;
                    if (tmp==-1) tmp = res;
                    else tmp = min(tmp, res);
                }
            }
            else {
                long long res = solve(i+1,c1,c2,1);
                if (res!=-1) {
                    res += f[i]*d1;
                    if (tmp==-1) tmp = res;
                    else tmp = min(tmp, res);
                }
            }
        }
    }
    else {
        for (int j=v[i]; j<10; j++) {
            if (j==d1) {
                long long res = solve(i+1,max(c1-1,0),c2,j>v[i]);
                if (res!=-1) {
                    res += f[i]*d1;
                    if (tmp==-1) tmp = res;
                    else tmp = min(tmp, res);
                }
            }
            else if (j==d2) {
                long long res = solve(i+1,c1,max(c2-1,0),j>v[i]);
                if (res!=-1) {
                    res += f[i]*d1;
                    if (tmp==-1) tmp = res;
                    else tmp = min(tmp, res);
                }
            }
            else {
                long long res = solve(i+1,c1,c2,j>v[i]);
                if (res!=-1) {
                    res += f[i]*d1;
                    if (tmp==-1) tmp = res;
                    else tmp = min(tmp, res);
                }
            }
        }
    }

    dp[i][c1][c2][t] = tmp;

    return tmp;
}

long long FavouriteDigits::findNext(long long N, int digit1, int _count1, int digit2, int _count2) {

	d1 = digit1;
	d2 = digit2;
	count1 = _count1;
	count2 = _count2;

	if (digit1>digit2) {
        swap(digit1,digit2);
        swap(count1,count2);
	}

	long long n = N;
	while (n>0) {
        v[l] = n%10;
        l++;
        n /= 10;
	}
	reverse(v,v+l);

	f[0] = 1;
	for (int i=1; i<18; i++) f[i] = 10*f[i-1];

	long long ans = -1;

	for (int i=0; i<=count1; i++) {
        for (int j=0; j<=count2; j++) {
            if (i+j+l>17) continue;
            long long tmp = 0;
            for (int k=0; k<i; k++) tmp += f[l+i+j-k]*digit1;
            for (int k=0; k<j; k++) tmp += f[l+j-k]*digit2;
            if (i==0 && j==0) tmp += solve(0,count1,count2,0);
            else tmp += solve(0,count1,count2,1);
            if (ans==-1) ans = tmp;
            else ans = min(ans, tmp);
        }
	}

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
		cout << "Testing FavouriteDigits (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1383841980;
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
		FavouriteDigits _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long N = 47LL;
				int digit1 = 1;
				int count1 = 0;
				int digit2 = 2;
				int count2 = 0;
				_expected = 47LL;
				_received = _obj.findNext(N, digit1, count1, digit2, count2); break;
			}
			case 1:
			{
				long long N = 47LL;
				int digit1 = 5;
				int count1 = 0;
				int digit2 = 9;
				int count2 = 1;
				_expected = 49LL;
				_received = _obj.findNext(N, digit1, count1, digit2, count2); break;
			}
			case 2:
			{
				long long N = 47LL;
				int digit1 = 5;
				int count1 = 0;
				int digit2 = 3;
				int count2 = 1;
				_expected = 53LL;
				_received = _obj.findNext(N, digit1, count1, digit2, count2); break;
			}
			case 3:
			{
				long long N = 47LL;
				int digit1 = 2;
				int count1 = 1;
				int digit2 = 0;
				int count2 = 2;
				_expected = 200LL;
				_received = _obj.findNext(N, digit1, count1, digit2, count2); break;
			}
			case 4:
			{
				long long N = 123456789012345LL;
				int digit1 = 1;
				int count1 = 2;
				int digit2 = 2;
				int count2 = 4;
				_expected = 123456789012422LL;
				_received = _obj.findNext(N, digit1, count1, digit2, count2); break;
			}
			case 5:
			{
				long long N = 92LL;
				int digit1 = 1;
				int count1 = 1;
				int digit2 = 0;
				int count2 = 0;
				_expected = 100LL;
				_received = _obj.findNext(N, digit1, count1, digit2, count2); break;
			}
			/*case 6:
			{
				long long N = LL;
				int digit1 = ;
				int count1 = ;
				int digit2 = ;
				int count2 = ;
				_expected = LL;
				_received = _obj.findNext(N, digit1, count1, digit2, count2); break;
			}*/
			/*case 7:
			{
				long long N = LL;
				int digit1 = ;
				int count1 = ;
				int digit2 = ;
				int count2 = ;
				_expected = LL;
				_received = _obj.findNext(N, digit1, count1, digit2, count2); break;
			}*/
			/*case 8:
			{
				long long N = LL;
				int digit1 = ;
				int count1 = ;
				int digit2 = ;
				int count2 = ;
				_expected = LL;
				_received = _obj.findNext(N, digit1, count1, digit2, count2); break;
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
