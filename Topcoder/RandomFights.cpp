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


class RandomFights {
	public:
	double expectedNrOfPoints(vector <int> A, vector <int> B, int n) ;
};

int n;
int a[50010];
int b[50010];
long long sum[50010];

double RandomFights::expectedNrOfPoints(vector <int> A, vector <int> B, int _n) {
    n = _n;
    int j = 0;
    int m = A.size();
    for (int i=0; i<n; i++) {
        a[i] = A[j];
        int s = (j+1)%m;
        A[j] = ((A[j]^A[s])+13)%49999;
        j = s;
    }
    j = 0;
    m = B.size();
    for (int i=0; i<n; i++) {
        b[i] = B[j];
        int s = (j+1)%m;
        B[j] = ((B[j]^B[s])+13)%49999;
        j = s;
    }

    sort(a,a+n);
    sort(b,b+n);

    sum[0] = 0;
    for (int i=0; i<n; i++) sum[i+1] = sum[i] + b[i];
    long long res = 0;
    for (int i=0; i<n; i++) {
        int k1 = 0, k2 = 0;
        int lo = 0;
        int hi = n-1;
        while (lo<hi) {
            int mi = (lo+hi)/2;
            if (b[mi]<a[i]) {
                lo = mi+1;
            }
            else {
                hi = mi;
            }
        }
        k1 = lo;
        lo = 0;
        hi = n-1;
        while (lo<hi) {
            int mi = (lo+hi)/2;
            if (b[mi]<=a[i]) {
                lo = mi+1;
            }
            else {
                hi = mi;
            }
        }
        k2 = lo;
        if (b[k1]<a[i]) k1++;
        if (b[k2]<=a[i]) k2++;
        //cout<<a[i]<<" "<<k1<<" "<<k2<<endl;
        res = res + (long long)a[i]*a[i]*(k1-(n-k2));
        //cout<<(long long)a[i]*a[i]*(k1-(n-k2))<<endl;
        res = res - 2LL*(long long)a[i]*(sum[k1] - (sum[n]-sum[k2]));
        //cout<<2LL*(long long)a[i]*(sum[k1] - (sum[n]-sum[k2]))<<endl;
        //cout<<res<<endl;
    }
    for (int i=0; i<n; i++) {
        int k1 = 0, k2 = 0;
        int lo = 0;
        int hi = n-1;
        while (lo<hi) {
            int mi = (lo+hi)/2;
            if (a[mi]<b[i]) {
                lo = mi+1;
            }
            else {
                hi = mi;
            }
        }
        k1 = lo;
        lo = 0;
        hi = n-1;
        while (lo<hi) {
            int mi = (lo+hi)/2;
            if (a[mi]<=b[i]) {
                lo = mi+1;
            }
            else {
                hi = mi;
            }
        }
        k2 = lo;
        if (a[k1]<b[i]) k1++;
        if (a[k2]<=b[i]) k2++;
        res = res - (long long)b[i]*b[i]*(k1-(n-k2));
    }
    //cout<<res<<endl;
    return (double)res/n;
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
		cout << "Testing RandomFights (950.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1388578732;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 950.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		RandomFights _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A[] = {6};
				int B[] = {4};
				int n = 1;
				_expected = 4.0;
				_received = _obj.expectedNrOfPoints(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), n); break;
			}
			case 1:
			{
				int A[] = {1,7};
				int B[] = {3,5};
				int n = 2;
				_expected = 0.0;
				_received = _obj.expectedNrOfPoints(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), n); break;
			}
			case 2:
			{
				int A[] = {3,7};
				int B[] = {1,5};
				int n = 2;
				_expected = 20.0;
				_received = _obj.expectedNrOfPoints(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), n); break;
			}
			case 3:
			{
				int A[] = {45,35,236,2342,5543,21,32,2,6,23,24,23,41,1};
				int B[] = {2345,45,2345,345};
				int n = 50;
				_expected = 1.2721986164E8;
				_received = _obj.expectedNrOfPoints(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), n); break;
			}
			case 4:
			{
				int A[] = {34,3245,2534,53,53,46,346,246,346,2,624,624,6,245,6324,6542,624,6};
				int B[] = {345,234,523,4624,6,2456,345,634,634,7,3457,376,34,6234,62,523,52,35,32};
				int n = 7;
				_expected = -9713701.714285715;
				_received = _obj.expectedNrOfPoints(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), n); break;
			}
			case 5:
			{
				int A[] = {1,2,3,4};
				int B[] = {1,2,3,4};
				int n = 50000;
				_expected = 0.0;
				_received = _obj.expectedNrOfPoints(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), n); break;
			}
			/*case 6:
			{
				int A[] = ;
				int B[] = ;
				int n = ;
				_expected = ;
				_received = _obj.expectedNrOfPoints(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), n); break;
			}*/
			/*case 7:
			{
				int A[] = ;
				int B[] = ;
				int n = ;
				_expected = ;
				_received = _obj.expectedNrOfPoints(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), n); break;
			}*/
			/*case 8:
			{
				int A[] = ;
				int B[] = ;
				int n = ;
				_expected = ;
				_received = _obj.expectedNrOfPoints(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), n); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

//END CUT HERE
