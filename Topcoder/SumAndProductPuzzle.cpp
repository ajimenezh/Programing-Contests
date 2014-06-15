#line 2 "SumAndProductPuzzle.cpp"
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

bool has[5000010];
bool isprime[5000010];

bool check(int a) {
    for (int i=1; i<=a/2; i++) {
        int j = a-i;
        if (isprime[i] && isprime[j]) return false;
    }
    return true;
}

class SumAndProductPuzzle
{
        public:
        long long getSum(int A, int B) {

            for (int i=2; i<=5000000; i++) isprime[i] = 1;
            for (int i=2; i*i<=5000000; i++) if (isprime[i]) {
                for (int j=i*i; j<=5000000; j+=i) isprime[j] = 0;
            }

            long long tot = 0;
            for (int i=A; i<=B; i++) {
                if (check(i)) {
                    cout<<i<<endl;
                    tot += i;
                }
            }
            return tot;
        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 30; int Arg1 = 33; long long Arg2 = 33LL; verify_case(0, Arg2, getSum(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 8; int Arg1 = 11; long long Arg2 = 19LL; verify_case(1, Arg2, getSum(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 40; int Arg1 = 43; long long Arg2 = 0LL; verify_case(2, Arg2, getSum(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 47; int Arg1 = 74; long long Arg2 = 168LL; verify_case(3, Arg2, getSum(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 2; long long Arg2 = 0LL; verify_case(4, Arg2, getSum(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
        SumAndProductPuzzle ___test;
        ___test.run_test(-1);

        system("pause"); //Windows Only

        return 0;
}
// END CUT HERE
