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

const long long mod = 1000000007;

vector<vector<long long> > mul(vector<vector<long long> > m, vector<vector<long long> > k) {
    vector<vector<long long> > t(2,vector<long long> (2,0));
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            t[i][j] = 0;
            for (int p=0; p<2; p++) {
                t[i][j] = (t[i][j] + m[i][p]*k[p][j]%mod)%mod;
            }
        }
    }
    return t;
}

vector<vector<long long> > solve(vector<vector<long long> > m, long long n) {
    if (n==1) {
        m[0][0] = 3;
        m[1][0] = 1;
        m[0][1] = 1;
        m[1][1] = 3;
        return m;
    }
    vector<vector<long long> > k(2,vector<long long> (2,0));
    k[0][0] = m[0][0];
    k[1][0] = m[1][0];
    k[0][1] = m[0][1];
    k[1][1] = m[1][1];

    m = solve(m,n/2);

    m = mul(m,m);

    if (n%2==1) m = mul(m,k);
    return m ;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    long long n;
    cin>>n;
    if (!n) {
        cout<<1;
        return 0;
    }
    vector<vector<long long> > m(2,vector<long long> (2,0));
    m[0][0] = 3;
    m[1][0] = 1;
    m[0][1] = 1;
    m[1][1] = 3;

    m = solve(m,n);

    cout<<m[0][0]%mod<<endl;

    return 0;

}
