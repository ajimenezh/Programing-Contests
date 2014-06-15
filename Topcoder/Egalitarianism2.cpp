#line 2 "Egalitarianism2.cpp"
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

vector<int> x,y;
int n;

double dist[21][21];
int par[20];

int find(int p) {
    if (par[p]==p) return p;
    par[p] = find(par[p]);
    return par[p];
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    par[a] = b;
}

double mst(double m) {
    vector<pair<double,pair<int,int> > > v;

    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            v.push_back(make_pair((dist[i][j]-m)*(dist[i][j]-m), make_pair(i,j)));
        }
    }

    sort(v.begin(), v.end());

    for (int i=0; i<n; i++) par[i] = i;

    double tot = 0;
    vector<double> all;
    for (int i=0; i<v.size(); i++) {
        if (find(v[i].second.first)!=find(v[i].second.second)) {
            merge(v[i].second.first, v[i].second.second);
            tot += dist[v[i].second.first][v[i].second.second];
            all.push_back(dist[v[i].second.first][v[i].second.second]);
        }
    }

    tot /= (n-1);

    double tmp = 0.0;
    for (int i=0; i<all.size(); i++) tmp += (all[i] - tot)*(all[i] - tot);

    return sqrt(tmp/(n-1));

}

class Egalitarianism2
{
        public:
        double minStdev(vector <int> _x, vector <int> _y)
        {
            x = _x;
            y = _y;
            n = x.size();

            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) if (i!=j) {
                    dist[i][j] = sqrt((double)(x[i]-x[j])*(x[i]-x[j]) + (double)(y[i]-y[j])*(y[i]-y[j]));
                }
            }

            vector<double> m;
            for (int i=0; i<n; i++) for (int j=i+1; j<n; j++) {
                for (int ii=i+1; ii<n; ii++) for (int jj=ii+1; jj<n; jj++) {
                    double m1 = dist[i][j];
                    double m2 = dist[ii][jj];
                    m.push_back((m1+m2)/2.0 + 1.0e-8);
                    m.push_back((m1+m2)/2.0 - 1.0e-8);
                }
            }

            double res = 100000000000000.0;
            for (int i=0; i<m.size(); i++) {
                res = min(res, mst(m[i]));
            }

            return res;
        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,0,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(0, Arg2, minStdev(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,9,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.5; verify_case(1, Arg2, minStdev(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {12,46,81,56}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,45,2,67}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 6.102799971320928; verify_case(2, Arg2, minStdev(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0,0,0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,2,3,9,10,15,16}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.9428090415820632; verify_case(3, Arg2, minStdev(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {167053, 536770, -590401, 507047, 350178, -274523, -584679, -766795, -664177, 267757, -291856, -765547, 604801, -682922, -404590, 468001, 607925, 503849, -499699, -798637}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-12396, -66098, -56843, 20270, 81510, -23294, 10423, 24007, -24343, -21587, -6318, -7396, -68622, 56304, -85680, -14890, -38373, -25477, -38240, 11736}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 40056.95946451828; verify_case(4, Arg2, minStdev(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {-306880, 169480, -558404, -193925, 654444, -300247, -456420, -119436, -620920, -470018, -914272, -691256, -49418, -21054, 603373, -23656, 891691, 258986, -453793, -782940}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-77318, -632629, -344942, -361706, 191982, 349424, 676536, 166124, 291342, -268968, 188262, -537953, -70432, 156803, 166174, 345128, 58614, -671747, 508265, 92324}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 36879.15127634308; verify_case(5, Arg2, minStdev(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
        Egalitarianism2 ___test;
        ___test.run_test(-1);

        system("pause"); //Windows Only

        return 0;
}
// END CUT HERE
