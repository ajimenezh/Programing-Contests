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

#define fo(i,n) for(int i=0; i<(int)n; i++)
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

vector<int> w;
map<long long, double> dp;
int n;

long long hash(vector<int> &v) {
    long long h = 0;
    long long f = 1;
    for (int i=0; i<n; i++) {
        h += f*v[i];
        f *= 10LL;
    }
    return h;
}

int fmin(int i, int j) {
    if (i<j) return i;
    return j;
}

int fmax(int i, int j) {
    if (i>j) return i;
    return j;
}

void fswap(int &i, int &j) {
    int tmp = i;
    i = j;
    j = tmp;
}

double solve1(vector<int> &v) {
    if (w==v) return 0.0;
    long long h = hash(v);
    if (dp.find(h)!=dp.end()) return dp[h];

    double res = 0.0;

    int c = 0, k = n*n;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (v[fmin(i,j)] > v[fmax(i,j)]) {
                fswap(v[i],v[j]);
                res += 1.0/(k)*(1.0 + solve1(v));
                fswap(v[i],v[j]);
            }
            else {
                c++;
            }
        }
    }

    res = (res + (double)c/k) / (1.0 - (double)c/k);

    dp[h] = res;

    return res;
}

double solve2(vector<int> &v) {
    if (w==v) return 0.0;
    long long h = hash(v);
    if (dp.find(h)!=dp.end()) return dp[h];

    double res = 0.0;

    int c = 0, k = n-1;

    for (int i=0; i<n-1; i++) {
        if (v[i] > v[i+1]) {
            fswap(v[i],v[i+1]);
            res += 1.0/(k)*(1.0 + solve2(v));
            fswap(v[i],v[i+1]);
        }
        else {
            c++;
        }
    }

    res = (res + (double)c/k) / (1.0 - (double)c/k);

    dp[h] = res;

    return res;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int tt;
    cin>>tt;
    while (tt--) {
        vector<int> v;
        cin>>n;
        for (int i=0; i<n; i++) {
            int a;
            cin>>a;
            v.push_back(a);
        }
        w = v;
        sort(w.begin(),w.end());
        dp.clear();
        double s1 = solve1(v);
        printf("Monty %.6lf ",s1);
        dp.clear();
        double s2 = solve2(v);
        printf("Carlos %.6lf\n",s2);
    }

    return 0;

}
