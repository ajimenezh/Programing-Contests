#line 2 "CycleColoring.cpp"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

typedef long long LL;
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)

int n;
vector<int> c, f, t;
long long dp[55][2];
int k;
int mod = 1000000007;

long long solve(int i, int p) {
    if (i==n && p==0) return 1;
    if (i==n) return 0;
    if (dp[i][p]>=0) return dp[i][p];

    if (toVertex[i]==fromVertex[i]) {

    }
    else {
        if (abs(toVertex[i]-fromVertex[i])==1 || c[i] - abs(toVertex[i]-fromVertex[i])==1) {
            int a = min(abs(toVertex[i]-fromVertex[i]), c[i] - abs(toVertex[i]-fromVertex[i]));
            int b = c[i] - 2 - a;

            long long tmp = k-1;
            if (b==1) tmp = (tmp*(k-1))%mod;
            else {
                tmp = (tmp*fpow((k-)))
            }
        }
        else {
            int a = abs(toVertex[i]-fromVertex[i]) - 1;
            int b = c[i] - 2 - a;

            long long tmp = fpow(a-2,k);
            tmp = (tmp*(k-1))%mod;
            tmp = (tmp*(k-1))%mod;
            tmp = fpow(b-2,k);
            tmp = (tmp*(k-1))%mod;
            tmp = (tmp*(k-1))%mod;

            dp[i][p] = (solve(i+1, 0) + ((k-1)*solve(i+1, 1))%mod)%mod;
            dp[i][p] = (dp[i][p]*tmp)%mod;

            return dp[i][p];

        }
    }
}

class CycleColoring
{
        public:
        int countColorings(vector <int> vertexCount, vector <int> fromVertex, vector <int> toVertex, int K) {

            n = vertexCount.size();
            c = vertexCount;
            f = fromVertex;
            t = toVertex;
            k = K;

            for (int i=0; i<n; i++) {
                dp[i][0] = -1;
                dp[i][1] = -1;
            }

            return solve(0,0);

        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; int Arg4 = 12; verify_case(0, Arg4, countColorings(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; int Arg4 = 12; verify_case(1, Arg4, countColorings(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {3, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; int Arg4 = 0; verify_case(2, Arg4, countColorings(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {9, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 8; int Arg4 = 589124602; verify_case(3, Arg4, countColorings(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {14, 15, 16, 17}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5, 10, 4, 6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10, 3, 14, 10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 614; int Arg4 = 818050159; verify_case(4, Arg4, countColorings(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arr0[] = {482373, 283712, 883, 12834, 5, 5, 482734, 99912, 35881, 277590}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {59283, 49782, 0, 0, 3, 2, 84791, 40017, 2263, 461}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {150173, 709, 11108, 0, 4, 7, 5902, 712, 190232, 390331}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 479360784; int Arg4 = 763634309; verify_case(5, Arg4, countColorings(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
        CycleColoring ___test;
        ___test.run_test(-1);

        system("pause"); //Windows Only

        return 0;
}
// END CUT HERE
